/***************************************************************************
 *            callbacks.c
 *
 *  Sun August 14 05:36:40 2016
 *  Copyright  2016  kevin cando
 *  <user@host>
 ****************************************************************************/
/*
 * callbacks.c
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

#include "callbacks.h"

void
on_window_destroy (GtkWidget *widget, gpointer data)
{
	gtk_main_quit ();
}

void 
VentanaPrincipal_configure_event_cb(GtkWindow *window,
                                    GdkEvent *event,
                                    gpointer data){

	gtk_window_get_size (window,&WINDOW_WIDTH,&WINDOW_HEIGHT);

}

void btnMnuVtnPrincipalSettings_activate_cb(GtkMenuItem *menuitem,
                                            gpointer     user_data){

	GtkWidget *window;
	
	window = GTK_WIDGET (gtk_builder_get_object (builder, "Settings"));
	gtk_widget_show (window);
}

void btnMnuVtnPrincipalAbout_activate_cb(GtkMenuItem *menuitem,
                                         gpointer     user_data){

	GtkWidget *window;
	
	window = GTK_WIDGET (gtk_builder_get_object (builder, "About"));
	gtk_widget_show (window);
}

void 
btnNewMnuVtnPrincipal_clicked_cb(GtkButton *button,
                                 gpointer user_data){

	GtkWidget *revealer, *revealer2;
	
	revealer = GTK_WIDGET (gtk_builder_get_object (builder, "RvlMnuVtnPrincipal"));

	revealer2 = GTK_WIDGET (gtk_builder_get_object (builder, "RvlStageMnuPrincipal"));
	
	gtk_revealer_set_reveal_child (GTK_REVEALER(revealer),FALSE);
	
	gtk_revealer_set_reveal_child (GTK_REVEALER(revealer2),TRUE);
}

void 
btnLoadMnuVtnPrincipal_clicked_cb(GtkButton *button,
                                 gpointer user_data){
}

void 
btnExitMnuVtnPrincipal_clicked_cb(GtkButton *button,
                                 gpointer user_data){
	gtk_main_quit();
}