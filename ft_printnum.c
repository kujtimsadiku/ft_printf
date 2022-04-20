#include "ft_printf.h"

// int	ft_printspace(t_data *data, char *nbr, int i)
// {
// 	int space;
// 	int length;
// 	// char *temp;

// 	length = 0;
// 	space = ft_atoi(&nbr[i]);
// 	data->skip = ft_intlen(space);
// 	while (space != 0)
// 	{
// 		length += write(1, " ", 1);
// 		space--;
// 	}
// 	return (length);
// }

// int	ft_printnum(int nbr)
// {
// 	int		width;
// 	char	*nbrstr;

// 	nbrstr = ft_itoa(nbr);
// 	width = ft_printstr(nbrstr, ft_strlen(nbrstr));
// 	free(nbrstr);
// 	return (width);
// }

int	ft_print_signed(t_data *ap)
{

}

int	ft_print_unsigned(t_data *ap)
{

}

int	ft_printnum(t_data *ap)
{
	char buf[MAXBUF];
}