/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:20:05 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/25 13:32:08 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_file_exists(char *path)
{
	int		fd;

	if ((fd = open(path, O_RDONLY)) != -1)
	{
		ft_close_fd(fd);
		return (1);
	}
	return (0);
}
