/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:29:52 by aborboll          #+#    #+#             */
/*   Updated: 2021/05/27 16:59:04 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	init_struct(t_info *info, char **str, va_list *args, int fd)
{
	int	i;

	i = 0;
	while (i++ < N_FLAGS)
		info->flags[i] = 0;
	i = 0;
	while (i < N_LENS)
		info->length[i++] = 0;
	info->args = args;
	info->str = str;
	info->count = 0;
	info->width = -1;
	info->precision = -1;
	info->type = '\0';
	info->res = NULL;
	info->std = fd;
}

void	reinit_lengths(t_info *info)
{
	int	i;

	i = 0;
	while (i++ < N_LENS)
		info->length[i] = 0;
}

void	reinit(t_info *info)
{
	int	i;

	i = 0;
	while (i < N_FLAGS)
	{
		info->flags[i] = 0;
		i++;
	}
	i = 0;
	while (i < N_LENS)
		info->length[i++] = 0;
	info->width = -1;
	info->precision = -1;
	info->type = '\0';
	if (info->res != NULL)
		ft_strdel(&info->res);
}
