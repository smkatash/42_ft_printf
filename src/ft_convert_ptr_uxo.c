/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr_uxo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:37:32 by kanykei           #+#    #+#             */
/*   Updated: 2022/08/29 17:47:55 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_convert_uxo(t_format *tab, t_placeholder *holder, char *base)
{
	unsigned int	num;
	char			*str;

	str = NULL;
	num = (unsigned int)(va_arg(tab->args, unsigned int));
	str = ft_itoa_base((unsigned long)num, base);
	holder->arg = ft_strdup(str);
	free(str);
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
	if (num)
		ft_prefix(holder, 0);
	if (!holder->justify)
		ft_left_place(&holder->arg, holder->padding, holder->width);
	else
		ft_right_place(&holder->arg, ' ', holder->width);
	holder->size = ft_strlen(holder->arg);
}

static char	*ft_init_null(t_placeholder *holder)
{
	char	*str;

	if (holder->precision > -1)
	{
		str = malloc((holder->precision + 1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_memset(str, '0', (size_t)holder->precision);
		str[holder->precision] = '\0';
	}
	else
		str = ft_strdup("0");
	return (str);
}

void	ft_convert_pointer(t_format *tab, t_placeholder *holder)
{
	void	*ptr;
	char	*str;

	str = NULL;
	ptr = va_arg(tab->args, void *);
	if (!ptr)
		str = ft_init_null(holder);
	else
		str = ft_itoa_base((unsigned long)ptr, "0123456789abcdef");
	holder->arg = ft_strjoin("0x", str);
	free (str);
	if (!holder->justify)
		ft_left_place(&holder->arg, ' ', holder->width);
	else
		ft_right_place(&holder->arg, ' ', holder->width);
	holder->size = ft_strlen(holder->arg);
}
