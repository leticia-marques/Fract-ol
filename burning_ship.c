/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:33:45 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/06 14:01:37 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static void	update_values(t_window *win)
{
	double	d;

	while (pow(win->z.real, 2) + pow(win->z.im, 2) <= 4 && \
													win->frac.iteration < MAX)
	{
		d = pow(win->z.real, 2) - pow(win->z.im, 2) + win->c.real;
		win->z.im = fabs(2 * win->z.real * win->z.im) + win->c.im;
		win->z.real = d;
		win->frac.iteration++;
	}
}

void	burning_ship(t_window *win)
{
	win->frac.y = 0;
	while (win->frac.y < HEIGHT)
	{
		win->frac.x = 0;
		while (win->frac.x < WIDTH)
		{
			win->c.real = win->frac.x / win->zoom.scale + win->zoom.offset_x;
			win->c.im = win->frac.y / win->zoom.scale + win->zoom.offset_y;
			win->z.real = 0;
			win->z.im = 0;
			win->frac.iteration = 0;
			update_values(win);
			if (win->frac.iteration < MAX)
				get_color(win, win->frac.iteration);
			else
				win->img.data[(win->frac.y * win->img.line_len) + \
												(win->frac.x * 4)] = 0x000000;
			win->frac.x++;
		}
		win->frac.y++;
	}
	mlx_put_image_to_window(win->pointer, win->window, win->img.pointer, 0, 0);
}
