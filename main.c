/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:36:10 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/03 18:36:12 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*
Função de teste pessoal: compara a saída e o valor de retorno da ft_printf 
com os da printf original da libc, usando %s e %x.
*/
int	main(void)
{
	int	my_return;
	int	original_return;

	my_return = ft_printf("My printf: Hello %s!\n", "World");
	original_return = printf("Original : Hello %s!\n", "World");
	printf("Returns -> Mine: %d | Original: %d\n\n",
		my_return, original_return);
	my_return = ft_printf("My printf Hex: %x\n", 255);
	original_return = printf("Original Hex : %x\n", 255);
	printf("Returns -> Mine: %d | Original: %d\n", my_return, original_return);
	return (0);
}
