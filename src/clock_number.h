/***************************************************************************
 *            clock_number.h
 *
 *  Tue August 16 20:26:59 2016
 *  Copyright  2016  kevin cando
 *  <user@host>
 ****************************************************************************/
/*
 * clock_number.h
 *
 * Copyright (C) 2016 - kevin cando
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "dependencies.h"

typedef ClutterSize ClutterPosition;

typedef struct ClockNumber{
	 ClutterActor *actor;
	 ClutterContent *canvas;
	 ClutterSize *size;
	 ClutterPosition *position;
	 gint value;
}ClockNumber;


ClockNumber *clock_number_init( gfloat width, 
                           		gfloat height, 
                           		gfloat xpos, 
                           		gfloat ypos);

ClockNumber *create_clock_number(  gfloat xpos, 
                             	   gfloat ypos, 
                             	   gfloat width, 
                             	   gfloat height, 
                             	   gint number,
                             	   gint number_of_rect);

void clock_number_change_canvas(ClockNumber *cn, cairo_t *canvas);

