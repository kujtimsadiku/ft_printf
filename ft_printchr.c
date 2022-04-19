#include "ft_printf.h"

int	ft_printchr(t_data *ap, int c)
{
	int	len;
	int	i;
	char chr;
	
	i = 0;
	if (ap->zero)
		i = ft_printwidth(ap, 1);
	else if (ap->num)
		i = ft_printwidth(ap, 1);
	i += write(1, &c, 1);
	return (i);
}