#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>

// # define OCTAL
// # define HEX

typedef struct	s_data
{
	va_list args;
	int		width;
	int		zero;
	int		prc;
	int		point;
	int		dash;
	int		space;
	int		skip;
}				t_data;

typedef struct	s_args
{
	va_list args;
}				t_args;


int ft_putstr_int(char *str);
int	ft_printstr(char *str);
int	ft_printnum(int nbr);
int	ft_format(t_data *data, const char *format, int i);
int	ft_printchr(int c);
int	ft_printf(const char *format, ...);
int	ft_printspace(t_data *data, char *nbr, int i);
void	ft_init_add(t_data *data);



#endif