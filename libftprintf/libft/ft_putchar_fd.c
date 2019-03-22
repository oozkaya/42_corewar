/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:10:54 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/22 12:32:29 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	int		ret;

	if (fd <= 0)
	{
		write(2, "error: bad file descriptor", 13);
		return ;
	}
	if ((ret = write(fd, &c, 1)) < 0)
		write(2, "write() error", 13);
}
