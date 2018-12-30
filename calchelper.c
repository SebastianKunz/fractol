/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calchelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:46:17 by skunz             #+#    #+#             */
/*   Updated: 2018/12/15 16:46:18 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc_ship(t_thread *t)
{
	t->old_r = t->new_r;
	t->old_i = t->new_i;
	t->new_r = pow(fabs(t->old_r - t->old_i), 2) + t->c_r;
	t->new_i = 2 * t->old_r * t->old_i + t->c_i;
}

void	ft_set_zero(t_thread *t)
{
	t->new_r = 0;
	t->new_i = 0;
	t->old_r = 0;
	t->old_i = 0;
}

void	ft_calc(t_thread *t)
{
	t->old_r = t->new_r;
	t->old_i = t->new_i;
	t->new_r = t->old_r * t->old_r - t->old_i * t->old_i + t->c_r;
	t->new_i = 2 * t->old_r * t->old_i + t->c_i;
}
