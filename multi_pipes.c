/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 04:14:59 by zjaddad           #+#    #+#             */
/*   Updated: 2023/05/20 04:40:40 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "LIBFT/libft.h"

typedef struct {
    int fd[2];
    int fd_inf;
    int fd_outf;
    pid_t pid;
} t_pp;

void execute_command(char **av, char **env, int in_fd, int out_fd) {
    dup2(in_fd, 0);
    dup2(out_fd, 1);
    
    char **cmd = ft_split(av[2], ' ');
    execve(cmd[0], cmd, env);
	printf("ZAKI. ");
    perror("Error");
    exit(1);
}

void execute_pipeline(char **av, char **env, int num_pipes) {
    t_pp pp[num_pipes];
    int i = 0;

    // Create pipes
    while (i < num_pipes) {
        if (pipe(pp[i].fd) == -1) {
            perror("Pipe Error");
            exit(1);
        }
        i++;
    }

    // Spawn child processes
    i = 0;
    while (i < num_pipes + 1) {
        pp[i].pid = fork();
        if (pp[i].pid == -1) {
            perror("Fork");
            exit(1);
        }
        
        if (pp[i].pid == 0) {
            // Child process
            if (i == 0) {
                // First command, set input from file
                close(pp[i].fd[0]);
                dup2(pp[i].fd_inf, 0);
            } else {
                // Intermediate commands, set input from previous pipe
                close(pp[i].fd[0]);
                dup2(pp[i - 1].fd[0], 0);
            }
            
            if (i == num_pipes) {
                // Last command, set output to file
                close(pp[i].fd[1]);
                dup2(pp[i].fd_outf, 1);
            } else {
                // Intermediate commands, set output to next pipe
                close(pp[i].fd[1]);
                dup2(pp[i].fd[0], 1);
            }
            
            execute_command(av, env, pp[i].fd[0], pp[i].fd[1]);
        } else {
            // Parent process
            if (i > 0) {
                // Close previous pipe in parent process
                close(pp[i - 1].fd[0]);
                close(pp[i - 1].fd[1]);
            }
        }

        i++;
    }

    // Close remaining pipes in parent process
    close(pp[num_pipes].fd[0]);
    close(pp[num_pipes].fd[1]);

    // Wait for child processes to finish
    i = 0;
    while (i < num_pipes + 1) {
        waitpid(pp[i].pid, NULL, 0);
        i++;
    }
}

int main(int ac, char **av, char **env) {
    if (ac >= 5) 
	{
        int num_pipes = ac - 4;
		//(void)env;
        t_pp pp;

        pp.fd_inf = open(av[1], O_RDWR);
        if (pp.fd_inf == -1) 
		{
            perror("ERROR");
            exit(1);
        }

        pp.fd_outf = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
        if (pp.fd_outf == -1) {
            perror("ERROR");
            exit(1);
        }
		execute_pipeline(av, env, num_pipes);
	}
}
