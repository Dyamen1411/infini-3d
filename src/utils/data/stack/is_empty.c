/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:28:16 by amassias          #+#    #+#             */
/*   Updated: 2023/11/03 12:49:05 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_empty.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @brief Implementation of #stack_is_empty
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

bool	stack_is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}
