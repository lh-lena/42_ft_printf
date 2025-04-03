/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:58:48 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/03 22:27:42 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/*
	If the 0 and - flags both appear, the 0 flag is ignored.
	If a precision is given with an integer conversion (d, i, u, x, and X), 
	the 0 flag is ignored.
	A '+' overrides a 'space' if both are used.
*/
void	update_t_printf(t_format *src)
{
	if (src->zero_pad)
	{
		if (src->left_align)
			src->zero_pad = 0;
		else if (src->precision != -1 && (src->sp == 'd' \
		|| src->sp == 'i' || src->sp == 'u' \
		|| src->sp == 'x' || src->sp == 'X'))
			src->zero_pad = 0;
	}
	if (src->plus && src->space)
		src->space = 0;
	if (src->space && (src->sp != 'd' && src->sp != 'i'))
		src->space = 0;
	if (src->plus && (src->sp != 'd' && src->sp != 'i'))
		src->plus = 0;
	if (src->zero_pad)
		src->pad_char = '0';
	else
		src->pad_char = ' ';
	if (src->sp == 'p')
		src->hash = 1;
}

void	flush_buffer(t_buffer *buf)
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
	src->pad_char = ' ';
	src->padding = 0;
	src->nbr = 0;
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
