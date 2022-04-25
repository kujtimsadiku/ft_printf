#include "ft_printf.h"

void	ft_init_add(t_data *data)
{
	data->sign = 0;
	data->num = 0;
	data->base = 0;
	data->width = 0;
	data->len = 0;
	data->stat.ladjust = FALSE; //'-'
	data->stat.altfmt = FALSE; //'#'
	data->stat.is_digit = FALSE; //isdigit
}

int	ft_specifier(t_data *ap, const char *format, int i)
{
	i += ft_flags(ap, &format[i]);
	i += ft_width(ap, &format[i]);
	i += ft_precision(ap, &format[i]);
	i += ft_modifier(ap, &format[i]);
	if (format[i] == 'c')
		ap->width += ft_printchr(ap, va_arg(ap->args, int));
	else if (format[i] == 's')
		ap->width += ft_printstr(ap, va_arg(ap->args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		ap->width += ft_printint(ap, va_arg(ap->args, int), 10); // avaa printnumissa
	else if (format[i] == 'p')
		ap->width += ft_printadr(ap, va_arg(ap->args, unsigned long long), 16); // avaa printnumissa
	else if (format[i] == 'u')
		ap->width += ft_savenum(ap, va_arg(ap->args, unsigned int), 10); // 
	else if (format[i] == 'x' || format[i] == 'X')
		ap->width += ft_savenum(ap, &format[i], va_arg(ap->args, unsigned int), 16);
	else if (format[i] == 'o')
		ap->width += ft_savenum(ap, va_arg(ap->args, unsigned int), 8);
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