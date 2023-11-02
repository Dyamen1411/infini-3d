/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:22:25 by ale-boud          #+#    #+#             */
/*   Updated: 2023/11/01 19:05:00 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/math/ray.h"

void	*field_at(
			const t_field2d *field,
			unsigned int x,
			unsigned int y
			)
{
	return ((char *)field->field + (x % field->width + y * field->width));
}
