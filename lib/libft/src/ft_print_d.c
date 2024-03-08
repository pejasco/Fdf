/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:58:56 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/09 22:35:05 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(long n, int base, char spec)
{
	int		count;
	char	*symbolx;
	char	*symbolxl;

	symbolx = "0123456789abcdef";
	symbolxl = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_d(-n, base, spec) + 1);
	}
	else if (n < base && spec == 'X')
		return (ft_print_c(symbolxl[n]));
	else if (n < base)
		return (ft_print_c(symbolx[n]));
	else
	{
		count = ft_print_d(n / base, base, spec);
		return (count + ft_print_d(n % base, base, spec));
	}
}
