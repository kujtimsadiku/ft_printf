#include "ft_printf.h"

int	ft_print_signed(t_data *ap, int nbr, int base)
{

}

int	ft_print_unsigned(t_data *ap, unsigned int nbr, int base)
{

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

int	ft_savenum(t_data *ap, unsigned int u, int base)
{
	char		buf[MAXBUF];
	char		*p;
	static char digits[32];

	ft_strncpy(digits, "0123456789abcdef0123456789ABCDEF", 32);
	p = &buf[MAXBUF - 1];
	while (u != 0)
	{
		*p-- = digits[(u % ap->base) + ap->capitals];
		u /= ap->base;
	}
	ap->len = (&buf[MAXBUF - 1] - p);
	return ();
}