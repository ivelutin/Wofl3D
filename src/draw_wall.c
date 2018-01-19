/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 03:00:45 by ivelutin          #+#    #+#             */
/*   Updated: 2017/08/10 03:19:42 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/keys.h"

void	wall(t_alpha *vz)
{
	vz->wall.lineh = (int)(HEIGHT / vz->ray.prpwall);
	vz->wall.drawin = -vz->wall.lineh / 2 + HEIGHT / 2;
	if (vz->wall.drawin < 0)
		vz->wall.drawin = 0;
	vz->wall.drawend = vz->wall.lineh / 2 + HEIGHT / 2;
	if (vz->wall.drawend >= HEIGHT)
		vz->wall.drawend = HEIGHT - 1;
}

void	draw(int x, t_alpha *vz, int grid)
{
	int c;

	c = color(grid);
	if (vz->wall.side == 1)
		c /= 2;
	while (vz->wall.drawin < vz->wall.drawend)
	{
		mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x, vz->wall.drawin, c);
		vz->wall.drawin++;
	}
}
