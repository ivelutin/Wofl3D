/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 02:59:42 by ivelutin          #+#    #+#             */
/*   Updated: 2017/08/10 03:09:35 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/keys.h"

void	wall_col(t_alpha *vz, int hit)
{
	while (hit == 0)
	{
		if (vz->map.distx < vz->map.disty)
		{
			vz->map.distx += vz->ray.betax;
			vz->map.mapx += vz->map.stepx;
			vz->wall.side = 0;
		}
		else
		{
			vz->map.disty += vz->ray.betay;
			vz->map.mapy += vz->map.stepy;
			vz->wall.side = 1;
		}
		if (g_map[vz->map.mapx][vz->map.mapy] > 0)
			hit = 1;
	}
	if (vz->wall.side == 0)
		vz->ray.prpwall = (vz->map.mapx - vz->ray.posx + \
			(1 - vz->map.stepx) / 2) / vz->ray.dirx;
	else
		vz->ray.prpwall = (vz->map.mapy - vz->ray.posy + \
			(1 - vz->map.stepy) / 2) / vz->ray.diry;
}
