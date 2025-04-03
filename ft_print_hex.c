/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:53:08 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/03 21:03:57 by ohladkov         ###   ########.fr       */
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
	const char			*symbols;
	int					padding;
	char				tmp[BUFFER_SIZE];
	unsigned long long	nbr;

	symbols = \
	ft_ternary_str(src->specifier, 'X', "0123456789ABCDEF", "0123456789abcdef");
	src->len = 0;
	nbr = n;
	if (nbr == 0)
		tmp[src->len++] = '0';
	while (nbr > 0)
	{
		tmp[src->len++] = symbols[nbr % 16];
		nbr /= 16;
	}
	if (src->precision >= src->len)
	{
		padding = src->precision - src->len;
		while (padding--)
			tmp[src->len++] = '0';
	}
	if (src->hash && (n != 0 || src->specifier == 'p'))
	{
		tmp[src->len++] = ft_ternary_str(src->specifier, 'X', "X", "x")[0];
		// if (src->specifier == 'X')
		// 	tmp[src->len++] = 'X';
		// else
		// 	tmp[src->len++] = 'x';
		tmp[src->len++] = '0';
	}
	tmp[src->len] = '\0';
	write_buf_digit(tmp, src, buf);
}
