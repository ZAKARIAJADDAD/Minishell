/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:46:40 by zjaddad           #+#    #+#             */
/*   Updated: 2023/05/15 05:39:12 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "../libft/libft.h"

void	get_export(t_env *exp, int fd)
{
	t_env	*tmp;

	tmp = exp;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(tmp->key, fd);
		if (tmp->value)
		{
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(tmp->value, fd);
			ft_putstr_fd("\"", fd);
		}
		ft_putstr_fd("\n", fd);
		tmp = tmp->next;
	}
}

t_env	*key_value(char *s)
{
	t_env	*new_node;
	char	*eq;

	eq = ft_strchr(s, '=');
	if (eq)
		*eq = '\0';
	new_node = malloc(sizeof(t_env) + 1);
	new_node->key = ft_strdup(s);
	if (eq)
		new_node->value = ft_strdup(eq + 1);
	else
		new_node->value = NULL;
	return (new_node);
}

int	update_value(char *key, char *value, t_env *evr)
{
	t_env	*tmp;

	tmp = evr;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			if (!value)
				return (1);
			else
				tmp->value = value;
			return (2);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_export(char **cmd, int outf)
{
	int		len;
	int		i;
	t_env	*exprt;
	t_env	*tmp;

	exprt = glob.envr;
	len = args_len(cmd);
	tmp = malloc(sizeof(t_env) * len + 1);
	i = 0;
	if (len != 1)
	{
		while (++i < len)
		{
			tmp = key_value(cmd[i]);
			if (!foreign_letter(tmp->key))
				return ;
			else if (update_value(tmp->key, tmp->value, exprt) == 0)
				ft_lstadd_back((t_list **)&exprt, ft_lstnew(tmp));
		}
	}
	else
		get_export(exprt, outf);
}