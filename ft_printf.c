/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:25:14 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/15 17:47:43 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_is_specifier(char specifier, va_list args)
{
	char	*s;
	char	c;

	if (specifier == 'c')
		return (c = va_arg(args, int), write(1, &c, 1));
	if (specifier == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			s = "(null)";
		return (write(1, s, ft_strlen(s)));
	}
	if (specifier == 'd' || specifier == 'i')
		return (print_signednum(args));
	if (specifier == 'u')
		return (print_unsignednum(args));
	if (specifier == 'x' || specifier == 'X')
		return (print_as_hex(args, specifier));
	if (specifier == 'p')
		return (print_hex_address(args));
	if (specifier == '%')
		return (write(1, "%", 1));
	return (write(1, "%", 1) + write(1, &specifier, 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		check_result;
	int		sum;

	va_start(args, s);
	sum = 0;
	count = 0;
	if (!s || (s[0] == '%' && ft_strlen(s) < 2) || write(1, "", 0) == -1)
		return (-1);
	while (s[count] != '\0')
	{
		if (s[count] == '%' && s[count + 1] != '\0')
		{
			check_result = check_is_specifier(s[++count], args);
			if (check_result < 0)
				return (va_end(args), -1);
			sum += check_result;
		}
		else
			sum += write(1, &s[count], 1);
		count++;
	}
	return (va_end(args), sum);
}
