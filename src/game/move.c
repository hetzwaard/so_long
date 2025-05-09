/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 15:37:28 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/08 16:27:55 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	move_left(t_map *map)
{
	if (check_collect(map, '1', -1, 0))
		return ;
	map->player->instances[0].x -= 96;
	map->move++;
	ft_printf("%d\n", map->move);
	collect_exit(map);
}

static void	move_right(t_map *map)
{
	if (check_collect(map, '1', 1, 0))
		return ;
	map->player->instances[0].x += 96;
	map->move++;
	ft_printf("%d\n", map->move);
	collect_exit(map);
}

static void	move_down(t_map *map)
{
	if (check_collect(map, '1', 0, 1))
		return ;
	map->player->instances[0].y += 96;
	map->move++;
	ft_printf("%d\n", map->move);
	collect_exit(map);
}

static void	move_up(t_map *map)
{
	if (check_collect(map, '1', 0, -1))
		return ;
	map->player->instances[0].y -= 96;
	map->move++;
	ft_printf("%d\n", map->move);
	collect_exit(map);
}

void	move(mlx_key_data_t key, void	*param)
{
	t_map	*map;

	map = param;
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
	{
		if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
			move_up(map);
		else if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
			move_down(map);
		else if (key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
			move_right(map);
		else if (key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
			move_left(map);
		else if (key.key == MLX_KEY_ESCAPE)
			mlx_close_window(map->mlx);
	}
}
