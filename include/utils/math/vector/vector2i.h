/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2i.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:33:25 by ale-boud          #+#    #+#             */
/*   Updated: 2023/11/01 16:37:43 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2I_H
# define VECTOR2I_H

/**
 * @struct s_vector2i
 * @brief Integer vector 2 (x, y).
 * @author ale-boud
 */
typedef struct s_vector2i {
	int	x;
	int	y;
}	t_vector2i;

// ************************************************************************** //
// *                                                                        * //
// * Function prototypes                                                    * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Vector addition (a.x + b.x, a.y + b.y).
 * @param a Vector a.
 * @param b Vector b.
 * @return #s_vector2i result of the vector addition.
 */
t_vector2i	vec2i_add(
				const t_vector2i *a,
				const t_vector2i *b
				);

/**
 * @brief Vector substraction (a.x - b.x, a.y - b.y).
 * @param a Vector a.
 * @param b Vector b.
 * @return #s_vector2i result of the vector substraction.
 */
t_vector2i	vec2i_sub(
				const t_vector2i *a,
				const t_vector2i *b
				);

/**
 * @brief Vector scalar multiplication (a.x * f, a.y * f).
 * @param a Vector a.
 * @param f	Factor f.
 * @return #s_vector2i result of the vector multiplication.
 */
t_vector2i	vec2i_mul(
				const t_vector2i *a,
				int f
				);

#endif
