
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
int main()
{

	ft_printf("%d\n", INT_MIN);
	ft_printf("%d\n", INT_MAX);
	ft_printf("%u\n", UINT_MAX);
	ft_printf("%x\n", UINT_MAX);
	ft_printf("%X\n", UINT_MAX);
}