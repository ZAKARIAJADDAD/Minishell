/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:23:00 by zjaddad           #+#    #+#             */
/*   Updated: 2023/05/20 06:27:26 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "../minishell.h"

void	execution(t_data_cmd *cmds)
{
	t_exc	exc;

	pipes_creation(&exc.pipe);
	exc.i = -1;
	while (++exc.i < glob.nb_cmds)
	{
		
	}
}