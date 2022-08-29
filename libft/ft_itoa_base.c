/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 07:53:56 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/13 23:30:25 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizeofnum(unsigned long num, size_t base)
{
	size_t	b;

	if ((num / base) == 0)
		b = 1;
	else
		b = 1 + ft_sizeofnum(num / base, base);
	return (b);
}

static void	ft_base_set(char *str, char *base, unsigned long num, size_t n)
{
	size_t	b;

	b = ft_strlen(base);
	if (num >= (unsigned long int)b)
		ft_base_set(str, base, num / b, n - 1);
	str[n] = base[num % b];
}

char	*ft_itoa_base(unsigned long num, char *base)
{
	size_t	n;
	size_t	b;
	char	*str;

	b = ft_strlen(base);
	n = ft_sizeofnum(num, b);
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	str[n--] = '\0';
	ft_base_set(str, base, num, n);
	return (str);
}
