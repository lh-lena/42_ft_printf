/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:58:25 by ohladkov          #+#    #+#             */
/*   Updated: 2025/03/30 18:28:01 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

// %[$][flags][width][.precision][length modifier]conversion

# define BUFFER_SIZE 1024

typedef struct s_printf
{
	// flags
	int left_align;
	int zero_pad;
	int plus;
	int space;
	int hash;
	// width 0 - 9
	int width;
	// precision
	int precision;
	// conversion
	char specifier;

}	t_printf;

typedef struct s_buffer
{
	char	data[BUFFER_SIZE];
	int		idx;
	int		count;
}	t_buffer;

int	ft_printf(const char *format, ...);
int	print_char(int c);
void flush_buffer(t_buffer *buf);
void write_buf_char(int c, t_buffer *buf);
int	print_str(char *str);
int	print_digit(long n, t_printf *src);
void	write_buf_digit(long n, t_printf *src, t_buffer *buf);
// int	print_hexupp(long n, unsigned int base);
// int	print_unshex(unsigned long long n, unsigned int base);
int	print_hex(unsigned long long n, unsigned int base, char conversion);

int	print_ptr(void *ptr);
void	print_struct(t_printf src);

#endif
