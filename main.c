#include "ft_printf.h"

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