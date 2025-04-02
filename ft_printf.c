/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:58:48 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/02 21:10:56 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	parse_format(const char **f, t_format *src)
{
	// parse flags
	while (**f && (**f == '-' || **f == '0' || **f == '+' || **f == ' ' || **f == '#'))
	{
		if (**f == '-')
			src->left_align = 1;
		if (**f == '0')
			src->zero_pad = 1;
		if (**f == '+')
			src->plus = 1;
		if (**f == ' ')
			src->space = 1;
		if (**f == '#')
			src->hash = 1;
		(*f)++;
	}

	// parse width (with nonzero first digit)
	if (**f && **f != '.' && **f != '0')
	{
		while (**f && **f >= '0' && **f <= '9')
		{
			src->width = src->width * 10 + (**f - '0');
			(*f)++;
		}
	}

	// parse precision
	if (**f == '.')
	{
		(*f)++;
		src->precision = 0;
		while (**f >= '0' && **f <= '9' && **f)
		{
			src->precision = src->precision * 10 + (**f - '0');
			(*f)++;
		}
	}
}

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
}

void	printf_format(char specifier, va_list *args, t_format *src, t_buffer *buf)
{
	src->specifier = specifier;
	update_t_printf(src);
	if (specifier == 'c')
		write_buf_char(va_arg(*args, int), src, buf);
	else if (specifier == 's')
		write_buf_str(va_arg(*args, char *), src, buf);
	else if (specifier == 'd')
		write_buf_digit(va_arg(*args, int), src, buf);
	else if (specifier == 'u')
		write_buf_digit(va_arg(*args, unsigned int), src, buf);
	else if (specifier == 'i')
		write_buf_digit(va_arg(*args, int), src, buf);
	// else if (specifier == 'x' || specifier == 'X')
	// 	print_hex(va_arg(*args, unsigned int), 16, specifier);
	// else if (specifier == 'p')
	// 	print_ptr(va_arg(*args, void *));
	else if (specifier == '%')
		write_buf_char(specifier, NULL, buf);
}
/* 
void	print_struct(t_format src)
{
	print_str("src.hash ");
	print_digit(src.hash, &src);
	print_char('\n');

	print_str("src.left_align ");
	print_digit(src.left_align, &src);
	print_char('\n');

	print_str("src.plus ");
	print_digit(src.plus, &src);
	print_char('\n');

	print_str("src.precision ");
	print_digit(src.precision, &src);
	print_char('\n');

	print_str("src.space ");
	print_digit(src.space, &src);
	print_char('\n');

	print_str("src.width ");
	print_digit(src.width, &src);
	print_char('\n');

	print_str("src.zero_pad ");
	print_digit(src.zero_pad, &src);
	print_char('\n');

	print_str("src.specifier ");
	print_char(src.specifier);
	print_char('\n');
}
 */

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
			// print_struct(*ft_printf);
			// fprintf(stderr, "format %s\n", format);
			printf_format(*format, &args, &ft_printf, &buf);
		}
		else
			write_buf_char(*format, NULL, &buf);
			// count += write(1, format, 1);
		format++;
	}
	flush_buffer(&buf);
	va_end (args);
	return (buf.count);
}
