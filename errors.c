/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:40:13 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/09 14:25:13 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	clear_memory(t_window *win)
{
	if (win->img.pointer)
		mlx_destroy_image(win->pointer, win->img.pointer);
	if (win->window)
		mlx_destroy_window(win->pointer, win->window);
	if (win->pointer)
		mlx_destroy_display(win->pointer);
	free(win->pointer);
	free(win);
	exit(1);
}

void	errors(int n, t_window *win)
{
	if (n == 1)
	{
		printf("Not enough arguments\n");
		printf("Type Julia, Mandelbrot or burning-ship.");
	}
	else if (n == 2)
	{
		printf("Wrong arguments.\n");
		printf("If you're trying to render a Julia fractol you must pass");
		printf(" the values for Real C and Imaginary C, like so: './fractol");
		printf(" julia 0 0.8i'");
		printf(" Or you can try Mandelbrot and Burning-ship. Using either ");
		printf("'./fractol mandelbrot' or './fractol burning-ship");
	}
	clear_memory(win);
}
