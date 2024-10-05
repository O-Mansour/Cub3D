/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:52:05 by alagmiri          #+#    #+#             */
/*   Updated: 2023/10/03 21:44:34 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*space_pass(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	return (&str[i]);
}

void	fill_txt(char **ptr, char **txt)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
		i++;
	if (i != 2)
		ft_error("Expect: NO ./path\n");
	if (*txt)
		ft_error("Double texture\n");
	*txt = ft_strdup(ptr[1]);
	f_free(ptr);
}

int	ft_elem(t_parse *l, char *str)
{
	if (str[0] == '\0')
		return (0);
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		fill_txt(ft_split(str, ' '), &l->no);
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		fill_txt(ft_split(str, ' '), &l->so);
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		fill_txt(ft_split(str, ' '), &l->ea);
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		fill_txt(ft_split(str, ' '), &l->we);
	else if (str[0] == 'F' && str[1] == ' ')
		fill_color(ft_split(str, ' '), &l->f);
	else if (str[0] == 'C' && str[1] == ' ')
		fill_color(ft_split(str, ' '), &l->c);
	else
		ft_error("Invalid keyword\n");
	return (1);
}

void	fill_map(t_parse *l, char **map)
{
	int	i;
	int	max_len;
	int	len;

	max_len = 0;
	i = -1;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (len > max_len)
			max_len = len;
	}
	l->widht = max_len;
	l->height = i;
	l->map = ft_calloc(sizeof(char *), l->height + 1);
	if (l->map == NULL)
		ft_error("Allocation failed.\n");
	i = -1;
	while (map[++i])
	{
		l->map[i] = ft_calloc(sizeof(char), l->widht + 1);
		if (l->map[i] == NULL)
			ft_error("Allocation failed.\n");
		ft_strlcpy(l->map[i], map[i], ft_strlen(map[i]) + 1);
	}
}

void	ft_check_data(t_parse *l)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (l->file[i] && count < 6)
		count += ft_elem(l, space_pass(l->file[i++]));
	if (count != 6)
		ft_error("Wrong elements in the file\n");
	while (l->file[i] && (space_pass(l->file[i]))[0] == '\0')
		i++;
	if (l->file[i] == NULL)
		ft_error("There is no map\n");
	fill_map(l, &l->file[i]);
	check_map(l);
	check_separ(l);
}
