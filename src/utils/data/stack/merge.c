/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:38:25 by amassias          #+#    #+#             */
/*   Updated: 2023/11/03 12:49:58 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file merge.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @brief Implementation of #stack_merge
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
// * Helper prototypes                                                      * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Gets the last node of @c stack .
 * @param stack A stack.
 * @return A pointer to the last node of @c stack .
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
static struct s__stack_node_	**_get_last(t_stack *stack);

// ************************************************************************** //
// *                                                                        * //
// * Definitions                                                            * //
// *                                                                        * //
// ************************************************************************** //

void	stack_merge(t_stack *head, t_stack *tail)
{
	*_get_last(head) = tail->top;
	tail->top = NULL;
}

// ************************************************************************** //
// *                                                                        * //
// * Helper definitions                                                     * //
// *                                                                        * //
// ************************************************************************** //

static struct s__stack_node_	**_get_last(t_stack *stack)
{
	struct s__stack_node_	**node;

	node = &stack->top;
	if (*node == NULL)
		return (node);
	while ((*node)->next)
		node = &(*node)->next;
	return (node);
}
