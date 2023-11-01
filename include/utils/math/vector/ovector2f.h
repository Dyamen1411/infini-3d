/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ovector2f.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:37:03 by ale-boud          #+#    #+#             */
/*   Updated: 2023/11/01 16:30:14 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVECTOR2F_H
# define OVECTOR2F_H

# include "vector2f.h"

/**
 * @struct s_ovector2f
 * @brief Oriented vector 2 (position and direction).
 * @author ale-boud
 */
typedef struct s_ovector2d {
	t_vector2f	pos;
	t_vector2f	dir;
}	t_ovector2f;

#endif
