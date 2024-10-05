/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:35:58 by omansour          #+#    #+#             */
/*   Updated: 2023/10/02 23:40:01 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	leave_fct(void)
{
	exit (0);
	return (0);
}

void	fix_angle(int *angle)
{
	if (*angle < 0)
		*angle += 360;
	else if (*angle >= 360)
		*angle -= 360;
}

void	adjust_angle(double *angle)
{
	if (*angle < 0)
		*angle += 360;
	else if (*angle >= 360)
		*angle -= 360;
}

void	pixel_put(t_elts *elts, int x, int y, int color)
{
	char	*dst;

	dst = elts->img_addr + (y * elts->img_line_len + x * (elts->img_bpp / 8));
	*(int *)dst = color;
}

int	get_pixel_color(t_data *texture, int x, int y)
{
	char	*addr;

	if (y < 0)
		y = 0;
	addr = texture->addr
		+ (int)(y * texture->line_length + x * (texture->bits_per_pixel / 8));
	return (*(int *)addr);
}
