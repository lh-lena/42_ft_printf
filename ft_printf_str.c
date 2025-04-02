/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:45:44 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/02 21:09:47 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void write_buf_char(int c, t_format *src, t_buffer *buf)
{
	if (!buf)
		return;
	if (buf->idx >= BUFFER_SIZE)
	{
		flush_buffer(buf);
	}
	buf->data[buf->idx++] = c;
}

/* 
int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
} */

void	write_buf_str(char *str, t_format *src, t_buffer *buf)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		s = "(null)";
	else
		s = str;
	while (s[i])
		write_buf_char(s[i++], NULL, buf);
}

int	ft_ternary_subtraction(int left, int rigth)
{
	if (left > rigth)
		return (left - rigth);
	else
		return (0);
}

void	write_buf_digit(long n, t_format *src, t_buffer *buf)
{
	char	tmp[BUFFER_SIZE];
	int		len;
	int		padding;
	char	pad_char;

	len = 0;
	if (n < 0)
	{
		if (!src->plus)
			src->sign = '-';
		n *= -1;
	}
	if (n == 0)
		tmp[len++] = '0';
	while (n > 0)
	{
		tmp[len++] = '0' + (n % 10);
		n /= 10;
	}
	if (src->sign == '-' || src->sign == '+')
		tmp[len++] = src->sign;
	// fprintf(stderr, "src->precision %d, len %d\n",src->precision, len);
	if (src->precision >= len)
	{
		padding = src->precision - len;
		while (padding--)
			tmp[len++] = '0';
	}
	padding = ft_ternary_subtraction(src->width, len);
	if (!src->left_align && padding > 0)
	{
		while (padding--)
			write_buf_char(src->pad_char, NULL, buf);
	}
	while (len--)
		write_buf_char(tmp[len], NULL, buf);
	if (src->left_align && padding > 0)
	{
		while (padding--)
			write_buf_char(' ', NULL, buf);
	}
}

/* int i = 0;
int	print_digit(long n, t_format *src)
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
} */

