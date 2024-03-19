/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:12:10 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/18 22:50:12 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>
//#include <stdlib.h>

static size_t	get_str_count(char const *s, char d);
static char		*extract_str(char const *s, char c);

/**
 * @brief Splits a string into an array of strings (words) using a specified
 * delimiter character.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return 
 * A dynamically allocated array of strings. Each string is a word from the
 * original string 's'. The array is terminated by a NULL pointer. If the
 * allocation fails, the function returns NULL.
 * 
 * The memory for the array and for each word is dynamically allocated and must
 * be freed by the caller.*/
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	total;
	char	**strs;

	total = get_str_count(s, c);
	strs = (char **)malloc((total + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			strs[j] = extract_str(&s[i], c);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	strs[j] = NULL;
	return (strs);
}

static size_t	get_str_count(char const *s, char d)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (s[i])
	{
		while (s[i] == d)
			i++;
		if (s[i] != d && s[i])
			sum++;
		while (s[i] != d && s[i])
			i++;
	}
	ft_printf("LH's split%d\n", sum);
	return (sum);
}

static char	*extract_str(char const *s, char c)
{
	char	*out_str;
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	out_str = (char *)malloc((len + 1) * sizeof(char));
	ft_memcpy(out_str, s, len);
	out_str[len] = '\0';
	return (out_str);
}



/*
Simon!!!!!!!!!!!!!!!!!!!
static size_t	ft_count_word(const char *s, char c)
{
	size_t	res;

	res = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			while (*s && *s != c)
				s++;
			res++;
		}
	}
	return (res);
}

static size_t	ft_word_length(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_clean_up(size_t k, char **arr)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(arr[i]);
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	size_t		i;
	size_t		k;

	k = 0;
	res = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	while (res && s && *s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[k] = malloc(sizeof(char) * (ft_word_length(s, c) + 1));
			if (!res[k])
				return (ft_clean_up(k, res));
			i = -1;
			while (s[++i] && s[i] != c)
				res[k][i] = s[i];
			res[k++][i] = 0;
			s += i;
		}
	}
	if (res)
		res[k] = NULL;
	return (res);
}
*/

/*
mine!!!!!!!!!!!!!!!!!!!

static size_t	nr_of_arrays(char const *s, char d)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (s[i])
	{
		while (s[i] == d)
			i++;
		if (s[i] != d && s[i])
		{
			while (s[i] != d && s[i])
				i++;
			sum++;
		}
	}
	return (sum);
}

static char	*extract_str(char const *s, char c)
{
	char	*out_str;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	out_str = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (s[i] != c && i < len)
	{
		out_str[i] = s[i];
		i++;
	}
	out_str[i] = '\0';
	return (out_str);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		total;
	char		**strs;

	i = 0;
	j = 0;
	total = nr_of_arrays(s, c);
	ft_printf("My_split%d\n", total);
	strs = (char **)malloc(sizeof(char *) * (total + 1));
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			strs[j] = extract_str(&s[i], c);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	strs[j] = NULL;
	return (strs);
}
*/

/*#include <stdio.h>

int	main(void)
{
	char *s = "021";
	char c = '2';
	char **output;

	output = ft_split(s, c);
	for (int i = 0; output[i] != NULL; i++)
		printf("%s\n", output[i]);
	return (0);
}*/
