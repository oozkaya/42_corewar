/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c0_struct_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:58:03 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/02 12:13:40 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_init_indic
** Initializes the indicators' structure
*/

int		ft_init_indic(t_indic **ind)
{
	*ind = NULL;
	if (!((*ind) = (t_indic*)malloc(sizeof(t_indic))))
		return (-1);
	ft_bzero((*ind)->flags, 5 + 1);
	ft_bzero((*ind)->size, 2 + 1);
	(*ind)->width = 0;
	(*ind)->isprec = 0;
	(*ind)->precision = 0;
	return (1);
}

/*
** ft_free_indic
** Frees the indicators' structure
*/

void	ft_free_indic(t_indic **ind)
{
	if (*ind)
		ft_memdel((void**)ind);
}

/*
** ft_init_buffer
** Initializes the buffer's structure
*/

int		ft_init_buffer(t_buff **buff, int fd)
{
	*buff = NULL;
	if (!((*buff) = (t_buff*)malloc(sizeof(t_buff))))
		return (-1);
	(*buff)->size_max = 4096;
	if (!((*buff)->str = ft_strnew((*buff)->size_max)))
		return (-1);
	ft_bzero((*buff)->prefix, 3);
	(*buff)->suffix = NULL;
	(*buff)->sign_printed = 0;
	(*buff)->iszero = 0;
	(*buff)->printed = 0;
	(*buff)->index = 0;
	(*buff)->fd = fd;
	(*buff)->err = 0;
	(*buff)->valid_pos = 0;
	return (1);
}

/*
** ft_free_buff
** Frees the buffer's structure
*/

void	ft_free_buff(t_buff **buff)
{
	if (((*buff)->str))
		ft_strdel(&(*buff)->str);
	ft_strclr((*buff)->prefix);
	if (((*buff)->suffix))
		ft_strdel(&(*buff)->suffix);
	if (*buff)
		ft_memdel((void**)buff);
}

/*
** ft_reset_struct
** At the end of the conversion, frees and resets some element's structures but
** not everything. For example, the counter of the printed elements must be kept
*/

void	ft_reset_struct(t_indic **ind, t_buff **buff)
{
	ft_free_indic(ind);
	ft_strclr((*buff)->prefix);
	if (((*buff)->suffix))
		ft_strdel(&(*buff)->suffix);
	(*buff)->sign_printed = 0;
	(*buff)->iszero = 0;
	(*buff)->printed = 0;
}
