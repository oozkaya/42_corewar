/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e1_indicators_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:58:47 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/26 14:35:37 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_precision_manager
** Redirects to the right function considering the type.
*/

void	ft_precision_manager(t_indic **ind, t_buff **buff, char **str)
{
	int			i;
	const t_ft	prec[] = {{"bpdiouxX", NULL, ft_precision_int, NULL, NULL},
		{"sS", NULL, ft_precision_string, NULL, NULL},
		{0, 0, 0, 0, 0}
	};

	i = 0;
	if ((*ind)->isprec == 0)
		return ;
	while (prec[i].letter)
	{
		if ((*ind)->type && ft_strchr(prec[i].letter, (*ind)->type))
		{
			prec[i].f2(ind, buff, str);
			break ;
		}
		i++;
	}
}

/*
** ft_flags_manager
** Redirects to the right functions considering the type.
*/

void	ft_flags_manager(t_indic **ind, t_buff **buff, char **str)
{
	ft_print_sign_before(ind, buff, str);
	ft_manage_hashtag(ind, buff, str);
	if (ft_strchr("di", (*ind)->type))
		ft_manage_plus_signed(ind, buff, str);
	else if (ft_strchr("sc%0", (*ind)->type))
		ft_manage_plus_string(ind, buff, str);
	else
		ft_manage_plus_unsigned(ind, buff, str);
	ft_putsbuffer(buff, (*buff)->prefix);
	ft_manage_zero(ind, buff, str);
}

/*
** ft_indicators_manager
** Main function for indicators
*/

void	ft_indicators_manager(t_indic **ind, t_buff **buff, char **str)
{
	if (!*str)
		return ;
	ft_flags_manager(ind, buff, str);
	ft_precision_manager(ind, buff, str);
	ft_manage_minus(ind, buff, str);
}
