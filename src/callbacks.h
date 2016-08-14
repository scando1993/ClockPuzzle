/***************************************************************************
 *            callbacks.h
 *
 *  Sun August 14 05:36:40 2016
 *  Copyright  2016  kevin cando
 *  <user@host>
 ****************************************************************************/
/*
 * callbacks.h
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

#include "dependencies.h"

extern GtkBuilder *builder;

//CallBacks para las acciones de la ventana principal
void
on_window_destroy (GtkWidget *widget, gpointer data);

//Callbacks para las funciones del menu de la ventana principal
void 
btnMnuVtnPrincipalSettings_activate_cb(GtkMenuItem *menuitem,gpointer user_data);

void 
btnMnuVtnPrincipalAbout_activate_cb(GtkMenuItem *menuitem,gpointer user_data);

//Callbacks para las funciones del toolbar de la ventana principal

//Callbacks para las funciones del menu principal de la ventana principal
void 
btnNewMnuVtnPrincipal_clicked_cb(GtkButton *button,gpointer user_data);

void 
btnLoadMnuVtnPrincipal_clicked_cb(GtkButton *button,gpointer user_data);

void 
btnExitMnuVtnPrincipal_clicked_cb(GtkButton *button,gpointer user_data);
