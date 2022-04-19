#include "ft_printf.h"

void	ft_init_add(t_data *data)
{
	data->space = 0;
	data->sign = 0;
	data->number = 0
	data->dash = FALSE;
	data->hash = FALSE;
	data->space = FALSE;
	data->zero = FALSE;
	data->num = FALSE;
	// data->width = 0;
	// data->skip = 0;
}

int	ft_specifier(t_data *ap, const char *format, int i)
{
	i += ft_flags(ap, &format[i]);
	i += ft_width(ap, &format[i]);
	i += ft_precision(ap, &format[i]);
	i += ft_length(ap, &format[i]);
	if (format[i] == 'c')
		ap->width += ft_printchr(ap, va_arg(ap->args, int));
	else if (format[i] == 's')
		ap->width += ft_printstr(ap, va_arg(ap->args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		ap->width += ft_printint(ap, va_arg(ap->args, int));
	else if (format[i] == 'p')
		ap->width += ft_printadr(ap, va_arg(ap->args, unsigned long long));
	else if (format[i] == 'u')
		ap->width += ft_printfu(ap, va_arg(ap->args, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
		ap->width += ft_printhex(ap, va_arg(ap->args, unsigned int));
	else if (format[i] == 'o')
		ap->width += ft_printoct(ap, va_arg(ap->args, unsigned int));
	else if (format[i] == '%')
		i += write(1, "%%", 1);
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
			ft_init_add(&data);
			i = ft_specifier(&data, format, i + 1);
		}
		else
			data.width += write(1, &format[i], 1);
		i++;
	}
	va_end(data.args);
	return (data.width);
}