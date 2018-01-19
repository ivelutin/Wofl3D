/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 16:44:03 by ivelutin          #+#    #+#             */
/*   Updated: 2017/08/10 17:21:12 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../Libft/libft.h"

# define WIDTH		720
# define HEIGHT		480
# define MAP_WIDTH	24
# define MAP_HEIGHT	24

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				x;
}					t_mlx;

typedef struct		s_map
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			plx;
	double			ply;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	double			distx;
	double			disty;
	double			mvspeed;
	double			rotspeed;
}					t_map;

typedef struct		s_ray
{
	double			camx;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			betax;
	double			betay;
	double			prpwall;
}					t_ray;

typedef struct		s_wall
{
	int				lineh;
	int				drawin;
	int				drawend;
	int				side;
}					t_wall;

typedef struct		s_alpha
{
	t_mlx			mlx;
	t_map			map;
	t_ray			ray;
	t_wall			wall;
}					t_alpha;

# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

extern int		g_map[MAP_WIDTH][MAP_HEIGHT];

# endif

/*
** main.c
*/
int					main(int argc, char **argv);
int					wolf(t_alpha *vz);

/*
** keys.c
*/
int					ft_ladilla(int key, t_alpha *vz, double	oldir, \
								double oldplane);
int					key_hook(int k, t_alpha *vz);
int					exit_hook(t_alpha *vz);

/*
** initcol.c
*/
void				init(t_alpha *vz);
int					color(int grid);

/*
** raydir.c
*/
void				diray(t_alpha *vz, int x);
void				step(t_alpha *vz);

/*
** wall_col.c
*/
void				wall_col(t_alpha *vz, int hit);
/*
** draw_wall.c
*/
void				wall(t_alpha *vz);
void				draw(int x, t_alpha *vz, int grid);

#endif
