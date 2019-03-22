/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e0_size_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:30:54 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/26 14:31:56 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_get_string_di
** Gets the next integer variadic argument
** and puts it in a char* with ft_itoa_base
*/

void	ft_get_string_di(t_indic **ind, va_list ap, char **str, int base)
{
	if (ft_strcmp((*ind)->size, "hh") == 0)
		(*ind)->nb = (signed char)va_arg(ap, int);
	else if (ft_strcmp((*ind)->size, "h") == 0)
		(*ind)->nb = (short int)va_arg(ap, int);
	else if (ft_strcmp((*ind)->size, "l") == 0)
		(*ind)->nb = va_arg(ap, long int);
	else if (ft_strcmp((*ind)->size, "ll") == 0)
		(*ind)->nb = va_arg(ap, long long int);
	else if (ft_strcmp((*ind)->size, "j") == 0)
		(*ind)->nb = va_arg(ap, intmax_t);
	else if (ft_strcmp((*ind)->size, "t") == 0)
		(*ind)->nb = va_arg(ap, ptrdiff_t);
	else if (ft_strcmp((*ind)->size, "z") == 0)
		(*ind)->nb = va_arg(ap, size_t);
	else
		(*ind)->nb = va_arg(ap, int);
	*str = ft_itoa_base((*ind)->nb, base);
}

/*
** ft_get_string_bouxX
** Gets the next unsigned integer variadic argument
** and puts it in a char* with ft_uitoa_base
*/

void	ft_get_string_bouxx(t_indic **ind, va_list ap, char **str, int base)
{
	if ((*ind)->type == 'b')
		base = 2;
	else if ((*ind)->type == 'o' || (*ind)->type == 'O')
		base = 8;
	else if ((*ind)->type == 'x' || (*ind)->type == 'X')
		base = 16;
	if (ft_strcmp((*ind)->size, "hh") == 0)
		(*ind)->nb = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_strcmp((*ind)->size, "h") == 0)
		(*ind)->nb = (unsigned short int)va_arg(ap, unsigned int);
	else if (ft_strcmp((*ind)->size, "l") == 0)
		(*ind)->nb = va_arg(ap, unsigned long int);
	else if (ft_strcmp((*ind)->size, "ll") == 0)
		(*ind)->nb = va_arg(ap, unsigned long long int);
	else if (ft_strcmp((*ind)->size, "j") == 0)
		(*ind)->nb = va_arg(ap, uintmax_t);
	else if (ft_strcmp((*ind)->size, "z") == 0)
		(*ind)->nb = va_arg(ap, size_t);
	else if (ft_strcmp((*ind)->size, "t") == 0)
		(*ind)->nb = va_arg(ap, ptrdiff_t);
	else
		(*ind)->nb = va_arg(ap, unsigned int);
	*str = ft_uitoa_base((*ind)->nb, base);
}

/*
** ft_get_string_p
** Gets the next variadic argument as void* and puts it in a char*.
*/

void	ft_get_string_p(t_indic **ind, va_list ap, char **str, int base)
{
	base = 16;
	(*ind)->nb = (unsigned long int)va_arg(ap, void*);
	*str = ft_uitoa_base((*ind)->nb, base);
}

/*
** ft_get_chars_cs
** Gets the next char, char* or wchar_t* variadic argument.
*/

void	ft_get_chars_cs(t_indic **ind, va_list ap, char **str)
{
	char	*tmp;

	if ((*ind)->type == 'c')
	{
		if (ft_strcmp((*ind)->size, "l") == 0)
			(*ind)->c = va_arg(ap, wchar_t);
		else
			(*ind)->c = (char)va_arg(ap, int);
	}
	else if ((*ind)->type == 's')
	{
		if (ft_strcmp((*ind)->size, "l") == 0)
		{
			if (!((*ind)->ws = va_arg(ap, wchar_t*)))
				(*ind)->ws = L"(null)";
		}
		else
		{
			if (!(tmp = va_arg(ap, char*)))
				*str = (*ind)->isprec && !(*ind)->precision
				? ft_strdup("") : ft_strdup("(null)");
			else
				*str = ft_strdup(tmp);
		}
	}
}

/*
** ft_get_string
** Redirects to the right function considering the type.
*/

void	ft_get_string(t_indic **ind, va_list ap, char **str)
{
	int			i;
	const t_ft	length[] = {{"3di", 0, 0, ft_get_string_di, 0},
		{"3bouxX", 0, 0, ft_get_string_bouxx, 0},
		{"3p", 0, 0, ft_get_string_p, 0},
		{"4cs", 0, 0, 0, ft_get_chars_cs},
		{0, 0, 0, 0, 0}
	};

	i = 0;
	while (length[i].letter)
	{
		if ((*ind)->type && ft_strchr(length[i].letter, (*ind)->type))
		{
			if (length[i].letter[0] == '3')
				length[i].f3(ind, ap, str, 10);
			else if (length[i].letter[0] == '4')
				length[i].f4(ind, ap, str);
			return ;
		}
		i++;
	}
	*str = NULL;
}
