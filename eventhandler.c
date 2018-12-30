/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:00:00 by skunz             #+#    #+#             */
/*   Updated: 2018/12/14 20:00:01 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** ESC (53) and Q (12) exit the program
** Left Arrow (123) to move the fractol left
** Right Arrow (124) to move the fractol right
** Down Arrow (125) to move the fractol down
** Up Arrow (126) to move the fractol up
** 1 Key (18) increase red by 10
** 2 Key (19) decrease red by 10
** 3 Key (20) increase green by 10
** 4 Key (21) decrease green by 10
** 5 Key (23) increase blue by 10
** 6 Key (22) decrease blue by 10
*/

int		ft_keydown(int key, void *param)
{
	t_handler *handler;

	handler = (t_handler*)param;
	if (key == 53 || key == 12)
		exit(1);
	(key == 123) ? ft_update_view(handler, 0, -0.05, 0) : (0);
	(key == 124) ? ft_update_view(handler, 0, 0.05, 0) : (0);
	(key == 125) ? ft_update_view(handler, 0, 0, 0.05) : (0);
	(key == 126) ? ft_update_view(handler, 0, 0, -0.05) : (0);
	(key == 18) ? ft_update_color(handler, 10, 0, 0) : (0);
	(key == 19) ? ft_update_color(handler, -10, 0, 0) : (0);
	(key == 20) ? ft_update_color(handler, 0, 10, 0) : (0);
	(key == 21) ? ft_update_color(handler, 0, -10, 0) : (0);
	(key == 23) ? ft_update_color(handler, 0, 0, 10) : (0);
	(key == 22) ? ft_update_color(handler, 0, 0, -10) : (0);
	(key == 37) ? ft_update_lsd(handler) : (0);
	(key == 15) ? ft_set_default_color(handler) : (0);
	if ((key >= 123 && key <= 126) || (key >= 18 && key <= 23) ||
		key == 37 || key == 15)
		ft_draw_all(handler, handler->func);
	return (0);
}

/*
** Changes the constant of the julia-set
** static variables are used to identify where the mouse moved
*/

int		ft_mousemove(int x, int y, void *param)
{
	t_handler	*handler;
	static int	px;
	static int	py;

	handler = (t_handler*)param;
	if (handler->func == ft_draw_julia_thread)
	{
		if (x > px)
			ft_update_const(handler, 0.0005, 0);
		else
			ft_update_const(handler, -0.0005, 0);
		if (y > py)
			ft_update_const(handler, 0, -0.0005);
		else
			ft_update_const(handler, 0, 0.0005);
		px = x;
		py = y;
		ft_draw_all(handler, handler->func);
	}
	return (0);
}

/*
** This function is used to zoom in and out with the mouse wheel
** button 4: scroll up
** button 5: scroll down
*/

int		ft_mousepress(int button, int x, int y, void *param)
{
	t_handler *handler;

	handler = (t_handler*)param;
	if (button == 4)
	{
		ft_update_view(handler, 0.1, 0, 0);
		ft_draw_all(handler, handler->func);
	}
	else if (button == 5)
	{
		ft_update_view(handler, -0.1, 0, 0);
		ft_draw_all(handler, handler->func);
	}
	return (0);
}
