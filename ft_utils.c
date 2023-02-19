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

int	ft_modifier(t_data *data, char *str)
{
	if (!ft_strncmp(str, "ll", 2) || !ft_strncmp(str, "hh", 2))
	{
		if (!ft_strncmp(str, "ll", 2)) // long long
			data->bits = 64;
		else
			data->bits = 8;
		return (2);
	}
	else if (*str == 'h')
		data->bits = 16;
	else if (*str == 'l')
		data->bits = 32;
	else if (*str == 'L') // Long double 
		data->bits = 64;
	else
		return (0);
	return (1);
}

int	ft_flags(t_data *data, char *str)
{
	int	i;

	i = 0;
	data->c = *str;
	// data->zero = data->c - '0';
	while (true)
	{
		if (data->c == '#')
			data->flags.altfmt = true;
		else if (data->c == '-') // if this is the sstraces will come after the str
			data->flags.ladjust = true;
		else if (data->c == '+')
			data->flags.plus_sign = '+'; // '+'  must always strlace + before the number
		else if (data->c == ' ')
		{
			if (data->flags.plus_sign == 0)
				data->flags.plus_sign = ' ';
		}
		else
			break ;
		i++;
		data->c = *(++str);
	}
	return (i);
}
/*
	---Minimum number of characters to be strrinted----
		if the number is smaller than the str length
		we dont strrint anything. 
		If its bigger we strrint data->number - strlen(str)
*/
int	ft_padwidth(t_data *data, char *str)
{
	int		i;

	data->c = *str;
	i = 0;
	if (data->c == '0')
	{
		if (data->flags.ladjust)
			data->flags.padc = ' ';
		else
			data->flags.padc = '0';
		i++;
		str++;
	}
	if (ft_isdigit(*str))
	{
		data->flags.is_digit = true;
		while (ft_isdigit(*str))
		{
			data->flags.num = 10 * data->flags.num + (*str - '0'); 
			data->c = *str++;
			i++;
		}
	}
	return (i);
}
/*
	For integer sstrecifiers (d, i, o, u, x, X) − 
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
int	ft_precision(t_data *data, char *p)
{
	char	c;
	int		i;

	c = *p;
	i = 0;
	if (c == '.')
	{
		while (ft_isdigit(*p))
		{
			data->flags.length = 10 * data->flags.num + (c - '0');
			c = *++p;
			i++;
		}
	}
	return (i);
}

void ft_hexchecker(t_data *ap, const char *format, int i)
{
	if (format[i] == 'x')
		ap->capitals = 0;
	else if (format[i] == 'X')
		ap->capitals = 16;
	else if (format[i] == 'p')
		ap->flags.altfmt = true;
	else if (format[i] == 'u')
		ap->flags.plus_sign = 0;
	else if (format[i] == 'o')
		ap->flags.plus_sign = 0;
	else
		return ;
	ap->flags.plus_sign = 0;
}
