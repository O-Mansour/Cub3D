/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:45:14 by alagmiri          #+#    #+#             */
/*   Updated: 2022/11/03 21:29:38 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*si;
	unsigned char	*sl;

	i = 0;
	si = (unsigned char *)s1;
	sl = (unsigned char *)s2;
	while (i < n)
	{
		if (si[i] != sl[i])
			return (si[i] - sl[i]);
		i++;
	}
	return (0);
}
