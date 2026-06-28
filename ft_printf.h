#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_check_flag(char c, va_list args);
char	*ft_strchr(const char *s, int c);
int		ft_putchar_count(char c);
int		ft_putstr_count(char *str);
int		ft_putptr_count(void *ptr);
int		ft_putnbr_count(int c);
int		ft_putunsigned_count(unsigned int a);
int		ft_puthex_count(unsigned int n, char format);
int		ft_putptr_recursive(unsigned long n);
int		ft_new_flag(void);
#endif
