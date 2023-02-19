#include "ft_printf.h"

void	ft_init_add(t_data *data)
{

	data->sign = 0;
	data->base = 0;
	data->width = 0;
	data->len = 0;
	data->base = 10;
	data->capitals = 0;
	data->bits = 0;
	data->null_c = false;
	data->flags.num = 0;
	data->flags.ladjust = false; //'-'
	data->flags.altfmt = false; //'#'
	data->flags.is_digit = false; //isdigit
	data->flags.altfmtcapital = NULL;
	data->flags.zero = 0;
	data->flags.plus_sign = 0;
	data->flags.padc = ' ';
}

static int	ft_specifier2(t_data *ap, const char *format, int i)
{
	i += ft_flags(ap, (char *)&format[i]);
	i += ft_padwidth(ap, (char *)&format[i]);
	// i += ft_precision(ap, (char *)&format[i]);
	i += ft_modifier(ap, (char *)&format[i]);
	ft_hexchecker(ap, format, i);
	return (i);
}

int	ft_specifier(t_data *ap, const char *format, int i)
{
	i = ft_specifier2(ap, format, i);
	if (format[i] == 'c')
		ap->width += ft_printchr(ap, va_arg(ap->args, int));
	else if (format[i] == 's')
		ap->width += ft_printstr(ap, va_arg(ap->args, char *));
	else if (format[i] == 'd' || format[i] == 'i') // %i makes hex, oxtal to and integer value otherwise its same as decimal
		ap->width += ft_print_int(ap, va_arg(ap->args, int)); // avaa printnumissa
	else if (format[i] == 'p')
		ap->width += ft_print_u(ap, va_arg(ap->args, unsigned long long), 16); // avaa printnumissa
	else if (format[i] == 'u')
		ap->width += ft_print_u(ap, va_arg(ap->args, unsigned int), 10); // 
	else if (format[i] == 'x' || format[i] == 'X')
		ap->width += ft_print_u(ap, va_arg(ap->args, unsigned int), 16);
	// else if (format[i] == 'o') // base 8
		// ap->width += ft_print_u(ap, va_arg(ap->args, unsigned int), 8);
	else if (format[i] == '%')
		ap->width += write(1, "%%", 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	t_data	data;

	i = 0;
	ret = 0;
	data.width = 0;
	va_start(data.args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_init_add(&data); //bzero(&data, sizeof(data))
			i = ft_specifier(&data, format, i + 1);
		}
		else
			data.width += write(1, &format[i], 1);
		i++;
	}
	va_end(data.args);
	return (data.width);
}