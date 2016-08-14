/***************************************************************************
 *            MainWindow.h
 *
 *  Sun August 14 05:45:07 2016
 *  Copyright  2016  kevin cando
 *  <user@host>
 ****************************************************************************/
/*
 * MainWindow.h
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

/* For testing purpose, define TEST to use the local (not installed) ui file */
#define TEST
#ifdef TEST
#define UI_FILE "src/clock_puzzle.ui"
#else
#ifdef G_OS_WIN32
#define UI_FILE ui_file
#else
#define UI_FILE PACKAGE_DATA_DIR"/ui/clock_puzzle.ui"
#endif
#endif
#define TOP_WINDOW "VentanaPrincipal"

extern gint WINDOW_WIDTH;
extern gint WINDOW_HEIGHT;

//Metodo para crear la ventana principal
GtkWidget* create_window (void);
