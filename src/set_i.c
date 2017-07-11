/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 14:59:00 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/26 16:49:34 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void    ft_interface(t_env *env)
{
	if ((env->sdl.tset[TINTER] = SDL_CreateTexture(env->sdl.rend, \
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTHS, \
			HEIGHT)) == NULL)
		ft_error_sdl();
	SDL_SetRenderTarget(env->sdl.rend, env->sdl.tset[TINTER]);
	env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/interface.bmp");
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TIMG], NULL, NULL);
	SDL_DestroyTexture(env->sdl.tset[TIMG]);
	ft_text_interface(env, 1);
	ft_text_interface(env, 2);
	SDL_SetRenderTarget(env->sdl.rend, NULL);
}

void	ft_text_interface(t_env *env, int text)
{
	ft_text_cases_interface(env, text);
	if ((env->sdl.tset[TTEXT] = SDL_CreateTextureFromSurface(env->sdl.rend, \
			env->sdl.text)) == NULL)
		ft_error_sdl();
	SDL_QueryTexture(env->sdl.tset[TTEXT], NULL, NULL, &env->sdl.rset[DTEXT].w\
		, &env->sdl.rset[DTEXT].h);
	env->sdl.rset[DTEXT].x = ((WIDTHS / 2) - (env->sdl.rset[DTEXT].w / 2));
	env->sdl.rset[DTEXT].y = HEIGHT / 3 + env->set.pos;
	SDL_FreeSurface(env->sdl.text);
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TTEXT], NULL, \
		&env->sdl.rset[DTEXT]);
	env->set.pos = (env->set.pos == 100) ? 0 : env->set.pos + 100;
}

void    ft_text_cases_interface(t_env *env, int text)
{
	if (text == 1)
	{
			if ((env->sdl.text = TTF_RenderText_Blended(env->sdl.font, \
					"Objects", env->set.color[(env->set.select == 1) ? 1 : 0]))\
					== NULL)
			ft_error_sdl();
	}
	if (text == 2)
	{
		if ((env->sdl.text = TTF_RenderText_Blended(env->sdl.font, "Lights", \
				env->set.color[(env->set.select == 2) ? 1 : 0])) == NULL)
			ft_error_sdl();
	}
}
void	ft_ev_inter(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
			env->set.select = (env->set.select == 2) ? 1 : 2;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
			env->set.select = (env->set.select == 2) ? 1 : 2;
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		env->set.tab = (env->set.select == 1) ? OBJECTS : LIGHTS;
		env->set.select = 1;
		env->set.pos = 0;
		if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 30)) == NULL)
			ft_error_sdl();
		SDL_DestroyTexture(env->sdl.tset[TINTER]);
	}
}
