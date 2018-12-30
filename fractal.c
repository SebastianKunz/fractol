/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:39:31 by skunz             #+#    #+#             */
/*   Updated: 2018/12/15 16:39:32 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_draw_julia_thread(void *thread)
{
	t_thread	*t;
	int			i;
	int			x;

	t = (t_thread*)thread;
	while (++t->y_s < t->y_e)
	{
		x = -1;
		while (++x < WIDTH)
		{
			i = -1;
			t->new_r = 1.5 * (x - WIDTH / 2) / (0.5 * t->view.zoom * WIDTH)
				+ t->view.move_x;
			t->new_i = (t->y_s - HEIGHT / 2) / (0.5 * t->view.zoom * HEIGHT)
				+ t->view.move_y;
			while (((t->new_r * t->new_r + t->new_i * t->new_i) < 4)
				&& ++i < t->view.max_iter)
				ft_calc(t);
			put_pixel_in_img(t, x, t->y_s,
				ft_color(i % 255 + t->r, i % 255 + t->g,
					102 * (i < t->view.max_iter)) + t->b);
		}
	}
	return (NULL);
}

void	*ft_draw_mandelbrot_thread(void *thread)
{
	t_thread	*t;
	int			i;
	int			x;

	t = (t_thread*)thread;
	while (++t->y_s < t->y_e)
	{
		x = -1;
		while (++x < WIDTH)
		{
			i = -1;
			t->c_r = 1.5 * (x - WIDTH / 2) / (0.5 * t->view.zoom * WIDTH)
				+ t->view.move_x;
			t->c_i = (t->y_s - HEIGHT / 2) / (0.5 * t->view.zoom * HEIGHT)
				+ t->view.move_y;
			ft_set_zero(t);
			while (((t->new_r * t->new_r + t->new_i * t->new_i) < 4)
				&& ++i < t->view.max_iter)
				ft_calc(t);
			put_pixel_in_img(t, x, t->y_s,
				ft_color(i % 255 + t->r, i % 255 + t->g, i % 255 + t->b));
		}
	}
	return (NULL);
}

void	*ft_draw_ship_thread(void *thread)
{
	t_thread	*t;
	int			i;
	int			x;

	t = (t_thread*)thread;
	while (++t->y_s < t->y_e)
	{
		x = -1;
		while (++x < WIDTH)
		{
			i = -1;
			t->c_r = 1.5 * (x - WIDTH / 2) / (0.5 * t->view.zoom * WIDTH)
				+ t->view.move_x;
			t->c_i = (t->y_s - HEIGHT / 2) / (0.5 * t->view.zoom * HEIGHT)
				+ t->view.move_y;
			ft_set_zero(t);
			while (((t->new_r * t->new_r + t->new_i * t->new_i) < 4)
				&& ++i < t->view.max_iter)
				ft_calc_ship(t);
			put_pixel_in_img(t, x, t->y_s,
				ft_color(i % 255 + t->r, i % 255 + t->g, i % 255 + t->b));
		}
	}
	return (NULL);
}
