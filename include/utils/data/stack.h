/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:02:03 by amassias          #+#    #+#             */
/*   Updated: 2023/11/03 13:08:41 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file stack.h
 * @author amassias (amassias@student.42lehavre.fr)
 * @brief Definition and utilitaries of a stack.
 * @date 2023-11-03
 * @copyright Copyright (c) 2023
 * @note Preformence-wise, it would probably be better to use dynamic arrays.
 * We will see in an other revision.
 */

// ************************************************************************** //
// *                                                                        * //
// * Header guard                                                           * //
// *                                                                        * //
// ************************************************************************** //

#ifndef STACK_H
# define STACK_H

# include "stdbool.h"

// ************************************************************************** //
// *                                                                        * //
// * Structures                                                             * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @struct s__stack_node_
 * @brief A linked list node.
 * @see s_stack
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
struct	s__stack_node_ {
	/**
	 * @brief A pointer to the following node.
	 */
	struct s__stack_node_	*next;

	/**
	 * @brief The data held in this node.
	 */
	void					*data;
};

/**
 * @struct s_stack
 * @brief Data related to a stack (implemented using a linked list).
 * @see s__stack_node_
 * @author amassias (amassias.42student.fr)
 * @date 2023-11-03
 */
struct	s_stack {
	struct s__stack_node_	*top;
};

// ************************************************************************** //
// *                                                                        * //
// * Custom types                                                           * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @typedef t_stack
 * @copydoc s_stack
 */
typedef struct s_stack	t_stack;

// ************************************************************************** //
// *                                                                        * //
// * Prototypes                                                             * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Creates an empty stack.
 * @return An empty stack created or @c NULL if an error occured.
 * @see s_stack
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
t_stack	*stack_create(void);

/**
 * @brief Tells whether @c stack is empty or not.
 * @param stack A stack.
 * @return whether @c stack is empty or not.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
bool	stack_is_empty(t_stack *stack);

/**
 * @brief Pushes an element on the top of @c stack.
 * @param stack A stack.
 * @param data The data to be pushed. If it is @c NULL, nothing will be pushed
 * on @c stack .
 * @return @c NULL if an error occured, @c data otherwise.
 * @see s_stack
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
void	*stack_push(t_stack *stack, void *data);

/**
 * @brief Peeks the top of @c stack .
 * @param stack A stack.
 * @return The element on the top of the stack or @c NULL if the stack is empty.
 * @see s_stack
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
void	*stack_peek(t_stack *stack);

/**
 * @brief Pops the top of the stack.
 * @param stack The stack.
 * @return @c NULL if the stack is empty, the data at the top of the stack
 * otherwise.
 * @see s_stack
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
void	*stack_pop(t_stack *stack);

/**
 * @brief Merges @c tail two stacks into @c head then clears @c tail .
 * @param head The stack that will receive @c tail .
 * @param tail The stack that will be merged into @c head and cleared.
 * @see s_stack
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
void	stack_merge(t_stack *head, t_stack *tail);

/**
 * @brief Destroys and clears @c *stack_ptr using @c delete_element
 * (if it is not @c NULL ) and then sets @c *stack_ptr to @c NULL .
 * @param stack_ptr A pointer to a stack.
 * @param delete_element The function that properly deletes any element in
 * @c *stack_ptr . If there is no need to clear the elements, you can pass
 * @c NULL instead.
 * @see s_stack
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
void	stack_destroy(t_stack **stack_ptr, void (*delete_element)(void *));

#endif