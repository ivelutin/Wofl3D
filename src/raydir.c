/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raydir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 02:56:33 by ivelutin          #+#    #+#             */
/*   Updated: 2017/08/10 03:13:01 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/keys.h"

/*
** calculates position, direction, what where are we, length of ray from current
** position.
*/

void	diray(t_alpha *vz, int x)
{
	vz->ray.camx = 2 * x / (double)WIDTH - 1;
	vz->ray.posx = vz->map.posx;
	vz->ray.posy = vz->map.posy;
	vz->ray.dirx = vz->map.dirx + vz->map.plx * vz->ray.camx;
	vz->ray.diry = vz->map.diry + vz->map.ply * vz->ray.camx;
	vz->map.mapx = (int)vz->ray.posx;
	vz->map.mapy = (int)vz->ray.posy;
	vz->ray.betax = sqrt(1 + pow(vz->ray.diry, 2) / pow(vz->ray.dirx, 2));
	vz->ray.betay = sqrt(1 + pow(vz->ray.dirx, 2) / pow(vz->ray.diry, 2));
}

void	step(t_alpha *vz)
{
	if (vz->ray.dirx < 0)
	{
		vz->map.stepx = -1;
		vz->map.distx = (vz->ray.posx - vz->map.mapx) * vz->ray.betax;
	}
	else
	{
		vz->map.stepx = 1;
		vz->map.distx = (vz->map.mapx + 1.0 - vz->ray.posx) * vz->ray.betax;
	}
	if (vz->ray.diry < 0)
	{
		vz->map.stepy = -1;
		vz->map.disty = (vz->ray.posy - vz->map.mapy) * vz->ray.betay;
	}
	else
	{
		vz->map.stepy = 1;
		vz->map.disty = (vz->map.mapy + 1.0 - vz->ray.posy) * vz->ray.betay;
	}
}
