/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:43:02 by aborboll          #+#    #+#             */
/*   Updated: 2021/04/15 19:09:51 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, t_uint start, size_t len)
{
	char	*new;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return ((char *)ft_calloc(start * sizeof(char), len));
	s += start;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, s, len + 1);
	return (new);
}
