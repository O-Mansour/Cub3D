/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:46:34 by alagmiri          #+#    #+#             */
/*   Updated: 2022/10/30 13:32:54 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize )
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	if (dstsize == 0 || dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (dst[j] != '\0')
		j++;
	while (src[i] != '\0' && j + i + 1 < dstsize)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (ft_strlen(src) + j);
}
