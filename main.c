/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:40:25 by skunz             #+#    #+#             */
/*   Updated: 2018/12/13 17:40:48 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_start_julia(t_handler *handler)
{
	int			i;
	t_thread	*thread;

	i = -1;
	if (!(thread = malloc(sizeof(t_thread) * MAX_THREAD)))
		ft_error(2);
	while (++i < MAX_THREAD)
	{
		ft_init_thread(&thread[i], handler->view, handler->mlx, i);
		thread[i].c_r = -0.7;
		thread[i].c_i = 0.27015;
		thread[i].r = 4;
		thread[i].g = 4;
		thread[i].b = -50;
	}
	handler->thread = thread;
	handler->func = ft_draw_julia_thread;
	ft_draw_all(handler, handler->func);
}

void	ft_start_mandelbrot(t_handler *handler)
{
	int			i;
	t_thread	*thread;

	i = -1;
	if (!(thread = malloc(sizeof(t_thread) * MAX_THREAD)))
		ft_error(2);
	while (++i < MAX_THREAD)
	{
		ft_init_thread(&thread[i], handler->view, handler->mlx, i);
		thread[i].c_r = 0;
		thread[i].c_i = 0;
		thread[i].view.move_x = -0.2;
		thread[i].r = 14;
		thread[i].g = 14;
		thread[i].b = 10;
	}
	handler->thread = thread;
	handler->func = ft_draw_mandelbrot_thread;
	ft_draw_all(handler, handler->func);
}

void	ft_start_ship(t_handler *handler)
{
	int			i;
	t_thread	*thread;

	i = -1;
	if (!(thread = malloc(sizeof(t_thread) * MAX_THREAD)))
		ft_error(2);
	while (++i < MAX_THREAD)
	{
		ft_init_thread(&thread[i], handler->view, handler->mlx, i);
		thread[i].c_r = 0;
		thread[i].c_i = 0;
		thread[i].view.zoom = 0.65;
		thread[i].view.move_x = -0.35;
		thread[i].view.move_y = -0.5;
	}
	handler->thread = thread;
	handler->func = ft_draw_ship_thread;
	ft_draw_all(handler, handler->func);
}

void	ft_choose_fractal(char *arg, t_handler *handler)
{
	if (!ft_strcmp(arg, "julia"))
		ft_start_julia(handler);
	else if (!ft_strcmp(arg, "mandelbrot"))
		ft_start_mandelbrot(handler);
	else if (!ft_strcmp(arg, "ship"))
		ft_start_ship(handler);
	else
		ft_error(3);
}

int		main(int argc, char **argv)
{
	t_handler	handler;
	t_mlx		mlx;
	t_view		view;

	if (argc == 2)
	{
		ft_init_mlx(&mlx);
		ft_init_view(&view);
		handler.mlx = mlx;
		handler.view = view;
		ft_choose_fractal(argv[1], &handler);
		mlx_hook(mlx.win_ptr, 6, 0, ft_mousemove, (void*)&handler);
		mlx_hook(mlx.win_ptr, 4, 0, ft_mousepress, (void*)&handler);
		mlx_key_hook(mlx.win_ptr, ft_keydown, (void*)&handler);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		ft_error(1);
	return (0);
}
