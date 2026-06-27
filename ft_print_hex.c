#include "ft_printf.h"

int	ft_puthex_count(unsigned int n, char format)
{
	int		count;
	int 	*base;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if	(n >= 16)
		count += ft_puthex_count((n / 16), format);
	count += ft_putchar_count(base[n % 16]);
	return (count);
}

int	ft_putptr_recursive(unsigned long n)
{
	int		count;
	char 	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putptr_recursive(n / 16);
	count += ft_putchar_count(base[n % 16]);
	return (count);
}

int	ft_new_flag(void)
{
	write(1, "teste", 6);
	return (6);
}
