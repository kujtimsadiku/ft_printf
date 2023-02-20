#include "ft_printf.h"

/*
**	static function that is used only when ft_printstr is called.
**	prints the str and return the lenght of the str for our p_lenght
*/
// int ft_putstr_int(t_data *ap, char *str)
// {
// 	return (write(1, str, ft_strlen(str)));

/*prints till the null character comes and stops and 
if there are pads to add we add those*/

int	ft_puts(t_data *data, char *str)
{
	int	width;

	width = 0;
	if (data->flags.altfmt)
	{
		if (data->capitals == 16)
			width += write(1, "0X", 2);
		else
			width += write(1, "0x", 2);
	}
	width += write(1, str, ft_strlen(str));
	return (width);
}

int ft_printstrhelper(t_data *data, char *str)
{
	int		width;

	width = 0;
	if (str == NULL && data->flags.altfmt)
		return (write(1, "0x", 2));
	if (str == NULL)
	{
		data->null_c = true;
		width += write(1, "(null)", 6);
	}
	else if (*str == '\0')
	{
		if (data->flags.is_digit)
			width += ft_printpads(data->flags.num, data->flags.padc);
	}
	return (width);
}

int	ft_printstr(t_data *data, char *str)
{
	int		width;

	width = ft_printstrhelper(data, str);
	if (data->null_c)
		return (width);
	if (data->flags.ladjust)
	{
		width += ft_puts(data, str);
		width += ft_printpads(data->flags.num - ft_strlen(str), data->flags.padc);
	}
	else if (data->flags.padc == '0')
	{
		width += ft_printpads(data->flags.num - ft_strlen(str), data->flags.padc);
		width += ft_puts(data, str);
	}
	else if (data->flags.is_digit)
	{
		width += ft_printpads(data->flags.num - ft_strlen(str), data->flags.padc);
		width += ft_puts(data, str);
	}
	else
		width += ft_printstr2(data, str);
	return (width);
}

int	ft_printstr2(t_data *data, char *str)
{
	int		width;

	width = 0;
	if (data->flags.plus_sign != 0)
	{
		width += ft_printpads(1, data->flags.plus_sign);
		width += ft_puts(data, str);
	}
	else
		width += ft_puts(data, str);
	return (width);
}
