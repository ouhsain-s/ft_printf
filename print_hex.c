/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:13:42 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/15 21:59:45 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_bites_ashex(unsigned long num, char *index)
{
	int	count;

	count = 0;
	if (num >= 16)
		count = print_bites_ashex(num / 16, index);
	return (count + write(1, &index[num % 16], 1));
}

int	print_as_hex(va_list arg, char larg)
{
	unsigned int	num;
	char			*index;

	if (larg == 'x')
		index = "0123456789abcdef";
	else
		index = "0123456789ABCDEF";
	num = va_arg(arg, unsigned int);
	return (print_bites_ashex(num, index));
}

int	print_hex_address(va_list arg)
{
	unsigned long	num;
	void			*p;

	p = va_arg(arg, void *);
	if (!p)
		return (write(1, "(nil)", 5));
	num = (unsigned long)p;
	return (write(1, "0x", 2) + print_bites_ashex(num, "0123456789abcdef"));
}
