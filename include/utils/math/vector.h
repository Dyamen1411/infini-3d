/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:32:56 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/31 03:19:02 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

// ************************************************************************** //
// *                                                                        * //
// * Type definition                                                        * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Coordination type.
 */
typedef float t_coord;

// ************************************************************************** //
// *                                                                        * //
// * Structures                                                             * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @struct s_vector2d
 * @brief Vector 2D (x, y).
 * @author ale-boud
 */
typedef struct s_vector2d {
	t_coord	x;
	t_coord	y;
}	t_vector2d;

/**
 * @struct s_ovector2d
 * @brief Oriented vector 2D (position and direction).
 * @author ale-boud
 */
typedef struct s_ovector2d {
	t_vector2d	pos;
	t_vector2d	dir;
}	t_ovector2d;

// ************************************************************************** //
// *                                                                        * //
// * Prototypes                                                             * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Vector addition (a.x+b.x, a.y+b.y).
 * @param a Vector a.
 * @param b Vector b.
 * @return #s_vector2d result of the vector addition.
 */
t_vector2d	vec2_add(const t_vector2d *a, const t_vector2d *b);

/**
 * @brief Vector substraction (a.x-b.x, a.y-b.y).
 * @param a Vector a.
 * @param b Vector b.
 * @return #s_vector2d result of the vector substraction.
 */
t_vector2d	vec2_sub(const t_vector2d *a, const t_vector2d *b);

/**
 * @brief Vector dot product (a.x*b.x+a.y*b.y).
 * @param a Vector a.
 * @param b Vector b.
 * @return #t_coord result of the dot product.
 */
t_coord		vec2_dot(const t_vector2d *a, const t_vector2d *b);

/**
 * @brief Vector scalar multiplication (a.x*f,a.y*f).
 * @param a Vector a.
 * @param f	Factor f.
 * @return #s_vector2d result of the vector multiplication.
 */
t_vector2d	vec2_mul(const t_vector2d *a, t_coord f);

#endif
