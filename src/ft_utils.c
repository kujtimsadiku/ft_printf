/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:58:03 by ksadiku           #+#    #+#             */
/*   Updated: 2023/02/21 16:32:27 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_modifier(t_data *data, char *str)
{
	if (!ft_strncmp(str, "ll", 2) || !ft_strncmp(str, "hh", 2))
	{
		if (!ft_strncmp(str, "ll", 2))
			data->bits = 64;
		else
			data->bits = 8;
		return (2);
	}
	else if (*str == 'h')
		data->bits = 16;
	else if (*str == 'l')
		data->bits = 32;
	else if (*str == 'L')
		data->bits = 64;
	else
		return (0);
	return (1);
}

int	ft_flags(t_data *data, char *str)
{
	int		i;
	char	c;

	i = 0;
	c = *str;
	while (true)
	{
		if (c == '#')
			data->flags.altfmt = true;
		else if (c == '-')
			data->flags.ladjust = true;
		else if (c == '+')
			data->flags.plus_sign = '+';
		else if (c == ' ')
		{
			if (data->flags.plus_sign == 0)
				data->flags.plus_sign = ' ';
		}
		else
			break ;
		i++;
		c = *(++str);
	}
	return (i);
}

static int	ft_width_digit(t_data *data, char *str)
{
	int		i;

	i = 0;
	if (ft_isdigit(*str))
	{
		data->flags.is_digit = true;
		while (ft_isdigit(*str))
		{
			data->flags.num = 10 * data->flags.num + (*str - '0');
			data->t_c = *str++;
			i++;
		}
	}
	else
		return (0);
	return (i);
}

int	ft_padwidth(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (*str == '0')
	{
		if (data->flags.ladjust)
			data->flags.padc = ' ';
		else
			data->flags.padc = '0';
		i++;
		str++;
		while (i + ft_flags(data, &(*str)) > i)
		{
			i++;
			str++;
		}
	}
	i += ft_width_digit(data, &(*str));
	return (i);
}

void	ft_hexchecker(t_data *ap, const char *format, int i)
{
	if (format[i] == 'x')
		ap->capitals = 0;
	else if (format[i] == 'X')
		ap->capitals = 16;
	else if (format[i] == 'p')
	{
		ap->flags.altfmt = true;
		ap->ptr_addr = true;
	}
	else if (format[i] == 'u')
		ap->flags.plus_sign = 0;
	else if (format[i] == 'o')
		ap->flags.plus_sign = 0;
	else
		return ;
	ap->flags.plus_sign = 0;
}
