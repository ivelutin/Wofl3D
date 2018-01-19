/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 02:04:25 by ivelutin          #+#    #+#             */
/*   Updated: 2017/08/10 17:23:23 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/keys.h"

int		exit_hook(t_alpha *vz)
{
	mlx_destroy_window(vz->mlx.mlx, vz->mlx.win);
	exit(0);
}

int		ft_ladilla(int key, t_alpha *vz, double oldir, double oldplane)
{
	oldir = vz->map.dirx;
	oldplane = vz->map.plx;
	if (key == RIGHT_ARROW)
	{
		vz->map.dirx = vz->map.dirx * cos(-vz->map.rotspeed) - vz->map.diry \
			* sin(-vz->map.rotspeed);
		vz->map.diry = oldir * sin(-vz->map.rotspeed) + vz->map.diry \
			* cos(-vz->map.rotspeed);
		vz->map.plx = vz->map.plx * cos(-vz->map.rotspeed) - vz->map.ply \
			* sin(-vz->map.rotspeed);
		vz->map.ply = oldplane * sin(-vz->map.rotspeed) + vz->map.ply \
			* cos(-vz->map.rotspeed);
	}
	else if (key == LEFT_ARROW)
	{
		vz->map.dirx = vz->map.dirx * cos(vz->map.rotspeed) - vz->map.diry \
			* sin(vz->map.rotspeed);
		vz->map.diry = oldir * sin(vz->map.rotspeed) + vz->map.diry \
			* cos(vz->map.rotspeed);
		vz->map.plx = vz->map.plx * cos(vz->map.rotspeed) - vz->map.ply \
			* sin(vz->map.rotspeed);
		vz->map.ply = oldplane * sin(vz->map.rotspeed) + vz->map.ply \
			* cos(vz->map.rotspeed);
	}
	return (0);
}

int		key_hook(int key, t_alpha *vz)
{
	if (key == ESC)
		exit(0);
	else if (key == UP_ARROW)
	{
		if (!(g_map[(int)(vz->map.posx + vz->map.dirx * vz->map.mvspeed)]\
			[(int)(vz->map.posy)]))
			vz->map.posx += vz->map.dirx * vz->map.mvspeed;
		if (!(g_map[(int)(vz->map.posx)]\
			[(int)(vz->map.posy + vz->map.diry * vz->map.mvspeed)]))
			vz->map.posy += vz->map.diry * vz->map.mvspeed;
	}
	else if (key == DOWN_ARROW)
	{
		if (!(g_map[(int)(vz->map.posx - vz->map.dirx * vz->map.mvspeed)]\
			[(int)(vz->map.posy)]))
			vz->map.posx -= vz->map.dirx * vz->map.mvspeed;
		if (!(g_map[(int)(vz->map.posx)]\
			[(int)(vz->map.posy - vz->map.diry * vz->map.mvspeed)]))
			vz->map.posy -= vz->map.diry * vz->map.mvspeed;
	}
	else if (key == RIGHT_ARROW || key == LEFT_ARROW)
		ft_ladilla(key, vz, 0, 0);
	mlx_clear_window(vz->mlx.mlx, vz->mlx.win);
	wolf(vz);
	return (0);
}
