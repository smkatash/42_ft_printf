/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:25:28 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/14 00:26:32 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_vprintf(const char *fmt, va_list args)
{
	t_format	*node;
	int			len;

	node = ft_lstnew_format(fmt, args);
	if (!node)
		return (0);
	while (node->format[node->first])
	{
		if (node->format[node->first] == '%')
			ft_placeholder_check(node);
		else
		{
			node->len += write(1, &node->format[node->first++], 1);
		}
	}
	len = node->len;
	free(node);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	if (format == NULL)
		return (0);
	va_start(args, format);
	i = ft_vprintf(format, args);
	va_end(args);
	return (i);
}
