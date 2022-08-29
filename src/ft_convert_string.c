/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:29:01 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 17:47:57 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_strcpy_prec(const char *s, size_t size)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = ft_strlen((char *)s);
	if ((size_t)i > size)
		i = size;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s, i);
	ptr[i] = '\0';
	return (ptr);
}

void	ft_right_place(char **src, char padding, int width)
{
	size_t	len;
	size_t	padd;
	char	*dest;

	len = ft_strlen(*src);
	if (!width || width < (int)len)
		width = len;
	dest = (char *)malloc(width * sizeof(char));
	if (!dest)
		return ;
	ft_strlcpy(dest, *src, len + 1);
	padd = width - len;
	ft_memset(&dest[len], padding, padd);
	dest[width] = '\0';
	free(*src);
	*src = dest;
}

void	ft_left_place(char **src, char padding, int width)
{
	size_t	len;
	size_t	padd;
	char	*dest;

	len = ft_strlen(*src);
	if (!width || width < (int)len)
		width = len;
	dest = (char *)malloc(width * sizeof(char));
	if (!dest)
		return ;
	padd = width - len;
	ft_memset(dest, padding, padd);
	dest[padd] = '\0';
	ft_strlcat(dest, *src, width + 1);
	free(*src);
	*src = dest;
}

void	ft_convert_string(t_format *tab, t_placeholder *holder)
{
	int		len;
	char	*s;
	char	*ptr;

	s = ft_strdup(va_arg(tab->args, char *));
	if (!s)
		s = ft_strdup("(null)");
	len = (int)ft_strlen(s);
	holder->arg = (char *)malloc((len + 1) * sizeof(char));
	if (!holder->arg)
		return ;
	ft_strlcpy(holder->arg, s, len + 1);
	if (holder->precision > -1)
	{
		ptr = holder->arg;
		holder->arg = ft_strcpy_prec(ptr, (size_t)holder->precision);
		free (ptr);
	}
	if (!holder->justify)
		ft_left_place(&holder->arg, ' ', holder->width);
	else
		ft_right_place(&holder->arg, ' ', holder->width);
	holder->size = ft_strlen(holder->arg);
	free (s);
}
