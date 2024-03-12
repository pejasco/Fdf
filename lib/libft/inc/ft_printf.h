/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:00:04 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/09 15:23:18 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int		ft_printf(const char *str, ...);

int		ft_print_format(char spec, va_list ap);

int		ft_print_c(char c);

int		ft_print_s(char *str);

int		ft_print_d(long n, int base, char spec);

int		ft_print_p(void *p);

#endif
