/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 02:26:40 by lemarque          #+#    #+#             */
/*   Updated: 2021/12/05 02:26:55 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

double	ft_atod(char *args)
{
	double	sign;
	double	double_args;
	int		float_point;

	float_point = 0;
	double_args = 0;
	sign = 1;
	if (*args == '-' || *args == '+')
	{
		if (*args == '-')
			sign = -1;
		args++;
	}
	while (ft_isdigit(*args))
	{
		double_args = (double_args * 10) + (*args - '0');
		args++;
	}
	if (*args == '.')
		args++;
	while (ft_isdigit(*args) && ++float_point)
		double_args = (double_args * 10) + (*(args++) - '0');
	while (float_point-- > 0)
		double_args *= 0.10;
	return (double_args * sign);
}
