/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:29:59 by amassias          #+#    #+#             */
/*   Updated: 2023/11/03 12:53:29 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @brief Implementation of #stack_push
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

void	*stack_push(t_stack *stack, void *data)
{
	struct s__stack_node_	*node;

	if (data == NULL)
		return (data);
	node = (struct s__stack_node_ *) malloc(sizeof(struct s__stack_node_));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = stack->top;
	stack->top = node;
	return (data);
}
