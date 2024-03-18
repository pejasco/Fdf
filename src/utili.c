/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utili.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:21:55 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/18 22:25:05 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_all(char **strs)
{
  int   i;

  i = 0;
  while(strs && strs[i])
  {
    free(strs[i]);
    i++;
  }
  free(strs);
}

void free_all_int(int **strs)
{
  int   i;

  i = 0;
  while(strs && strs[i])
  {
    free(strs[i]);
    i++;
  }
  free(strs);
}

void free_stru(t_int_strs *struc)
{ 
  
  free_all_int(struc->rgb_strs);
  free_all_int(struc->values_strs);
}

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