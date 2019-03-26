/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c1_get_chars_to_convert.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:42:04 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/26 14:54:05 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_get_flags
** Gets flags '#', '0', '+', '-', ' '. Multiple flags is allowed.
*/

void	ft_get_flags(t_indic **ind, char *str)
{
	int		i;
	int		k;
	int		offset;

	i = (*ind)->start;
	k = 0;
	while ((*ind)->flags[k])
		k++;
	while (i < (*ind)->end)
	{
		offset = 0;
		if (str[i - 1] == '.')
			offset++;
		else if (str[i] >= '1' && str[i] <= '9')
		{
			while (ft_isdigit(str[i + offset]))
				offset++;
		}
		else if (ft_strchr("#0+- ", str[i])
			&& !ft_strchr((*ind)->flags, str[i]))
			(*ind)->flags[k++] = str[(i)];
		i += offset == 0 ? 1 : offset;
	}
}

/*
** ft_get_width
** Gets the width specifier as integer.
** If the width is negative, the flag '-' is activated & witdh becames positive.
*/

void	ft_get_width(t_indic **ind, va_list ap, char *str, int i)
{
	int		k;

	k = 0;
	while (i < (*ind)->end && ft_strchr("#0+- ", str[i]))
		i++;
	while (ft_isdigit(str[i]) == 1 || str[i] == '*')
	{
		if (ft_isdigit(str[i]) == 1)
		{
			(*ind)->width = ft_atoi(str + i);
			while (str[i] && ft_isdigit(str[i]) == 1)
				i++;
		}
		if (str[i] == '*')
		{
			if (((*ind)->width = va_arg(ap, int)) < 0)
			{
				(*ind)->width = ft_abs((*ind)->width);
				while ((*ind)->flags[k])
					k++;
				(*ind)->flags[k] = '-';
			}
			i++;
		}
	}
}

/*
** ft_get_precision
** Gets the precision specifier as integer.
** If the prec. is negative, the prec. flag is desactivated.
*/

void	ft_get_precision(t_indic **ind, va_list ap, char *str, int i)
{
	while (i < (*ind)->end && str[i] != '.')
		i++;
	if (str[i] && str[i] == '.')
	{
		i++;
		(*ind)->isprec = 1;
		(*ind)->precision = ft_atoi(str + i);
		if (str[i] && str[i] == '*')
		{
			(*ind)->precision = va_arg(ap, int);
			i++;
		}
	}
	while (ft_isdigit(str[i]) == 1 || str[i] == '*')
	{
		if (str[i] == '*')
			va_arg(ap, int);
		i++;
	}
	if ((*ind)->precision < 0)
	{
		(*ind)->isprec = 0;
		(*ind)->precision = 0;
	}
}

/*
** ft_get_size
** Gets the size specifier 'h', "hh", 'l', "ll", 'z', 't' or 'L'.
*/

void	ft_get_size(t_indic **ind, char *str)
{
	int		i;
	int		j;
	int		k;

	i = (*ind)->start;
	j = 0;
	k = 0;
	while (i < (*ind)->end && !ft_strchr("hljztL", str[i]))
		i++;
	if (str[i] && ft_strchr("hljztL", str[i]))
	{
		j++;
		if ((str[i] == 'h' || str[i] == 'l') && (str[i] == str[i + 1]))
			j++;
	}
	while ((*ind)->size[k])
		k++;
	while (j--)
	{
		(*ind)->size[k++] = str[i];
		i++;
	}
}

/*
** ft_get_size
** Gets the type specifier.
*/

void	ft_get_type(t_indic **ind, char *str)
{
	int		i;

	i = (*ind)->end;
	while (str[i] && ft_strchr("#0+- *.0123456789hljztL", str[i]))
		i++;
	(*ind)->type = str[i];
	(*ind)->end = i;
}
