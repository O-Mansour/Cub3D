/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:53:01 by alagmiri          #+#    #+#             */
/*   Updated: 2023/10/03 19:48:35 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(long int n)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		k = 1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i + k);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		i;
	long	nb;
	int		l;

	nb = (long)n;
	i = 0;
	l = count_digits(nb);
	r = (char *) malloc ((1 + l) * sizeof(char));
	if (r == NULL)
		return (0);
	r[l] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		r[i++] = '-';
	}
	while (l > i)
	{
		r[--l] = nb % 10 + 48;
		nb /= 10;
	}
	return (r);
}
