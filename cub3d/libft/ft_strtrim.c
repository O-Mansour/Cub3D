/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:55:05 by alagmiri          #+#    #+#             */
/*   Updated: 2022/10/29 21:05:10 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	j = ft_strlen(s1);
	while (j != 0)
	{
		if (ft_strchr(set, s1[j]) == 0)
			break ;
		j--;
	}
	size = (j - i) + 1;
	str = ft_substr(s1, i, size);
	return (str);
}
