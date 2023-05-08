#include "builtins.h"
#include "../libft/libft.h"
#include "minishell.h"

void	check_builtin(char **cmd, int fd, t_env	*envr)
{
	int	i = 1;

	if (!ft_strcmp(cmd[0], "echo"))
		echo(cmd, fd);
	else if (!ft_strcmp(cmd[0], "pwd"))
		pwd(cmd, fd);
	else if (!ft_strcmp(cmd[0], "unset"))
		unset(cmd, envr);
	else
		printf("NO BUILTINS\n");
	// else if (!ft_strcmp(cmd[i], "cd"))
	// 	cd(cmd[i]);
	// else if (!ft_strcmp(cmd[i], "export"))
	// 	export();
	// else if (!ft_strcmp(cmd[i], "exit"))
	// 	ft_exit();
	// else if (!ft_strcmp(cmd[i], "env"))
	// 	env();
	// else
	// 	execute();
}

int main(int ac, char **av, char **env) {
	t_env	*envr;
    int i = 0;
	int	fd = 1;
	char *input;
	char	**cmd_prt;

	get_env(&envr, env);
	while (1)
	{
		input = readline("\033[0;32mExecution =>> ");
		if (!input || input[0] == '\0')
			continue ;
		epur_str(input);
		cmd_prt =  ft_split(input, ' ');
		check_builtin(cmd_prt, fd, envr);
	}
    return 0;
}