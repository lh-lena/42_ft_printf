/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:41:20 by ohladkov          #+#    #+#             */
/*   Updated: 2025/04/03 21:41:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ternary_subtraction(int left, int rigth)
{
	if (left > rigth)
		return (left - rigth);
	return (0);
}

char	*ft_ternary_str(char sp1, char sp2, char *s1, char *s2)
{
	if (sp1 == sp2)
		return (s1);
	return (s2);
}
