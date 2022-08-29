/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:25:13 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/13 17:01:29 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_lstnew_format(const char *fmt, va_list args)
{
	t_format	*tab;

	tab = malloc(sizeof(t_format));
	if (!tab)
		return (NULL);
	tab->format = fmt;
	va_copy(tab->args, args);
	tab->first = 0;
	tab->len = 0;
	return (tab);
}	

static t_placeholder	*ft_lstnew_placeholder(void)
{
	t_placeholder	*p;

	p = malloc(sizeof(t_placeholder));
	if (!p)
		return (NULL);
	p->justify = 0;
	p->prefix = ft_strdup("");
	p->padding = ' ';
	p->width = 0;
	p->precision = -1;
	p->type = '\0';
	p->arg = NULL;
	p->size = 0;
	return (p);
}

void	ft_placeholder_check(t_format *tab)
{
	t_placeholder	*holder;

	tab->first++;
	holder = ft_lstnew_placeholder();
	ft_parse_data(tab, holder);
	if (holder->type)
	{
		ft_convert(tab, holder);
		tab->len += write(1, holder->arg, holder->size);
		free(holder->arg);
	}
	free(holder->prefix);
	free(holder);
}
