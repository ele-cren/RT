/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_at.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:07:16 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/11 13:48:01 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_ev_at_dub(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == 6) ? 1 : env->set.select + 1;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 1) ? 6 : env->set.select - 1;
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		ft_init_set(env);
		env->set.tab = OBJECTS;
	}
}

void	ft_ev_at_return1(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		if (env->set.p[1] == 0)
		{
			if (env->set.select == 1)
			{
				ft_add_elem_obj(env);
				env->tmp.current = NULL;
				SDL_DestroyTexture(env->sdl.draw);
				ft_browse_pixels(env);
				env->parse.objects++;
				ft_init_set(env);
				env->set.tab = OBJECTS;
			}
			else if (env->set.select == 2)
				ft_ev_at_return2(env);
			else if (env->set.select == 3 || env->set.select == 4 || \
					env->set.select == 5)
				ft_ev_at_return3(env);
		}
	}
}

void	ft_ev_at_return2(t_env *env)
{
	ft_stock_elem(env);
	ft_delete_elem_obj(env);
	ft_init_set(env);
	env->set.del = 1;
	SDL_DestroyTexture(env->sdl.draw);
	ft_browse_pixels(env);
	env->parse.objects--;
	env->set.tab = OBJECTS;
	if (env->parse.objects == 0)
	{
		if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 50)) == NULL)
			ft_error_sdl();
		env->set.tab = INTERFACE;
	}
}

void	ft_ev_at_return3(t_env *env)
{
	if (env->set.select == 3)
	{
		env->set.tab = POSTAB;
		env->set.select = 2;
	}
	else if (env->set.select == 4)
	{
		env->set.tab = DIRTAB;
		env->set.select = 2;
	}
	else if (env->set.select == 5)
	{
		env->set.tab = COLTAB;
		env->set.select = 2;
	}
}
