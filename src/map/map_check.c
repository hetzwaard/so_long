/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 04:26:00 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/07 05:54:49 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	map_name(char *str)
{
	while (*str != '.')
	{
		str++;
		if (!*str)
			error_exit(0);
	}
	if (ft_strcmp(str, ".ber"))
		error_exit(0);
}

char	**map_read(int fd, int size)
{
	int		i;
	char	**map;

	i = 0;
	map = ft_calloc(size + 1, sizeof(char *));
	if (!map)
		exit(1);
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i++])
			break ;
	}
	close(fd);
	return (map);
}

int	map_line(int fd)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		i++;
	}
	close(fd);
	return (i);
}
