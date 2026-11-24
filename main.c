#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	ft_printf("ft_printf 1 :%x\n", 16);

	printf("printf 2 :%x\n", 16);
	fflush(stdout);

	ft_printf("ft_printf 3 :%x\n", 4565);

	printf("printf 4 :%x\n", 4565);
	fflush(stdout);
}