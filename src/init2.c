/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:02:17 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/25 15:01:22 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_init_pixel(t_env *env)
{
	env->tmp.solution = -1;
	env->tmp.current = NULL;
	env->calc.solution = -1;
	env->cam.view_plane_point = ft_vect_op(ft_vect_op(env->cam.bot, '+', \
		ft_vect_op2(env->sdl.pos.x, '*', env->cam.x_inc)), '+', \
		ft_vect_op2(env->sdl.pos.y, '*', env->cam.y_inc));
	env->cam.pixel = ft_vect_op(env->cam.view_plane_point, '-', env->cam.pos);
	/*env->cam.pixel.x = env->cam.view_plane.x + env->cam.right.x * \
		XINDENT * env->sdl.pos.x - env->cam.up.x * \
		YINDENT * env->sdl.pos.y;
	env->cam.pixel.y = env->cam.view_plane.y + env->cam.right.y * \
		XINDENT * env->sdl.pos.x - env->cam.up.y * \
		YINDENT * env->sdl.pos.y;
	env->cam.pixel.z = env->cam.view_plane.z + env->cam.right.z * \
		XINDENT * env->sdl.pos.x - env->cam.up.z * \
		YINDENT * env->sdl.pos.y;*/
}

void	ft_init_set(t_env *env)
{
	env->set.tab = INTERFACE;
	env->set.select = 1;
	env->set.del = 0; 
	env->set.inc = 1; 
	env->set.nb[0] = 0;
	env->set.nb[1] = 0;
	env->set.nb[2] = 0;
	env->set.p[0] = 0;
	env->set.p[1] = 0;
	env->set.at = 1;
	env->set.id_o = 0;
	env->set.pos = 0;
	env->set.block = 0;
	env->set.obj[0] = env->obj;
	env->set.obj[1] = env->obj;
	env->set.obj[2] = NULL;
	env->set.obj[3] = env->obj;
	env->set.color[0].r = 239;
	env->set.color[0].g = 239;
	env->set.color[0].b = 239;
	env->set.color[1].r = 152;
	env->set.color[1].g = 42;
	env->set.color[1].b = 42;
}

void	ft_calc_angles(t_env *env)
{
	t_obj	*tmp;

	tmp = env->obj;
	while (env->obj)
	{
		if (env->obj->type != SPHERE)
		{
			env->obj->dir.x = 0;
			env->obj->dir.y = 0;
			env->obj->dir.z = 1;
			env->obj->dir = ft_vect_rot(env->obj->dir, env->obj->angles.z, 1);
			env->obj->dir = ft_vect_rot(env->obj->dir, env->obj->angles.y, 2);
			env->obj->dir = (env->obj->dir.x != 1 && env->obj->dir.x != -1) ? \
				ft_vect_rot(env->obj->dir, env->obj->angles.x, 3) : \
				ft_vect_rot(env->obj->dir, env->obj->angles.x, 1);
		}
		env->obj = env->obj->next;
	}
	env->obj = tmp;
}

void	ft_init_draw(t_env *env)
{
	if ((env->sdl.draw = SDL_CreateTexture(env->sdl.rend, \
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, \
			WIDTHR, HEIGHT)) == NULL)
		ft_error_sdl();
}
