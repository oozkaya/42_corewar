/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c2_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:06:41 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/02 14:13:13 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_putinstr_buffer
** Used with the ft_fprintf() and ft_vfprintf() functions.
** Puts the buffer in a new string dynamically allocate with malloc(3).
*/

char	*ft_putinstr_buffer(t_buff **buff)
{
	char	*str;

	if (!(str = ft_strnew((*buff)->valid_pos)))
	{
		(*buff)->err = -1;
		return (NULL);
	}
	return (ft_strncpy(str, (*buff)->str, (*buff)->valid_pos));
}

/*
** ft_valid_buffer
** Validates the characters to print, even if printf returns -1.
*/

void	ft_valid_buffer(t_buff **buff)
{
	if ((*buff)->err != -1)
		(*buff)->valid_pos = (*buff)->index;
}

/*
** ft_double_buffsize
** Multiplies by 2 the size of the buffer.
*/

void	ft_double_buffsize(t_buff **buff)
{
	char	tmp[(*buff)->size_max];

	ft_strcpy(tmp, (*buff)->str);
	ft_strdel(&(*buff)->str);
	(*buff)->size_max *= 2;
	if (!((*buff)->str = ft_strnew((*buff)->size_max)))
	{
		ft_error_manager(buff);
		return ;
	}
	ft_strcpy((*buff)->str, tmp);
}

/*
** ft_putcbuffer
** Puts a char in the buffer
*/

void	ft_putcbuffer(t_buff **buff, char c)
{
	(*buff)->str[(*buff)->index] = c;
	(*buff)->index++;
	(*buff)->str[(*buff)->index] = '\0';
	(*buff)->printed++;
	if ((*buff)->index == (*buff)->size_max)
		ft_double_buffsize(buff);
}

/*
** ft_putsbuffer
** Puts a string in the buffer char by char.
*/

void	ft_putsbuffer(t_buff **buff, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putcbuffer(buff, str[i]);
		i++;
	}
}
