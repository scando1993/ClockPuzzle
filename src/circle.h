/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * circle.h
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

#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define CIRCLE_TYPE_ClutterActor             (circle_get_type ())
#define CIRCLE_ClutterActor(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), CIRCLE_TYPE_ClutterActor, Circle))
#define CIRCLE_ClutterActor_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), CIRCLE_TYPE_ClutterActor, CircleClass))
#define CIRCLE_IS_ClutterActor(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CIRCLE_TYPE_ClutterActor))
#define CIRCLE_IS_ClutterActor_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), CIRCLE_TYPE_ClutterActor))
#define CIRCLE_ClutterActor_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), CIRCLE_TYPE_ClutterActor, CircleClass))

typedef struct _CircleClass CircleClass;
typedef struct _Circle Circle;
typedef struct _CirclePrivate CirclePrivate;


struct _CircleClass
{
	GObjectClass parent_class;
};

struct _Circle
{
	GObject parent_instance;

	CirclePrivate *priv;
};

GType circle_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* _CIRCLE_H_ */

