/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:45:24 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/23 17:47:26 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define __CONVERTER "cspdiuxX%"

int		ft_printf(const char *format, ...);
int		type(va_list args, const char c, size_t len);
int		ptrdef(long a, char *base);
char	*ft_itoa(int n);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(const int n);
int		ft_putnbrbase(long n, char *base);
int		ft_putptrbase(unsigned long n, char *base);
char	*ft_itoa(int n);
// long	ft_strlen(char *str);

#endif