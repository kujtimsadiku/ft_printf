#include "ft_printf.h"

void	ft_init_add(t_data *data)
{
	data->width = 0;
	data->space = 0;
	data->plus = FALSE;
	data->dash = FALSE;
	data->hash = FALSE;
	data->space = FALSE;
	// data->skip = 0;
}

int	ft_format(t_data *ap, const char *format, int i)
{
	// ap->skip = 1;
	i += ft_flags(ap, &format[i])
	i += ft_modifier(ap, &format[i])
	if (format[i] == 'c')
		ap->width += ft_printchr(va_arg(ap->args, int));
	else if (format[i] == 's')
		ap->width += ft_printstr(va_arg(ap->args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		ap->width += ft_printnum(va_arg(ap->args, int));
	// else if (format == 'p')
	// 	p_lenght += ft_printadr(va_arg(args, unsigned long long));
	// else if (format == 'u')
	// 	p_lenght += ft_printfuns(va_arg(args, unsigned int));
	// else if (format == 'x' || format == 'X')
	// 	p_lenght += ft_printhex(va_arg(args, unsigned int), format);
	else if (format[i + ap->skip] == '%')
		return (write(1, "%", 1));
	return (ap->skip + i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	t_data	data;

	i = 0;
	ret = 0;
	ft_init_add(&data);
	va_start(data.args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			data.skip = 0;
			i = ft_format(&data, format, i + 1);
		}
		else
			data.width += ft_printchr(format[i]);
		i++;
	}
	va_end(data.args);
	return (data.width);
}