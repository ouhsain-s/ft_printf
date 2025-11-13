/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:30:10 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/13 13:19:07 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>

int  ft_strlen(const char *s);
int putnbr(unsigned int n);
int	print_unsignednum(va_list arg);
int	print_signednum(va_list arg);

#endif