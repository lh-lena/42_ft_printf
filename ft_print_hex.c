/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:53:08 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/03 22:35:37 by ohladkov         ###   ########.fr       */
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
	const char			*sbl;
	char				tmp[BUFFER_SIZE];
	unsigned long long	nbr;

	sbl = ft_ternary_str(src->sp, 'X', "0123456789ABCDEF", "0123456789abcdef");
	nbr = n;
	if (nbr == 0)
		tmp[src->len++] = '0';
	while (nbr > 0)
	{
		tmp[src->len++] = sbl[nbr % 16];
		nbr /= 16;
	}
	if (src->precision >= src->len)
	{
		src->padding = src->precision - src->len;
		while (src->padding--)
			tmp[src->len++] = '0';
	}
	if (src->hash && (n != 0 || src->sp == 'p'))
	{
		tmp[src->len++] = ft_ternary_str(src->sp, 'X', "X", "x")[0];
		tmp[src->len++] = '0';
	}
	write_buf_revdigit(tmp, src, buf);
}
