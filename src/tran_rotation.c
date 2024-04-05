/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tran_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:10:22 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/05 15:01:47 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	rot_x_mx_4x4(double degree)
{
	t_mx	rot_x;

	rot_x = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{1, 0, 0, 0},
	{0, cos(degree), -sin(degree), 0},
	{0, sin(degree), cos(degree), 0},
	{0, 0, 0, 1}}};
	return (rot_x);
}

t_mx	rot_y_mx_4x4(double degree)
{
	t_mx	rot_y;

	rot_y = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{cos(degree), 0, sin(degree), 0},
	{0, 1, 0, 0},
	{-sin(degree), 0, cos(degree), 0},
	{0, 0, 0, 1}}};
	return (rot_y);
}

t_mx	rot_z_mx_4x4(double degree)
{
	t_mx	rot_z;

	rot_z = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{cos(degree), -sin(degree), 0, 0},
	{sin(degree), cos(degree), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}}};
	return (rot_z);
}
