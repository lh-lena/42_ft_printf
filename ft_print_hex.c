/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:53:08 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/03 00:27:33 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formating_ptr(void *ptr, t_format *src, t_buffer *buf)
{
	unsigned long long	address;
	address = (unsigned long long)ptr;
	formating_hex(address, src, buf);
}

void	formating_hex(unsigned long long n, t_format *src, t_buffer *buf)
{
	const char	*symbols;
	int			padding;
	char		tmp[BUFFER_SIZE];
	
	if (src->specifier == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";

	src->len = 0;
	if (n == 0)
		tmp[src->len++] = '0';
	while (n > 0)
	{
		tmp[src->len++] = symbols[n % 16];
		n /= 16;
	}
	if (src->precision >= src->len)
	{
		padding = src->precision - src->len;
		while (padding--)
			tmp[src->len++] = '0';
	}
	if (src->hash)
	{
		tmp[src->len++] = 'x';
		tmp[src->len++] = '0';
	}
	tmp[src->len] = '\0';
	write_buf_digit(tmp, src, buf);
}
