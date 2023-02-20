#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

// # define OCTAL
// # define HEX
# define MAXBUF 64 // for a long double = ll

typedef struct	s_flags
{
	bool	ladjust;
	bool	altfmt;
	bool	is_digit;
	char	*altfmtcapital;
	int		zero;
	int		length;
	int		num; // how many 0 or spaces
	char	plus_sign;
	char	padc;
}				t_flags;

typedef struct	s_data
{
	t_flags	flags;
	va_list args;
	int		prec;
	int		length;
	int		width;
	int		bits;
	int		sign;
	int		base;
	int		capitals;
	int		len;
	char	c;
	long	n;
	unsigned long	u;
	char	*prefix;
	bool	null_c;
	bool	ptr_addr;
}				t_data;

typedef struct	s_args
{
	va_list args;
}				t_args;

int	ft_printstr(t_data *data, char *str);
int	ft_printstr2(t_data *data, char *str);
void	ft_typecast_u(t_data *data, unsigned long long *num);
void	ft_typecast(t_data *data, long long *num);
int	ft_print_int(t_data *data, long long num);
int	ft_print_u(t_data *data, unsigned long long u, int base);
int	ft_check_if_ptr(t_data *data, unsigned long long u);
int	ft_format(t_data *data, const char *format, int i);
int	ft_printchr(t_data *data, int c);
int ft_printpads(unsigned int n, char c);
int	ft_printf(const char *format, ...);
int	ft_printspace(t_data *data, char *nbr, int i);
void ft_init_add(t_data *data);
int	ft_flags(t_data *data, char *p);
int	ft_padwidth(t_data *ap, char *p);
int ft_precision(t_data *data, char *p);
int	ft_modifier(t_data *data, char *p);
void ft_hexchecker(t_data *ap, const char *format, int i);



#endif