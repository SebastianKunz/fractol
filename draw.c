/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:38:02 by skunz             #+#    #+#             */
/*   Updated: 2018/12/14 18:38:05 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_in_img(t_thread *thread, int x, int y, int color)
{
	int sub;

	sub = HEIGHT / MAX_THREAD;
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
		*(int *)&thread->data[(x * thread->bpp >> 3) +
			((y - sub * thread->id) * thread->sizeline)] = color;
}

void	ft_draw_all(t_handler *handler, void *func)
{
	int			i;
	pthread_t	work[MAX_THREAD];

	i = -1;
	while (++i < MAX_THREAD)
		pthread_create(&work[i], NULL, func, (void*)&handler->thread[i]);
	i = -1;
	while (++i < MAX_THREAD)
		pthread_join(work[i], NULL);
	i = -1;
	while (++i < MAX_THREAD)
		mlx_put_image_to_window(handler->mlx.mlx_ptr, handler->mlx.win_ptr,
			handler->mlx.img_ptr[i], 0, HEIGHT / MAX_THREAD * i);
}
