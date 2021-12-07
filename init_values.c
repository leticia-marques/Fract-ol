/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:41:24 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/07 11:15:48 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	init_values(t_window *win)
{
	win->zoom.scale = ((HEIGHT / 2) + (WIDTH / 2)) / 4;
	win->zoom.mouse_x = WIDTH / 2;
	win->zoom.mouse_y = HEIGHT / 2;
	win->zoom.offset_x = WIDTH / 2 / win->zoom.scale * -1;
	win->zoom.offset_y = HEIGHT / 2 / win->zoom.scale * -1;
	win->color = -1;
}

void	init_image(t_window *win)
{
	win->img.pointer = mlx_new_image(win->pointer, WIDTH, HEIGHT);
	win->img.data = mlx_get_data_addr(win->img.pointer, &win->img.bpp, \
										&win->img.line_len, &win->img.endian);
}

void	init_window(t_window *win)
{
	win->pointer = mlx_init();
	win->window = mlx_new_window(win->pointer, WIDTH, HEIGHT, win->frac.name);
	init_image(win);
}
