/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:03:35 by mabriand          #+#    #+#             */
/*   Updated: 2020/01/22 13:53:52 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft-printf_header/libftprintf.h"

/*
** commentaire
*/

void	ft_arg(const char *str, t_position *ptr_pos, va_list ap, int *ret_pf)
{
	t_position	bis;
	t_format	ret_format;

	bis = *ptr_pos;
	while (str[bis.index] != '\0')
	{
		if (str[bis.index] == '%')
		{
			*ret_pf += ft_get_string(str, &bis.pos);
			ret_format = ft_get_format(str, &bis.pos, ap);
			if (ft_check_format(ret_format) != -1)
			{
				*ret_pf += ft_print_arguments(ret_format, ap);
				bis.index = bis.pos - 1;
			}
			else
				return ;
		}
		bis.index++;
	}
	*ptr_pos = bis;
	return ;
}
