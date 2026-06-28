#include "ft_printf.h"
#include <stdarg.h>

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_check_flag(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_count(va_arg(args, int));
	else if (c == 's')
		count += ft_putchar_count(va_arg(args, char *));
	else if (c == 'f')
		count += ft_putchar_count(va_arg(args, void *));
	else if (c == 'd')
		count += ft_putchar_count(va_arg(args, int));
	else if (c == 'o')
		count += ft_putchar_count(va_arg(args, int));
	else if (c == 'p')
		count += ft_putunsigned_count(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_puthex_count(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		count += ft_puthex_count(va_arg(args, unsigned int), 'X');
	else if (c == '%')
		count += ft_putchar_count('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		chars;
	va_list args;

	chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			if(ft_strchr("colocar as letras do outro aqui", *format))
				chars += ft_check_flag(*format, args);
			else if (*format == 'f')
				chars += ft_new_flag();
			else 
				chars += ft_putchar_count('%') + ft_putchar_count(*format);
		}
		else if (*format == '%' && *(format + 1) == '\0')
			chars += ft_putchar_count('%');
		else 
			chars += ft_putchar_count(*format);
		format++;
	}
	va_end(args);
	return (chars);
}
