/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 16:40:45 by ivelutin          #+#    #+#             */
/*   Updated: 2017/08/10 17:17:20 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/keys.h"

int		wolf(t_alpha *vz)
{
	int x;

	while (1)
	{
		x = 0;
		while (x < WIDTH)
		{
			diray(vz, x);
			step(vz);
			wall_col(vz, 0);
			wall(vz);
			draw(x, vz, g_map[vz->map.mapx][vz->map.mapy]);
			x++;
		}
		return (0);
	}
}

int		main(int argc, char **argv)
{
	t_alpha *vz;

	if (!(vz = (t_alpha*)ft_memalloc(sizeof(t_alpha))))
		return (0);
	if ((ft_strcmp(argv[0], "./wolf3d")))
		return (0);
	if (argc == 1)
	{
		init(vz);
		vz->mlx.mlx = mlx_init();
		vz->mlx.win = mlx_new_window(vz->mlx.mlx, WIDTH, HEIGHT, "WOLF3D");
		wolf(vz);
		mlx_hook(vz->mlx.win, 2, 2, key_hook, vz);
		mlx_hook(vz->mlx.win, 17, 0, exit_hook, vz);
		mlx_loop(vz->mlx.mlx);
	}
	else
		write(1, "usage: ./wolf3d\n", 16);
	ft_memdel((void**)&vz);
	return (0);
}
