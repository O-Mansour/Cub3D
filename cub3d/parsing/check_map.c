/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:51:47 by alagmiri          #+#    #+#             */
/*   Updated: 2023/10/03 19:51:51 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_lrdu(char **map, int y, int x)
{
	if (x == 0 || y == 0)
		return (1);
	if (map[y + 1] == NULL || map[y][x + 1] == '\0')
		return (1);
	if (ft_strchr("NWSE01", map[y][x + 1]) == NULL)
		return (1);
	if (ft_strchr("NWSE01", map[y][x - 1]) == NULL)
		return (1);
	if (ft_strchr("NWSE01", map[y + 1][x]) == NULL)
		return (1);
	if (ft_strchr("NWSE01", map[y - 1][x]) == NULL)
		return (1);
	return (0);
}

void	check_map1(t_parse *l, int x, int y)
{
	if (ft_strchr("NWSE", l->map[y][x]))
	{
		if (l->veiw)
			ft_error("More than one player\n");
		l->veiw = l->map[y][x];
		l->px = x;
		l->py = y;
		if (check_lrdu(l->map, y, x))
			ft_error("Unclosed map\n");
	}
	else if (l->map[y][x] == '0')
	{
		if (check_lrdu(l->map, y, x))
			ft_error("Unclosed map\n");
	}
	else if (l->map[y][x] != '1' && l->map[y][x] != ' ')
		ft_error("Invalid character in the map\n");
}

void	check_map(t_parse *l)
{
	int	x;
	int	y;

	y = 0;
	while (l->map[y])
	{
		x = 0;
		while (l->map[y][x])
		{
			check_map1(l, x, y);
			x++;
		}
		y++;
	}
	if (l->veiw == 0)
		ft_error("No player in the map\n");
}

void	check_separ(t_parse *l)
{
	int	i;

	i = 0;
	while (l->map[i] && l->map[i][0])
		i++;
	while (l->map[i] && l->map[i][0] == '\0')
		i++;
	if (l->map[i])
		ft_error("Empty line in map\n");
}

void	find_angle(t_parse *l)
{
	l->map[(int)l->py][(int)l->px] = '0';
	if (l->veiw == 'E')
		l->angle = 0;
	else if (l->veiw == 'N')
		l->angle = 270;
	else if (l->veiw == 'W')
		l->angle = 180;
	else if (l->veiw == 'S')
		l->angle = 90;
}
