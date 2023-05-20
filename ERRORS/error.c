/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 06:17:37 by zjaddad           #+#    #+#             */
/*   Updated: 2023/05/20 06:19:17 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../LIBFT/libft.h"

int	print_error(char *s)
{
	ft_putstr_fd("minishell: ", 2);
	perror(s);
	exit(EXIT_FAILURE);
}