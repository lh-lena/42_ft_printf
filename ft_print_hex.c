/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:53:08 by ohladkov          #+#    #+#             */
/*   Updated: 2025/03/30 00:25:18 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	print_hexupp(long n, unsigned int base)
{
	int			count;
	const char	*symbols;

	symbols = "0123456789ABCDEF";
	count = 0;
	if (n >= base)
		count += print_hexupp(n / base, base);
	n = symbols[n % base];
	count += write(1, &n, 1);
	return (count);
}

int	print_unshex(unsigned long long n, unsigned int base)
{
	int			count;
	const char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n >= base)
		count += print_unshex(n / base, base);
	n = symbols[n % base];
	count += write(1, &n, 1);
	return (count);
} */

/* int	print_hex(unsigned long long n, unsigned int base, char conversion)
{
	int			count;
	const char	*symbols;

	if (conversion == 'x')
		symbols = "0123456789abcdef";
	else if (conversion == 'X')
		symbols = "0123456789ABCDEF";
	else
		return (0);
	count = 0;
	if (n >= base)
		count += print_hex(n / base, base, conversion);
	n = symbols[n % base];
	count += write(1, &n, 1);
	return (count);
} */

void	write_buf_hexupp(long n, t_format *src, t_buffer *buf)
{
	char	s[BUFFER_SIZE];
	int		len;

	len = 0;
	if (src && src->hash)
	{
		s[len++] = '0';
		s[len++] = 'X';
	}
	
}

void	write_buf_unshex(unsigned long long n, t_format *src, t_buffer *buf)
{
	
}
