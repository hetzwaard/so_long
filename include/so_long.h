/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 13:25:18 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/05/08 16:34:47 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/include/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_map
{
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*wall;
	mlx_image_t	*space;
	mlx_image_t	*collect;
	char		**map;
	int			x;
	int			y;
	int			move;
	int			c_count;
	int			p_count;
	int			s_count;
	int			w_count;
	int			e_count;
}	t_map;

void	error_exit(int i, t_map *map);
void	error_mlx(t_map *map);
void	error_fd(int i);
void	map_name(char *str);
char	**map_read(int fd, int size);
int		map_line(int fd);
void	map_init(t_map *map);
void	map_name(char *str);
void	map_depth(t_map *map);
void	map_build(t_map *map);
char	**map_dup(t_map *map);
void	flood_fill(t_map *map);
void	collect_exit(t_map *map);
int		check_collect(t_map *map, char collect, int x, int y);
void	move(mlx_key_data_t key, void	*param);