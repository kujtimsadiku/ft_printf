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

int	ft_modifier(t_data *ap, char *p)
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
	else if (c == 'h')
		ap->bytes = 16;
	else if (c == 'l')
		ap->bytes = 32;
	else if (c == 'L')
		ap->bytes = 64;
	else
		return (0);
	return (1);
}

int	ft_flags(t_data *ap, char *p)
{
	int	i;

	i = 0;
	ap->c = *p;
	ap->zero = ap->c - '0';
	while (1)
	{
		if (ap->c == '#')
			ap->stat.altfmt = TRUE;
		else if (ap->c == '-') // if this is the spaces will come after the str
			ap->stat.ladjust = TRUE;
		else if (ap->c == '+')
			ap->plus_sign = '+';
		else if (ap->c == ' ')
			if (ap->plus_sign == 0)
				ap->plus_sign = ' ';
		else
			break ;
		i++;
		ap->c = *(++p);
	}
	return (i);
}
/*
	---Minimum number of characters to be printed----
		if the number is smaller than the str length
		we dont print anything. 
		If its bigger we print ap->number - strlen(str)
*/
int	ft_width(t_data *ap, char *p)
{
	int		i;

	ap->c = *p;
	i = 0;
	if (ap->c = '0')
	{
		if (ap->stat.ladjust)
			ap->padc = ' ';
		else
			ap->padc = '0';
		p++;
	}
	if (ft_isdigit(*p))
	{
		ap->stat.is_digit = TRUE;
		while (ft_isdigit(*p))
		{
			ap->num = 10 * ap->num + (*p - '0'); 
			// c = *++p;
			ap->c = *p++;
			i++;
		}
	}
	return (i);
}
/*
	For integer specifiers (d, i, o, u, x, X) − 
	precision specifies the minimum number of digits to be written. 
	If the value to be written is shorter than this number, 
	the result is padded with leading zeros. 
	The value is not truncated even if the result is longer. 
	A precision of 0 means that no character is written for the value 0. 
	For e, E and f specifiers − this is the number of digits to be printed after the decimal point. 
	For g and G specifiers − This is the maximum number of significant digits to be printed.
	For s − this is the maximum number of characters to be printed. 
	By default all characters are printed until the ending null character is encountered. 
	For c type − it has no effect. When no precision is specified, the default is 1. 
	If the period is specified without an explicit value for precision, 0 is assumed.
*/
int	ft_precision(t_data *ap, char *p)
{
	char	c;
	int		i;

	c = *p;
	i = 0;
	if (c == '.')
	{
		while (ft_isdigit(*p))
		{
			ap->num = 10 * ap->num + (c - '0');
			c = *++p;
			i++;
		}
	}
	return (i);
}

/*
	If the ap->zero is true then we will add 0 as much as the ap->number - len is;
*/