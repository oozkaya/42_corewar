/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:37:13 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/27 15:10:50 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int				i;
	unsigned long	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == ' '
				|| str[i] == '\v' || str[i] == '\r') && str[i] != '\0')
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if (nb > 9223372036854775807)
		return (sign < 0 ? 0 : -1);
	return (sign < 0 ? -nb : nb);
}

intmax_t	ft_atointmax(const char *str)
{
	int				i;
	uintmax_t		nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == ' '
				|| str[i] == '\v' || str[i] == '\r') && str[i] != '\0')
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (sign < 0 ? -nb : nb);
}
