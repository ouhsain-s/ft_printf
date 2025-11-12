/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:25:14 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/12 18:01:45 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	check_is_specifier(char specifier, va_list args)
{
	char ch;
	int re;
	if(specifier == 'c')
		return ( ch = va_arg(args, int), write(1, &ch, 1));
	else
		return(write(1, "%" ,1) + write(1, &specifier, 1));
}

int ft_printf(char  *specifiers, ...)
{
	va_list args;
	int count;
	int	sum;
	
	va_start(args, specifiers);
	sum = 0;
	count = 0;
	while (specifiers[count] != '\0')
	{
		if(specifiers[count] == '%'&& specifiers[count + 1] != '\0')
		{
			sum += check_is_specifier(specifiers[++count], args);
		}
		else
		{
			sum++;
			write(1, &specifiers[count], 1);
		}
		count++;
	}
	return (sum);
}

int main()
{
	//int origin = printf("H%",16);
	int origin = printf("%",16);
	int my = ft_printf("%",16);

	 printf("|\nthis origin >> %d\n and this my >> %d\n", origin, my);
}