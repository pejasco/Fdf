/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:59:22 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/09 22:42:24 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <unistd.h>
//#include <stdarg.h>
//#include <stdio.h>

#include "ft_printf.h"

int	ft_print_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count = ft_print_c(va_arg(ap, int));
	else if (spec == 's')
		count = ft_print_s(va_arg(ap, char *));
	else if (spec == 'p')
		count = ft_print_p(va_arg(ap, void *));
	else if (spec == 'd')
		count = ft_print_d(va_arg(ap, int), 10, spec);
	else if (spec == 'i')
		count = ft_print_d(va_arg(ap, int), 10, spec);
	else if (spec == 'u')
		count = ft_print_d(va_arg(ap, unsigned int), 10, spec);
	else if (spec == 'x')
		count = ft_print_d(va_arg(ap, unsigned int), 16, spec);
	else if (spec == 'X')
		count = ft_print_d(va_arg(ap, unsigned int), 16, spec);
	else if (spec == '%')
		count = write (1, "%", 1);
	return (count);
}

static int	is_specifier(char c)
{
	static const char	*specifiers = "cspdiuxX%%";

	return (ft_strchr(specifiers, c) != NULL);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_print_c(str[i]);
		else if (is_specifier(str[i + 1]))
			count += ft_print_format(str[++i], ap);
		else
			return (-1);
		i++;
	}
	va_end(ap);
	return (count);
}

/*
c	char			int
s	string			int
p	ptr				uintptr_t			hexadecimal format
d	int				decimal				base 10 
i	int				integer				base 10
u	unsigned int	unsigned decimal	base 10
x	unsigned int	hexadecimal lower	base 16
X	unsigned int	hexadecimal upper	base 16
*/

/*
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int	main(void)
{
	char			c;
	char			*str;
	uintptr_t		*ptr1;
	uintptr_t		*ptr2 = NULL;
	//int		u;
	//int		i;
	
	c = 'a';
	str = "testing";
	//ptr2 = 0x12345678;	
	int d1 = INT_MAX;
	int d2 = INT_MIN;
	ptr1 = (uintptr_t *) &d2;
	//int d3 = 1.234567;
	int d4 = -1;

	unsigned int test1 = UINT_MAX;
	//unsigned int test2= 4242;
	unsigned int test3= 0;
	unsigned int test4 = -4242;

	printf("Char_MAX: 			%c\n", c);
	printf("Str_testing: 		%s\n", str);
	printf("Ptr1_&str: 			%p\n", ptr1);
	printf("Ptr2_NULL: 			%p\n", ptr2);
	printf("d1_d_INT_MAX: 		%d\n", d1);
	printf("d1_i_INT_MAX: 		%i\n", d1);
	printf("d2_d_INT_MIN: 		%d\n", d2);
	printf("d2_i_INT_MIN: 		%i\n", d2);
	//printf("d3_1.234567 		%d\n", d3);
	//printf("i3_1.234567 		%i\n", d3);
	printf("d4_d_-1: 			%d\n", d4);
	printf("d4_i_-1: 			%i\n", d4);
	printf("test1_u_UINT_MAX: 	%u\n", test1);
	printf("test1_x_UINT_MAX: 	%x\n", test1);
	printf("test1_X_UINT_MAX:  	%X\n", test1);
	printf("test3_u_0:  		%u\n", test3);
	printf("test3_x_0:  		%x\n", test3);	
	printf("test3_X_0:  		%X\n", test3);
	printf("test4_u_-4242:  	%u\n", test4);
	printf("test4_x_-4242:  	%x\n", test4);	
	printf("test4_X_-4242:  	%X\n", test4);
}*/
