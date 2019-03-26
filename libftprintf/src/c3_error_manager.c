/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_error_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:18:01 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/02 12:24:14 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_error_manager
** In case of error, the function ft_printf will return -1.
*/

void	ft_error_manager(t_buff **buff)
{
	(*buff)->err = -1;
}
