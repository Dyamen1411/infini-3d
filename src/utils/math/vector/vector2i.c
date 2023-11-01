/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:37:51 by ale-boud          #+#    #+#             */
/*   Updated: 2023/11/01 16:38:47 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/math/vector.h"

t_vector2i	vec2i_add(
				const t_vector2i *a,
				const t_vector2i *b
				)
{
	return ((t_vector2i){a->x + b->x, a->y + b->y});
}

t_vector2i	vec2i_sub(
				const t_vector2i *a,
				const t_vector2i *b
				)
{
	return ((t_vector2i){a->x - b->x, a->y - b->y});
}

t_vector2i	vec2i_mul(
				const t_vector2i *a,
				int f
				)
{
	return ((t_vector2i){a->x * f, a->y * f});
}
