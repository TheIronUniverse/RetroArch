/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2015 - Daniel De Matteis
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __UI_COMPANION_DRIVER_H
#define __UI_COMPANION_DRIVER_H

#include <stddef.h>
#include <boolean.h>

#ifdef HAVE_CONFIG_H
#include "../config.h"
#endif

#include "../command_event.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ui_companion_driver
{
   void *(*init)(void);
   void (*deinit)(void *data);
   int  (*iterate)(void *data, unsigned action);
   void (*toggle)(void *data);
   void (*event_command)(void *data, unsigned action);
   void (*notify_content_loaded)(void *data);

   const char *ident;
} ui_companion_driver_t;

extern const ui_companion_driver_t ui_companion_null;
extern const ui_companion_driver_t ui_companion_cocoatouch;
extern const ui_companion_driver_t ui_companion_qt;

/**
 * ui_companion_find_driver:
 * @ident               : Identifier name of driver to find.
 *
 * Finds driver with @ident. Does not initialize.
 *
 * Returns: pointer to driver if successful, otherwise NULL.
 **/
const ui_companion_driver_t *ui_companion_find_driver(const char *ident);

const ui_companion_driver_t *ui_companion_get_ptr(void);

/**
 * ui_companion_init_first:
 *
 * Finds first suitable driver and initialize.
 *
 * Returns: pointer to first suitable driver, otherwise NULL. 
 **/
const ui_companion_driver_t *ui_companion_init_first(void);

#ifdef __cplusplus
}
#endif

#endif
