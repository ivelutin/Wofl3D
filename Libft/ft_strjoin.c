/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:10:23 by ivelutin          #+#    #+#             */
/*   Updated: 2017/01/13 16:10:24 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		len;

	fresh = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ft_strcpy(fresh, s1);
		ft_strcat(fresh, s2);
	}
	return (fresh);
}
