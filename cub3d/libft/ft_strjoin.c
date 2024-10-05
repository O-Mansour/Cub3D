/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:54:47 by alagmiri          #+#    #+#             */
/*   Updated: 2023/10/03 19:49:17 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		leni;
	int		j;
	int		lenj;
	char	*r;
	int		i;

	i = 0 ;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	leni = ft_strlen(s1);
	lenj = ft_strlen(s2);
	r = (char *)malloc ((leni + lenj + 1) * sizeof(char));
	if (r == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		r[i++] = s2[j++];
	r[i] = '\0';
	return (r);
}
