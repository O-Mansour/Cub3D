/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:01:26 by alagmiri          #+#    #+#             */
/*   Updated: 2022/10/30 12:36:25 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*r;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	r = (char *)malloc (len * sizeof (char) + 1);
	if (r == NULL)
		return (0);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
