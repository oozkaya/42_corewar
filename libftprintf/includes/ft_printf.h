/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:22:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/19 15:49:46 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"

/*
** Need to be uncommented to use ft_fprintf or ft_vfprintf
** fwrite() is a forbidden function
** # include <stdio.h>
*/

# define PRINT_IN_STRING	-123456789

/*
** Unicode masks
**	MASK_BYTE00		0x0		0xxx xxxx	||	RMASK_BYTE00	0x7F	0111 1111
**	MASK_BYTE01		0xC0	110x xxxx	||	RMASK_BYTE01	0x1F	0001 1111
**	MASK_BYTE02		0xE0	1110 xxxx	||	RMASK_BYTE02	0x0F	0000 1111
**	MASK_BYTE03		0xF0	1111 0xxx	||	RMASK_BYTE03	0x07	0000 0111
**	MASK_BYTE10		0x80	10xx xxxx	||	RMASK_BYTE10	0x3F	0011 1111
*/
# define MASK_BYTE00	0x0
# define RMASK_BYTE00	0x7F
# define MASK_BYTE01	0xC0
# define RMASK_BYTE01	0x1F
# define MASK_BYTE02	0xE0
# define RMASK_BYTE02	0x0F
# define MASK_BYTE03	0xF0
# define RMASK_BYTE03	0x07
# define MASK_BYTE10	0x80
# define RMASK_BYTE10	0x3F

/*
** Colors (F)Fonts (B)Backgrounds
*/
# define F_CLEAR		"\033[2K"
# define F_UP			"\033[A"
# define F_BOLD			"\033[1m"
# define F_UNDERLINE	"\033[4m"
# define F_BLINKING		"\033[5m"
# define F_NO 			"\033[0m"
# define F_BLACK		"\033[1;30m"
# define B_BLACK		"\033[0;40m"
# define F_RED			"\033[1;31m"
# define B_RED			"\033[0;41m"
# define F_GREEN		"\033[1;32m"
# define B_GREEN		"\033[0;42m"
# define F_YELLOW		"\033[1;33m"
# define B_YELLOW		"\033[0;43m"
# define F_BLUE			"\033[1;34m"
# define B_BLUE			"\033[0;44m"
# define F_PURPLE		"\033[1;35m"
# define B_PURPLE		"\033[0;45m"
# define F_CYAN			"\033[1;36m"
# define B_CYAN			"\033[0;46m"
# define F_WHITE		"\033[1;37m"
# define B_WHITE		"\033[0;47m"

/*
** Buffer
*/
typedef struct		s_buff
{
	intmax_t		size_max;
	char			*str;
	char			prefix[2 + 1];
	char			*suffix;
	int				sign_printed;
	int				iszero;
	int				printed;
	intmax_t		index;
	int				fd;
	int				err;
	intmax_t		valid_pos;
}					t_buff;

/*
** Indicators
*/
typedef struct		s_indic
{
	int				start;
	int				end;
	char			flags[5 + 1];
	int				width;
	int				isprec;
	int				precision;
	char			size[2 + 1];
	char			type;
	intmax_t		nb;
	unsigned int	c;
	wchar_t			*ws;
}					t_indic;

/*
** ft_printf and cie
*/
int					ft_printf(const char *str, ...);
int					ft_dprintf(int fd, const char *str, ...);
int					ft_asprintf(char **str, const char *fmt, ...);
int					ft_vprintf(const char *str, va_list ap);
int					ft_vdprintf(int fd, const char *str, va_list ap);
int					ft_vasprintf(char **str, const char *fmt, va_list ap);

/*
**Bonus functions with fwrite()
**int					ft_fprintf(FILE *file, const char *str, ...);
**int					ft_vfprintf(FILE *file, const char *str, va_list ap);
*/

/*
** Struct init and free
*/
int					ft_init_indic(t_indic **ind);
void				ft_free_indic(t_indic **ind);
int					ft_init_buffer(t_buff **buff, int fd);
void				ft_free_buff(t_buff **buff);
void				ft_reset_struct(t_indic **ind, t_buff **buff);

/*
** Printer
*/
void				ft_putcbuffer(t_buff **buff, char c);
void				ft_putsbuffer(t_buff **buff, char *str);
char				*ft_putinstr_buffer(t_buff **buff);
void				ft_valid_buffer(t_buff **buff);

/*
** Get chars to convert
*/
void				ft_get_all_indics(t_indic **in, va_list a, char *s, int *i);
void				ft_get_flags(t_indic **ind, char *str);
void				ft_get_width(t_indic **ind, va_list ap, char *str, int i);
void				ft_get_precision(t_indic **in, va_list ap, char *s, int i);
void				ft_get_size(t_indic **ind, char *str);
void				ft_get_type(t_indic **ind, char *str);
void				ft_capital_type(t_indic **ind);

/*
** Parse
*/
void				ft_parse_str(va_list ap, char *str, t_buff **buff);

/*
** Convert
*/
void				ft_arg_int(va_list ap, t_indic **ind, t_buff **buff);
void				ft_arg_char(va_list ap, t_indic **ind, t_buff **buff);
void				ft_arg_string(va_list ap, t_indic **ind, t_buff **buff);
void				ft_arg_novalid_conv(t_indic **i, t_buff **b);

/*
** Flags
*/
void				ft_indicators_manager(t_indic **i, t_buff **buff, char **s);
void				ft_print_sign_before(t_indic **i, t_buff **buff, char **s);
void				ft_manage_hashtag(t_indic **ind, t_buff **buff, char **str);
void				ft_manage_zero(t_indic **ind, t_buff **buff, char **str);
void				ft_manage_plus_signed(t_indic **i, t_buff **b, char **s);
void				ft_manage_plus_unsigned(t_indic **i, t_buff **b, char **s);
void				ft_manage_plus_string(t_indic **ind, t_buff **b, char **s);
void				ft_manage_minus(t_indic **ind, t_buff **buff, char **str);

/*
** Precision
*/
void				ft_precision_int(t_indic **ind, t_buff **buff, char **str);
void				ft_precision_string(t_indic **i, t_buff **buff, char **str);

/*
** Size
*/
void				ft_get_string(t_indic **ind, va_list ap, char **str);
void				ft_get_chars_csp(t_indic **ind, va_list ap);

/*
** Unicode
*/
void				ft_unicode_to_str(t_indic **ind,
									t_buff **b, char **s, int *i);
void				ft_convert_unicode(t_indic **ind, char **byte, int *i);

/*
** Errors
*/
void				ft_error_manager(t_buff **buff);

/*
** Associated function types and pointers
*/
typedef struct		s_conv
{
	char			*letters;
	void			(*f)(va_list, t_indic**, t_buff**);
}					t_conv;

typedef struct		s_ft
{
	char			*letter;
	void			(*f1)(va_list, t_indic**, t_buff**);
	void			(*f2)(t_indic**, t_buff**, char **str);
	void			(*f3)(t_indic**, va_list, char **str, int base);
	void			(*f4)(t_indic**, va_list, char **str);
}					t_ft;

#endif
