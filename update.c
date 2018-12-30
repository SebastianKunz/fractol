/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:11:21 by skunz             #+#    #+#             */
/*   Updated: 2018/12/15 14:11:22 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_update_view(t_handler *handler, double zoom,
			double move_x, double move_y)
{
	int i;

	i = -1;
	while (++i < MAX_THREAD)
	{
		ft_init_thread(&handler->thread[i], handler->thread[i].view,
			handler->mlx, i);
		handler->thread[i].view.zoom += zoom;
		handler->thread[i].view.move_x += move_x;
		handler->thread[i].view.move_y += move_y;
	}
}

void	ft_update_const(t_handler *handler, double c_r, double c_i)
{
	int i;

	i = -1;
	while (++i < MAX_THREAD)
	{
		ft_init_thread(&handler->thread[i], handler->thread[i].view,
			handler->mlx, i);
		handler->thread[i].c_r += c_r;
		handler->thread[i].c_i += c_i;
	}
}

void	ft_update_color(t_handler *handler, char r, char g, char b)
{
	int i;

	i = -1;
	while (++i < MAX_THREAD)
	{
		ft_init_thread(&handler->thread[i], handler->thread[i].view,
			handler->mlx, i);
		handler->thread[i].r += r;
		handler->thread[i].g += g;
		handler->thread[i].b += b;
	}
}

void	ft_update_lsd(t_handler *handler)
{
	int i;
	int num;
	int upper;
	int lower;

	upper = 255;
	lower = 0;
	i = -1;
	while (++i < MAX_THREAD)
	{
		ft_init_thread(&handler->thread[i], handler->thread[i].view,
			handler->mlx, i);
		num = (rand() % (upper - lower + 1)) + lower;
		handler->thread[i].r = num;
		num = (rand() % (upper - lower + 1)) + lower;
		handler->thread[i].g = num;
		num = (rand() % (upper - lower + 1)) + lower;
		handler->thread[i].b = num;
	}
}

void	ft_set_default_color(t_handler *handler)
{
	int i;

	i = -1;
	while (++i < MAX_THREAD)
	{
		ft_init_thread(&handler->thread[i], handler->thread[i].view,
			handler->mlx, i);
		if (handler->func == ft_draw_julia_thread)
		{
			handler->thread[i].r = 4;
			handler->thread[i].g = 4;
			handler->thread[i].b = -50;
		}
		else if (handler->func == ft_draw_mandelbrot_thread)
		{
			handler->thread[i].r = 14;
			handler->thread[i].g = 14;
			handler->thread[i].b = 10;
		}
	}
}
