/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 05:59:48 by amassias          #+#    #+#             */
/*   Updated: 2023/11/03 14:08:49 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file scene.h
 * @author amassias (amassias@student.42lehavre.fr)
 * @brief
 * @date 2023-11-01
 * @copyright Copyright (c) 2023
 * @deprecated DO NOT USE ! Scenes are not initialized, a revision of the scene
 * manager must be made
 * @todo Make a revision of the architecture of the scene manager system.<br>
 * The place where to put the scene initialization is non trivial which means
 * that the architecture is very bad !
 */

// ************************************************************************** //
// *                                                                        * //
// * Header guard                                                           * //
// *                                                                        * //
// ************************************************************************** //

#ifndef SCENE_H
# define SCENE_H

// ************************************************************************** //
// *                                                                        * //
// * Includes                                                               * //
// *                                                                        * //
// ************************************************************************** //

# include "utils/data/stack.h"

// ************************************************************************** //
// *                                                                        * //
// * Structures                                                             * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @struct s_scene
 * @brief Describes a scene. It should be used with a #s_scene_manager.
 * @see s_scene_manager
 * @author amassias (amassias@student.42lehavre.fr)
 */
struct s_scene {
	/**
	 * @brief A pointer to this scene context.
	 */
	void	*ctx;

	/**
	 * @brief Initializes this scene's context.
	 * @param global_context The game's context.
	 * @return A pointer to this scene's context.
	 */
	void	*(*init)(void *global_ctx);

	/**
	 * @brief Updates this scene.
	 * @param ctx This scene's context.
	 * @param global_context The game's context.
	 * @return A non null value if this scene should be destroyed, 0 otherwise.
	 */
	int		(*update)(void *ctx, void *global_ctx);

	/**
	 * @brief Renders this scene.
	 * @param ctx This scene's context.
	 * @param global_context The game's context.
	 */
	void	(*render)(void *ctx, void *global_ctx);

	/**
	 * @brief Destroys this scene's context.
	 * @param ctx This scene's context.
	 * @param global_context The game's context.
	 */
	void	(*destroy)(void *ctx, void *global_ctx);
};

/**
 * @struct s_scene_manager
 * @brief Manages which #s_scene should be active at any given point,
 * the #s_scene hierarchy, the #s_scene switching and all the cleanup.
 * @see s_scene
 * @author amassias (amassias@student.42lehavre.fr)
 */
struct s_scene_manager {
	/**
	 * @brief A context to pass to each scene.
	 */
	void	*global_ctx;

	/**
	 * @brief The scene stack. The scene on the top of this stack is the
	 * currently active scene.
	 */
	t_stack	*stack;

	/**
	 * @brief A temporary stack that holds all the scenes that have been pushed
	 * during a scene update.
	 */
	t_stack	*push_stack;
};

// ************************************************************************** //
// *                                                                        * //
// * Custom types                                                           * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @typedef t_scene
 * @copydoc s_scene
 */
typedef struct s_scene			t_scene;

/**
 * @typedef t_scene_manager
 * @copydoc s_scene_manager
 */
typedef struct s_scene_manager	t_scene_manager;

// ************************************************************************** //
// *                                                                        * //
// * Scene manager prototypes                                               * //
// *                                                                        * //
// ************************************************************************** //

/**
 * @brief Starts a scene manager with initial_scene as it's first #s_scene.
 * @param initial_scene The initial scene.
 * @param global_context A pointer to a global context.
 * @return @c 0 on success, a non null value if an error occured.
 * @note Complete the doc with all the workings of the manager (scene handling,
 * switching, etc...).
 * @author amassias (amassias@student.42lehavre.fr)
 */
int	scene_manager_start(
		t_scene *initial_scene,
		void *global_context
		);

/**
 * @brief Tells the #s_scene_manager that a new #s_scene is active.
 * @param manager A #s_scene_manager.
 * @param scene A #s_scene.
 * @return @c 0 on success, a non null value if an error occured.
 * @note Maybe dont let the user know if a scene failed to create and let the
 * manager handle it and crash accordingly ?
 * @author amassias (amassias@student.42lehavre.fr)
 */
int	scene_manager_push_scene(
		t_scene_manager *manager,
		t_scene *scene
		);

#endif