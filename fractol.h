/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:59:08 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/08 09:40:50 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include"mlx.h"
# include<stdlib.h>
# include<math.h>
# include"libft.h"
# include<stdio.h>

# define MAX 200
# define HEIGHT 500
# define WIDTH 800

typedef struct s_image
{
	void	*pointer;
	char	*data;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_fractol
{
	int		iteration;
	int		y;
	int		x;
	double	factor_real;
	double	factor_im;
	char	*name;

}			t_fractol;

typedef struct s_color
{
	double			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

}			t_color;

typedef struct s_zoom
{
	int		mouse_x;
	int		mouse_y;
	double	offset_x;
	double	offset_y;
	double	scale;
}			t_zoom;

typedef struct s_complex
{
	double	real;
	double	im;
}			t_complex;

typedef struct s_window
{
	void		*pointer;
	void		*window;
	t_image		img;
	t_fractol	frac;
	t_zoom		zoom;
	t_complex	z;
	t_complex	c;
	int			color;
}			t_window;

void	mandelbrot(t_window *window);
void	julia(t_window *window);
void	burning_ship(t_window *win);
void	get_color(t_window *win, int i);
int		mouse_hook(int keycode, int x, int y, t_window *win);
void	init_values(t_window *win);
void	init_window(t_window *win);
void	init_image(t_window *win);
void	check_arguments(t_window *win, int argc, char **argv);
int		ft_strcmp(char *str, char *str2);
void	errors(int n, t_window *win);
void	get_words_number(char *str, char c, t_window *win);
int		key_map(int keycode, t_window *win);
int		clear_memory(t_window *win);
int		call_fractol(t_window *win);
int		expose_hook(t_window *win);
void	check_values(t_window *win, char **args);
#endif
