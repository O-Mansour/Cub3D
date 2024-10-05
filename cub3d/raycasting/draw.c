/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:02:15 by omansour          #+#    #+#             */
/*   Updated: 2023/10/03 20:02:18 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ceil_floor(t_elts *elts)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_H / 2)
	{
		x = -1;
		while (++x < WINDOW_W)
			pixel_put(elts, x, y, elts->c);
		y++;
	}
	while (y < WINDOW_H)
	{
		x = -1;
		while (++x < WINDOW_W)
			pixel_put(elts, x, y, elts->f);
		y++;
	}
}

double	draw_wall_helper(t_elts *elts, int *start, int *end, double wall_height)
{
	double	tex_x;

	*start = round((WINDOW_H - wall_height) / 2);
	*end = round(*start + wall_height);
	if (*start < 0)
		*start = 0;
	if (*end > WINDOW_H)
		*end = WINDOW_H;
	if (elts->ray->hit_type)
		tex_x = elts->ray->y;
	else
		tex_x = elts->ray->x;
	tex_x = remainder(tex_x, TILE_SIZE);
	if (tex_x < 0)
		tex_x += TILE_SIZE;
	return (tex_x);
}

void	draw_wall_slice(t_elts *elts, double wall_height, t_data *txtr, int i)
{
	int		start;
	int		end;
	double	tex_x;
	int		tex_y;
	int		color;

	tex_x = draw_wall_helper(elts, &start, &end, wall_height);
	tex_x = (tex_x * txtr->width) / TILE_SIZE;
	while (start < end)
	{
		tex_y = ((int)(start + (wall_height / 2)
					- (WINDOW_H / 2)) / wall_height) * txtr->height;
		color = get_pixel_color(txtr, tex_x, tex_y);
		pixel_put(elts, i, start, color);
		start++;
	}
}

t_data	*get_txtr(t_elts *elts, double ray_angle)
{
	if (elts->ray->hit_type)
	{
		if (ray_angle > 90 && ray_angle <= 270)
			return (&elts->we_txt);
		else
			return (&elts->ea_txt);
	}
	else
	{
		if (ray_angle < 180)
			return (&elts->so_txt);
		else
			return (&elts->no_txt);
	}
	return (NULL);
}

void	draw_map(t_elts *elts)
{
	double	current_angle;
	double	dis;
	double	wall_height;
	int		i;
	t_data	*txtr;

	current_angle = elts->a - (FOV / 2);
	i = -1;
	ceil_floor(elts);
	while (++i < WINDOW_W)
	{
		adjust_angle(&current_angle);
		elts->ray->ang = current_angle;
		dis = dda(elts);
		dis *= cos((((current_angle - elts->a) * M_PI) / 180.0));
		wall_height = (WINDOW_H * 30) / dis;
		txtr = get_txtr(elts, current_angle);
		draw_wall_slice(elts, wall_height, txtr, i);
		current_angle += (FOV / WINDOW_W);
	}
	mlx_put_image_to_window(elts->mlx, elts->win, elts->img, 0, 0);
}
