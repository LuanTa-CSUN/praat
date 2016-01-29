#ifndef _DemoEditor_h_
#define _DemoEditor_h_
/* DemoEditor.h
 *
 * Copyright (C) 2009-2011,2012,2015 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "Editor.h"

Thing_define (DemoEditor, Editor) {
	GuiDrawingArea drawingArea;
	autoGraphics graphics;
	void *praatPicture;
	bool clicked, keyPressed, shiftKeyPressed, commandKeyPressed, optionKeyPressed, extraControlKeyPressed;
	long x, y;
	char32 key;
	bool waitingForInput, userWantsToClose, fullScreen;

	void v_destroy () noexcept
		override;
	void v_info ()
		override;
	void v_goAway ()
		override;
	bool v_hasMenuBar ()
		override { return false; }
	bool v_canFullScreen ()
		override { return true; }
	bool v_scriptable ()
		override { return false; }
	void v_createChildren ()
		override;
	void v_createMenus ()
		override;
};

void DemoEditor_init (DemoEditor me);
autoDemoEditor DemoEditor_create ();

void Demo_open ();
void Demo_close ();
struct autoDemoOpen {
	autoDemoOpen () { Demo_open (); }
	~autoDemoOpen () { Demo_close (); }
};

int Demo_windowTitle (const char32 *title);
int Demo_show ();
void Demo_waitForInput (Interpreter interpreter);
bool Demo_clicked ();
double Demo_x ();
double Demo_y ();
bool Demo_keyPressed ();
char32 Demo_key ();
bool Demo_shiftKeyPressed ();
bool Demo_commandKeyPressed ();
bool Demo_optionKeyPressed ();
bool Demo_extraControlKeyPressed ();
/* Shortcuts: */
bool Demo_input (const char32 *keys);
bool Demo_clickedIn (double left, double right, double bottom, double top);

/* End of file DemoEditor.h */
#endif
