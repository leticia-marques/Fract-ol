/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:44:03 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/06 16:56:59 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static void	update_values(t_window *win)
{
	double	d;

	while (pow(win->z.real, 2) + pow(win->z.im, 2) <= 4 && \
														win->frac.iteration > 1)
	{
		d = pow(win->z.real, 2) - pow(win->z.im, 2) + win->c.real;
		win->z.im = (2.0 * win->z.real * win->z.im) + win->c.im;
		win->z.real = d;
		win->frac.iteration--;
	}
}

void	julia(t_window *win)
{
	win->frac.y = 0;
	while (win->frac.y < HEIGHT)
	{
		win->frac.x = 0;
		while (win->frac.x < WIDTH)
		{
			win->z.im = win->frac.y / win->zoom.scale + \
															win->zoom.offset_y;
			win->z.real = win->frac.x / win->zoom.scale + \
															win->zoom.offset_x;
			win->frac.iteration = MAX;
			update_values(win);
			if (win->frac.iteration > 2)
				get_color(win, win->frac.iteration);
			else
				win->img.data[(win->frac.y * win->img.line_len) + \
												(win->frac.x * 4)] = 0x000000;
			win->frac.x++;
		}
		win->frac.y++;
	}
	mlx_put_image_to_window(win->pointer, win->window, win->img.pointer, \
							0, 0);
}
