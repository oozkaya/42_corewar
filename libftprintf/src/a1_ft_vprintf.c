/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a1_ft_vprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:53 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/02 14:21:43 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_printf() and ft_vprintf() functions write output to stdout
** cf. man printf(3)
*/

int		ft_vprintf(const char *str, va_list ap)
{
	int			ret;
	int			fd;
	t_buff		*buff;

	fd = 1;
	if ((ft_init_buffer(&buff, fd) == -1))
		return (-1);
	ft_parse_str(ap, (char*)str, &buff);
	write(fd, buff->str, buff->valid_pos);
	ret = buff->err != -1 ? buff->index : -1;
	ft_free_buff(&buff);
	return (ret);
}

/*
** ft_dprintf() and ft_vdprintf() write output to the given file descriptor
*/

int		ft_vdprintf(int fd, const char *str, va_list ap)
{
	int			ret;
	t_buff		*buff;

	if ((ft_init_buffer(&buff, fd) == -1))
		return (-1);
	ft_parse_str(ap, (char*)str, &buff);
	write(fd, buff->str, buff->valid_pos);
	ret = buff->err != -1 ? buff->index : -1;
	ft_free_buff(&buff);
	return (ret);
}

/*
** ft_fprintf() and ft_vfprintf() write output to the given output stream
** Need to be uncommented to use ft_fprintf or ft_vfprintf
** fwrite() is a forbidden function
*/

/*
**int		ft_vfprintf(FILE *file, const char *str, va_list ap)
**{
**	int			ret;
**	t_buff		*buff;
**
**	if ((ft_init_buffer(&buff, 1) == -1))
**		return (-1);
**	ft_parse_str(ap, (char*)str, &buff);
**	fwrite(buff->str, 1, buff->valid_pos, file);
**	ret = buff->err != -1 ? buff->index : -1;
**	ft_free_buff(&buff);
**	return (ret);
**}
*/

/*
** ft_asprintf() and ft_vasprintf() dynamically allocate a new string.
*/

int		ft_vasprintf(char **str, const char *fmt, va_list ap)
{
	int			ret;
	int			fd;
	t_buff		*buff;

	fd = PRINT_IN_STRING;
	if ((ft_init_buffer(&buff, fd) == -1))
		return (-1);
	ft_parse_str(ap, (char*)fmt, &buff);
	*str = ft_putinstr_buffer(&buff);
	ret = buff->err != -1 ? buff->index : -1;
	ft_free_buff(&buff);
	return (ret);
}
