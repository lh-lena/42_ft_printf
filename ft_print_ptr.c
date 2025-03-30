/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:30:15 by ohladkov          #+#    #+#             */
/*   Updated: 2025/03/30 14:34:37 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(void *ptr)
{
	unsigned long long	address;
	int					count;

	count = 0;
	if (!ptr)
		return (count += write(1, "(nil)", 5));
	address = (unsigned long long)ptr;
	count += write(1, "0x", 2);
	count += print_hex(address, 16, 'x');
	return (count);
}
