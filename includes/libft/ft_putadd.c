/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:32:31 by ioduwole          #+#    #+#             */
/*   Updated: 2023/06/19 16:32:31 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_add(unsigned long n)
{
	int	dgt;

	dgt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		dgt++;
		n /= 16;
	}
	return (dgt);
}

char	*ft_putadd(unsigned long n)
{
	char	*str;
	int		dgt;
	int		tmp;

	dgt = ft_count_add(n);
	str = malloc(sizeof(char) * (dgt + 1));
	if (str == NULL)
		return (NULL);
	str[dgt] = '\0';
	dgt--;
	while (dgt >= 0)
	{
		tmp = n % 16;
		if (tmp > 9)
			str[dgt] = ft_chexi(tmp);
		else
			str[dgt] = tmp + 48;
		n /= 16;
		dgt--;
	}
	return (str);
}
