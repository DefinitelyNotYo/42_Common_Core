*This project has been created as part of the 42 curriculum by yoherfan.*

# Inception

## Description

**Goal.** Inception is a system administration project whose aim is to build a small web infrastructure with **Docker** and **Docker Compose**, inside a virtual machine. Each service runs in its own dedicated container, built from a custom Dockerfile based on `debian:bookworm` (no pre-built service images pulled from Docker Hub).

**Overview.** The stack is made of three services:

| Service | Image | Role |
|---|---|---|
| **nginx** | `nginx:inception` | Only entry point of the infrastructure: listens on port **443** only, TLSv1.2 / TLSv1.3, self-signed certificate |
| **wordpress** | `wordpress:inception` | WordPress running on **PHP 8.2-FPM** (no web server inside), listening on port 9000 for FastCGI requests from nginx |
| **mariadb** | `mariadb:inception` | MariaDB database used by WordPress |

The containers talk to each other through a dedicated bridge network (`inception-network`). Two persistent volumes store the database and the WordPress files.

### Use of Docker and included sources

Docker packages each service together with its dependencies in an isolated, reproducible container, described by a Dockerfile and orchestrated by Docker Compose. The sources included in this repository are:

```
inception/
├── Makefile
├── secrets/
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── .env
    ├── docker-compose.yml
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── conf/50-server.cnf
        │   └── tools/init_db.sh
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/nginx.conf
        │   └── tools/generate_ssl.sh
        └── wordpress/
            ├── Dockerfile
            ├── conf/www.conf
            └── tools/setup_wordpress.sh
```

- **`Makefile`**: builds and manages the whole stack (`all`, `build`, `up`, `down`, `clean`, `fclean`, `re`) and creates the data directories.
- **`srcs/docker-compose.yml`**: defines the three services, the network, the volumes and the secrets.
- **`srcs/.env`**: non-sensitive configuration (domain name, database name, database user).
- **`secrets/`**: password files used as Docker secrets (must never be committed to the repository).
- **`requirements/mariadb/`**: Dockerfile, server configuration (`50-server.cnf`) and `init_db.sh`, which initializes the data directory, creates the database and the user on first run, then starts `mysqld` in the foreground.
- **`requirements/nginx/`**: Dockerfile, `nginx.conf` (TLS, FastCGI pass to `wordpress:9000`) and `generate_ssl.sh`, which generates a self-signed certificate and starts nginx in the foreground.
- **`requirements/wordpress/`**: Dockerfile (PHP-FPM 8.2 and extensions), pool configuration (`www.conf`) and `setup_wordpress.sh`, which downloads WordPress, generates `wp-config.php` (reading the DB password from the secret) and starts PHP-FPM in the foreground.

### Main design choices

- **One service per container**, each one running a single foreground process as PID 1 (`exec mysqld`, `exec nginx -g "daemon off;"`, `exec php-fpm8.2 -F`), with no `tail -f` / `sleep infinity` hacks.
- **Custom images** built from `debian:bookworm`, tagged `<service>:inception`, with `restart: always`.
- **Single entry point**: only port 443 is published to the host. MariaDB (3306) and PHP-FPM (9000) are reachable only inside the Docker network.
- **TLS only**: nginx accepts TLSv1.2 and TLSv1.3 with a self-signed certificate generated at first start.
- **Idempotent setup**: the database and WordPress are initialized only if they do not exist yet, so data survives container restarts and rebuilds.
- **Database passwords as Docker secrets**, read by the setup scripts from `/run/secrets/`; non-sensitive configuration in `.env`.
- **Shared WordPress volume** mounted in both `wordpress` and `nginx`, so nginx serves static files directly and forwards only PHP to PHP-FPM.
- **Service startup order** handled with `depends_on` (`nginx` → `wordpress` → `mariadb`).

### Comparisons

#### Virtual Machines vs Docker

| | Virtual Machine | Docker |
|---|---|---|
| Isolation | Full guest OS with its own kernel, strong isolation | Isolated processes (namespaces / cgroups) sharing the host kernel |
| Size | GBs of disk | MBs per image |
| Startup | Minutes | Seconds |
| Overhead | Hypervisor + full OS per VM | Very low |
| Portability | Heavy disk images | Lightweight images rebuilt from a Dockerfile |
| Typical use | Running different OSes, strong security boundaries | Packaging and deploying applications and services |

In this project Docker runs *inside* a VM: the VM provides the host environment, Docker provides lightweight per-service isolation and reproducibility.

#### Secrets vs Environment Variables

| | Docker Secrets | Environment Variables |
|---|---|---|
| Storage | Files mounted read-only in `/run/secrets/` | Part of the container environment |
| Exposure | Not shown by `docker inspect` nor in the process environment | Visible with `docker inspect`, `env`, logs, child processes |
| Best for | Passwords, keys, credentials | Non-sensitive configuration |

Here the database passwords live in `secrets/db_password.txt` and `secrets/db_root_password.txt`; the containers receive only the *path* of the file (`MYSQL_PASSWORD_FILE`, `WORDPRESS_DB_PASSWORD_FILE`), while `.env` holds non-sensitive values (domain, database name, user).

#### Docker Network vs Host Network

| | Docker Network (bridge) | Host Network |
|---|---|---|
| Isolation | Each container has its own network namespace | Container shares the host's network stack |
| Service discovery | Built-in DNS: containers reach each other by service name (`mariadb`, `wordpress`) | None, everything goes through the host |
| Exposure | Only explicitly published ports are reachable from outside | Every listening port is exposed on the host |
| Port conflicts | Avoided | Likely |

A custom bridge network (`inception-network`) is used, so only nginx's port 443 is exposed. `network: host` and `links` are forbidden by the subject.

#### Docker Volumes vs Bind Mounts

| | Docker Volumes | Bind Mounts |
|---|---|---|
| Management | Managed by Docker (`docker volume ...`) | Direct mapping of a host path |
| Portability | Independent of the host directory layout | Depends on the host filesystem |
| Typical use | Persistent application data | Development, sharing sources/configs with the host |

This project declares **named volumes** (`mariadb_data`, `wordpress_data`) whose storage location is set to `/home/<login>/data/mariadb` and `/home/<login>/data/wordpress` through the `local` driver options, as required by the subject: they are managed as Docker volumes but the data lives at a known path on the host.

## Instructions

### Prerequisites

- A Linux virtual machine with **Docker** (with the Compose plugin), **make** and **sudo**.
- The domain name pointing to the local machine. Add this line to `/etc/hosts`:
  ```
  127.0.0.1   yoherfan.42.fr
  ```

### Configuration

1. Clone the repository and enter it:
   ```bash
   git clone <repository-url> inception && cd inception
   ```
2. Create the secret files (one password per file, no trailing spaces):
   ```bash
   mkdir -p secrets
   echo "<db_user_password>" > secrets/db_password.txt
   echo "<db_root_password>" > secrets/db_root_password.txt
   ```
3. Create `srcs/.env` with the non-sensitive variables:
   ```
   DOMAIN_NAME=yoherfan.42.fr
   MYSQL_DATABASE=wordpress_db
   MYSQL_USER=wp_user
   ```

### Compilation and execution

| Command | Description |
|---|---|
| `make` / `make all` | Create the data directories, build the images and start the containers |
| `make build` | Create `/home/$USER/data/{mariadb,wordpress}` and build the images |
| `make up` | Start the containers in the background |
| `make down` | Stop and remove the containers |
| `make clean` | `down`, then `docker system prune -af` (removes unused images, networks and cache) |
| `make fclean` | `clean`, then remove Docker volumes and delete `/home/$USER/data` |
| `make re` | `fclean` followed by `all` |

### Usage

Once the containers are up (`docker ps` shows `nginx`, `wordpress` and `mariadb`):

- Website: `https://yoherfan.42.fr` (the self-signed certificate triggers a browser warning; accept it).
- On the first visit WordPress shows its installation page, where the site title and the administrator account are created. The admin dashboard is then available at `https://yoherfan.42.fr/wp-admin`.
- Useful checks:
  ```bash
  docker compose -f srcs/docker-compose.yml logs -f
  docker exec -it mariadb mysql -u root -p     # use the content of secrets/db_root_password.txt
  ```

## Resources

### References

- [Docker documentation](https://docs.docker.com/)
- [Dockerfile best practices](https://docs.docker.com/build/building/best-practices/)
- [Docker Compose documentation](https://docs.docker.com/compose/)
- [Docker secrets](https://docs.docker.com/engine/swarm/secrets/)
- [Docker volumes and bind mounts](https://docs.docker.com/engine/storage/)
- [Docker networking](https://docs.docker.com/engine/network/)
- [NGINX documentation](https://nginx.org/en/docs/)
- [MariaDB Knowledge Base](https://mariadb.com/kb/en/documentation/)
- [WordPress documentation](https://wordpress.org/documentation/)
- [PHP-FPM configuration](https://www.php.net/manual/en/install.fpm.configuration.php)
- Tutorial: "Docker NGINX + WordPress + MariaDB Tutorial - Inception42" by alejiri (dev.to)

### Use of AI

AI (Claude) was used as a support tool for:

- **Understanding concepts**: [e.g. PID 1 and foreground processes, Docker secrets, volumes vs bind mounts, FastCGI between nginx and PHP-FPM].
- **Debugging**: [e.g. updating `init_db.sh` and `setup_wordpress.sh` to read the passwords from Docker secrets; investigating why the `wordpress_db` database had no tables after startup].
- **Documentation**: drafting and structuring this README.

All AI-generated content was reviewed, tested and fully understood before being included in the project.
