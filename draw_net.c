/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_net.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:18:27 by mhonchar          #+#    #+#             */
/*   Updated: 2019/01/22 17:24:56 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_net(t_matrix *m, char *pixels)
{
    int     i;
    int     j;

    i = -1;
    while (++i < m->row - 1)
    {
        j = -1;
        while (++j < m->cols - 1)
        {
            ft_draw_line_img(pixels, m->matrix[i][j], m->matrix[i][j + 1], 0xFFFFFF);
            ft_draw_line_img(pixels, m->matrix[i][j], m->matrix[i + 1][j], 0xFFFFFF);
        }
        ft_draw_line_img(pixels, m->matrix[i][m->cols - 1], m->matrix[i + 1][m->cols - 1], 0xFFFFFF);
    }
    i = -1;
    while (++i < m->cols - 1)
        ft_draw_line_img(pixels, m->matrix[m->row - 1][i], m->matrix[m->row - 1][i + 1], 0xFFFFFF);
}