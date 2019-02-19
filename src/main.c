/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:27:08 by mhonchar          #+#    #+#             */
/*   Updated: 2019/02/19 19:19:15 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main()
{

	printf("Hello World!\n");
	return (0);
}

	/*
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "fdf");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	create_img(&mlx);
	draw_net(points, mlx.pixels);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 10, 10);
	mlx_key_hook(mlx.win_ptr, deal_key, (void*)(&mlx));
	
	mlx_loop(mlx.mlx_ptr);
	*/