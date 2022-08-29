/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:08:53 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/13 23:46:36 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pref_transform(char const *str, char const ch)
{
	char	*pref;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	pref = (char *)malloc((len + 2) * sizeof(char));
	if (!pref)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		pref[i] = str[i];
		i++;
	}
	pref[i++] = ch;
	pref[i] = '\0';
	return (pref);
}

static void	ft_convert_char(t_format *tab, t_placeholder *holder)
{
	char	c;

	c = (wint_t)va_arg(tab->args, wint_t);
	if (!holder->width)
		holder->width += 1;
	holder->arg = (char *)malloc(holder->width * sizeof(char));
	if (!holder->arg)
		return ;
	ft_memset(holder->arg, ' ', holder->width);
	if (holder->justify == 1)
		holder->arg[0] = c;
	else
		holder->arg[holder->width - 1] = c;
	holder->size = holder->width;
}

static void	ft_convert_cpy(t_placeholder *holder)
{
	holder->arg = ft_pref_transform("", holder->type);
	if (!holder->justify)
		ft_left_place(&holder->arg, holder->padding, holder->width);
	else
		ft_right_place(&holder->arg, ' ', holder->width);
	holder->size = ft_strlen(holder->arg);
}

void	ft_convert(t_format *tab, t_placeholder *holder)
{
	if (holder->type == 'c')
		ft_convert_char(tab, holder);
	else if (holder->type == 's')
		ft_convert_string(tab, holder);
	else if (holder->type == 'd' || holder->type == 'i')
		ft_convert_num(tab, holder);
	else if (holder->type == 'p')
		ft_convert_pointer(tab, holder);
	else if (holder->type == 'u')
		ft_convert_uxo(tab, holder, "0123456789");
	else if (holder->type == 'x')
		ft_convert_uxo(tab, holder, "0123456789abcdef");
	else if (holder->type == 'X')
		ft_convert_uxo(tab, holder, "0123456789ABCDEF");
	else if (holder->type == 'o')
		ft_convert_uxo(tab, holder, "01234567");
	else
		ft_convert_cpy(holder);
}
