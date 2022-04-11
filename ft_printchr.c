#include "ft_printf.h"

int	ft_printchr(int c)
{
	return (write(1, &c, 1));
}