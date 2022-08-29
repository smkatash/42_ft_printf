/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:05:48 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/14 00:31:23 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <inttypes.h>

typedef struct s_format
{
	const char	*format;
	va_list		args;
	size_t		first;
	size_t		len;
}				t_format;

typedef struct s_placeholder
{
	int		justify;
	char	*prefix;
	int		padding;
	int		width;
	int		precision;
	char	type;
	char	*arg;
	size_t	size;
}			t_placeholder;

//Create struct for a format, called by vprintf
t_format	*ft_lstnew_format(const char *fmt, va_list args);
//Called by vprinft to create and holder struct,
// to check arguments after % sign & to convert types
void		ft_placeholder_check(t_format *tab);
//Checks the placeholder content 
void		*ft_parse_data(t_format *tab, t_placeholder *holder);
//Checks the flags and adds char into prefix holder & returns it 
char		*ft_pref_transform(char const *str, char const ch);
//Compares specifiers and converts accroding to types
void		ft_convert(t_format *tab, t_placeholder *holder);
//Allocates memory into arg holder and copies string from the va_list
//Checks for precision and justify of left and right paddings
void		ft_convert_string(t_format *tab, t_placeholder *holder);
//Defines left padding according to the passed width
void		ft_left_place(char **src, char padding, int width);
//Defines left padding according to the passed width
void		ft_right_place(char **src, char padding, int width);
//Converts int from args & applies decimal type, 
//checks for padding and for neg num through syntax conversion
void		ft_convert_num(t_format *tab, t_placeholder *holder);
//Places prefix holder according to neg/pos sign for numerical
void		ft_prefix(t_placeholder *holder, int neg);
void		ft_convert_pointer(t_format *tab, t_placeholder *holder);
//Converts hex/dec/octal arg according to passed bases into arg holder
void		ft_convert_uxo(t_format *tab, t_placeholder *holder, char *base);
int			ft_printf(const char *format, ...);

#endif
