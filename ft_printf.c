/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:58:48 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/03 01:32:58 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/*
	If the 0 and - flags both appear, the 0 flag is ignored.
	If a precision is given with an integer conversion (d, i, u, x, and X), the 0 flag is ignored.
	A '+' overrides a 'space' if both are used.
*/
void	update_t_printf(t_format *src)
{
	if (src->zero_pad)
	{
		if (src->left_align)
			src->zero_pad = 0;
		else if (src->precision != -1 && (src->specifier == 'd' || src->specifier == 'i' || src->specifier == 'u' || src->specifier == 'x' || src->specifier == 'X'))
			src->zero_pad = 0;
	}
	if (src->plus && src->space)
		src->space = 0;
	if (src->plus && (src->specifier == 'd' || src->specifier == 'i'))
		src->sign = '+';
	if (src->zero_pad)
		src->pad_char = '0';
	else
		src->pad_char = ' ';
	if (src->specifier == 'p')
		src->hash = 1;
}

void	print_struct(t_format *src)
{
	printf("hash: %d\nleft_align: %d\nplus: %d\nprecision: %d\nspace: %d\nwidth: %d\nzero_pad: %d\nlen: %d\nsign: %c\n",
	src->hash,
	src->left_align,
	src->plus,
	src->precision,
	src->space,
	src->width,
	src->zero_pad,
	src->len,
	src->sign);
}

void flush_buffer(t_buffer *buf)
{
	if (buf->idx > 0)
	{
		buf->count += write(1, buf->data, buf->idx);
		buf->idx = 0;
	}
}

void	init_t_printf(t_format *src)
{
	src->hash = 0;
	src->left_align = 0;
	src->plus = 0;
	src->precision = -1;
	src->space = 0;
	src->width = 0;
	src->zero_pad = 0;
	src->len = 0;
	src->sign = ' ';
}

void	init_t_buffer(t_buffer *buf)
{
	buf->idx = 0;
	buf->count = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	ft_printf;
	t_buffer	buf;

	if (!format)
		return (-1);
	va_start(args, format);
	init_t_buffer(&buf);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			init_t_printf(&ft_printf);
			parse_format(&format, &ft_printf);
			printf_format(*format, &args, &ft_printf, &buf);
		}
		else
			write_buf_char(*format, NULL, &buf);
		format++;
	}
	flush_buffer(&buf);
	va_end (args);
	return (buf.count);
}
