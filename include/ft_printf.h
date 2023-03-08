/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:09:40 by ksadiku           #+#    #+#             */
/*   Updated: 2023/03/03 17:19:59 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define MAXBUF 64

typedef struct s_flags
{
	bool	ladjust;
	bool	is_digit;
	bool	altfmt;
	bool	add_sign;
	int		num;
	int		prec;
	char	plus_sign;
	char	padc;
}				t_flags;

typedef struct s_data
{
	t_flags			flags;
	va_list			args;
	int				length;
	int				width;
	int				bits;
	int				capitals;
	int				pads_used;
	int				base;
	char			sign_c;
	char			*prefix;
	char			*build;
	bool			null_c;
	bool			ptr_addr;
	bool			its_prec;
}					t_data;

typedef struct s_args
{
	va_list		args;
}				t_args;

int		ft_printf(const char *format, ...);
void	ft_init_add(t_data *data);

int		ft_specifier(t_data *ap, const char *format, int i);
int		ft_flags(t_data *data, char *str);
int		ft_padwidth(t_data *data, char *str);
int		ft_modifier(t_data *data, char *str);

void	ft_hexchecker(t_data *ap, const char *format, int i);
void	ft_prefix(t_data *data);
int		ft_itsptr(t_data *data, unsigned long long u);

int		ft_print_int(t_data *data, long long num);
void	ft_typecast(t_data *data, long long *num);
int		ft_print_u(t_data *data, unsigned long long u, int base);
void	ft_typecast_u(t_data *data, unsigned long long *num);

int		ft_printstr(t_data *data, char *str);
int		ft_flag_print(t_data *data, char *str, int (*putc)(char));
int		ft_printstr_helper(t_data *data, char *str);
int		ft_putc(char c);

int		ft_printchr(t_data *data, int c, int (*putc)(char));
int		ft_printpads(t_data *data, int c);

int		ft_printnumber(t_data *data, char *num, int (*putc)(char));
int		ft_printint(t_data *data, char *num, int (*putc)(char));

#endif