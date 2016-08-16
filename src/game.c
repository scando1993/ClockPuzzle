/***************************************************************************
 *            game.c
 *
 *  Sun August 14 10:14:04 2016
 *  Copyright  2016  kevin cando
 *  <user@host>
 ****************************************************************************/
/*
 * game.c
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

#include "game.h"

ClutterActor *create_clock_number(gfloat xpos, gfloat ypos, gfloat width, gfloat height, gint number,gint number_of_rect);

ClutterActor *clutter_circle(gfloat xpos,gfloat ypos,gfloat width,gfloat height);

//void on_actor_resize (ClutterActor *actor,const ClutterActorBox *allocation,ClutterAllocationFlags flags,gpointer user_data);
void on_stage_button_press(ClutterStage *stage, ClutterEvent *event, gpointer data) ;
gboolean draw_circle (ClutterCanvas *canvas,cairo_t *cr,int width,int height,gpointer data);
//gboolean idle_resize (gpointer data);


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

gboolean draw_circle (ClutterCanvas *canvas,
                      cairo_t *cr,
                      int width,
                      int height,
                      gpointer data){

	ClutterSize *size = (ClutterSize*) data;
	
	cairo_save (cr);


	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);

	cairo_restore (cr);

	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);

	//* scale the modelview to the size of the surface *
	cairo_scale (cr, width, height);

	cairo_set_line_cap (cr, CAIRO_LINE_CAP_ROUND);
	cairo_set_line_width (cr, 1);

	clutter_cairo_set_source_color (cr, CLUTTER_COLOR_Blue);
	cairo_translate (cr,width / 2., height / 2.);
	cairo_arc (cr, size->width, size->height, width, 0, M_PI * 2);
	cairo_stroke (cr);

	//* we're done drawing *
	return TRUE;
}
/*
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

*/
ClutterActor *clutter_circle(gfloat xpos, 
                             gfloat ypos,
                             gfloat width, 
                             gfloat height){

	ClutterActor *actor;
	ClutterContent *canvas;
	
	canvas = clutter_canvas_new ();
	clutter_canvas_set_size (CLUTTER_CANVAS (canvas),(int) width,(int) height);

	actor = clutter_actor_new ();
	clutter_actor_set_content (actor, canvas);
	clutter_actor_set_content_scaling_filters (actor,
		                                 	   CLUTTER_SCALING_FILTER_TRILINEAR,
		                                 	   CLUTTER_SCALING_FILTER_LINEAR);

	clutter_actor_set_position(actor, xpos, ypos);

	ClutterSize *size = clutter_size_init (clutter_size_alloc (),xpos,ypos);
	
	// resize the canvas whenever the actor changes size 
//	g_signal_connect (actor, "allocation-changed", G_CALLBACK (on_actor_resize), NULL);

	// connect our drawing code 
	g_signal_connect (canvas, "draw", G_CALLBACK (draw_circle), size);

	// invalidate the canvas, so that we can draw before the main loop starts 
	clutter_content_invalidate (canvas);

	return actor;
}

ClutterActor *create_clock_number(gfloat xpos, 
                                  gfloat ypos, 
                                  gfloat width, 
                                  gfloat height, 
                                  gint number,
                                  gint number_of_rect) {

	ClutterActor *figure = clutter_actor_new ();
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

	ClutterActor *text = clutter_text_new_with_text ("Sans Bold","");

	gchar numberStr[4] = "";
	sprintf(numberStr,"%d",number);

	clutter_text_set_text (CLUTTER_TEXT(text),numberStr);

	clutter_actor_set_position (text,xpos,ypos);
	//clutter_actor_set_size (text,width,height);
	
	clutter_actor_add_child (figure, text);
	
	return figure;
}

GtkWidget* create_stage(){
	ClutterColor stage_color = { 255, 255, 255, 255 };

	GtkWidget *clutterStage = gtk_clutter_embed_new ();
	
    stage = gtk_clutter_embed_get_stage (GTK_CLUTTER_EMBED(clutterStage));

	//stage_size = clutter_size_init (clutter_size_alloc (),800,(500-60));
	
	gtk_widget_set_size_request (clutterStage, 800, 550);

	clutter_actor_set_background_color (stage, &stage_color);

	g_signal_connect(stage, "button-press-event", G_CALLBACK(on_stage_button_press), NULL);
	
	return clutterStage;		
}

void generate_clock(gint stages){
	gdouble r = 400/2;
	gfloat xo = 800/2;
	gfloat yo = 550/2;
	gdouble rotation = 0.0;

	gfloat offset = 1;
	gfloat size = 400/stages*2 - offset;
	
	for(int i = 0; i < stages; i++){

		printf("r*cos(%f) = %f\nr*sen(%f)= %f\n",rotation,r*cos(M_PI*rotation/180),rotation,r*sin(M_PI*rotation/180));
		
		gfloat x = xo + (float)r*cos(M_PI*rotation/180);
		gfloat y = yo + (float)r*sin(M_PI*rotation/180);

		gfloat tamx, tamy;
		printf("%f,%f\n",x,y);
		
		ClutterActor *figure = create_clock_number(x,y,size,size,i,24);
		gchar numberStr[10] = "";
		sprintf(numberStr,"(%.3f,%.3f)",x,y);

		//ClutterActor *figure = clutter_text_new_with_text ("Sans Bold",numberStr);
		//clutter_actor_set_position (figure,x,y);
		clutter_actor_get_size (figure, &tamx,&tamy);

		printf ("%f, %f\n",tamx,tamy);
		
		clutter_actor_add_child (stage,figure);

		rotation += 360/(stages);
		printf ("%f\n",rotation);
	}	
}

void new_game(){
	generate_clock(12);
	clutter_actor_show (stage);
}