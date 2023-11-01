/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:41:14 by ale-boud          #+#    #+#             */
/*   Updated: 2023/11/01 16:38:53 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/math/vector.h"

t_vector2f	vec2f_add(
				const t_vector2f *a,
				const t_vector2f *b
				)
{
	return ((t_vector2f){a->x + b->x, a->y + b->y});
}

t_vector2f	vec2f_sub(
				const t_vector2f *a,
				const t_vector2f *b
				)
{
	return ((t_vector2f){a->x - b->x, a->y - b->y});
}

t_coord	vec2f_dot(
			const t_vector2f *a,
			const t_vector2f *b
			)
{
	return (a->x * b->x + a->y * b->y);
}

t_vector2f	vec2f_mul(
				const t_vector2f *a,
				t_coord f
				)
{
	return ((t_vector2f){a->x * f, a->y * f});
}
