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

ClutterActor *create_clock_number(gint xpos, gint ypos, gint width, gint height, gint number);
void on_stage_button_press(ClutterStage *stage, ClutterEvent *event, gpointer data) ;

void on_stage_button_press(ClutterStage *stage, ClutterEvent *event, gpointer data) {
    // find out which part of the screen was clicked
    gfloat x = 0;
    gfloat y = 0;

	gint width = 0;
	gint height = 0;

    clutter_event_get_coords(event, &x, &y);

    // find which actor was clicked
    ClutterActor* clicked = clutter_stage_get_actor_at_pos(CLUTTER_STAGE(stage), CLUTTER_PICK_ALL, x, y);

	clutter_actor_get_size (clicked,&width,&height);

    // ignore clicks on the stage
    if (clicked == CLUTTER_ACTOR(stage)) return;

    // hide the actor that was clicked
    clutter_actor_hide(clicked);
}

ClutterActor *create_clock_number(gint xpos, gint ypos, gint width, gint height, gint number) {
	ClutterActor *figure = clutter_actor_new ();
	gdouble rotation = 0.0;
	
	for(int i = 0; i < 12; i++){
		rotation += 15;
		
		ClutterColor col = { rand() % 256, rand() % 256, rand() % 256, 128 };
		ClutterActor *rect = clutter_rectangle_new_with_color(&col);

		clutter_actor_set_size(rect, width, height);
		clutter_actor_set_position(rect, xpos, ypos);
		clutter_actor_set_anchor_point(rect, width/2, height/2);
		clutter_actor_set_rotation_angle (rect,CLUTTER_Z_AXIS,rotation)	;

		clutter_actor_add_child (figure,rect);
	}

	g_signal_connect(figure, "button-press-event", G_CALLBACK(on_stage_button_press), NULL);
	
    return figure;
}

GtkWidget* create_stage(){
	ClutterColor stage_color = { 0, 0, 0, 255 };

	GtkWidget *clutterStage = gtk_clutter_embed_new ();
	
    stage = gtk_clutter_embed_get_stage (GTK_CLUTTER_EMBED(clutterStage));

	gtk_widget_set_size_request (clutterStage, 512, 512);
    clutter_actor_set_background_color (stage, &stage_color);

	return clutterStage;		
}

void generate_clock(gint stages){
	for(int i = 0; i < stages; i++){
		ClutterActor *figure = create_clock_number(300,400,100,100,1);
		clutter_actor_add_child (stage,figure);
	}	
}

void new_game(){
	generate_clock(1);
	clutter_actor_show (stage);
}