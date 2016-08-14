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

	GtkWidget *clutterStage = create_stage();
	
	GtkRevealer *revealer = GTK_REVEALER(GTK_WIDGET (gtk_builder_get_object (builder,"RvlStageMnuPrincipal")));

	gtk_container_add (GTK_CONTAINER(revealer),clutterStage);
	
//	g_object_unref (builder);
	g_signal_connect(G_OBJECT(window), "configure-event",G_CALLBACK(VentanaPrincipal_configure_event_cb), NULL);

#if !defined(TEST) && defined(G_OS_WIN32)
	g_free (prefix);
	g_free (datadir);
	g_free (ui_file);
#endif
	
	return window;
}
