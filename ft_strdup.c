/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:43:39 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/26 04:26:43 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdp(char *s1)
{
	unsigned int	len;
	unsigned int	i;
	char			*p;

	i = 0;
	len = ft_strln(s1);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == 0)
		return (NULL);
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
