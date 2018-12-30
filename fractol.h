/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:38:31 by skunz             #+#    #+#             */
/*   Updated: 2018/12/14 18:38:33 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_THREAD 72

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		**img_ptr;
}				t_mlx;

typedef struct	s_view
{
	double		zoom;
	double		move_x;
	double		move_y;
	int			max_iter;
}				t_view;

typedef struct	s_thread
{
	int			id;
	double		c_r;
	double		c_i;
	double		new_r;
	double		new_i;
	double		old_r;
	double		old_i;
	int			y_s;
	int			y_e;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	char		r;
	char		g;
	char		b;
	t_view		view;
}				t_thread;

typedef struct	s_handler
{
	t_mlx		mlx;
	t_thread	*thread;
	t_view		view;
	void		*func;
}				t_handler;

/*
** helper.c
*/

int				ft_color(int r, int g, int b);
void			ft_init_mlx(t_mlx *mlx);
void			ft_init_view(t_view *view);
void			ft_init_thread(t_thread *thread, t_view view,
					t_mlx mlx, int id);
void			ft_error(int code);

/*
** fractal.c
*/

void			*ft_draw_julia_thread(void *t);
void			*ft_draw_mandelbrot_thread(void *t);
void			*ft_draw_ship_thread(void *thread);

/*
** draw.c
*/

void			put_pixel_in_img(t_thread *thread, int x, int y, int color);
void			ft_draw_all(t_handler *handler, void *func);

/*
** eventhandler.c
*/

int				ft_keydown(int key, void *param);
int				ft_mousemove(int x, int y, void *param);
int				ft_mousepress(int button, int x, int y, void *param);

/*
** update.c
*/

void			ft_update_view(t_handler *handler, double zoom,
					double move_x, double move_y);
void			ft_update_const(t_handler *handler, double c_r, double c_i);
void			ft_update_color(t_handler *handler, char r, char g, char b);
void			ft_update_lsd(t_handler *handler);
void			ft_set_default_color(t_handler *handler);

/*
** calchelper.c
*/

void			ft_calc_ship(t_thread *t);
void			ft_set_zero(t_thread *t);
void			ft_calc(t_thread *t);

#endif
