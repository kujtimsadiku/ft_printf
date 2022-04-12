#include "ft_printf.h"

int	ft_printspace(t_data *data, char *nbr, int i)
{
	int space;
	int length;

	length = 0;
	space = ft_atoi(&nbr[i]);
	data->skip = ft_intlen(space);
	while (space != 0)
	{
		length += write(1, " ", 1);
		space--;
	}
	return (length);
}

#include "ft_printf.h"

/*
	hh = For integer types, causes printf to expect an int-sized 
	integer argument which was promoted from a char.

	h = For integer types, causes printf to expect an int-sized 
	integer argument which was promoted from a short.

	l = For integer types, causes printf to expect a long-sized integer argument.
	For floating point types, this is ignored.
	float arguments are always promoted to double when used in a varargs call.

	ll = For integer types, causes printf to expect a long long-sized integer argument.
	L = For floating point types, causes printf to expect a long double argument. 
	z = For integer types, causes printf to expect a size_t-sized integer argument.
*/

/*
	-----For the %04d and etc

	else if (format[i] >= '0' && format[i] <= '9')
	{
		ap->width += ft_printspace(ap, (char *)format, i);
		ft_format(ap, format, i + ap->skip);
	}
*/
int	ft_modifier(t_data *ap, const char *p)
{
	char	c;

	c = *p;
	if (!ft_strncmp(p, "ll", 2) || !ft_strncmp(p, "hh", 2))
	{
		if (!ft_strncmp(p, "ll", 2))
			ap->bytes = 64;
		else
			ap->bytes = 8;
		return (2);
	}
	if (c == 'h')
		ap->bytes = 16;
	else if (c == 'l')
		ap->bytes = 32;
	else if (c == 'L')
		ap->bytes = 64;
	else
		return (0);
}

int	ft_flags(t_data *ap, const char *p)
{
	char	c;

	c = *p;
	if (c == '#')
		ap->hash = TRUE;
	else if (c == '-')
		ap->dash = TRUE;
	else if (c == '+')
		ap->space = ' ';
	else if (c == ' ')
		ap->space = TRUE
	else
		return (0);
	return (1);
}