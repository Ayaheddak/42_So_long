/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:50:07 by aheddak           #+#    #+#             */
/*   Updated: 2022/05/13 06:48:47 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*dest;

	i = 0;
	if (!s)
		return (NULL);
	if (!len || start >= ft_strln(s))
		return (ft_strdp(""));
	if (len > ft_strln(s))
		len = ft_strln(s);
	dest = (char *) malloc (sizeof(char) * (len + 1));
	if (dest == 0)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
