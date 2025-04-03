/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:51:02 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/03 23:07:15 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static void	prepend_zero(char *s[BUFFER_SIZE], t_format *src);

void	write_buf_revdigit(char *str, t_format *src, t_buffer *buf)
{
	int	padding;

	padding = ft_ternary_subtraction(src->width, src->len);
	if (!src->left_align && padding > 0)
	{
		while (padding--)
			write_buf_char(src->pad_char, NULL, buf);
	}
	while ((src->len)-- && str[src->len])
		write_buf_char(str[src->len], NULL, buf);
	if (src->left_align && padding > 0)
	{
		while (padding--)
			write_buf_char(' ', NULL, buf);
	}
}

void	write_buf_digit(char *str, t_format *src, t_buffer *buf)
{
	int	i;

	i = 0;
	src->padding = ft_ternary_subtraction(src->width, src->len);
	if (src->sign == '-' || src->sign == '+')
		src->padding -= 1;
	if (src->space && src->nbr >= 0)
		write_buf_char(' ', NULL, buf);
	if ((src->sign == '-' || src->sign == '+') && src->pad_char == '0')
		write_buf_char(src->sign, NULL, buf);
	if (!src->left_align && src->padding > 0)
	{
		while (src->padding--)
			write_buf_char(src->pad_char, NULL, buf);
	}
	if ((src->sign == '-' || src->sign == '+') && src->pad_char != '0')
		write_buf_char(src->sign, NULL, buf);
	i = 0;
	while (i < src->len && str[i])
		write_buf_char(str[i++], NULL, buf);
	if (src->left_align && src->padding > 0)
	{
		while (src->padding--)
			write_buf_char(' ', NULL, buf);
	}
}

void	process_digit(long *n, t_format *src, char *tmp)
{
	src->nbr = *n;
	src->len = 0;
	if (*n < 0)
	{
		src->sign = '-';
		*n *= -1;
	}
	if (*n == 0)
		tmp[src->len++] = '0';
	while (*n > 0)
	{
		tmp[src->len++] = '0' + (*n % 10);
		*n /= 10;
	}
	if (src->precision >= src->len)
	{
		src->padding = src->precision - src->len;
		while (src->padding--)
			tmp[src->len++] = '0';
	}
}

void	formating_digit(long n, t_format *src, t_buffer *buf)
{
	char	tmp[BUFFER_SIZE];
	char	res[BUFFER_SIZE];
	int		i;

	i = 0;
	process_digit(&n, src, tmp);
	if (src->sign != '-' && src->plus)
		src->sign = '+';
	while (src->len - 1 >= 0)
		res[i++] = tmp[(src->len)-- - 1];
	res[i] = '\0';
	src->len = i;
	write_buf_digit(res, src, buf);
}

