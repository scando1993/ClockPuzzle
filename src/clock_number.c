/***************************************************************************
 *            clock_number.c
 *
 *  Tue August 16 20:26:59 2016
 *  Copyright  2016  kevin cando
 *  <user@host>
 ****************************************************************************/
/*
 * clock_number.c
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

#include "clock_number.h"

ClutterActor *clutter_circle(gfloat xpos,gfloat ypos,gfloat width,gfloat height);

//void on_actor_resize (ClutterActor *actor,const ClutterActorBox *allocation,ClutterAllocationFlags flags,gpointer user_data);
void on_stage_button_press(ClutterStage *stage, ClutterEvent *event, gpointer data) ;
gboolean draw_circle (ClutterCanvas *canvas,cairo_t *cr,int width,int height,gpointer data);
//gboolean idle_resize (gpointer data);

/*
void on_stage_button_press(ClutterStage *stage, ClutterEvent *event, gpointer data) {
    // find out which part of the screen was clicked
    gfloat x = 0;
    gfloat y = 0;

	gfloat width = 0;
	gfloat height = 0;

    clutter_event_get_coords(event, &x, &y);

    // find which actor was clicked
    ClutterActor* clicked = clutter_stage_get_actor_at_pos(CLUTTER_STAGE(stage), CLUTTER_PICK_ALL, x, y);

	clutter_actor_get_size (clicked,&width,&height);

	g_critical("%f,%f",width,height);
	
    // ignore clicks on the stage
    if (clicked == CLUTTER_ACTOR(stage)) return;

	ClutterActor *circle = clutter_circle(x,y,width,height);

	clutter_actor_add_child (stage,circle);

	
    // hide the actor that was clicked
    //clutter_actor_hide(clicked);
	clutter_actor_show (circle);
}
*/
gboolean draw_clock_number (ClutterCanvas *canvas,
                  			cairo_t *cr,
		      				int width,
				      		int height,
				      		gpointer data){

	GRand *rand = g_rand_new();

	int number_of_rect = 24;

	static int i = 0;
	
	//ClutterSize *position = (ClutterSize*) data;

	ClockNumber *cn = (ClockNumber*) data;

	cairo_save (cr);

	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	
	cairo_paint (cr);

	cairo_restore (cr);

	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);

	//* scale the modelview to the size of the surface *
	//cairo_scale (cr, width, height);

	cairo_set_line_cap (cr, CAIRO_LINE_CAP_ROUND);
	cairo_set_line_width (cr, 1);

	gdouble rotation = 0.0;

	for(int i = number_of_rect; i > 0; i--){
		ClutterColor col = {	
							g_rand_int_range (rand,0,256), 
							g_rand_int_range (rand,0,256), 
							g_rand_int_range (rand,0,256), 
							255 
		};

		

		clutter_cairo_set_source_color (cr,&col);

		cairo_rectangle (cr,
		                 0,
		                 0,
		                 width,
		                 height);

		cairo_fill (cr);
		cairo_rotate (cr,rotation);
/*
		clutter_actor_set_size(rect, width, height);
		clutter_actor_set_position(rect, xpos, ypos);
		clutter_actor_set_anchor_point(rect, width/2, height/2);
		clutter_actor_set_rotation_angle (rect,CLUTTER_Z_AXIS,rotation)	;
*/
		rotation += 360/(2*number_of_rect)*(M_PI/180);
		
	}
	//* we're done drawing *
	return TRUE;
	/*
	gdouble rotation = 0.0;
	
	for(int i = number_of_rect; i > 0; i--){
		rotation += 360/(2*number_of_rect);
		
		ClutterColor col = { rand() % 256, rand() % 256, rand() % 256, i*128/number_of_rect };
		ClutterActor *rect = clutter_rectangle_new_with_color(&col);

		clutter_actor_set_size(rect, width, height);
		clutter_actor_set_position(rect, xpos, ypos);
		clutter_actor_set_anchor_point(rect, width/2, height/2);
		clutter_actor_set_rotation_angle (rect,CLUTTER_Z_AXIS,rotation)	;

		clutter_actor_add_child (figure,rect);

	}
*/
}

gboolean
invalidate_clock (gpointer data_){

	/* invalidate the contents of the canvas */
  clutter_content_invalidate (data_);

  /* keep the timeout source */
  return G_SOURCE_CONTINUE;
}

guint idle_resize_id;

gboolean idle_resize (gpointer data){
	
	ClutterActor *actor = data;
	float width, height;

	//* match the canvas size to the actor's *
	clutter_actor_get_size (actor, &width, &height);

	clutter_canvas_set_size(CLUTTER_CANVAS (clutter_actor_get_content (actor)),
		               		ceilf (width),
		               		ceilf (height));

	//* unset the guard *
	idle_resize_id = 0;

	//* remove the timeout *
	return G_SOURCE_REMOVE;
}

void on_actor_resize (ClutterActor *actor,
                      const ClutterActorBox *allocation,
                      ClutterAllocationFlags flags,
                      gpointer user_data){
	
	//* throttle multiple actor allocations to one canvas resize; we use a guard
	//* variable to avoid queueing multiple resize operations
	//
	if (idle_resize_id == 0)
		idle_resize_id = clutter_threads_add_timeout (1000, idle_resize, actor);
}

ClockNumber *clock_number_init(gfloat width, 
                               gfloat height, 
                               gfloat xpos, 
                               gfloat ypos){
	
	ClockNumber *cn = (ClockNumber*)malloc(sizeof(ClockNumber));

	cn->actor = clutter_actor_new ();
	cn->canvas = clutter_canvas_new ();
	cn->size = clutter_size_init (clutter_size_alloc (), width, height);
	cn->position = clutter_size_init (clutter_size_alloc (), xpos, ypos);
	cn->value = 0;

	return cn;
}

ClockNumber *create_clock_number( gfloat xpos, 
                                  gfloat ypos, 
                                  gfloat width, 
                                  gfloat height, 
                                  gint number,
                                  gint number_of_rect) {

	ClockNumber *cn = clock_number_init(width, height, xpos, ypos);

	
	clutter_actor_set_content (cn->actor,cn->canvas);
	
	clutter_actor_set_content_scaling_filters (cn->actor,
		                                 	   CLUTTER_SCALING_FILTER_TRILINEAR,
		                                 	   CLUTTER_SCALING_FILTER_LINEAR);

	clutter_canvas_set_size (CLUTTER_CANVAS (cn->canvas),width,height);

	clutter_actor_set_position(cn->actor, xpos, ypos);

	clutter_actor_set_size (cn->actor, width, height);

	/* the actor now owns the canvas */
	g_object_unref (cn->canvas);

	ClutterActor *text = clutter_text_new_with_text ("Sans Bold","");

	gchar numberStr[4] = "";
	
	sprintf(numberStr,"%d",number);

	clutter_text_set_text (CLUTTER_TEXT(text),numberStr);

	clutter_actor_add_child (cn->actor, text);

	clutter_actor_set_position (text,xpos,ypos);

	cn->value = number;

	// resize the canvas whenever the actor changes size 
//	g_signal_connect (cn->actor, "allocation-changed", G_CALLBACK (on_actor_resize), NULL);

	// connect our drawing code 
	g_signal_connect (cn->canvas, "draw", G_CALLBACK (draw_clock_number), cn);

	// invalidate the canvas, so that we can draw before the main loop starts 
	clutter_content_invalidate (cn->canvas);

	/* set up a timer that invalidates the canvas every second */
//	clutter_threads_add_timeout (1000, invalidate_clock, cn->canvas);

	return cn;
}
