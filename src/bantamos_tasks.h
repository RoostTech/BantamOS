/*
 * BantamOS - an RTOS targetted at the Atmel AVR family
 *
 * Copyright 2014 ZachWick <zach@zachwick.xxx>
 *
 * This file is part of BantamOS.
 *
 * BantamOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the license, or
 * (at you option) any later version.
 *
 * BantamOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULA PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BantamOS. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BANTAMOS_TASKS_H
#define BANTAMOS_TASKS_H

#include "bantamos_types.h"

/**
 * A handle type for tasks.
 *
 * All Task API functions use TaskHandle_t typed variables to 
 * reference tasks.
 */
typedef void * TaskHandle_t;

/**
 * The various states that a task can be in.
 *
 * A task can only ever be in one of the following states at a
 * given time:
 * Running   - The task is currently executing
 * Ready     - The task is able to execute, but is not currently executing 
 * Blocked   - The task is waiting to enter the Ready state
 * Suspended - The task is suspended and can never transition to the Ready state
 * Deleted   - The task has been deleted, but the correspondin handle remains
 */
typedef enum {
	Running = 0,
	Ready,
	Blocked,
	Suspended,
	Deleted
} TaskState_e;

/**
 * A container for a memory region and some related data
 *
 */
typedef struct
{
	/**
	 * The beginning address of the memory region
	 */
	void *base_address;

	/**
	 * The length of the memory region in bytes
	 */
	uint32_t length;

	/**
	 * Additional parameters of the memory region
	 */
	uint32_t params;
} MemoryRegion_t;

/**
 * A container for a task and its properties
 *
 * A TaskHandle_t type pointer generally points to one of these structs
 * and is used to reference the TaskStatus_t struct.
 */
typedef struct
{
	/**
	 * A function pointer to a function that implements the task
	 */
	void * task_function;
	
	/**
	 * The size of the stack allocated for the task
	 */
	uint16_t stack_depth;

	/**
	 * The priority of the task. A lower number equates to a higher
	 * priority.
	 */
	uint8_t priority;

	/**
	 * The current state of the task.
	 */
	TaskState_e state;

	/**
	 * A unique identifier for the task.
	 */
	uint8_t task_number;
} TaskStatus_t;

#endif
