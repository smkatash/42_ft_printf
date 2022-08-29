/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:00:25 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/13 22:37:01 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_allflags(t_format *tab, t_placeholder *holder)
{
	char	*ptr;

	if (!holder->prefix)
		holder->prefix = ft_strdup("");
	while (ft_strrchr("-0# +", tab->format[tab->first]))
	{
		if (tab->format[tab->first] == '-')
			holder->justify = 1;
		if (ft_strrchr("# +", tab->format[tab->first]))
		{
			ptr = holder->prefix;
			holder->prefix = ft_pref_transform(ptr, tab->format[tab->first]);
			free (ptr);
		}
		if (tab->format[tab->first] == '0')
			holder->padding = '0';
		tab->first++;
	}
}

static void	ft_check_width(t_format *tab, t_placeholder *holder)
{
	int	width;

	width = holder->width;
	if (tab->format[tab->first] == '*')
	{
		width = (int)va_arg(tab->args, int);
		if (width < 0)
		{
			holder->justify = 1;
			width *= -1;
		}
		tab->first++;
	}
	else if (ft_isdigit(tab->format[tab->first]))
	{
		width = 0;
		while (ft_isdigit(tab->format[tab->first]))
		{
			width = (width * 10) + (tab->format[tab->first] - '0');
			tab->first++;
		}
	}
	holder->width = width;
}

static void	ft_check_precision(t_format *tab, t_placeholder *holder)
{
	int	precision;

	precision = holder->precision;
	if (tab->format[tab->first] == '.')
	{
		tab->first++;
		if (tab->format[tab->first] == '*')
		{
			precision = (int)va_arg(tab->args, int);
			tab->first++;
		}
		else if (!ft_isdigit(tab->format[tab->first]))
			precision = 0;
		else
		{
			precision = 0;
			while (ft_isdigit(tab->format[tab->first]))
			{
				precision = (precision * 10) + (tab->format[tab->first] - '0');
				tab->first++;
			}
		}
	}
	holder->precision = precision;
}

static void	ft_check_type(t_format *tab, t_placeholder *holder)
{
	if (!ft_strrchr("-0# +123456789*", tab->format[tab->first]) \
	&& ft_isprint(tab->format[tab->first]))
	{
		holder->type = tab->format[tab->first];
		tab->first++;
	}
}

void	*ft_parse_data(t_format *tab, t_placeholder *holder)
{
	char	*flags;

	flags = "-0# +123456789*";
	ft_check_allflags(tab, holder);
	ft_check_width(tab, holder);
	ft_check_precision(tab, holder);
	ft_check_type(tab, holder);
	if (!holder->type && (ft_strrchr(flags, tab->format[tab->first])))
		ft_parse_data(tab, holder);
	return (holder);
}
