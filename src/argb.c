/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:48:25 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/30 18:10:42 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_argb	argb(unsigned char alpha, unsigned char r, unsigned char g,
				unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, alpha});
}

unsigned char	get_a(t_argb argb)
{
	return (((unsigned char *)&argb)[3]);
}

unsigned char	get_r(t_argb argb)
{
	return (((unsigned char *)&argb)[2]);
}

unsigned char	get_g(t_argb argb)
{
	return (((unsigned char *)&argb)[1]);
}

unsigned char	get_b(t_argb argb)
{
	return (((unsigned char *)&argb)[0]);
}
