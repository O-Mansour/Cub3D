/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:32:11 by alagmiri          #+#    #+#             */
/*   Updated: 2023/09/08 09:32:11 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>

# define TILE_SIZE 64
# define WINDOW_W 1080.0
# define WINDOW_H 720.0
# define P_SPEED 10
# define FOV 60.0

typedef struct s_data
{
	int		height;
	int		width;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_ray
{
	double	x;
	double	y;
	double	dis;
	double	xv;
	double	yv;
	double	disv;
	double	xh;
	double	yh;
	double	dish;
	double	ang;
	bool	hit_type;
}	t_ray;

typedef struct s_parse
{
	char	**file;
	char	**map;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		f;
	int		c;
	int		height;
	int		widht;
	double	angle;
	char	veiw;
	double	px;
	double	py;
	t_data	no_txt;
	t_data	so_txt;
	t_data	we_txt;
	t_data	ea_txt;
	void	*mlx;
}	t_parse;

typedef struct s_elts
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img;
	void	*img_addr;
	double	y_player;
	double	x_player;
	int		img_bpp;
	int		img_line_len;
	int		img_endian;
	int		a;
	int		height;
	int		width;
	int		c;
	int		f;
	int		mouse_x;
	int		mouse_y;
	t_data	no_txt;
	t_data	so_txt;
	t_data	we_txt;
	t_data	ea_txt;
	t_ray	*ray;
}	t_elts;

int		ft_check_name(char *s);
char	**open_file(char *str);
void	ft_error(char *s);
void	read_mp(char *str, t_parse *data);
void	count_height(char *str, t_parse *data);
void	f_free(char **ptr);
void	check_map(t_parse *l);
void	find_angle(t_parse *l);
void	check_separ(t_parse *l);
void	ft_check_data(t_parse *l);
char	*space_pass(char *str);
void	fill_color(char **ptr, int *txt);
void	ft_inis(t_parse *l, char **argv);
int		ft_check_file_xpm(char *s);
void	ft_open_txt(t_parse *l);

void	draw_map(t_elts *elts);
int		clicks(int key, void *p);
int		leave_fct(void);
void	adjust_angle(double *angle);
void	fix_angle(int *angle);
void	pixel_put(t_elts *elts, int x, int y, int color);
int		get_pixel_color(t_data *texture, int x, int y);
double	dda(t_elts *elts);

#endif
