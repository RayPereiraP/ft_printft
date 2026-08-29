/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:35:51 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/03 18:46:13 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

/*
procura o caractere c dentro da string s e retorna o 
endereco da primeira ocorrencia, ou NULL.
*/
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

/*
Despachante: recebe o especificador (c) e a lista de argumentos variadicos
ainda nao consumidos, e chama a funcao de impressao correspondente e finaliza
retornando quantos caracteres foram escritos
*/
int	ft_check_flag(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_count(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr_count(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putptr_count(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_count(va_arg(args, int));
	else if (c == 'u')
		count += ft_putunsigned_count(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_puthex_count(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		count += ft_puthex_count(va_arg(args, unsigned int), 'X');
	else if (c == '%')
		count += ft_putchar_count('%');
	return (count);
}

/*
Funcao principal: percorre a string de formato caractere por caractere, 
delega especificadores validos ao ft_check_flag, e faz a imprissão de caracteres
comuns diretamente e retorna o total de caracteres escritos, = ao printf orig
*/
int	ft_printf(const char *format, ...)
{
	int		chars;
	va_list	args;

	chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			if (ft_strchr("cspdiuxX%", *format))
				chars += ft_check_flag(*format, args);
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
