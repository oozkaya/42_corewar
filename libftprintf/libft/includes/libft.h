/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:44:39 by ade-verd          #+#    #+#             */
/*   Updated: 2018/11/07 16:58:48 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memccpy_src(void *dst, void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t len);

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
int					ft_strchr_pos(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strrchr_pos(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strleft(const char *str, const char *left);
int					ft_strright(const char *str, const char *right);
char				*ft_strnstr(const char *hstack, const char *ndle, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char const *s1, char const *s2, size_t len);
char				*ft_strnjoinfree(char const *s1, char const *s2, size_t len,
										int pick);
char				*ft_strtrim(char const *s);
char				*ft_stroffset(char *str, unsigned int offset);
char				**ft_strsplit(char const *s, char c);
char				**ft_strmsplit(const char *str, char *chars);
void				ft_freetab_strsplit(char **tab);
int					ft_countwords(char const *s, char c);

int					ft_atoi(const char *str);
intmax_t			ft_atointmax(const char *str);
intmax_t			ft_atoi_base(const char *str, int str_base);
uintmax_t			ft_uatoi_base(const char *str, int str_base);
char				*ft_itoa(int n);
char				*ft_itoa_base(intmax_t value, int base);
char				*ft_uitoa_base(uintmax_t value, int base);
int					ft_abs(int n);
int					ft_intlen(int n);
void				ft_swap(int *a, int *b);
int					ft_power(int nb, int power);
int					ft_sqrt(int nb);
int					ft_int_sqrt(int nb);
int					ft_bitlen(unsigned int n);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
char				*ft_strupper(char *str);
int					ft_tolower(int c);
char				*ft_strlower(char *str);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new0);
void				ft_lstappend(t_list *new0, t_list *first_link);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_open_fd(char *path, int oflag, int perm);
int					ft_close_fd(int fd);
int					ft_remove(char *path);
int					ft_file_exists(char *path);

#endif
