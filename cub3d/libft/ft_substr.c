/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:14:18 by alagmiri          #+#    #+#             */
/*   Updated: 2022/11/03 23:44:37 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*strr;
	char	*st;
	size_t	l;

	i = 0;
	l = 0;
	st = (char *)s;
	if (!s)
		return (NULL);
	if (start <= ft_strlen(st))
		l = ft_strlen(st) - start;
	if (len < l)
		l = len;
	strr = (char *)malloc (l * sizeof(char) + 1);
	if (strr == NULL)
		return (0);
	while (i < l)
		strr[i++] = st[start++];
	strr[i] = '\0';
	return (strr);
}
