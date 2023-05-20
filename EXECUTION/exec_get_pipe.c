/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_get_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 06:08:08 by zjaddad           #+#    #+#             */
/*   Updated: 2023/05/20 06:21:07 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../LIBFT/libft.h"

void	pipe_creation(t_pipes *pipes)
{
	if (pipe(pipes->p1_end) == -1)
		exit(print_error("Pipe Error"));
	if (pipe(pipes->p2_end) == -1)
		exit(print_error("Pipe Error"));
}