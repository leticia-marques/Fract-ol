/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:38:00 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/08 10:41:04 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static void	att_pixel(t_window *win, int color)
{
	int	pixel;

	pixel = (win->frac.y * win->img.line_len) + (win->frac.x * 4);
	if (win->img.endian == 1)
	{
		win->img.data[pixel + 0] = (color >> 24) & 0xFF;
		win->img.data[pixel + 1] = (color >> 16) & 0xFF;
		win->img.data[pixel + 2] = (color >> 8) & 0xFF;
		win->img.data[pixel + 3] = (color) & 0xFF;
	}
	else if (win->img.endian == 0)
	{
		win->img.data[pixel + 0] = (color) & 0xFF;
		win->img.data[pixel + 1] = (color >> 8) & 0xFF;
		win->img.data[pixel + 2] = (color >> 16) & 0xFF;
		win->img.data[pixel + 3] = (color >> 24) & 0xFF;
	}
}

void	get_color(t_window *win, int i)
{
	t_color		color;

	color.t = pow(log(((double)(i % 128))) / log(128.0), 2);
	if (color.t < 0.99)
	{
		color.r = 8 * (1 - color.t) * pow(color.t, 3) * 255;
		color.g = 16 * pow((1 - color.t), 2) * pow(color.t, 2) * 255;
		color.b = 8.5 * pow((1 - color.t), 3) * color.t * 255;
		att_pixel(win, (color.r << 16 | color.g << 8 | color.b));
		if (win->color == 0)
			att_pixel(win, (color.r << 16 | color.g << 8 | color.b));
		else if (win->color == 1)
			att_pixel(win, (color.r << 16 | color.b << 8 | color.g));
		else if (win->color == 2)
			att_pixel(win, (color.g << 16 | color.b << 8 | color.r));
		else if (win->color == 3)
			att_pixel(win, (color.g << 16 | color.r << 8 | color.b));
		else if (win->color == 4)
			att_pixel(win, (color.b << 16 | color.r << 8 | color.g));
		else if (win->color == 5)
			att_pixel(win, (color.b << 16 | color.g << 8 | color.r));
	}
}
