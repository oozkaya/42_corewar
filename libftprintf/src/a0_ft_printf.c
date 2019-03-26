/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a0_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:53 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/26 14:59:44 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_printf() and ft_vprintf() functions write output to stdout
** cf. man printf(3)
*/

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, str);
	ret = ft_vprintf(str, ap);
	va_end(ap);
	return (ret);
}

/*
** ft_dprintf() and ft_vdprintf() write output to the given file descriptor
*/

int		ft_dprintf(int fd, const char *str, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, str);
	ret = ft_vdprintf(fd, str, ap);
	va_end(ap);
	return (ret);
}

/*
** ft_fprintf() and ft_vfprintf() write output to the given output stream
** Need to be uncommented to use ft_fprintf or ft_vfprintf
** fwrite() is a forbidden function
*/

/*
**int		ft_fprintf(FILE *file, const char *str, ...)
**{
**	va_list		ap;
**	int			ret;
**
**	va_start(ap, str);
**	ret = ft_vfprintf(file, str, ap);
**	va_end(ap);
**	return (ret);
**}
*/

/*
** ft_asprintf() and ft_vasprintf() dynamically allocate a new string.
*/

int		ft_asprintf(char **str, const char *fmt, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, fmt);
	ret = ft_vasprintf(str, fmt, ap);
	va_end(ap);
	return (ret);
}
