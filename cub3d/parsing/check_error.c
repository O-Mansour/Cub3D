/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:32:41 by alagmiri          #+#    #+#             */
/*   Updated: 2023/09/08 09:32:41 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_height1(char *str)
{
	int		fd;
	char	*savee;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("Invalid file descriptor\n");
	savee = get_next_line(fd);
	while (savee)
	{
		free(savee);
		savee = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**open_file(char *str)
{
	int		fd;
	char	**line;
	int		i;

	line = malloc(sizeof(char *) * (count_height1(str) + 1));
	if (!line)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("Invalid file descriptor\n");
	i = 0;
	line[i] = get_next_line(fd);
	while (line[i])
	{
		i++;
		line[i] = get_next_line(fd);
	}
	close(fd);
	if (i == 0)
		ft_error("Empty file\n");
	return (line);
}

int	ft_check_name(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] != '/' && s[i] && s[i + 1] == '.' && s[i + 2] == 'c'
			&& s[i + 3] == 'u' && s[i + 4] == 'b' && s[i + 5] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(char *str)
{
	write(2, "Error,\n", 7);
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	f_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
		free(ptr[i++]);
	free(ptr);
}
