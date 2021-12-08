/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:27:11 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/08 16:49:08 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	check_values(t_window *win, char **args)
{
	int	i;
	int	i_sign;
	int	dot;
	int	sign;

	i = 0;
	i_sign = 0;
	dot = 0;
	sign = 0;
	while (args[1][i] != '\0' && (ft_isascii(args[1][i]) == 1 || \
			args[1][i] == '.'))
	{
		if (args[1][i] == '+' || args[1][i] == '-')
			sign++;
		if (args[1][i] == '.')
			dot++;
		if (ft_isalpha(args[1][i]) == 1 && args[1][i] != 'i')
			return (errors(2, win));
		if (args[1][i] == 'i')
			i_sign++;
		if (i_sign > 1 || dot > 1 || sign > 1)
			return (errors(2, win));
		i++;
	}
}
