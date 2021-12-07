/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:34:57 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/07 12:21:12 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	call_fractol(t_window *win)
{
	if (ft_strcmp(win->frac.name, "Mandelbrot") == 0)
		mandelbrot(win);
	else if (ft_strcmp(win->frac.name, "Julia") == 0)
		julia(win);
	else if (ft_strcmp(win->frac.name, "Burning Ship") == 0)
		burning_ship(win);
	return (1);
}

static void	zoom(t_window *win, double z)
{
	double	mouse_down_x;
	double	mouse_down_y;
	double	mouse_focus_x;
	double	mouse_focus_y;

	mouse_down_x = (double)win->zoom.mouse_x / win->zoom.scale + \
															win->zoom.offset_x;
	mouse_down_y = (double)win->zoom.mouse_y / win->zoom.scale + \
															win->zoom.offset_y;
	win->zoom.scale *= z;
	mouse_focus_x = (double)win->zoom.mouse_x / win->zoom.scale + \
															win->zoom.offset_x;
	mouse_focus_y = (double)win->zoom.mouse_y / win->zoom.scale + \
															win->zoom.offset_y;
	win->zoom.offset_x += mouse_down_x - mouse_focus_x;
	win->zoom.offset_y += mouse_down_y - mouse_focus_y;
	mlx_destroy_image(win->pointer, win->img.pointer);
	init_image(win);
	call_fractol(win);
}

int	mouse_hook(int keycode, int x, int y, t_window *win)
{
	win->zoom.mouse_x = (double)x;
	win->zoom.mouse_y = (double)y;
	if (keycode == 7 || keycode == 4)
	{
		zoom(win, 1.1);
	}
	else if (keycode == 6 || keycode == 5)
	{
		zoom(win, 0.9);
	}
	return (1);
}
