/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:32:56 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/31 02:18:36 by ale-boud         ###   ########.fr       */
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
 * @brief Coordination type
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

#endif
