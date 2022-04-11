#include "ft_printf.h"

/*
**	static function that is used only when ft_printstr is called.
**	prints the str and return the lenght of the str for our p_lenght
*/
int ft_putstr_int(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_printstr(char *str)
{
	if (str == NULL)
		return (ft_putstr_int("(null)"));
	return (ft_putstr_int(str));
}
