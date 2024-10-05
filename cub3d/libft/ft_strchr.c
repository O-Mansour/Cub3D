/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:22:11 by alagmiri          #+#    #+#             */
/*   Updated: 2023/10/03 19:47:29 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*st;

	st = (char *) s;
	while (*st)
	{
		if (*st == (char ) c)
			return ((st));
		st++;
	}
	return (0);
}
