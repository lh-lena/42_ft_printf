/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:45:44 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/03 00:50:57 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_buf_char(int c, t_format *src, t_buffer *buf)
{
	char	str[2];

	if (!buf)
		return ;
	if (buf->idx >= BUFFER_SIZE)
	{
		flush_buffer(buf);
	}
	if (!src)
	{
		buf->data[buf->idx++] = c;
		return ;
	}
	str[0] = c;
	str[1] = '\0';
	src->len = 1;
	write_buf_str(str, src, buf);
}

void	write_buf_str(char *str, t_format *src, t_buffer *buf)
{
	int	padding;
	int	i;

	padding = ft_ternary_subtraction(src->width, src->len);
	if (!src->left_align && padding > 0)
	{
		while (padding--)
			write_buf_char(src->pad_char, NULL, buf);
	}
	i = 0;
	while (i < src->len)
		write_buf_char(str[i++], NULL, buf);
	if (src->left_align && padding > 0)
	{
		while (padding--)
			write_buf_char(' ', NULL, buf);
	}
}

void	formating_str(char *str, t_format *src, t_buffer *buf)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
	{
		s = "(null)";
		while (s[i])
			write_buf_char(s[i++], NULL, buf);
		return ;
	}
	while (str[i])
		i++;
	src->len = i;
	if (src->precision != -1 && src->precision < src->len)
		src->len = src->precision;
	write_buf_str(str, src, buf);
}
