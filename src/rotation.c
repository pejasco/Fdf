/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:10:22 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/01 16:46:56 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	rot_mx_4x4_x(double angle)
{
	t_mx	rot_x;

	rot_x = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{1, 0, 0, 0},
	{0, cos(angle), -sin(angle), 0},
	{0, sin(angle), cos(angle), 0},
	{0, 0, 0, 1}}};
	return (rot_x);
}

t_mx	rot_mx_4x4_y(double angle)
{
	t_mx	rot_y;

	rot_y = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{cos(angle), 0, sin(angle), 0},
	{0, 1, 0, 0},
	{-sin(angle), 0, cos(angle), 0},
	{0, 0, 0, 1}}};
	return (rot_y);
}

t_mx	rot_mx_4x4_z(double angle)
{
	t_mx	rot_z;

	rot_z = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{cos(angle), -sin(angle), 0, 0},
	{sin(angle), cos(angle), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}}};
	return (rot_z);
}