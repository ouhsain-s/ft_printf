/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:25:14 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/14 12:16:09 by souhsain         ###   ########.fr       */
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

int	ft_printf(const char *specifiers, ...)
{
	va_list	args;
	int		count;
	int		check_result;
	int		sum;

	if (!specifiers)
		return (-1);
	va_start(args, specifiers);
	sum = 0;
	count = 0;
	while (specifiers[count] != '\0')
	{
		if (specifiers[count] == '%' && specifiers[count + 1] != '\0')
		{
			check_result = check_is_specifier(specifiers[++count], args);
			if (check_result < 0)
				return (va_end(args), -1);
			sum += check_result;
		}
		else
			sum += write(1, &specifiers[count], 1);
		count++;
	}
	return (va_end(args), sum);
}
