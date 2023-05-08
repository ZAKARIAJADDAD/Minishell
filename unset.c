/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:06:13 by zjaddad           #+#    #+#             */
/*   Updated: 2023/05/08 16:29:20 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
#include "../libft/libft.h"


int	foreign_letter(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if ((cmd[i] >= '!' && cmd[i] <= '/')
			|| (cmd[i] >= '[' && cmd[i] <= '^')
			|| (cmd[i] == '`')
			|| (cmd[i] >= '}' && cmd[i] <= '~')
			|| (cmd[0] >= '0' && cmd[0] <= '9'))
		{
			printf("%s: not a valid\n", cmd);
			return (0);
		}
		i++;
	}
	return (1);
}

void	unset(char **cmd, t_env *evr)
{
	int	i = 1;
	t_env	*tmp;

	tmp = evr;	
	// PS: check if program get env_value(mean those are after '=' in env)
	//it must display nothing. Become functional just if get it env_key
	if (cmd[0] && (!cmd[1] || !(foreign_letter(cmd[1]))))
		return ;
	while (cmd[i])
	{
		while (tmp)
		{
			if (!ft_strcmp(cmd[i], tmp->key))
				printf("%s\n", tmp->value);
			tmp = tmp->next;	
		}
		tmp = evr;
		i++;
	}
}