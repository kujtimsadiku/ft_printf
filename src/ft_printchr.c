/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:25 by ksadiku           #+#    #+#             */
/*   Updated: 2023/02/20 19:12:18 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printpads(t_data *data)
{
	int		len;

	len = 0;
	while (data->length-- > 0)
		len += write(1, &(data->flags.padc), 1);
	return (len);
}

int	ft_printchr(t_data *data, int c)
{
	int		len;

	len = 0;
	data->length = data->flags.num - 1;
	if (!data->flags.ladjust && data->length > 1)
		len += ft_printpads(data);
	len += write(1, &c, 1);
	if (data->flags.ladjust && data->length > 1)
		len += ft_printpads(data);
	return (len);
}
