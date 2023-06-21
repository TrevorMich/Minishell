/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:32:55 by ioduwole          #+#    #+#             */
/*   Updated: 2023/06/19 16:32:55 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_x(va_list args, char c)
{
	char			*str;
	int				i;
	unsigned int	n;

	i = 0;
	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	str = ft_puthexi(n, c);
	if (!str)
		str = "(NULL)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}

int	ft_print_p(va_list args)
{
	char				*str;
	unsigned long		n;
	int					i;

	i = 0;
	n = va_arg(args, unsigned long);
	write(1, "0x", 2);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	str = ft_putadd(n);
	if (str == NULL)
		str = "0";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}
