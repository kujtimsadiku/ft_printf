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

int	ft_length(t_data *ap, char *p)
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
	char	c;
	int		iszero;

	c = *p;
	iszero = c - '0';
	if (c == '#')
		ap->hash = TRUE;
	else if (c == '-')
		ap->dash = TRUE;
	else if (c == '+')
		ap->sign = '+';
	else if (c == ' ')
		if (ap->sign == 0)
			ap->sign = ' ';
	else if (iszero == 0)
		ap->zero = TRUE;
	return (1);
}
/*
	---Minimum number of characters to be printed----
		if the number is smaller than the str length
		we dont print anything. 
		If its bigger we print ap->number - strlen(str)
*/
int	ft_width(t_data *ap, const char *p)
{
	// char	c;
	int		i;

	// c = *p;
	i = 0;
	if (isdigit(*p))
	{
		ap->num = TRUE;
		while (isdigit(*p))
		{
			ap->number = 10 * ap->number + (*p - '0'); 
			// c = *++p;
			*p++;
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
		while (isdigit(*p))
		{
			ap->number = 10 * ap->number + (c - '0');
			c = *++p;
			i++;
		}
	}
	return (i);
}

/*
	If the ap->zero is true then we will add 0 as much as the ap->number - len is;
*/
int	ft_printwidth(t_data *ap, int len)
{
	int	width;

	width = 0;
	if (ap->zero)
	{
		while (ap->number - len)
		{
			width += write(1, "0", 1);
			ap->number--;
		}
	}
	else if (ap->num)
	{
		while (ap->number - len)
		{
			width += write(1, " ", 1);
			ap->number--;
		}
	}
	return (width);
}
