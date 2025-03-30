/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:45:44 by ohladkov          #+#    #+#             */
/*   Updated: 2025/03/30 18:47:37 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void write_buf_char(int c, t_buffer *buf)
{
	if (buf->idx >= BUFFER_SIZE)
	{
		flush_buffer(buf);
	}
	buf->data[buf->idx++] = c;
}

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int		count;
	char	*s;

	if (!str)
		s = "(null)";
	else
		s = str;
	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

/*
void test_d(void)
{
// Right-align, minimum width 5 (default, no flag)
printf("|%5d|\n", 42);       // Output: |   42|

// Left-align, minimum width 5
printf("|%-5d|\n", 42);      // Output: |42   |

// Zero-pad to width 5
printf("|%05d|\n", 42);      // Output: |00042|

// Specify precision (at least 3 digits)
printf("|%.3d|\n", 42);      // Output: |042|

// Width 5 and precision 3 (note padding for width)
printf("|%5.3d|\n", 42);     // Output: |  042|
}
*/

int	ft_ternary_subtraction(int left, int rigth)
{
	if (left > rigth)
		return (left - rigth);
	else
		return (0);
}

void	write_buf_digit(long n, t_printf *src, t_buffer *buf)
{
	char	tmp[BUFFER_SIZE];
	int		len;
	int		padding;

	len = 0;
	if (n < 0)
	{
		if (src->plus)
			write_buf_char('+', buf);
		else
			write_buf_char('-', buf);
		n *= -1;
	}
	if (n == 0)
		tmp[len++] = '0';
	while (n > 0)
	{
		tmp[len++] = '0' + (n % 10);
		n /= 10;
	}
	if (src->precision > len) //?// change?
	{
		padding = src->precision - len;
		while (padding--)
			tmp[len++] = '0';
	}
	else if (src->precision != -1)
		len -= src->precision;
	padding = ft_ternary_subtraction(src->width, len);
	if (!src->left_align && padding > 0)
	{
		char pad_char = (src->zero_pad) ? '0' : ' '; // change
		while (padding--)
			write_buf_char(pad_char, buf);
	}
	while (len--)
		write_buf_char(tmp[len], buf);
	if (src->left_align && padding > 0)
	{
		while (padding--)
			write_buf_char(' ', buf);
	}
}

int i = 0;
int	print_digit(long n, t_printf *src)
{
	int			count;
	const char	*symbols;

	count = 0;
	symbols = "0123456789";
	if (n < 0)
	{
		i++;
		count += write (1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		i++;
		count += print_digit(n / 10, src);
	}
	i++;
	n = symbols[n % 10];
	count += write(1, &n, 1);
	return (count);
}

