/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:59:40 by zjaddad           #+#    #+#             */
/*   Updated: 2023/05/07 04:25:22 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../libft/libft.h"

void	print_error(char *cmd)
{
	if (!ft_strcmp(cmd, "pwd"))
		printf("command not found\n");
}

void	pwd(char **input, int fd)
{
	char	*s;

	if (input[0])
		if (input[0][0] == '-' && input[0][1])
			return (print_error(input[0]));
	ft_putstr_fd(getcwd(NULL, 0), fd);
	ft_putstr_fd("\n", fd);
}