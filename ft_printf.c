/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:25:14 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/13 17:00:34 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check_is_specifier(char specifier, va_list args)
{
	char *s;
	char c;
	int l;
	
	if (specifier == 'c')
		return (c = va_arg(args, int), write(1, &c, 1));
	if (specifier == 's')
	{
		if (!(s = va_arg(args, char *)))
			s = "(null)";
		return (write(1, s, ft_strlen(s)));
	}
	if (specifier == 'd' || specifier == 'i')
		return(print_signednum(args));
	if (specifier == 'u')
		return (print_unsignednum(args));
	if (specifier == 'x' || specifier == 'X')
		return (print_as_hex(args, specifier));
	if (specifier == 'p')
		return(print_hex_address(args));
	if (specifier == '%')
		return(write(1, "%", 1));
	return(write(1, "%", 1) + write(1, &specifier, 1));
}

int ft_printf(const char  *specifiers, ...)
{
	va_list args;
	int count;
	int check_result;
	int	sum;
	
	if (!specifiers)
		return (-1);
	va_start(args, specifiers);
	sum = 0;
	count = 0;
	while (specifiers[count] != '\0')
	{
		if(specifiers[count] == '%'&& specifiers[count + 1] != '\0')
		{
			sum += check_result = check_is_specifier(specifiers[++count], args);
			if(check_result < 0)
				return(va_end(args), -1);
		}
		else
			sum += write(1, &specifiers[count], 1);
		count++;
	}
	return (va_end(args), sum);
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int main(void)
{
    int i = 42;
    unsigned int u = 3000000000U;
    void *p = &i;
    char *s = "Hello, world!";
    char c = 'A';

    // ==== %c ====
    ft_printf("Test %%c normal: %c\n", c);
    ft_printf("Test %%c zero: %c\n", '\0');

    // ==== %s ====
    ft_printf("Test %%s normal: %s\n", s);
    ft_printf("Test %%s empty: %s\n", "");
    ft_printf("Test %%s NULL: %s\n", (char *)NULL);

    // ==== %p ====
    ft_printf("Test %%p non-NULL: %p\n", p);
    ft_printf("Test %%p NULL: %p\n", NULL);

    // ==== %d / %i ====
    ft_printf("Test %%d positive: %d\n", i);
    ft_printf("Test %%d negative: %d\n", -i);
    ft_printf("Test %%i zero: %i\n", 0);
    ft_printf("Test %%d INT_MAX: %d\n", INT_MAX);
    ft_printf("Test %%d INT_MIN: %d\n", INT_MIN);

    // ==== %u ====
    ft_printf("Test %%u zero: %u\n", 0U);
    ft_printf("Test %%u large: %u\n", u);

    // ==== %x / %X ====
    ft_printf("Test %%x lower small: %x\n", 3735928559U);
    ft_printf("Test %%X upper small: %X\n", 3735928559U);
    ft_printf("Test %%x zero: %x\n", 0U);

    // ==== %% ====
    ft_printf("Test %% percent: %%\n");

    return 0;
}