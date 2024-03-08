/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:59:22 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/10 16:01:17 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdlib.h>
#include "ft_printf.h"

#define HEXA_BASE 16
#define DEFAULT_ADDR_MAX_LEN 20

int	ft_print_p(void *p)
{
	int			i;
	uintptr_t	addr_int;
	char		s[DEFAULT_ADDR_MAX_LEN];
	char const	*symbolx = "0123456789abcdef";

	addr_int = (uintptr_t)p;
	if (p == NULL)
		return (ft_print_s("(nil)"));
	i = DEFAULT_ADDR_MAX_LEN - 1;
	s[i--] = '\0';
	while (addr_int >= 16)
	{
		s[i] = symbolx[addr_int % HEXA_BASE];
		addr_int /= 16;
		i--;
	}
	s[i--] = symbolx[addr_int];
	s[i--] = 'x';
	s[i] = '0';
	return (ft_print_s(&s[i]));
}
