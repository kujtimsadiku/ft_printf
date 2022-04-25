#include "ft_printf.h"

int		ft_hex_len(unsigned int u)
{
	int	len;

	len = 0;
	while (u != 0)
	{
		u = u / 16;
		len++;
	}
	return (len);
}

/*
	0. Build number
	1. Minus from length the lenght of string
	2. Minus from length: sign and prefix
	3. Print spaces for length
	4. Print sign (comes from %d %i) print_signed(){	sign = - / +	}
	5. Print prefix
	6. Print zeros
	7. Print number from build num
	8. Print ladjust spaces
*/
