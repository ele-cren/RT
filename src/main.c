/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:42:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/12 11:35:08 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		main(int ac, char **av)
{
	t_env	env;
	int		i;

	if (ac == 2)
	{
		i = 1;
		ft_parse(&env, av[1]);
		ft_init_sdl(&env);
		ft_init_set(&env);
		ft_calc_angles(&env);
		ft_settings(&env);
		/*while (env.obj)
		{
			printf("obj %d type :%d\n", i, env.obj->type);
			printf("obj %d tex :%d\n", i, env.obj->tex);
			printf("obj %d radius :%d\n", i, env.obj->radius);
			printf("obj %d pos x %f y %f z %f\n", i, env.obj->pos.x, \
					env.obj->pos.y, env.obj->pos.z);
			printf("obj %d angles x %f y %f z %f\n", i, env.obj->angles.x, \
					env.obj->angles.y, env.obj->angles.z);
			printf("obj %d angle %d\n", i, env.obj->angle);
			printf("obj %d reflexion %d\n", i, env.obj->ref);
			printf("obj %d color red %d green %d blue %d\n", i, \
			env.obj->color.red, env.obj->color.green, env.obj->color.blue);
			printf("obj %d tile red %d green %d blue %d, w %d\n", i, \
			env.obj->tile.red, env.obj->tile.green, env.obj->tile.blue, \
			env.obj->tile.w);
			printf("obj %d finished %d\n", i, env.obj->finished);
			printf("obj %d min %d max %d\n", i, env.obj->fin[0], env.obj->fin[1]);
			i++;
			env.obj = env.obj->next;
		}*/
		ft_browse_pixels(&env);
		ft_display(&env);
		while (env.sdl.keep)
		{
			SDL_WaitEvent(&env.sdl.event);
			if (env.sdl.event.type == SDL_QUIT || \
								env.sdl.event.key.keysym.sym == SDLK_ESCAPE)
				env.sdl.keep = 0;
			if (env.sdl.event.type == SDL_KEYDOWN)
			{
				ft_event(&env);
				ft_settings(&env);
				ft_display(&env);
			}
		}
		SDL_DestroyRenderer(env.sdl.rend);
		SDL_DestroyWindow(env.sdl.win);
		SDL_Quit();
	}
	else
		ft_putendl("Usage : ./rt scene");
	return (0);
}
