/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:46:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/28 16:24:05 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	mtxa_mult_mtxb(t_mx mtxa, t_mx mtxb)
{
	t_mx		product;
	int			i;
	
	if (mtxa.col_num != mtxb.row_num)
		exit;
	product = (t_mx){.row_num = mtxa.row_num, .col_num = mtxb.col_num};
	cal_mx_product(&product, &mtxa, &mtxb);
	return (product);
}

void	calc_mx_product(t_mx *product, t_mx *mxb)
{
	int		i;
	int		p_row_i;
	







}
