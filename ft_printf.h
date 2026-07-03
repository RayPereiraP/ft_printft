/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:36:01 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/03 18:47:28 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int     ft_printf(const char *format, ...);
int     ft_check_flag(char c, va_list args);
char    *ft_strchr(const char *s, int c);
int     ft_putchar_count(char c);
int     ft_putstr_count(char *str);
int     ft_putptr_count(void *ptr);
int     ft_putnbr_count(int c);
int     ft_putunsigned_count(unsigned int a);
int     ft_puthex_count(unsigned int n, char format);
int     ft_putptr_recursive(unsigned long n);

#endif