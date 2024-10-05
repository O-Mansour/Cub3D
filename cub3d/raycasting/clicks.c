/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clicks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:02:03 by omansour          #+#    #+#             */
/*   Updated: 2023/10/03 20:02:06 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_empty_space(t_elts *elts, int x, int y)
{
	if (elts->map[y / TILE_SIZE][x / TILE_SIZE] != '0')
		return (false);
	if (elts->map[(y + 10) / TILE_SIZE][x / TILE_SIZE] != '0')
		return (false);
	if (elts->map[(y - 10) / TILE_SIZE][x / TILE_SIZE] != '0')
		return (false);
	if (elts->map[y / TILE_SIZE][(x + 10) / TILE_SIZE] != '0')
		return (false);
	if (elts->map[y / TILE_SIZE][(x - 10) / TILE_SIZE] != '0')
		return (false);
	return (true);
}

void	move_player(t_elts *elts, int angle)
{
	double	new_x;
	double	new_y;
	double	tmp_x;

	fix_angle(&angle);
	tmp_x = elts->x_player;
	new_x = elts->x_player + cos((angle * M_PI) / 180.0) * P_SPEED;
	new_y = elts->y_player + sin((angle * M_PI) / 180.0) * P_SPEED;
	if (is_empty_space(elts, new_x, elts->y_player))
		elts->x_player = new_x;
	if (is_empty_space(elts, tmp_x, new_y))
		elts->y_player = new_y;
}

void	rotate_player(t_elts *elts, bool rotate)
{
	if (rotate)
		elts->a += 3;
	else
		elts->a -= 3;
	fix_angle(&elts->a);
}

int	clicks(int key, void *p)
{
	t_elts	*elts;

	elts = (t_elts *)p;
	if (key == 65307)
		exit(0);
	else if (key == 115)
		move_player(elts, elts->a - 180);
	else if (key == 119)
		move_player(elts, elts->a);
	else if (key == 100)
		move_player(elts, elts->a + 90);
	else if (key == 97)
		move_player(elts, elts->a - 90);
	else if (key == 65363)
		rotate_player(elts, true);
	else if (key == 65361)
		rotate_player(elts, false);
	draw_map(elts);
	return (0);
}
