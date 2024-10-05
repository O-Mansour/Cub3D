/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:19:14 by alagmiri          #+#    #+#             */
/*   Updated: 2022/11/25 18:47:46 by alagmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_line(char *buffer);
char	*ft_next(char *s);
int		ft_check(char *str);
char	*ft_free(char **str, char *s);
char	*ft_strjoinn(char *s1, char *s);
int		ft_strlenn(char *str);
char	*get_next_line(int fd);

#endif
