/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:28:03 by mhonchar          #+#    #+#             */
/*   Updated: 2019/02/19 19:17:14 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <math.h>






typedef struct	s_vector3
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_vector3;

typedef struct	s_rotation
{
	double	x;
	double	y;
	double	z;
}				t_rotation;

typedef struct	s_matrix
{
	t_vector3	**mtrx;
	t_rotation	radians;
	int			rows;
	int			cols;
}				t_matrix;

#endif