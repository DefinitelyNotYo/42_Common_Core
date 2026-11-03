*This project has been created as part of the 42 curriculum by [login1][, [login2]].*

# Inception

## Description

**Goal.** Inception is a system administration project whose aim is to build a small, secure web infrastructure using **Docker** and **Docker Compose**, inside a virtual machine. Every service runs in its own container, built from a custom Dockerfile (no pre-built images except the base OS: Debian Bookworm).

**Overview.** The stack is made of three services:

| Service | Role |
|---|---|
| **NGINX** | Only entry point of the infrastructure, listens on port 443 with TLSv1.2/1.3 |
| **WordPress + PHP-FPM** | Serves the website (no web server inside, it talks to NGINX via FastCGI on port 9000) |
| **MariaDB** | Database backing WordPress |

Two persistent volumes store the WordPress files and the database, and all containers communicate through a dedicated Docker network.

### Use of Docker and included sources

Docker packages each service with its dependencies in an isolated, reproducible container. The sources included in the repository are:

- `Makefile`: builds and manages the whole stack (`all`, `build`, `up`, `down`, `clean`, `fclean`, `re`).
- `srcs/docker-compose.yml`: defines services, network, volumes and secrets.
- `srcs/requirements/mariadb/`: Dockerfile, configuration and setup script for MariaDB.
- `srcs/requirements/wordpress/`: Dockerfile (debian:bookworm, php8.2-fpm), `tools/setup_wordpress.sh` for the automatic WordPress installation.
- `srcs/requirements/nginx/`: Dockerfile and NGINX configuration with TLS.
- `secrets/`: password files (not committed to the repository).
- `srcs/.env`: non-sensitive environment variables (domain name, DB name, usernames).

### Main design choices

- **One process per container**, with the main process running in the foreground as PID 1 (no `tail -f`, `sleep infinity` or infinite-loop hacks).
- **Custom images** built from `debian:bookworm`, with `restart: always` policy.
- **Only port 443 exposed** to the host; MariaDB and PHP-FPM are reachable only inside the Docker network.
- **Idempotent setup scripts**: WordPress and the database are initialized only on first run, so data persists across restarts.
- **Passwords as Docker secrets**, other configuration through the `.env` file.

### Comparisons

**Virtual Machines vs Docker**

| | Virtual Machine | Docker |
|---|---|---|
| Isolation | Full OS with its own kernel, strong isolation | Processes isolated via namespaces/cgroups, kernel shared with the host |
| Weight | GBs of disk, slow boot | MBs, starts in seconds |
| Resources | High overhead (hypervisor + guest OS) | Very low overhead |
| Portability | Heavy disk images | Lightweight, reproducible images from a Dockerfile |
| Use case | Running different OSes, strong security boundaries | Packaging and deploying applications and microservices |

In this project Docker is used inside a VM: the VM provides the host environment, Docker provides lightweight per-service isolation.

**Secrets vs Environment Variables**

| | Docker Secrets | Environment Variables |
|---|---|---|
| Storage | Files mounted in `/run/secrets/` (in-memory) | Stored in the container environment |
| Visibility | Not shown in `docker inspect` or process env | Visible via `docker inspect`, `env`, logs |
| Best for | Passwords, keys, credentials | Non-sensitive configuration (domain, DB name, user) |

Here passwords live in `secrets/*.txt` and are read by the setup scripts, while the `.env` file holds only non-sensitive values.

**Docker Network vs Host Network**

| | Docker Network (bridge) | Host Network |
|---|---|---|
| Isolation | Containers get their own network namespace | Container shares the host's network stack |
| Communication | Containers reach each other by service name via built-in DNS | No isolation, services bind directly to host ports |
| Security | Only explicitly published ports are exposed | Every listening port is exposed on the host |
| Port conflicts | Avoided | Likely |

A custom bridge network is used (host network and `links` are forbidden by the subject), so only NGINX is reachable from outside.

**Docker Volumes vs Bind Mounts**

| | Docker Volumes | Bind Mounts |
|---|---|---|
| Management | Managed by Docker (`docker volume ...`) | Direct mapping of a host path |
| Portability | Independent from host directory structure | Depends on the host filesystem layout |
| Permissions | Handled by Docker | Subject to host UID/GID |
| Use case | Persistent application data | Development, sharing source code or configs |

Named volumes are used for the database and WordPress files; their data is stored on the host under `/home/[login]/data/` as required by the subject.

## Instructions

### Prerequisites

- A Linux virtual machine with Docker and Docker Compose installed
- `make`
- The domain `[login].42.fr` pointing to the local IP, add it to `/etc/hosts`:
  ```
  127.0.0.1   [login].42.fr
  ```

### Setup

1. Clone the repository:
   ```bash
   git clone [repository-url] inception && cd inception
   ```
2. Create the secret files in `secrets/` (e.g. `db_password.txt`, `db_root_password.txt`, `wp_admin_password.txt`, `wp_user_password.txt`).
3. Create `srcs/.env` with the non-sensitive variables (see `srcs/.env.example`).

### Execution

| Command | Description |
|---|---|
| `make` / `make all` | Build the images and start the stack |
| `make build` | Build the images |
| `make up` | Start the containers |
| `make down` | Stop the containers |
| `make clean` | Stop the containers and remove images/networks |
| `make fclean` | `clean` + remove volumes and persistent data |
| `make re` | `fclean` followed by `all` |

Then open `https://[login].42.fr` in your browser (the self-signed certificate will trigger a warning) and the admin panel at `https://[login].42.fr/wp-admin`.

## Resources

### References

- [Docker documentation](https://docs.docker.com/)
- [Dockerfile best practices](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)
- [Docker Compose documentation](https://docs.docker.com/compose/)
- [Docker secrets](https://docs.docker.com/engine/swarm/secrets/)
- [NGINX documentation](https://nginx.org/en/docs/)
- [MariaDB documentation](https://mariadb.com/kb/en/documentation/)
- [WordPress documentation](https://wordpress.org/documentation/) and [WP-CLI](https://wp-cli.org/)
- [PHP-FPM configuration](https://www.php.net/manual/en/install.fpm.configuration.php)
- Tutorial: "Docker NGINX + WordPress + MariaDB Tutorial - Inception42" by alejiri (dev.to)

### Use of AI

AI (Claude) was used for:

- [e.g. understanding concepts: PID 1, Docker secrets, volumes vs bind mounts]
- [e.g. debugging the setup scripts for MariaDB and WordPress, including reading secrets and the empty database issue]
- [e.g. drafting and structuring this README]

All AI-generated content was reviewed, tested and fully understood before being included in the project.
