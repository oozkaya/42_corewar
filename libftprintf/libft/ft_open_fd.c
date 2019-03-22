/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:35:34 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/07 16:43:19 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_open_fd(char *path, int oflag, int perm)
{
	int		fd;

	if ((fd = open(path, oflag, perm)) == -1)
	{
		ft_putstr_fd("open() error\n", 2);
		return (-1);
	}
	return (fd);
}
