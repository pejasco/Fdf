/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.london.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:29:23 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 22:40:27 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char*s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*
char	*ft_strrchr(const char *s, int c)
{
	int	position;

	position = 0;
	while (s[position])
	{
		position++;
	}
	while (position )
	{
		if(*(s + position) == c)
		{
			return ((char *)(s + position));
		}
		position--;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}*/

/*int 	main(void)
{
	char tweet[] = "This is my @tention";
	
	//char *mention = strrchr(tweet, 'T');
	char *mention = ft_strrchr(tweet, 't');
	printf("%s\n", mention);
	return (0);
}*/
