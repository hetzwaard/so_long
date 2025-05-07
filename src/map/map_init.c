/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 04:50:54 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/07 06:09:30 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	map_wall(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if ((y == 0 || y == (map->y - 1)) && map->map[y][x] != '1')
				error_exit(1);
			if ((x == 0 || x == (map->x - 1)) && map->map[y][x] != '1')
				error_exit(1);
			x++;
		}
		y++;
	}
}

void	map_count(char c, t_map *map)
{
	if (c == '1')
		map->w_count++;
	else if (c == '0' || c == 'P' || c == 'E' || c == 'C')
	{
		map->s_count++;
		if (c == 'C')
			map->c_count++;
		else if (c == 'P')
			map->p_count++;
		else if (c == 'E')
			map->e_count++;
	}
	else
		error_exit(1);
	if (map->p_count > 1 || map->e_count > 1)
		error_exit(1);
}

int	map_len(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		map_count(str[i], map);
		i++;
	}
	if (str[i] == '\n')
		str[i] = 0;
	return (i);
}

void	map_init(t_map *map)
{
	int	i;

	i = 0;
	map->x = 0;
	map->y = 0;
	map->move = 0;
	map->w_count = 0;
	map->s_count = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	while (map->map[map->y])
	{
		i = map_len(map->map[map->y], map);
		if ((i != map->x && map->y))
			error_exit(1);
		map->x = i;
		map->y++;
	}
	if (map->x < 3 || map->y < 3)
		error_exit(1);
	if (map->p_count < 1 || map->e_count < 1 || map->c_count < 1
		|| map->w_count < 7)
		error_exit(1);
	map_wall(map);
}
