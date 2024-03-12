/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:45:53 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/09 15:46:10 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if the 'c' is a white-space character.
 * 
 * White-space characters are: ' ', '\\t', '\\n', '\\v', '\\f', and '\\r'.
 * 
 * @param c Character to check.
 * @return int 
 * Non-zero if the character is a white-space character, and zero otherwise.
 */
int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}
