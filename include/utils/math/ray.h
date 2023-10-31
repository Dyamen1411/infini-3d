/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:18:15 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/31 19:09:26 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

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
	 * @brief A pointer to the object hitten in the #s_field2d. NULL if no hit.
	 * @see s_field2d
	 */
	void	*what;

	/**
	 * @brief Which side hit.
	 */
	int		side;

	/**
	 * @brief The perp distance to the object hitten. 0. if no hit.
	 */
	t_coord	perpdist;
}	t_rayhit;

/**
 * @struct s_field2d
 * @brief 
 * @author ale-boud
 */
typedef struct s_field2d {
	/**
	 * @brief Pointer array of size width*height.
	 */
	void			*field;

	unsigned int	width;
	unsigned int	height;

	/**
	 * @brief Function pointer to know whether or not there is a hit.
	 * @param what Pointer in the field array.
	 * @return 0 if no hit, a non null value if hit.
	 */
	int				(*hitten)(void*what);
}	t_field2d;

// ************************************************************************** //
// *                                                                        * //
// * Prototypes                                                             * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Throw a ray into the #s_field2d, with a maximum iteration of maxitr.
 * @param ray #s_ovector2d The ray to throw.
 * @param field #s_field2d The field we are working on.
 * @param maxitr Please do not set this to infinity :).
 * @return #s_rayhit The ray hit information.
 */
t_rayhit	ray_throw(
	const t_ovector2d *ray,
	const t_field2d *field,
	unsigned long maxitr
	);

#endif
