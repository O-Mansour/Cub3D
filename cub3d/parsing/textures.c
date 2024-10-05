/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:52:37 by alagmiri          #+#    #+#             */
/*   Updated: 2023/10/03 19:52:40 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_inis(t_parse *l, char **argv)
{
	l->no = 0;
	l->so = 0;
	l->ea = 0;
	l->we = 0;
	l->f = -1;
	l->c = -1;
	l->px = 0;
	l->py = 0;
	l->veiw = 0;
	l->file = open_file(argv[1]);
}

int	ft_check_file_xpm(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] != '/' && s[i] && s[i + 1] == '.' && s[i + 2] == 'x'
			&& s[i + 3] == 'p' && s[i + 4] == 'm' && s[i + 5] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_init_txt(void *mlx, t_data *data, char *filename)
{
	if (filename == NULL || filename[0] == '\0')
		ft_error("Invalid file path\n");
	if (ft_check_file_xpm(filename))
		ft_error("Invalid file path .xpm\n");
	data->img = mlx_xpm_file_to_image(mlx, filename,
			&data->width, &data->height);
	if (data->img == NULL)
		ft_error("mlx_xpm_file_to_image\n");
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel,
			&data->line_length,
			&data->endian);
	if (data->addr == NULL)
		ft_error("mlx_xpm_file_to_image\n");
}

void	ft_open_txt(t_parse *l)
{
	l->mlx = mlx_init();
	if (l->mlx == NULL)
		ft_error("mlx_init\n");
	ft_init_txt(l->mlx, &l->no_txt, l->no);
	ft_init_txt(l->mlx, &l->so_txt, l->so);
	ft_init_txt(l->mlx, &l->we_txt, l->we);
	ft_init_txt(l->mlx, &l->ea_txt, l->ea);
}
