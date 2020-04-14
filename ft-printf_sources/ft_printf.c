/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:56:29 by mabriand          #+#    #+#             */
/*   Updated: 2020/01/22 17:34:01 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft-printf_header/libftprintf.h"

/*
** commentaire
*/

int		ft_printf(const char *str, ...)
{
	t_position	position;
	int			ret_printed;
	size_t		len;
	va_list		ap;

	position.index = 0;
	position.pos = 0;
	ret_printed = 0;
	va_start(ap, str);
	ft_arg(str, &position, ap, &ret_printed);
	va_end(ap);
	len = position.index - position.pos;
	write(1, (str + position.pos), len);
	ret_printed += len;
	return (ret_printed);
}
