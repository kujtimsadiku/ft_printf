#include "ft_printf.h"

int		ft_hex_len(unsigned int u)
{
	int	len;

	len = 0;
	while (u != 0)
	{
		u = u / 16;
		len++;
	}
	return (len);
}

void	ft_check_hex(t_data *ap, char c, unsigned int u)
{
	if (u != 0 && ap->hash)
	{
		if (c == 'x')
			ap->capitals = 0;
		else if (*str == 'X')
			ap->capitals = 16;
	}
}

// char *ft_convert_to_hex(t_data *ap, unsigned int u)
// {
// 	char *str;
// 	unsigned int	len;

// 	len = ft_hex_len(u);
// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	ap->base = 16;
// 	while ()
// }

void ft_helper(t_data *ap, const char *p)
{
	if (ap->hash)
	{
		ap->length -= 2;
		if (ap->num && ap->zero)
		{
			while ()
		}
	}
	else
}

int	ft_printhex(t_data *ap, char *str, unsigned int u)
{
	char		buf[MAXBUF];
	char		*p;
	static char digits[32];

	ft_strncpy(digits, "0123456789abcdef0123456789ABCDEF", 32);
	p = &buf[MAXBUF - 1];
	if (u == 0)
		return (write(1, "0", 1));
	ft_check_hex(ap, *str, u);
	while (u != 0)
	{
		*p-- = digits[(u % ap->base) + ap->capitals];
		u /= ap->base;
	}
	ap->number = (&buf[MAXBUF - 1] - p);
	ft_helper(ap, p);
	return (ft_hex_len(u));
}