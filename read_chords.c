/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_chords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:40:09 by mhonchar          #+#    #+#             */
/*   Updated: 2019/02/05 18:36:23 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_del(char ** arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

int		ft_save_open(char *fname)
{
	char	*buf[BUFF_SIZE];
	int		fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (-1);
	if ((read(fd, buf, 0)) < 0)
		return (-1);
	
	return (fd);
}

int		ft_create_mtxr(t_matrix *mtrx)
{
	int		i;

	i = 0;
	if (!(mtrx->matrix = (t_point **)malloc(sizeof(t_point *) * (mtrx->row))))
		return (-1);
	while (i < mtrx->row)
	{
		if (!(mtrx->matrix[i] = (t_point *)malloc(sizeof(t_point) * (mtrx->cols))))
			return (-1);
		i++;
	}
	return (0);
}

int		ft_read_coords(char *fname, t_matrix *mtrx)
{
	int		fd;
	char	*line;
	char	**data;

	if ((fd = ft_save_open(fname)) == -1)
		return (-1);
	get_next_line(fd, &line);
	data = ft_strsplit(line, ' ');
	mtrx->cols = 0;
	while (data[mtrx->cols])
		mtrx->cols++;
	ft_del(data);
	free(line);
	mtrx->row = 1;
	while (get_next_line(fd, &line) == 1)
	{
		mtrx->row++;
		free(line);
	}
	free(line);
	close(fd);
	if (ft_create_mtxr(mtrx) == -1)
		return (-1);
	return (0);
}

int		ft_init_struct(char *fname, t_matrix *mtrx)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**data;

	if ((fd = ft_save_open(fname)) == -1)
		return (-1);
	i = 0;
	while (i < mtrx->row)
	{
		get_next_line(fd, &line);
		data = ft_strsplit(line, ' ');
		j = 0;
		while (j < mtrx->cols)
		{
			mtrx->matrix[i][j].x = j*15;
			mtrx->matrix[i][j].y = i*15;
			mtrx->matrix[i][j].z = ft_atoi(data[j])*15;
			j++;
		}
		i++;
		free(line);
		ft_del(data);
	}
	close(fd);
	return (0);
}