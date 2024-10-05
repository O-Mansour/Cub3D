/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:52:24 by alagmiri          #+#    #+#             */
/*   Updated: 2023/10/03 19:52:26 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	count_nbr(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error("Not a number\n");
		res = res * 10 + str[i] - 48;
		if (res > 255)
			ft_error("Number greater than 255\n");
		i++;
	}
	return (res);
}

int	find_rgb(char *str)
{
	char	**rgb;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		ft_error("Invalid format r,g,b\n");
	rgb = ft_split(str, ',');
	i = 0;
	while (rgb && rgb[i])
		i++;
	if (i != 3)
		ft_error("Invalid format r,g,b\n");
	count = ft_rgb(count_nbr(rgb[0]), count_nbr(rgb[1]), count_nbr(rgb[2]));
	f_free(rgb);
	return (count);
}

void	fill_color(char **ptr, int *txt)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
		i++;
	if (i != 2)
		ft_error("Expect: F 255,0,100\n");
	if (*txt != -1)
		ft_error("Double F or C\n");
	*txt = find_rgb(ptr[1]);
	f_free(ptr);
}
