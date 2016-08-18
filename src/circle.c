/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * circle.c
 * Copyright (C) 2016 kevin cando <scando@fiec.espol.edu.ec>
 *
 * clock_puzzle is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * clock_puzzle is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "circle.h"

struct _CirclePrivate
{
};




static gchar
circle_get_string (3)
{
	/* TODO: Add private function implementation here */
}

G_DEFINE_TYPE (Circle, circle, G_TYPE_OBJECT);

static void
circle_init (Circle *circle)
{
	circle->priv = G_TYPE_INSTANCE_GET_PRIVATE (circle, CIRCLE_TYPE_ClutterActor, CirclePrivate);

	/* TODO: Add initialization code here */
}

static void
circle_finalize (GObject *object)
{
	/* TODO: Add deinitalization code here */

	G_OBJECT_CLASS (circle_parent_class)->finalize (object);
}

static void
circle_class_init (CircleClass *klass)
{
	GObjectClass* object_class = G_OBJECT_CLASS (klass);

	g_type_class_add_private (klass, sizeof (CirclePrivate));

	object_class->finalize = circle_finalize;
}


