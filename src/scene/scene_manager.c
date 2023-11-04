/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:48:03 by amassias          #+#    #+#             */
/*   Updated: 2023/11/04 20:26:42 by amassias         ###   ########.fr       */
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

#include <stdlib.h>

// ************************************************************************** //
// *                                                                        * //
// * Helper prototypes                                                      * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Initializes @c manager with @c initial_scene as it's root scene.
 * @param manager A pointer to a scene manager.
 * @param initial_scene A scene.
 * @param global_context The context that will be passed to all the scenes.
 * @return @c 0 on success, a non null value otherwise.
 * @see s_scene_manager
 * @see s_scene
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-03
 */
static int	_init(
				t_scene_manager *manager,
				t_scene *initial_scene,
				void *global_context
				);

/**
 * @brief Puts the @c manager push stack ahead of the original scene stack
 * then clears the push stack.
 * @param manager A scene manager.
 * @see s_scene_manager
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-01
 */
static void	_merge_scene_stacks(
				t_scene_manager *manager
				);

/**
 * @brief Pops the top of the @c manager 's scene stack.
 * @param manager A scene manager.
 * @see s_scene_manager
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-01
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

	_init(&manager, initial_scene, global_context);
	while (manager.stack != NULL)
	{
		_merge_scene_stacks(&manager);
		scene = (t_scene *)stack_peek(manager.stack);
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
	return (stack_push(manager->push_stack, scene) != scene);
}

// ************************************************************************** //
// *                                                                        * //
// * Helper definitions                                                     * //
// *                                                                        * //
// ************************************************************************** //

static int	_init(
				t_scene_manager *manager,
				t_scene *initial_scene,
				void *global_context
				)
{
	manager->stack = stack_create();
	manager->push_stack = stack_create();
	if (manager->stack == NULL || manager->push_stack == NULL)
	{
		stack_destroy(&manager->stack, NULL);
		stack_destroy(&manager->push_stack, NULL);
		return (1);
	}
	if (stack_push(manager->stack, initial_scene) != initial_scene)
	{
		stack_destroy(&manager->stack, NULL);
		stack_destroy(&manager->push_stack, NULL);
		return (1);
	}
	manager->global_ctx = global_context;
	initial_scene->ctx = initial_scene->init(global_context);
	return (0);
}

static void	_merge_scene_stacks(
				t_scene_manager *manager
				)
{
	t_stack	*tmp;

	stack_merge(manager->push_stack, manager->stack);
	tmp = manager->stack;
	manager->stack = manager->push_stack;
	manager->push_stack = tmp;
}

static void	_pop_scene_stack(
				t_scene_manager *manager
				)
{
	t_scene	*scene;

	if (manager->stack->top == NULL)
		return ;
	scene = (t_scene *)manager->stack->top->data;
	scene->destroy(scene->ctx, manager->global_ctx);
	stack_pop(manager->stack);
}
