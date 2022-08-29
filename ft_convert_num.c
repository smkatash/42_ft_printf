/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:58:21 by kanykei           #+#    #+#             */
/*   Updated: 2022/04/14 00:31:42 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hx_prefix(t_placeholder *holder)
{
	char	*str;

	str = holder->arg;
	if (ft_strrchr(holder->prefix, '#'))
	{
		if (holder->type == 'x')
			holder->arg = ft_strjoin("0x", str);
		if (holder->type == 'X')
			holder->arg = ft_strjoin("0X", str);
		if (holder->type == 'o')
			holder->arg = ft_strjoin("0", str);
		free(str);
	}
}

void	ft_prefix(t_placeholder *holder, int neg)
{
	int	i;

	i = (int)ft_strlen(holder->arg);
	if (holder->type == 'd' || holder->type == 'i')
	{
		i += 1;
		if (ft_strrchr(holder->prefix, '+') && neg == 1)
			ft_left_place(&holder->arg, '+', i);
		else if (ft_strrchr(holder->prefix, ' ') && neg == 1)
			ft_left_place(&holder->arg, ' ', i);
		else if (neg == -1)
			ft_left_place(&holder->arg, '-', i);
	}
	else if (holder->type == 'x' || holder->type == 'X' || holder->type == 'o')
		ft_hx_prefix(holder);
}

static void	ft_convert_syntax(t_placeholder *holder, int neg)
{
	if (holder->justify)
	{
		ft_prefix(holder, neg);
		ft_right_place(&holder->arg, ' ', holder->width);
	}
	else
	{
		if (holder->padding == ' ')
		{
			ft_prefix(holder, neg);
			ft_left_place(&holder->arg, holder->padding, holder->width);
		}
		else if (holder->padding == '0')
		{
			if (neg < 0 || ft_strrchr(holder->prefix, ' ') || \
			ft_strrchr(holder->prefix, '+'))
				ft_left_place(&holder->arg, holder->padding, holder->width - 1);
			else
				ft_left_place(&holder->arg, holder->padding, holder->width);
			ft_prefix(holder, neg);
		}
	}
}

void	ft_convert_num(t_format *tab, t_placeholder *holder)
{
	int			neg;
	long int	num;

	neg = 1;
	num = (int)va_arg(tab->args, int);
	if (num < 0)
		neg *= -1;
	holder->arg = ft_itoa_base(neg * num, "0123456789");
	if (holder->precision > -1)
	{
		if (!holder->precision && num == 0)
		{
			free(holder->arg);
			holder->arg = ft_strdup("");
		}
		ft_left_place(&holder->arg, '0', holder->precision);
		holder->padding = ' ';
	}
	ft_convert_syntax(holder, neg);
	holder->size = ft_strlen(holder->arg);
}
