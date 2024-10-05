/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:38:14 by alagmiri          #+#    #+#             */
/*   Updated: 2023/09/08 11:02:54 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	j = 0;
	if (buffer[0] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		line[j++] = buffer[i++];
	line[j] = '\0';
	return (line);
}

char	*ft_next(char *s)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	save = malloc(ft_strlenn(s) - i * sizeof(char));
	if (!save)
		return (NULL);
	i++;
	while (s[i])
		save[j++] = s[i++];
	save[j] = '\0';
	free(s);
	return (save);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_free(char **str, char *s)
{
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	free(s);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stc;
	char		*line;
	char		*ptr;
	ssize_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	i = 1;
	while (ft_check(stc) == 0 && i != 0)
	{
		i = read(fd, ptr, BUFFER_SIZE);
		if (i == -1)
			return (ft_free(&stc, ptr));
		ptr[i] = '\0';
		stc = ft_strjoinn(stc, ptr);
	}
	free(ptr);
	if (!stc)
		return (NULL);
	line = ft_line(stc);
	stc = ft_next(stc);
	return (line);
}
