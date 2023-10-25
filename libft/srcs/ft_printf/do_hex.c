/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:03:19 by aborboll          #+#    #+#             */
/*   Updated: 2020/08/21 13:03:22 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	apply_hash(t_info *info, int flag, int iszero)
{
	if (info->flags[F_Hash] && iszero != 1)
	{
		if ((info->flags[F_Zero] && !info->flags[F_Neg]
				&& flag && info->precision < 0)
			|| (((!info->flags[F_Zero] || info->flags[F_Neg]) && !flag)
				|| (info->flags[F_Zero] && info->precision >= 0 && !flag)))
		{
			if (info->type == 'X')
				info->res = ft_strjoin_free(ft_strdup("0X"), info->res);
			else
				info->res = ft_strjoin_free(ft_strdup("0x"), info->res);
		}
	}
}

static	void	apply_width(t_info *info, int iszero, int len)
{
	if (info->width > len)
	{
		while (info->flags[F_Neg] && len < info->width)
		{
			info->res = ft_strjoin_free(info->res, ft_strdup(" "));
			len++;
		}
		if (info->flags[F_Zero] && !info->flags[F_Neg]
			&& info->flags[F_Hash] && info->precision < 0 && !iszero)
			len += 2;
		while (info->flags[F_Zero] && len < info->width && info->precision < 0)
		{
			info->res = ft_strjoin_free(ft_strdup("0"), info->res);
			len++;
		}
		while (len < info->width)
		{
			info->res = ft_strjoin_free(ft_strdup(" "), info->res);
			len++;
		}
	}
	apply_hash(info, 1, iszero);
}

static	void	apply_precision(t_info *info, int iszero)
{
	int	len;

	len = ft_strlen(info->res);
	if (info->precision > len)
	{
		while (info->precision > len)
		{
			info->res = ft_strjoin_free(ft_strdup("0"), info->res);
			len++;
		}
	}
	if (info->precision == 0 && iszero == 1)
	{
		free(info->res);
		info->res = ft_strdup("");
	}
	apply_hash(info, 0, iszero);
	apply_width(info, iszero, ft_strlen(info->res));
}

void	do_hex(t_info *info)
{
	if (info->length[L_long])
		info->res = ft_utoabase((t_long)va_arg(info->args[0], t_long), 16);
	else if (info->length[L_longlong])
		info->res = ft_utoabase((t_llong)va_arg(info->args[0], t_llong), 16);
	else if (info->length[L_ulong])
		info->res = ft_utoabase((t_ulong)va_arg(info->args[0], t_ulong), 16);
	else if (info->length[L_char])
		info->res = ft_utoabase((t_uchar)va_arg(info->args[0], t_uint), 16);
	else if (info->length[L_short])
		info->res = ft_utoabase((t_ushsort)va_arg(info->args[0], t_uint), 16);
	else
		info->res = ft_utoabase((t_uint)va_arg(info->args[0], t_uint), 16);
	if (info->type == 'x' || info->type == 'X')
	{
		if (info->type == 'X')
			ft_strto(info->res, ft_toupper);
		else
			ft_strto(info->res, ft_tolower);
	}
	apply_precision(info, ft_strcmp(info->res, "0") == 0);
}
