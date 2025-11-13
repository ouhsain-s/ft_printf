/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:09:54 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/13 15:51:47 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int putnbr(unsigned int n)
{
	char	c;
    int count;

    count = 0;
	if(n > 9)
		count = putnbr(n / 10);
	c = (n % 10) + '0';
	return (count + write(1, &c, 1));
}
int	print_unsignednum(va_list arg)
{
	unsigned	num;
    
	num = va_arg(arg, unsigned int);
	return(putnbr(num));
}

int	print_signednum(va_list arg)
{
	int num;
	int count;

	count = 0;
	num = va_arg(arg, int);
    
    if(num == -2147483648)
		return (write(1 ,"-2147483648", 11));
	if (num < 0)
	{
		count += write(1,"-", 1);
		num *= -1;
	}
	return(putnbr(num) + count);
}