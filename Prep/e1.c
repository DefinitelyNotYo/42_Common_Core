/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:35:38 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/04 14:59:15 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_popen(const char *file, char *const argv[], char type)
{
    if (!file || !argv || (type != 'r' && type != 'w'))
        return (-1);
    int fd[2];
    pipe(fd);
    if (type == 'r')
    {
        if (fork() == 0)
        {
            dup2(fd[1], STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            execvp(file, argv);
            exit(-1);
        }
        close (fd[1]);
        return (fd[0]);
    }
    if (type == 'w')
    {
		if (fork() == 0)
		{
        	dup2(fd[0], STDIN_FILENO);
        	close(fd[0]);
        	close(fd[1]);
        	execvp(file, argv);
        	exit(-1);     			
		}
        close (fd[0]);
        return (fd[1]);   
    }
	return (-1);
}

int main()
{
    int fd;
    char *line;

    fd = ft_popen("echo", (char *const []){"echo", "ciao", NULL}, 'r');
    close(fd);
    return (0);
}
