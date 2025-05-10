/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 04:26:00 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/10 02:49:19 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**map_dup(t_map *map)
{
	char	**map_dup;
	int		i;

	i = 0;
	map_dup = ft_calloc(map->y + 1, sizeof(char *));
	if (!map_dup)
		exit(1);
	while (map->map[i])
	{
		map_dup[i] = ft_strdup(map->map[i]);
		i++;
	}
	return (map_dup);
}

void	map_depth(t_map *map)
{
	int	i;

	i = 0;
	map->player->instances[0].z = 3;
	map->exit->instances[0].z = 1;
	while (i < map->w_count)
		map->wall->instances[i++].z = 1;
	i = 0;
	while (i < map->s_count)
		map->space->instances[i++].z = 0;
	i = 0;
	while (i < map->c_count)
		map->collect->instances[i++].z = 2;
}

void	map_name(char *str)
{
	while (*str != '.')
	{
		str++;
		if (!*str)
			error_exit(0, 0);
	}
	if (ft_strcmp(str, ".ber"))
		error_exit(0, 0);
}

char	**map_read(int fd, int size)
{
	int		i;
	char	**map;

	i = 0;
	if (fd < 0)
		error_exit(0, 0);
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
