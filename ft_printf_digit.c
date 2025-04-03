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
	// print_struct(src);

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

void	formating_digit(long n, t_format *src, t_buffer *buf)
{
	char	tmp[BUFFER_SIZE];
	char	res[BUFFER_SIZE];
	int		padding;
	long	nbr;
	int i = 0;

	src->len = 0;
	nbr = n;
	if (nbr < 0)
	{
		src->sign = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		tmp[src->len++] = '0';
	while (nbr > 0)
	{
		tmp[src->len++] = '0' + (nbr % 10);
		nbr /= 10;
	}
	if (src->precision >= src->len)
	{
		padding = src->precision - src->len;
		while (padding--)
			tmp[src->len++] = '0';
	}
	if (src->sign != '-' && src->plus)
		src->sign = '+';
	while (src->len - 1 >= 0)
		res[i++] = tmp[(src->len)-- - 1];
	res[i] = '\0';
	src->len = i;
	padding = ft_ternary_subtraction(src->width, src->len);
	if (src->sign == '-' || src->sign == '+')
		padding -= 1;
	if (src->space && n >= 0)
		write_buf_char(' ', NULL, buf);
	if ((src->sign == '-' || src->sign == '+') && src->pad_char == '0')
		write_buf_char(src->sign, NULL, buf);
	if (!src->left_align && padding > 0)
	{
		while (padding--)
			write_buf_char(src->pad_char, NULL, buf);
	}
	if ((src->sign == '-' || src->sign == '+') && src->pad_char != '0')
		write_buf_char(src->sign, NULL, buf);
	i = 0;
	while (i < src->len && res[i])
		write_buf_char(res[i++], NULL, buf);
	if (src->left_align && padding > 0)
	{
		while (padding--)
			write_buf_char(' ', NULL, buf);
	}
}
