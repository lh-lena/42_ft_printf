#include "ft_printf.h"

void	printf_format(char specifier, va_list *args, t_format *src, t_buffer *buf)
{
	src->specifier = specifier;
	update_t_printf(src);
	if (specifier == 'c')
		write_buf_char(va_arg(*args, int), src, buf);
	else if (specifier == 's')
		formating_str(va_arg(*args, char *), src, buf);
	else if (specifier == 'd')
		formating_digit(va_arg(*args, int), src, buf);
	else if (specifier == 'u')
		formating_digit(va_arg(*args, unsigned int), src, buf);
	else if (specifier == 'i')
		formating_digit(va_arg(*args, int), src, buf);
	else if (specifier == 'x' || specifier == 'X')
		formating_hex(va_arg(*args, unsigned int), src, buf);
	else if (specifier == 'p')
		formating_ptr(va_arg(*args, void *), src, buf);
	else if (specifier == '%')
		write_buf_char(specifier, NULL, buf);
}

void	parse_flags(const char **f, t_format *src)
{
	while (**f && (**f == '-' || **f == '0' || **f == '+' || **f == ' ' || **f == '#'))
	{
		if (**f == '-')
			src->left_align = 1;
		if (**f == '0')
			src->zero_pad = 1;
		if (**f == '+')
			src->plus = 1;
		if (**f == ' ')
			src->space = 1;
		if (**f == '#')
			src->hash = 1;
		(*f)++;
	}
}

void	parse_format(const char **f, t_format *src)
{
	parse_flags(f, src);

	if (**f && **f != '.' && **f != '0')
	{
		while (**f && **f >= '0' && **f <= '9')
		{
			src->width = src->width * 10 + (**f - '0');
			(*f)++;
		}
	}

	if (**f == '.')
	{
		(*f)++;
		src->precision = 0;
		while (**f >= '0' && **f <= '9' && **f)
		{
			src->precision = src->precision * 10 + (**f - '0');
			(*f)++;
		}
	}
}
