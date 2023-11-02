/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:18:15 by ale-boud          #+#    #+#             */
/*   Updated: 2023/11/02 10:21:49 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stdlib.h>
# include "vector.h"

// ************************************************************************** //
// *                                                                        * //
// * Structures                                                             * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @struct s_rayhit
 * @brief Describe a ray hit. Contain information about the hit or no hit.
 * @author ale-boud
 */
typedef struct s_rayhit {
	/**
	 * @brief A pointer to the object hit in the #s_field2d. NULL if no hit.
	 * @see s_field2d
	 */
	void	*what;

	/**
	 * @brief Which side hit.
	 */
	int		side;

	/**
	 * @brief The perp distance to the object hit. 0. if no hit.
	 */
	t_coord	perpdist;
}	t_rayhit;

/**
 * @brief #s_rayhit no hit statement
 */
# define NO_HIT (t_rayhit){NULL, 0, 0.}

/**
 * @struct s_field2d
 * @brief 
 * @author ale-boud
 */
typedef struct s_field2d {
	/**
	 * @brief Pointer array of size width*height. [x % width + y * width].
	 */
	void			*field;

	unsigned int	width;
	unsigned int	height;

	/**
	 * @brief Function pointer to know whether or not there is a hit.
	 * @param what Pointer in the field array.
	 * @return 0 if no hit, a non null value if hit.
	 */
	int				(*hit)(void*what);
}	t_field2d;

// ************************************************************************** //
// *                                                                        * //
// * Prototypes                                                             * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Throw a ray into the #s_field2d, with a maximum iteration of maxitr.
 * @param ray #s_ovector2f The ray to throw.
 * @param field #s_field2d The field we are working on.
 * @param maxitr Please do not set this to infinity :).
 * @return #s_rayhit The ray hit information.
 */
t_rayhit	ray_throw(
				const t_ovector2f *ray,
				const t_field2d *field,
				unsigned long maxitr
				);

/**
 * @brief Return a pointer to the item at (x, y) in the field.
 * @param x X coordinate.
 * @param y Y coordinate.
 * @return void* Pointer to the item at (x, y) in the field.
 */
void		*field_at(
				const t_field2d *field,
				unsigned int x,
				unsigned int y
				);

#endif
