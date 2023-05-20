/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:55:09 by zjaddad           #+#    #+#             */
/*   Updated: 2023/05/20 06:34:48 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <ctype.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdbool.h>


# define STDRIN		0
# define STDROUT	1
# define STDRERR	2
# define PIPE_END	-42

# define ECHO		0
# define CD			1
# define PWD		2
# define EXPORT		3
# define UNSET		4
# define ENV		5
# define EXIT		6
# define NONE_BLT	7

typedef struct cmd {
    char* value;
    struct cmd* next;
} t_cmd;

typedef struct s_str
{
	char		*str; //string entred by the user
	int			printed_error;// to know if i have printed an error or not
	char		**splited_str;// the string splited by pipes

}	t_str;

typedef struct s_env
{
	char			*key;// the key of the envirment variable
	char			*value;// the value of the envirment variable
	//struct s_env	*prev;  // Add a pointer to the previous node
	struct s_env	*next;
}	t_env;

typedef struct  s_gob
{
	int 	ex_status;
	int 	nb_cmds;
	t_env	*env_p;
	t_env	*exprt;
	// number of command;
} t_gob;

typedef struct s_pipes
{
	int	p1_end[2];
	int	p2_end[2];
}		t_pipes;

typedef struct s_exc
{
	t_pipes	pipe;
	int		builtin;
	int		child_pro;
	int		i;
}				t_exc;

typedef struct t_args
{
	char			*args;
	struct t_args	*next;
}	t_args;

typedef struct s_data_cmd
{
	t_args				*args;// the cmd that we will execute 
	int					fd_in;// the fd of the input 0
	int					fd_out;// the fd of the output 1
	struct s_data_cmd	*next;// if there is a pipe we will have a next cmd otherwise it will be NULL if there is no pipe
}	t_data_cmd;

/* ************************************************************************** */
/*		  							 Builtins Part							  */
/* ************************************************************************** */
void 	unset(t_args *cmd);
void	env(int outf);
void 	ft_exit(t_args *cmd);
void 	echo(t_args *input, int outf);
void 	cd(t_args *cmd);
void	ft_export(t_args *cmd, int outf);
void	pwd(t_args *input, int fd);
int		args_len(char **s);
int		foreign_letter(char *cmd);
void	get_env(char **envp);

/* ************************************************************************** */
/*		  							 	FT_List								  */
/* ************************************************************************** */

t_env	*ft_lstnew_s(char *key, char *value);
void	ft_lstadd_back_s(t_env **head, t_env *new);
t_args  *ft_lstnew_arg(void *content);
t_args  *ft_lstlast_arg(t_args *lst);
void 	ft_lstadd_back_arg(t_args **lst, t_args *new);
int 	ft_lstsizes(t_args *lst);

/* ************************************************************************** */
/*		  							 	free								  */
/* ************************************************************************** */
void	ft_free(t_env *evr);

/* ************************************************************************** */
/*		  					 		Temporary								  */
/* ************************************************************************** */

char	**ft_split_t(char const *s, char sep);
char	*epur_str(char* s);

/* ************************************************************************** */
/*		  							Signals 								  */
/* ************************************************************************** */

void	ctrl_d_handler(void);

/* ************************************************************************** */
/*		  	         	           	Errors   								  */
/* ************************************************************************** */

int	print_error(char *s);

/* ************************************************************************** */
/*		  							Execution								  */
/* ************************************************************************** */

void	execution(t_data_cmd *cmds);

/* ************************************************************************** */
/*		  						 Global Variabale							  */
/* ************************************************************************** */

t_gob glob;

/* ************************************************************************** */
/*		  						  Global Variable  							  */
/* ************************************************************************** */
#endif
