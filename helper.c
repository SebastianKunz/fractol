/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:36:44 by skunz             #+#    #+#             */
/*   Updated: 2018/12/14 18:36:48 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color(int r, int g, int b)
{
	int c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	return (c);
}

void	ft_error(int code)
{
	if (code == 1)
		ft_putstr("usage: ./fractol [fractal]\n");
	else if (code == 2)
		ft_putstr("malloc failed\n");
	else if (code == 3)
		ft_putstr("error: no such fractal [julia] [mandelbrot] [ship]\n");
	exit(-1);
}

void	ft_init_view(t_view *view)
{
	view->zoom = 1;
	view->move_x = 0;
	view->move_y = 0;
	view->max_iter = 250;
}

void	ft_init_thread(t_thread *thread, t_view view, t_mlx mlx, int id)
{
	thread->id = id;
	thread->new_r = 0;
	thread->new_i = 0;
	thread->old_r = 0;
	thread->old_i = 0;
	thread->y_s = (HEIGHT / MAX_THREAD * id) - 1;
	thread->y_e = HEIGHT / MAX_THREAD * id + HEIGHT / MAX_THREAD;
	thread->data = mlx_get_data_addr(mlx.img_ptr[id], &thread->bpp,
			&thread->sizeline, &thread->endian);
	thread->view = view;
}

void	ft_init_mlx(t_mlx *mlx)
{
	int i;

	i = -1;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "My Fractol");
	mlx->img_ptr = malloc(sizeof(void*) * MAX_THREAD);
	while (++i < MAX_THREAD)
		mlx->img_ptr[i] = mlx_new_image(mlx->mlx_ptr, WIDTH,
			HEIGHT / MAX_THREAD);
}
