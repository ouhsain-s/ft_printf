/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:25:14 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/13 12:27:35 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int putnbr(int n, int *count)
{
	char	c;
	
	if(n == -2147483648)
		return (*count = write(1 ,"-2147483648", 11));
	if (n < 0)
	{
		*count += write(1,"-", 1);
		n *= -1;
	}
	if(n > 9)
		putnbr(n / 10, count);
	c = (n % 10) + '0';
	return (*count += write(1, &c, 1), *count);
}
int	check_is_specifier(char specifier, va_list args)
{
	char *s;
	char c;
	int l;
	int count;
	
	count = 0;
	if (specifier == 'c')
		return (c = va_arg(args, int), write(1, &c, 1));
	if (specifier == 's')
	{
		if (!(s = va_arg(args, char *)))
			s = "(null)";
		return (l = ft_strlen(s), write(1, s, l));
	}
	if (specifier == 'd' || specifier == 'i')
		return(l = va_arg(args, int), putnbr(l, &count), count);
	else if (specifier == '%')
		return(write(1, "%", 1));
	else
		return(write(1, "%", 1) + write(1, &specifier, 1));
}

int ft_printf(char  *specifiers, ...)
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

int main(void)
{
    int origin, my;

    // 1. رقم موجب كبير
    origin = printf("1>>%d<<\n", 2147483647);
    my     = ft_printf("1>>%d<<\n", 2147483647);
    printf("| origin = %d | my = %d |\n\n", origin, my);

    // 2. رقم سالب كبير
    origin = printf("2>>%d<<\n", -2147483648);
    my     = ft_printf("2>>%d<<\n", -2147483648);
    printf("| origin = %d | my = %d |\n\n", origin, my);

    // 3. رقم صفر
    origin = printf("3>>%d<<\n", 0);
    my     = ft_printf("3>>%d<<\n", 0);
    printf("| origin = %d | my = %d |\n\n", origin, my);

    // 4. حرف عادي
    origin = printf("4>>%c<<\n", 'A');
    my     = ft_printf("4>>%c<<\n", 'A');
    printf("| origin = %d | my = %d |\n\n", origin, my);

    // 5. سلسلة عادية
    origin = printf("5>>%s<<\n", "Hello World!");
    my     = ft_printf("5>>%s<<\n", "Hello World!");
    printf("| origin = %d | my = %d |\n\n", origin, my);

    // 6. سلسلة فارغة
    origin = printf("6>>%s<<\n", "");
    my     = ft_printf("6>>%s<<\n", "");
    printf("| origin = %d | my = %d |\n\n", origin, my);

    // 7. سلسلة NULL
    origin = printf("7>>%s<<\n", NULL);
    my     = ft_printf("7>>%s<<\n", NULL);
    printf("| origin = %d | my = %d |\n\n", origin, my);

    // 8. نسبة مئوية
    origin = printf("8>>%%<<\n");
    my     = ft_printf("8>>%%<<\n");
    printf("| origin = %d | my = %d |\n\n", origin, my);

    // 9. دمج عدة أنواع
    origin = printf("9>>%s %c %d<<\n", "Test", 'X', -12345);
    my     = ft_printf("9>>%s %c %d<<\n", "Test", 'X', -12345);
    printf("| origin = %d | my = %d |\n\n", origin, my);

    // 10. سلسلة طويلة + رقم كبير
    origin = printf("10>>%s %d<<\n", "This is a very long string for testing", 987654321);
    my     = ft_printf("10>>%s %d<<\n", "This is a very long string for testing", 987654321);
    printf("| origin = %d | my = %d |\n\n", origin, my);

    return 0;
}
