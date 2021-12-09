/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:45:07 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/08 19:49:40 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	expose_hook(t_window *win)
{
	mlx_put_image_to_window(win->pointer, win->window, win->img.pointer, 0, 0);
	return (1);
}

int	key_map(int keycode, t_window *win)
{
	if (keycode == 99)
		win->color = (win->color + 1) % 6;
	if (keycode == 65307)
		clear_memory(win);
	if (keycode == 65362)
		win->zoom.offset_y -= win->zoom.offset_y * 0.01;
	if (keycode == 65364)
		win->zoom.offset_y += win->zoom.offset_y * 0.01;
	if (keycode == 65361)
		win->zoom.offset_x -= win->zoom.offset_x * 0.1;
	if (keycode == 65363)
		win->zoom.offset_x += win->zoom.offset_x * 0.01;
	mlx_destroy_image(win->pointer, win->img.pointer);
	init_image(win);
	call_fractol(win);
	return (1);
}
