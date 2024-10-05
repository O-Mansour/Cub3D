/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:33:35 by alagmiri          #+#    #+#             */
/*   Updated: 2023/10/03 19:45:04 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elts	*init_data(t_parse *p)
{
	t_elts	*elts;

	elts = malloc(sizeof(t_elts));
	if (!elts)
		ft_error("Allocation failed.\n");
	elts->map = p->map;
	elts->mlx = p->mlx;
	elts->a = p->angle;
	elts->x_player = (p->px + 0.5) * TILE_SIZE;
	elts->y_player = (p->py + 0.5) * TILE_SIZE;
	elts->width = p->widht;
	elts->height = p->height;
	elts->f = p->f;
	elts->c = p->c;
	elts->no_txt = p->no_txt;
	elts->so_txt = p->so_txt;
	elts->ea_txt = p->ea_txt;
	elts->we_txt = p->we_txt;
	elts->ray = malloc(sizeof(t_ray));
	if (!elts->ray)
		ft_error("Allocation failed.\n");
	return (elts);
}

void	mouse_rotate(t_elts *elts, bool rotate)
{
	if (rotate)
		elts->a += 1;
	else
		elts->a -= 1;
	fix_angle(&elts->a);
}

int	mouse_event(int x, int y, void *p)
{
	t_elts	*elts;

	elts = (t_elts *)p;
	(void)y;
	if (elts->mouse_x > x)
		mouse_rotate(elts, false);
	if (elts->mouse_x < x)
		mouse_rotate(elts, true);
	elts->mouse_x = x;
	draw_map(elts);
	return (0);
}

int	main(int argc, char **argv)
{
	t_parse	p;
	t_elts	*elts;

	if (argc != 2)
		ft_error("Invalid number of arguments\n");
	if (ft_check_name(argv[1]) == 1)
		ft_error("Invalid exetension of file\n");
	ft_inis(&p, argv);
	ft_check_data(&p);
	ft_open_txt(&p);
	find_angle(&p);
	elts = init_data(&p);
	elts->win = mlx_new_window(elts->mlx, WINDOW_W, WINDOW_H, "CUB3D_BONUS");
	elts->img = mlx_new_image(elts->mlx, WINDOW_W, WINDOW_H);
	elts->img_addr = mlx_get_data_addr(elts->img, &elts->img_bpp,
			&elts->img_line_len, &elts->img_endian);
	mlx_mouse_get_pos(elts->mlx, elts->win, &elts->mouse_x, &elts->mouse_y);
	draw_map(elts);
	mlx_hook(elts->win, 6, 1L << 6, &mouse_event, elts);
	mlx_hook(elts->win, 2, 1L << 0, &clicks, elts);
	mlx_hook(elts->win, 17, 0, &leave_fct, elts);
	mlx_loop(elts->mlx);
	return (0);
}
