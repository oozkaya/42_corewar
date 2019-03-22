/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:26:31 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 13:22:15 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

static int		ft_isvalid(char c, int base)
{
	char		*digits;
	char		*digits2;

	digits = "0123456789abcdef";
	digits2 = "0123456789ABCDEF";
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

static int		ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

intmax_t		ft_atoi_base(const char *str, int str_base)
{
	intmax_t	result;
	int			sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	sign = (str[0] == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_isvalid(*str, str_base))
		result = result * str_base + ft_value_of(*str++);
	return (result * sign);
}

uintmax_t		ft_uatoi_base(const char *str, int str_base)
{
	uintmax_t	result;
	int			sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	sign = (str[0] == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_isvalid(*str, str_base))
		result = result * str_base + ft_value_of(*str++);
	return (result * sign);
}
