/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:18:21 by ivelutin          #+#    #+#             */
/*   Updated: 2017/01/12 20:18:22 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mstr;

	if (s == NULL || f == NULL)
		return (NULL);
	mstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mstr == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		mstr[i] = f(i, s[i]);
	mstr[i] = '\0';
	return (mstr);
}
