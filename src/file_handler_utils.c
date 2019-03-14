/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:34:22 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/14 15:34:12 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int		ft_get_color(char *data, int z)
{
	char	*inf;

	inf = ft_strstr(data, ",0x");
	if (!inf)
	{
		if (z <= -5)
			return (C_BLUE);
		if (z <= 0)
			return (C_GREEN);
		if (z <= 5)
			return (C_YELLOW);
		if (z > 5)
			return (C_RED);
	}
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
