/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:45:56 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/06 16:50:14 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_window	*window;

	window = malloc(sizeof(t_window) * 1);
	init_values(window);
	check_arguments(window, argc, argv);
	mlx_hook(window->window, 2, 1L << 0, &key_map, window);
	mlx_expose_hook(window->window, &expose_hook, window);
	mlx_mouse_hook(window->window, &mouse_hook, window);
	mlx_hook(window->window, 17, 1L << 0, &clear_memory, window);
	mlx_loop(window->pointer);
}
