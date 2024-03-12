/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utili.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:21:55 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/12 13:49:22 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int find_comma(char *str)
{
  int   i;
  int   checker;

  i = 0;
  checker = 0;
  while (str[i])
  { 
    if (str[i] == ',')
    {
      checker = 1;
      return (1);
    }
    i++;
  }
  return (0);
}

char  










/*
uint32_t hex2int(char *hex)
{
  uint32_t val = 0;
  while (*hex)
  {
    uint8_t byte = *hex++;
    if (byte >= '0' && byte <= '9') 
        byte = byte - '0';
    else if (byte >= 'a' && byte <= 'f')
        byte = byte - 'a' + 10;
    else if (byte >= 'A' && byte <= 'F')
        byte = byte - 'A' + 10;
    val = (val << 4) | (byte);
  }  
    return (val);
}
*/