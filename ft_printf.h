#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>

// # define OCTAL
// # define HEX
# define TRUE 1
# define FALSE 0
# define MAXBUF 64

typedef struct	s_data
{
	bool	space;
	bool	dash;
	bool	hash;
	bool	zero;
	bool	num;
	va_list args;
	int		prec;
	int		number;
	int		length;
	int		width;
	int		asterik;
	int		skip;
	int		bytes;
	int		sign;

}				t_data;

typedef struct	s_args
{
	va_list args;
}				t_args;

int	ft_printstr(t_data *ap, char *str);
int	ft_printnum(int nbr);
int	ft_format(t_data *data, const char *format, int i);
int	ft_printchr(t_data *ap, int c);
int	ft_printf(const char *format, ...);
int	ft_printspace(t_data *data, char *nbr, int i);
void	ft_init_add(t_data *data);
int	ft_flags(t_data *ap, char *p);
int	ft_width(t_data *ap, char *p);
int ft_precision(t_data *ap, char *p);
int	ft_length(t_data *ap, char *p);



#endif