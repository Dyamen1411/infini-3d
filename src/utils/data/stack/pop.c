/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:33:11 by amassias          #+#    #+#             */
/*   Updated: 2023/11/03 12:53:11 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file pop.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @brief Implementation of #stack_pop
 * @see stack.h
 * @date 2023-11-03
 * @copyright Copyright (c) 2023
 */

// ************************************************************************** //
// *                                                                        * //
// * Includes                                                               * //
// *                                                                        * //
// ************************************************************************** //

#include "utils/data/stack.h"

#include <stdlib.h>

// ************************************************************************** //
// *                                                                        * //
// * Definitions                                                            * //
// *                                                                        * //
// ************************************************************************** //

void	*stack_pop(t_stack *stack)
{
	void					*data;
	struct s__stack_node_	*old_top;

	if (stack->top == NULL)
		return (NULL);
	data = stack->top->data;
	old_top = stack->top;
	stack->top = stack->top->next;
	free(old_top);
	return (data);
}
