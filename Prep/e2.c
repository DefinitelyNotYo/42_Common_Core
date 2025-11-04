/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:42:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/04 17:29:18 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int picoshell(char **cmds[])
{
    pid_t   pid;
    int     pipefd[2];
    int     prev_fd;
    int     i;

    prev_fd = -1;
    i = 0;
    while(cmds[i])
    {
		if (pipe(pipefd) == -1)
			exit(1);
        pid = fork();
        if (pid == 0)
        {
            if (prev_fd != -1)
            {
                if(dup2(prev_fd, STDIN_FILENO) == -1)
                    exit(1);
                close(prev_fd);
            }
            if (cmds[i + 1])
            {
                close(pipefd[0]);
                if(dup2(pipefd[1], STDOUT_FILENO) == -1)
                    exit(1);
                close(pipefd[1]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }
        if (prev_fd != -1)
            close(prev_fd);
        if(cmds[i + 1])
        {
            close(pipefd[1]);
            prev_fd = pipefd[0];
        }
        i++;
    }
	while (wait(&i) > 0)
		;
    close(pipefd[0]);
    close(pipefd[1]);
    return (0);
}

int main()
{
    char ***prova = calloc(sizeof(char **), 4);
    
    prova[0] = calloc(sizeof(char *), 3);
    prova[0][0] = "ls";
    // prova[0][1] = "";
    
    prova[1] = calloc(sizeof(char *), 3);
    prova[1][0] = "grep";
    prova[1][1] = "e";

    prova[2] = calloc(sizeof(char *), 3);
    prova[2][0] = "grep";
    prova[2][1] = "2";
    
    int i = -1;
    while(prova[++i]);
    printf("numero di comandi: %d\n", i);
    picoshell(prova);
    free (prova[0]);
    free(prova[1]);
    free(prova[2]);
    free(prova);
}