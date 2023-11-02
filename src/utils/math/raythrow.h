/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raythrow.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:19:37 by ale-boud          #+#    #+#             */
/*   Updated: 2023/11/02 10:43:46 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTHROW_H
# define RAYTHROW_H

# include "utils/math/vector.h"

/**
 * @struct s_raythrow
 * @brief Structure that contain all the necessary information to throw a ray.
 */
typedef struct s_raythrow {
	t_vector2i	mappos;
	t_vector2i	step;
	t_vector2f	side;
	t_vector2f	delta;
}	t_raythrow;

#endif
