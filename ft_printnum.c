#include "ft_printf.h"

int	ft_printulong(t_data *data, uintptr_t u, int base)
{
	static char	digits[MAXBUF];
	char		*build;
	int			length;

	ft_strcpy(digits, "0123456789abcdef0123456789ABCDEF");
	build = &digits[MAXBUF - 1];
	length = 0;
	if (u == 0 && data->flags.altfmt)
		return (write(1, "0", 1));
	while (u != 0)
	{
		*build-- = digits[u % base + data->capitals];
		u /= base;
	}
	build++;
	length += ft_printstr(data, &(*build));
	return (length);
}

bool	ft_checkbits(t_data *data, long long num)
{
	if (data->bits == 8)
		return ();
	else if (data_bits)
	else if (data_bits)
	else if (data_bits)
	else
		return (0);
}

int	ft_printint(t_data *data, long num)
{
	char	*numstr;
	int		length;

	numstr = ft_itoa(num);
	if (num < 0)
	{
		if (data->flags.plus_sign != 0)
			data->flags.plus_sign = 0;
	}
	length = ft_printstr(data, numstr);
	ft_free(numstr, length);
	return (length);
}