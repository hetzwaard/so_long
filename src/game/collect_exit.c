/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collect_exit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 15:48:12 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/08 16:27:48 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_exit(t_map *map, int x, int y)
{
	x /= 96;
	y /= 96;
	map->map[y][x] = '0';
}

int	check_move(t_map *map, char collect, int x, int y)
{
	x += map->player->instances[0].x / 96;
	y += map->player->instances[0].y / 96;
	if (map->map[y][x] == collect)
		return (1);
	return (0);
}

void	collect_exit(t_map *map)
{
	int	i;

	if (map->c_count == 0)
	{
		if (check_move(map, 'C', 0, 0))
		{
			map->player->instances[0].enabled = false;
			mlx_close_window(map->mlx);
		}
	}
	else if (check_move(map, 'C', 0, 0))
	{
		i = 0;
		while (map->player->instances[0].x != map->collect->instances[i].x
			|| map->player->instances[0].y != map->collect->instances[i].y)
			i++;
		map->collect->instances[i].enabled = false;
		check_exit(map, map->collect->instances[i].x,
			map->collect->instances[i].y);
		map->c_count--;
	}
}
