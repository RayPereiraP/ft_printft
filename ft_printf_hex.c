/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:35:36 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/03 18:50:44 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
faz a converção de um numero unsigned int para hexadecimal (base 16) e
imprime. 'format' escolhe minuscula ('x') ou maiuscula ('X').
Usa recursao para conseguir processar o resto do numero antes de imprimir o
digito atual, garantindo que a ordem impressao esteja ok
*/

#include "ft_printf.h"

int	ft_puthex_count(unsigned int n, char format)
{
	int		count;
	char	*base;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex_count((n / 16), format);
	count += ft_putchar_count(base[n % 16]);
	return (count);
}

/*
faz a converção de um endereco de memoria (unsigned long) para hexadecimal
minusculo e imprime. Usada apenas por %p, usa unsigned long pois
um ponteiro de 64 bits nao cabe garantidamente em unsigned int.
*/

int	ft_putptr_recursive(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putptr_recursive(n / 16);
	count += ft_putchar_count(base[n % 16]);
	return (count);
}
