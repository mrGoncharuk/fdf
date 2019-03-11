/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:55:24 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/11 17:38:35 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_del(char **arr)
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

int		ft_hex_to_dec(char *hex)
{
	int		hex_len;
	int		nb;
	int		i;
	char	c;

	hex_len = ft_strlen(hex);
	nb = 0;
	i = 0;
	while (i < hex_len)
	{
		c = hex[i];
		if (ft_isdigit(hex[i]))
			c -= '0';
		else if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
			c = ft_toupper(c) - 'A' + 10;
		nb += c * ft_pow(16, ((hex_len - i) - 1));
		i++;
	}
	return (nb);
}

int		ft_get_color(char *data)
{
	char	*inf;

	inf = ft_strstr(data, ",0x");
	if (!inf)
		return (C_WHITE);
	return (ft_hex_to_dec(inf + 3));
	
}

int		ft_2darr_len(char **arr)
{
	int		i;

	if (arr == NULL)
		return (-1);
	i = 0;
	while (*(arr + i))
		i++;
	return (i);
}

int		ft_mtrxalloc(t_matrix *m)
{
	int		i;

	i = 0;
	if (!(m->m = (t_vector3 **)malloc(sizeof(t_vector3 *) * (m->rows))))
		return (-1);
	while (i < m->rows)
	{
		if (!(m->m[i] = (t_vector3 *)malloc(sizeof(t_vector3) * (m->cols))))
			return (-1);
		ft_bzero(m->m[i], sizeof(t_vector3) * (m->cols));
		i++;
	}
	return (0);
}

int		ft_init_struct(t_matrix *mtrx, t_list *f)
{
	int		i;
	int		j;
	char	**data;

	i = 0;
	while (i < mtrx->rows)
	{
		data = ft_strsplit(((char *)f->content), ' ');
		if (ft_2darr_len(data) != mtrx->cols)
			return (-1);
		j = 0;
		while (j < mtrx->cols)
		{
			mtrx->m[i][j].x = j;
			mtrx->m[i][j].y = i;
			mtrx->m[i][j].z = ft_atoi(data[j]);
			mtrx->m[i][j].color = ft_get_color(data[j]);
			j++;
		}
		f = f->next;
		i++;
		ft_del(data);
	}
	return (0);
}

int		ft_list_init(t_list **f, t_win *win, char *fname)
{
	int		fd;
	t_list	*next;
	char	**data;

	if (!(fd = open(fname, O_RDONLY)) || fd < 0)
		return (-1);
	(*f) = ft_lstnew(NULL, 0);
	next = (*f);
	while (get_next_line(fd, (char **)&(next->content)))
	{
		next->next = ft_lstnew(NULL, 0);
		next = next->next;
	}
	close(fd);
	next = (*f);
	win->mtrx.rows = 0;
	while (next->next != NULL)
	{
		next = next->next;
		win->mtrx.rows++;
	}
	data = ft_strsplit((char *)((*f)->content), ' ');
	win->mtrx.cols = ft_2darr_len(data);
	ft_del(data);
	return (0);
}

int		ft_get_map(t_win *win, char *fname)
{
	t_list	*f;
	t_list	*next;

	ft_list_init(&f, win, fname);
	ft_mtrxalloc(&(win->mtrx));
	ft_init_struct(&(win->mtrx), f);
	while (f)
	{
		next = f->next;
		free(f->content);
		free(f);
		f = next;
	}
	win->draw_mtrx.cols = win->mtrx.cols;
	win->draw_mtrx.rows = win->mtrx.rows;
	ft_mtrxalloc(&(win->draw_mtrx));
	return (0);
}
