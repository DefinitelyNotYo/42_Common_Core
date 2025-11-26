/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:42:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/26 15:24:26 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int picoshell(char **cmds[])
{
    if(!cmds)
        return (1);
    int prev_fd = -1;
    int fd[2];
    int i = 0;
    while (cmds[i])
    {
        if(pipe(fd) == -1)
            return (1);
        if (fork() == 0)
        {
            if (prev_fd != -1)
            {
                if(dup2(prev_fd, STDIN_FILENO) == -1)
                    exit(1);
                close(prev_fd);
            }
            if (cmds[i + 1])
            {
                close(fd[0]);
                if(dup2(fd[1], STDOUT_FILENO) == -1)
                    exit(1);
                close(fd[1]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }
        if (prev_fd != -1)
            close(prev_fd);
        if (cmds[i + 1])
        {
            close(fd[1]);
            prev_fd = fd[0];
        }
        i++;
    }
    while (wait(&i) > 0)
        ;
    close(fd[0]);
    close(fd[1]);
    return (0);
}









































// int picoshell(char **cmds[])
// {
//     if (!cmds)
//         return (1);
//     int prev_fd = -1;
//     int i = 0;
//     int     fd[2];
//     while(cmds[i])
//     {
// 		if (pipe(fd) == -1)
// 			exit(1);
//         if (fork() == 0)
//         {
//             if (prev_fd != -1)
//             {
//                 if(dup2(prev_fd, STDIN_FILENO) == -1)
//                     exit(1);
//                 close(prev_fd);
//             }
//             if (cmds[i + 1])
//             {
//                 close(fd[0]);
//                 if(dup2(fd[1], STDOUT_FILENO) == -1)
//                     exit(1);
//                 close(fd[1]);
//             }
//             execvp(cmds[i][0], cmds[i]);
//             exit(1);
//         }
//         if (prev_fd != -1)
//             close(prev_fd);
//         if(cmds[i + 1])
//         {
//             close(fd[1]);
//             prev_fd = fd[0];
//         }
//         i++;
//     }
// 	while (wait(&i) > 0)
// 		;
//     close(fd[0]);
//     close(fd[1]);
//     return (0);
// }

int main()
{
    // char    ***prova = NULL;
    char ***prova = calloc(sizeof(char **), 4);
    
    prova[0] = calloc(sizeof(char *), 3);
    prova[0][0] = "echo";
    prova[0][1] = "squalala";
    
    prova[1] = calloc(sizeof(char *), 3);
    prova[1][0] = "cat";
    // prova[1][1] = "e";

    prova[2] = calloc(sizeof(char *), 3);
    prova[2][0] = "sed";
    prova[2][1] = "s/a/b/g";
    
    int i = -1;
    while(prova[++i]);
    printf("numero di comandi: %d\n", i);
    picoshell(prova);
    free (prova[0]);
    free(prova[1]);
    free(prova[2]);
    free(prova);
}