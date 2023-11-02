/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:01:58 by ale-boud          #+#    #+#             */
/*   Updated: 2023/11/02 11:01:55 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ray.c
 * @author ale-boud (ale-boud@student.42lehavre.fr)
 * @brief The implementation of a ray throw
 * @date 2023-11-01
 * @copyright Copyright (c) 2023
 */

// ************************************************************************** //
// *                                                                        * //
// * Includes                                                               * //
// *                                                                        * //
// ************************************************************************** //

#include <math.h>
#include "utils/math/ray.h"

#include "raythrow.h"

// ************************************************************************** //
// *                                                                        * //
// * Constant definitions                                                   * //
// *                                                                        * //
// ************************************************************************** //

#define SIDE_X 1
#define SIDE_Y 2

// ************************************************************************** //
// *                                                                        * //
// * Helper prototypes                                                      * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Init the #s_raythrow deltas sides and pos.
 * @param rt The #s_raythrow.
 * @param ray The #s_ovector2f ray.
 */
static void		_ray_throw_init(
					t_raythrow *rt,
					const t_ovector2f *ray
					);

/**
 * @brief Init the #s_raythrow sides and pos.
 * @param rt The #s_raythrow.
 * @param ray The #s_ovector2f ray.
 */
static void		__ray_throw_init_sidepos(
					t_raythrow *rt,
					const t_ovector2f *ray
					);

/**
 * @brief Check if the #s_raythrow is in the #s_field2d
 * @param rt The #s_raythrow.
 * @param field The #s_field2d.
 * @return @c 0 if we are not in the #s_field2d. A non null value if we're in.
 */
static int		_ray_throw_infield(
					const t_raythrow *rt,
					const t_field2d *field
					);

/**
 * @brief Helper to make the struct returning by #ray_throw.
 * @param rt The #s_raythrow.
 * @param side Which side hit. (SIDE_X or SIDE_Y).
 * @param what what hit.
 * @return #s_raythrow with all the information of the hit.
 */
static t_rayhit	_ray_throw_hit(
					const t_raythrow *rt,
					int side,
					void *what
					);

// ************************************************************************** //
// *                                                                        * //
// * Include definitions                                                    * //
// *                                                                        * //
// ************************************************************************** //

t_rayhit	ray_throw(
				const t_ovector2f *ray,
				const t_field2d *field,
				unsigned long maxitr
				)
{
	t_raythrow	rt;
	int			side;
	void		*what;

	_ray_throw_init(&rt, ray);
	while (maxitr-- != 0)
	{
		side = rt.side.x < rt.side.y;
		if (side)
		{
			rt.side.x += rt.delta.x;
			rt.mappos.x += rt.step.x;
		}
		else
		{
			rt.side.y += rt.delta.y;
			rt.mappos.y += rt.step.y;
		}
		if (!_ray_throw_infield(&rt, field))
			break ;
		what = field_at(field, rt.mappos.x, rt.mappos.y);
		if (field->hit(what))
			return (_ray_throw_hit(&rt, side + 1, what));
	}
	return (NO_HIT);
}

// ************************************************************************** //
// *                                                                        * //
// * Helper definitions                                                     * //
// *                                                                        * //
// ************************************************************************** //

/** @todo Fix the f**...abulus norminette :) */
#define ABS(x) (x)<0?(-(x)):(x)

static void	_ray_throw_init(
				t_raythrow *rt,
				const t_ovector2f *ray
				)
{
	if (ray->dir.x == 0.)
		rt->delta.x = INFINITY;
	else
		rt->delta.x = ABS(1. / ray->dir.x);
	if (ray->dir.y == 0.)
		rt->delta.y = INFINITY;
	else
		rt->delta.y = ABS(1. / ray->dir.y);
	__ray_throw_init_sidepos(rt, ray);
}

static void	__ray_throw_init_sidepos(
				t_raythrow *rt,
				const t_ovector2f *ray
				)
{
	rt->mappos = (t_vector2i){(int)ray->pos.x, (int)ray->pos.y};
	if (ray->dir.x >= 0.)
	{
		rt->step.x = 1;
		rt->side.x = (1. - (ray->pos.x - rt->mappos.x)) * rt->delta.x;
	}
	else
	{
		rt->step.x = -1;
		rt->side.x = (ray->pos.x - rt->mappos.x) * rt->delta.x;
	}
	if (ray->dir.y >= 0.)
	{
		rt->step.y = 1;
		rt->side.y = (1. - (ray->pos.y - rt->mappos.y)) * rt->delta.y;
	}
	else
	{
		rt->step.y = -1;
		rt->side.y = (ray->pos.y - rt->mappos.y) * rt->delta.y;
	}
}

static int	_ray_throw_infield(
				const t_raythrow *rt,
				const t_field2d *field
				)
{
	return (rt->mappos.x >= 0
		&& rt->mappos.x < (int)field->width
		&& rt->mappos.y >= 0
		&& rt->mappos.y < (int)field->height);
}

static t_rayhit	_ray_throw_hit(
					const t_raythrow *rt,
					int side,
					void *what
					)
{
	t_rayhit	rh;

	rh.what = what;
	if (side == SIDE_X)
	{
		rh.side = SIDE_X * rt->step.x;
		rh.perpdist = rt->side.x - rt->delta.x;
	}
	else
	{
		rh.side = SIDE_Y * rt->step.y;
		rh.perpdist = rt->side.y - rt->delta.y;
	}
	return (rh);
}
