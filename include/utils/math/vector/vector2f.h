/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:33:28 by ale-boud          #+#    #+#             */
/*   Updated: 2023/11/01 16:35:24 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2F_H
# define VECTOR2F_H

/**
 * @struct s_vector2f
 * @brief Float vector 2 (x, y).
 * @author ale-boud
 */
typedef struct s_vector2f {
	t_coord	x;
	t_coord	y;
}	t_vector2f;

// ************************************************************************** //
// *                                                                        * //
// * Function prototypes                                                    * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Vector addition (a.x + b.x, a.y + b.y).
 * @param a Vector a.
 * @param b Vector b.
 * @return #s_vector2f result of the vector addition.
 */
t_vector2f	vec2f_add(
				const t_vector2f *a,
				const t_vector2f *b
				);

/**
 * @brief Vector substraction (a.x - b.x, a.y - b.y).
 * @param a Vector a.
 * @param b Vector b.
 * @return #s_vector2f result of the vector substraction.
 */
t_vector2f	vec2f_sub(
				const t_vector2f *a,
				const t_vector2f *b
				);

/**
 * @brief Vector dot product (a.x * b.x + a.y * b.y).
 * @param a Vector a.
 * @param b Vector b.
 * @return #t_coord result of the dot product.
 */
t_coord		vec2f_dot(
				const t_vector2f *a,
				const t_vector2f *b
				);

/**
 * @brief Vector scalar multiplication (a.x * f, a.y * f).
 * @param a Vector a.
 * @param f	Factor f.
 * @return #s_vector2f result of the vector multiplication.
 */
t_vector2f	vec2f_mul(
				const t_vector2f *a,
				t_coord f
				);

#endif
