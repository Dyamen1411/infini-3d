/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:48:03 by amassias          #+#    #+#             */
/*   Updated: 2023/11/01 14:42:09 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file scene_manager.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @brief The implementation of a scene manager.
 * @date 2023-11-01
 * @copyright Copyright (c) 2023
 * @note If an error occured, maybe let an event manager handle it ? It may lead
 * to cleaner and more modulable error handling.
 */

// ************************************************************************** //
// *                                                                        * //
// * Includes                                                               * //
// *                                                                        * //
// ************************************************************************** //

#include "scene/scene.h"
#include "libft.h"

// ************************************************************************** //
// *                                                                        * //
// * Helper prototypes                                                      * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Puts the scene manager push stack ahead of the original scene stack
 * then clears the push stack.
 * @param manager The #s_scene_manager.
 * @author amassias (amassias@student.42lehavre.fr)
 */
static void	_merge_scene_stacks(
				t_scene_manager *manager
				);

/**
 * @brief Pops the top of the scene stack.
 * @param manager The #s_scene_manager.
 * @author amassias (amassias@student.42lehavre.fr)
 */
static void	_pop_scene_stack(
				t_scene_manager *manager
				);

// ************************************************************************** //
// *                                                                        * //
// * Include definitions                                                    * //
// *                                                                        * //
// ************************************************************************** //

int	scene_manager_start(
		t_scene *initial_scene,
		void *global_context
		)
{
	t_scene_manager	manager;
	t_scene			*scene;

	manager.global_ctx = global_context;
	manager.stack = NULL;
	manager.push_stack = NULL;
	if (scene_manager_push_scene(&manager, initial_scene) != 0)
		return (1);
	_merge_scene_stacks(&manager);
	while (manager.stack != NULL)
	{
		scene = (t_scene *)manager.stack->content;
		if (scene->update(scene->ctx, global_context))
		{
			_pop_scene_stack(&manager);
			continue ;
		}
		scene->render(scene->ctx, global_context);
	}
	return (0);
}

int	scene_manager_push_scene(
		t_scene_manager *manager,
		t_scene *scene
		)
{
	t_list	*node;

	node = ft_lstnew(scene);
	if (node == NULL)
		return (1);
	ft_lstadd_front(&manager->push_stack, node);
	return (0);
}

// ************************************************************************** //
// *                                                                        * //
// * Helper definitions                                                     * //
// *                                                                        * //
// ************************************************************************** //

static void	_merge_scene_stacks(
				t_scene_manager *manager
				)
{
	t_list	*tmp;
	t_scene	*scene;

	if (manager->push_stack == NULL)
		return ;
	scene = (t_scene *)manager->push_stack->content;
	scene->ctx = scene->init(manager->global_ctx);
	ft_lstadd_back(&manager->push_stack, manager->stack);
	manager->stack = manager->push_stack;
	manager->push_stack = NULL;
}

static void	_pop_scene_stack(
				t_scene_manager *manager
				)
{
	t_list	*new_head;
	t_scene	*scene;

	if (manager->stack == NULL)
		return ;
	scene = (t_scene *)manager->stack->content;
	new_head = manager->stack->next;
	scene->destroy(scene->ctx, manager->global_ctx);
	free(manager->stack);
	manager->stack = new_head;
}
