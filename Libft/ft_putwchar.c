/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:15:13 by ivelutin          #+#    #+#             */
/*   Updated: 2017/08/10 17:23:05 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putwchar(wchar_t ws)
{
	if (ws <= 127)
		ft_putchar(ws);
	else if (ws < 2048)
	{
		ft_putchar((ws >> 6) + 192);
		ft_putchar((ws & 63) + 128);
	}
	else if (ws < 65536)
	{
		ft_putchar((ws >> 12) + 224);
		ft_putchar(((ws >> 6) & 63) + 128);
		ft_putchar((ws & 63) + 128);
	}
	else if (ws < 1114112)
	{
		ft_putchar((ws >> 18) + 240);
		ft_putchar(((ws >> 12) & 63) + 128);
		ft_putchar(((ws >> 6) & 63) + 128);
		ft_putchar((ws & 63) + 128);
	}
}
