/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:13:55 by amassias          #+#    #+#             */
/*   Updated: 2023/11/03 12:48:38 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file destroy.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @brief Implementation of #stack_destroy
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
 * @brief Does nothing.
 * @param _ Unused parameter.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
static void	_do_nothing(void *_);

// ************************************************************************** //
// *                                                                        * //
// * Definitions                                                            * //
// *                                                                        * //
// ************************************************************************** //

void	stack_destroy(t_stack **stack_ptr, void (*delete_element)(void *))
{
	struct s__stack_node_	*node;

	if (*stack_ptr == NULL)
		return ;
	if (delete_element == NULL)
		delete_element = _do_nothing;
	while ((*stack_ptr)->top)
	{
		node = (*stack_ptr)->top;
		(*stack_ptr)->top = (*stack_ptr)->top->next;
		delete_element(node->data);
		free(node);
	}
	*stack_ptr = NULL;
}

// ************************************************************************** //
// *                                                                        * //
// * Helper definitions                                                     * //
// *                                                                        * //
// ************************************************************************** //

static void	_do_nothing(void *_)
{
	(void) _;
}
