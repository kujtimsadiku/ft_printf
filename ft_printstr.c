#include "ft_printf.h"

/*
**	static function that is used only when ft_printstr is called.
**	prints the str and return the lenght of the str for our p_lenght
*/
// int ft_putstr_int(t_data *ap, char *str)
// {
// 	return (write(1, str, ft_strlen(str)));
// }

int	ft_printstr(t_data *ap, char *str)
{
	int	width;

	width = 0;
	if (ap->zero == TRUE || ap->num == TRUE)
		width += ft_printpad(ap, ft_strlen(str));
	if (str == NULL || str == "" || *str == '\0')
		return (write(1, "", 0));
	else
		width += write(1, str, ft_strlen(str));
	return (width);
}
