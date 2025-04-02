#include "ft_printf.h"

int	ft_ternary_subtraction(int left, int rigth)
{
	if (left > rigth)
		return (left - rigth);
	else
		return (0);
}

void	write_buf_digit(char *str, t_format *src, t_buffer *buf)
{
	int	padding;
	int	sg;
	// print_struct(src);
	if (src->sign == '-' || src->sign == '+')
		sg = 1;
	else
		sg = 0;
	padding = ft_ternary_subtraction(src->width, src->len + sg);
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

void	formating_digit(long n, t_format *src, t_buffer *buf)
{
	char	tmp[BUFFER_SIZE];
	int		padding;

	src->len = 0;
	if (n < 0)
	{
		if (!src->plus)
			src->sign = '-';
		n *= -1;
	}
	if (n == 0)
		tmp[src->len++] = '0';
	while (n > 0)
	{
		tmp[src->len++] = '0' + (n % 10);
		n /= 10;
	}
	if (src->precision >= src->len)
	{
		padding = src->precision - src->len;
		while (padding--)
			tmp[src->len++] = '0';
	}
	// tmp[src->len] = '\0';
	if (src->sign == '-' || src->sign == '+')
	{
		// tmp[src->len++] = src->sign;
		write_buf_char(src->sign, NULL, buf);
	}
	print_struct(src);
	write_buf_digit(tmp, src, buf);
	// int padding;
	// padding = ft_ternary_subtraction(src->width, src->len);
	// if (!src->left_align && padding > 0)
	// {
	// 	while (padding--)
	// 		write_buf_char(src->pad_char, NULL, buf);
	// }
	// while ((src->len)-- && tmp[src->len])
	// 	write_buf_char(tmp[src->len], NULL, buf);
	// if (src->left_align && padding > 0)
	// {
	// 	while (padding--)
	// 		write_buf_char(' ', NULL, buf);
	// }
}
