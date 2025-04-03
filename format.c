/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:39:19 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/03 21:59:24 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_format(char sp, va_list *args, t_format *src, t_buffer *buf)
{
	src->sp = sp;
	update_t_printf(src);
	if (sp == 'c')
		write_buf_char(va_arg(*args, int), src, buf);
	else if (sp == 's')
		formating_str(va_arg(*args, char *), src, buf);
	else if (sp == 'd')
		formating_digit(va_arg(*args, int), src, buf);
	else if (sp == 'u')
		formating_digit(va_arg(*args, unsigned int), src, buf);
	else if (sp == 'i')
		formating_digit(va_arg(*args, int), src, buf);
	else if (sp == 'x' || sp == 'X')
		formating_hex(va_arg(*args, unsigned int), src, buf);
	else if (sp == 'p')
		formating_ptr(va_arg(*args, void *), src, buf);
	else if (sp == '%')
		write_buf_char(sp, NULL, buf);
}

void	parse_flags(const char **f, t_format *src)
{
	while (**f && (**f == '-' || **f == '0' || **f == '+' \
			|| **f == ' ' || **f == '#'))
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
}

void	parse_format(const char **f, t_format *src)
{
	parse_flags(f, src);
	if (**f && **f != '.' && **f != '0')
	{
		while (**f && **f >= '0' && **f <= '9')
		{
			src->width = src->width * 10 + (**f - '0');
			(*f)++;
		}
	}
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
