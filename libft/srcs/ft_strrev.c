/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:46:59 by aborboll          #+#    #+#             */
/*   Updated: 2021/04/15 19:10:18 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	int		a;
	int		b;
	char	c;

	a = 0;
	b = 0;
	while (str[a] != '\0')
		a++;
	a = a - 1;
	while (a > b)
	{
		c = str[a];
		str[a] = str[b];
		str[b] = c;
		b++;
		a--;
	}
	return (str);
}
