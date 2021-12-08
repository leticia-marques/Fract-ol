/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:32:34 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/08 17:18:22 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static void	is_im_valid(char **args, t_window *win)
{
	int	size;
	int	i_sign;

	size = ft_strlen(args[1]);
	i_sign = args[1][size - 1] == 'i';
	if (!i_sign)
		return (errors(2, win));
	check_values(win, args);
	args[1][size - 1] = '\0';
	win->c.real = ft_atod(args[0]);
	win->c.im = ft_atod(args[1]);
}

static void	is_real_valid(char **args, t_window *win)
{
	int	i;
	int	dot;
	int	sign;

	dot = 0;
	i = 0;
	while ((args[0][i] != '\0' && (ft_isascii(args[0][i]) == 1)) || \
			args[0][i] == '.')
	{
		if (args[0][i] == '+' || args[0][i] == '-')
			sign++;
		if (args[0][i] == '.')
			dot++;
		if (ft_isalpha(args[0][i]) == 1 && args[0][i] != 'i')
			return (errors(2, win));
		if (args[0][i] == 'i')
			return (errors(2, win));
		if ((args[0][i] == '.' && args[0][i++] == '\0') || dot > 1 || sign > 1)
			return (errors(2, win));
		i++;
	}
	is_im_valid(args, win);
}

void	get_words_number(char *str, char c, t_window *win)
{
	int		d;
	char	**args;
	char	*aux;

	d = 0;
	aux = str;
	while (*aux)
	{
		while (*aux == c)
			aux++;
		if (*aux && (*aux != c))
			d++;
		while (*aux && (*aux != c))
			aux++;
	}
	if (d < 2)
		return (errors(1, win));
	args = ft_split(str, ' ');
	is_real_valid(args, win);
}

void	set_julia_values(t_window *win, char **argv, int argc)
{
	char	*tmp;
	char	*new_string;

	win->frac.name = "Julia";
	if (argc == 3)
		get_words_number(argv[2], ' ', win);
	else if (argc > 3)
	{
		new_string = ft_strjoin(argv[2], " ");
		tmp = new_string;
		new_string = ft_strjoin(new_string, argv[3]);
		free(tmp);
		get_words_number(new_string, ' ', win);
		free(new_string);
	}
}

void	check_arguments(t_window *win, int argc, char **argv)
{
	if (argc < 2)
		errors(1, win);
	ft_strlower(argv[1]);
	if (ft_strcmp(argv[1], "julia") == 0 && argc > 3)
		set_julia_values(win, argv, argc);
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		win->frac.name = "Mandelbrot";
	else if (ft_strcmp(argv[1], "burningship") == 0 || \
										ft_strcmp(argv[1], "burning-ship") == 0)
		win->frac.name = "Burning Ship";
	else
		errors(2, win);
	init_window(win);
	call_fractol(win);
}
