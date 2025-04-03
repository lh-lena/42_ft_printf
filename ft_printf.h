/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:58:25 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/03 22:35:37 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

/**  %[$][flags][width][.precision][length modifier]conversion */

# define BUFFER_SIZE 1024

typedef struct s_format
{
	int		left_align;
	int		zero_pad;
	int		plus;
	int		space;
	int		hash;
	int		width;
	int		precision;
	char	sp;
	char	pad_char;
	char	sign;
	int		len;
	int		padding;
	long	nbr;
}	t_format;

typedef struct s_buffer
{
	char	data[BUFFER_SIZE];
	int		idx;
	int		count;
}	t_buffer;

int		ft_printf(const char *format, ...);
void	parse_format(const char **f, t_format *src);
void	parse_flags(const char **f, t_format *src);
void	printf_format(char sp, va_list *args, t_format *src, t_buffer *buf);
void	flush_buffer(t_buffer *buf);
void	init_t_printf(t_format *src);
void	init_t_buffer(t_buffer *buf);
void	update_t_printf(t_format *src);
void	write_buf_char(int c, t_format *src, t_buffer *buf);
void	formating_str(char *str, t_format *src, t_buffer *buf);
void	write_buf_str(char *str, t_format *src, t_buffer *buf);
void	formating_digit(long n, t_format *src, t_buffer *buf);
void	write_buf_revdigit(char *str, t_format *src, t_buffer *buf);
int		ft_ternary_subtraction(int left, int rigth);
void	formating_ptr(void *ptr, t_format *src, t_buffer *buf);
void	formating_hex(unsigned long long n, t_format *src, t_buffer *buf);
char	*ft_ternary_str(char sp1, char sp2, char *s1, char *s2);
char	*reverse_str(char* s, int len);

#endif
