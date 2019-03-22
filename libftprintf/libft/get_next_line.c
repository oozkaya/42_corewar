/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:13:45 by ade-verd          #+#    #+#             */
/*   Updated: 2019/03/05 13:54:23 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** get_next_line
** Extracts a line from fd.
** A line is ended by '\n' or EOF (End Of File)
**
** Return
** (1) A line is read | (0) Reading is over | (-1) Error
*/

static t_list	*ft_check_fd(t_list **begin, int fd)
{
	t_list	*file;

	file = *begin;
	while (file)
	{
		if (fd == (int)file->content_size)
			return (file);
		file = file->next;
	}
	file = ft_lstnew("\0", 1);
	file->content_size = fd;
	ft_lstadd(begin, file);
	return (file);
}

static int		new_content(t_list *f, int ret)
{
	char	*tmp;

	tmp = f->content;
	if (!(f->content = ft_strdup(f->content + ret)))
		return (0);
	ft_memdel((void**)&tmp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*f;
	t_list			*begin;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 0)
		return (-1);
	begin = f;
	f = ft_check_fd(&begin, fd);
	ft_bzero(buf, BUFF_SIZE + 1);
	while (!ft_memchr(f->content, '\n', ft_strlen(f->content) + 1)
		&& (ret = read(fd, buf, BUFF_SIZE)))
		if (!(f->content = ft_strnjoinfree(f->content, buf, ret, 0)))
			return (-1);
	ret = 0;
	while (((char *)f->content)[ret] && ((char *)f->content)[ret] != '\n')
		++ret;
	if (!(*line = ft_strndup(f->content, ret)))
		return (-1);
	(((char *)f->content)[ret] == '\n') ? ++ret : 0;
	if (!(new_content(f, ret)))
		return (-1);
	f = begin;
	return (ret ? 1 : 0);
}
