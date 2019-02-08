/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:27:26 by mhonchar          #+#    #+#             */
/*   Updated: 2019/02/08 17:47:27 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	x_rotate(t_matrix *m, int way)
{
	int		i;
	int		j;
	double	angle;

	angle = 0.314159265 * way;
	i = -1;
	while (++i < m->row)
	{
		j = -1;
		while (++j < m->cols)
		{
			m->matrix[i][j].y = m->matrix[i][j].y * cos(angle) + m->matrix[i][j].z * sin(angle);
			m->matrix[i][j].z = -m->matrix[i][j].y * sin(angle) + m->matrix[i][j].z * cos(angle);
		}
		
	}
}

void	y_rotate(t_matrix *m, int way)
{
	int		i;
	int		j;
	double	angle;

	i = -1;
	angle = 0.314159265 * way;
	while (++i < m->row)
	{
		j = -1;
		while (++j < m->cols)
		{
			m->matrix[i][j].x = m->matrix[i][j].x * cos(angle) + m->matrix[i][j].z * sin(angle);
			m->matrix[i][j].z = -m->matrix[i][j].x * sin(-angle) + m->matrix[i][j].z * cos(-angle);
		}
		
	}
}

void	z_rotate(t_matrix *m, int way)
{
	int		i;
	int		j;
	double	angle;
	
	i = -1;
	angle = 0.314159265 * way;
	while (++i < m->row)
	{
		j = -1;
		while (++j < m->cols)
		{
			m->matrix[i][j].x = m->matrix[i][j].x * cos(angle) - m->matrix[i][j].y * sin(angle);
			m->matrix[i][j].y = -m->matrix[i][j].x * sin(-angle) + m->matrix[i][j].y * cos(-angle);
		}
		
	}
}