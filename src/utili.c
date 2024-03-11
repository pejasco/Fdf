/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utili.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:21:55 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/11 21:53:42 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
    val = (val << 4) | (byte & 0xF);
  }  
    return (val);
}

int main