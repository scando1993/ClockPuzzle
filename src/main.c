/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2016 kevin cando <scando@fiec.espol.edu.ec>
 * 
 * Clock_Puzzle is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Clock_Puzzle is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "main_window.h"

typedef struct _Private Private;
struct _Private
{
	/* ANJUTA: Widgets declaration for clock_puzzle.ui - DO NOT REMOVE */
};

static Private* priv = NULL;


GtkBuilder *builder;

int
main (int argc, char *argv[])
{
 	GtkWidget *window;


#ifdef G_OS_WIN32
	gchar *prefix = g_win32_get_package_installation_directory_of_module (NULL);
	gchar *localedir = g_build_filename (prefix, "share", "locale", NULL);
#endif

#ifdef ENABLE_NLS

# ifndef G_OS_WIN32
	bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
# else
	bindtextdomain (GETTEXT_PACKAGE, localedir);
# endif
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
#endif
	
//	gtk_init (&argc, &argv);

	if (gtk_clutter_init_with_args (&argc, &argv, NULL, NULL, NULL, NULL) != CLUTTER_INIT_SUCCESS)
		g_error ("Unable to initialize GtkClutter");

	GError* error = NULL;

	/* Load UI from file */
	builder = gtk_builder_new ();

	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_critical ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, NULL);

	window = create_window ();

	priv = g_malloc (sizeof (struct _Private));
	/* ANJUTA: Widgets initialization for proyectointeligenciaartificial.ui - DO NOT REMOVE */

	gtk_widget_show_all (window);

	gtk_main ();


	g_free (priv);
	g_object_unref (builder);
#ifdef G_OS_WIN32
	g_free (prefix);
	g_free (localedir);
#endif

	return 0;
}

