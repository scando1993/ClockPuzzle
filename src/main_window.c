/***************************************************************************
 *            MainWindow.c
 *
 *  Sun August 14 05:45:07 2016
 *  Copyright  2016  kevin cando
 *  <user@host>
 ****************************************************************************/
/*
 * MainWindow.c
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

#include "main_window.h"

GtkWidget* create_window (void){

#if !defined(TEST) && defined(G_OS_WIN32)
	gchar *prefix = g_win32_get_package_installation_directory_of_module (NULL);
	gchar *datadir = g_build_filename (prefix, "share", PACKAGE, NULL);
	gchar *ui_file = g_build_filename (datadir, "ui", "proyectointeligenciaartificial.ui", NULL);
#endif
	
	GtkWidget *window;
	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, TOP_WINDOW));
        if (!window)
        {
                g_critical ("Widget \"%s\" is missing in file %s.",
				TOP_WINDOW,
				UI_FILE);
        }

	
	ClutterColor stage_color = { 0, 0, 0, 255 };

	GtkWidget *clutterStage = gtk_clutter_embed_new ();
	
    ClutterActor *stage = gtk_clutter_embed_get_stage (GTK_CLUTTER_EMBED(clutterStage));

	gtk_widget_set_size_request (clutterStage, 512, 512);
    clutter_actor_set_background_color (stage, &stage_color);

	GtkBox *vbox =GTK_BOX(GTK_WIDGET (gtk_builder_get_object (builder,"VBoxVtnPrincipal")));
    if (!vbox)
    {
            g_critical ("Widget \"%s\" is missing in file %s.",
			TOP_WINDOW,
			UI_FILE);
    }
	gtk_box_pack_start (vbox,clutterStage,TRUE,TRUE,0);
	
//	g_object_unref (builder);


#if !defined(TEST) && defined(G_OS_WIN32)
	g_free (prefix);
	g_free (datadir);
	g_free (ui_file);
#endif
	
	return window;
}
