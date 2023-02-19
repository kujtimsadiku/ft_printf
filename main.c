// #include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

int main(void)
{
	// char num[] = {2, 0, 0, 3, 4, 0, 3};
	// // int num2 = -324234;
	// int i = 0;
	// int index = 0;
	// // char c = 0;
	// // char *str = "HelloWorld";

	// // i = ft_printf("My ft_printf: %3s\n", str);
	// // ft_printf("%d\n", i);
	// // printf("\n");

	// while (index < 7)
	// {
	// 	i += ft_printf("%30d", num[index]);
	// 	index++;
	// }
	// ft_printf("\n%d", i);
	// ft_printf("%60c", 'E');
	// printf("%010s", "\0");

	// ft_printf("%+ d\n", 128);

	char *str = "Hello world";
	ft_printf("%p\n", &str);
	printf("%p", &str);
	// printf("%lx\n", 4294967294);
	return (0);
}