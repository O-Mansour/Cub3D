/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:38:43 by omansour          #+#    #+#             */
/*   Updated: 2023/09/27 21:57:24 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda_v(t_elts *elts, t_ray *ray)
{
	double	dx;
	double	dy;

	ray->xv = (int)(elts->x_player / TILE_SIZE
			+ (cos((ray->ang * M_PI) / 180) > 0)) * TILE_SIZE;
	ray->yv = elts->y_player + (ray->xv - elts->x_player)
		* tan((ray->ang * M_PI) / 180);
	while (ray->yv >= 0 && ray->xv >= 0 && ray->yv < elts->height * TILE_SIZE
		&& ray->xv < elts->width * TILE_SIZE)
	{
		if (elts->map[(int)ray->yv / TILE_SIZE]
			[(int)ray->xv / TILE_SIZE] != '0')
			break ;
		if (ray->xv >= TILE_SIZE && elts->map[(int)ray->yv / TILE_SIZE]
			[(int)ray->xv / TILE_SIZE - 1] != '0')
			break ;
		ray->xv += TILE_SIZE - (cos((ray->ang * M_PI) / 180) < 0)
			* 2 * TILE_SIZE;
		ray->yv = elts->y_player + (ray->xv - elts->x_player)
			* tan((ray->ang * M_PI) / 180);
	}
	dx = ray->xv - elts->x_player;
	dy = ray->yv - elts->y_player;
	ray->disv = sqrt(dx * dx + dy * dy);
}

void	dda_h(t_elts *elts, t_ray *ray)
{
	double	dx;
	double	dy;

	ray->yh = (int)(elts->y_player / TILE_SIZE
			+ (sin((ray->ang * M_PI) / 180) > 0)) * TILE_SIZE;
	ray->xh = elts->x_player + (ray->yh - elts->y_player)
		/ tan((ray->ang * M_PI) / 180);
	while (ray->yh >= 0 && ray->xh >= 0 && ray->yh < elts->height * TILE_SIZE
		&& ray->xh < elts->width * TILE_SIZE)
	{
		if (elts->map[(int)ray->yh / TILE_SIZE]
			[(int)ray->xh / TILE_SIZE] != '0')
			break ;
		if (ray->yh >= TILE_SIZE && elts->map[(int)ray->yh / TILE_SIZE - 1]
			[(int)ray->xh / TILE_SIZE] != '0')
			break ;
		ray->yh += TILE_SIZE - (sin((ray->ang * M_PI) / 180) < 0)
			* 2 * TILE_SIZE;
		ray->xh = elts->x_player + (ray->yh - elts->y_player)
			/ tan((ray->ang * M_PI) / 180);
	}
	dx = ray->xh - elts->x_player;
	dy = ray->yh - elts->y_player;
	ray->dish = sqrt(dx * dx + dy * dy);
}

double	dda(t_elts *elts)
{
	dda_h(elts, elts->ray);
	dda_v(elts, elts->ray);
	if (elts->ray->disv > elts->ray->dish)
	{
		elts->ray->dis = elts->ray->dish;
		elts->ray->x = elts->ray->xh;
		elts->ray->y = elts->ray->yh;
		elts->ray->hit_type = false;
	}
	else
	{
		elts->ray->dis = elts->ray->disv;
		elts->ray->x = elts->ray->xv;
		elts->ray->y = elts->ray->yv;
		elts->ray->hit_type = true;
	}
	return (elts->ray->dis);
}
