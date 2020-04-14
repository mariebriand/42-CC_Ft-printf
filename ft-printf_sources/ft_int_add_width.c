/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_add_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:54:04 by mabriand          #+#    #+#             */
/*   Updated: 2020/01/22 21:39:12 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft-printf_header/libftprintf.h"

/*
** commentaire
*/

char	*ft_int_add_width(t_format format, char *nbr)
{
	int		len;
	char	*with_width;
	char	*to_add;

	with_width = NULL;
	len = (int)ft_strlen(nbr);
	to_add = ft_calloc_flag((format.width - len), 32);
	if (format.flag == 0)
		with_width = ft_strjoin(to_add, nbr);
	else if (format.flag == 1)
		with_width = ft_int_cp(format.precision, format.width, len, nbr);
	else if (format.flag == 2)
		with_width = ft_join(nbr, to_add);
	free(to_add);
	return (with_width);
}

/*
** commentaire
*/

char	*ft_int_cp(int precision, int width, int len, char *nbr)
{
	char *with_width_cp;
	char *to_add_cp;

	if (precision < 0 && width > len)
	{
		if (nbr[0] == '-')
			width -= 1;
		with_width_cp = ft_int_add_precision(nbr, width);
	}
	else
	{
		to_add_cp = ft_calloc_flag((width - len), 48);
		with_width_cp = ft_join(to_add_cp, nbr);
		free(to_add_cp);
	}
	return (with_width_cp);
}
