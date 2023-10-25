/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:43:19 by aborboll          #+#    #+#             */
/*   Updated: 2021/05/27 17:04:37 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print(t_info *info)
{
	int	i;

	i = 0;
	if (info->flags[F_Neg] && info->flags[F_Trash])
		ft_putchar_fd((char)0, info->std);
	while (*info->res != '\0' && info->res[i])
	{
		ft_putchar_fd((char)info->res[i], info->std);
		i++;
	}
	if (!info->flags[F_Neg] && info->flags[F_Trash])
		ft_putchar_fd((char)0, info->std);
	if (ft_strlen(info->str[0]) > 0)
		(info->str[0])++;
	info->count += i;
}

void	check_and_print(t_info *info)
{
	(info->str[0])++;
	check_flags(info);
	check_width(info);
	check_for_precision(info);
	check_for_lengths(info);
	check_type(info);
	if (info->type)
	{
		if (info->type == 's' || info->type == 'S')
			do_string(info);
		if (info->type == 'i' || info->type == 'd' || info->type == 'u')
			do_number(info, 0);
		else if (info->type == 'o' || info->type == 'O')
			do_octal(info);
		else if (info->type == 'x' || info->type == 'X')
			do_hex(info);
		else if (info->type == 'c' || info->type == 'C')
			do_char(info);
		else if (info->type == 'p' || info->type == 'P')
			do_address(info);
		else if (info->type == '%')
			do_percentage(info);
		print(info);
	}
	reinit(info);
}

int	ft_printf(char *format, ...)
{
	va_list	args;
	int		result;
	t_info	*info;

	info = (t_info *)ft_strnew(sizeof(t_info));
	if (!info || !(format))
		return (EXIT_FAILURE);
	va_start(args, format);
	init_struct(info, &format, &args, STDOUT_FILENO);
	result = info->count;
	while (info->str[0][0])
	{
		if (info->str[0][0] != '%')
		{
			ft_putchar_fd(info->str[0][0], info->std);
			(info->str[0])++;
			info->count++;
		}
		else
			check_and_print(info);
	}
	result = info->count;
	free(info);
	va_end(args);
	return (result);
}
