/*
 #   Copyright (C) 2011 by Patrick Stinson                                 
 #   patrickkidd@gmail.com                                                   
 #                                                                         
 #   This program is free software; you can redistribute it and/or modify  
 #   it under the terms of the GNU General Public License as published by  
 #   the Free Software Foundation; either version 2 of the License, or     
 #   (at your option) any later version.                                   
 #                                                                         
 #   This program is distributed in the hope that it will be useful,       
 #   but WITHOUT ANY WARRANTY; without even the implied warranty of        
 #   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         
 #   GNU General Public License for more details.                          
 #                                                                         
 #   You should have received a copy of the GNU General Public License     
 #   along with this program; if not, write to the                         
 #   Free Software Foundation, Inc.,                                       
 #   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  
 */

#include <Python.h>
#include "MidiMessage.h"

#define __midi ((PyMidiMessage *)self)->m

#if OUSIA_SCRIPT_PYTHON3
#define PK_BOOL(x) PyBool_FromLong(x)
#define PK_INT(x) PyLong_FromLong(x)
#define PK_FLOAT(x) PyFloat_FromDouble(x)
#define PK_STRING(x) PyUnicode_FromString(x)
#else
#define PK_BOOL(x) PyBool_FromLong(x)
#define PK_INT(x) PyInt_FromLong(x)
#define PK_FLOAT(x) PyFloat_FromDouble(x)
#define PK_STRING(x) PyString_FromString(x)
#endif


typedef struct {
  PyObject_HEAD
  MidiMessage *m;
} PyMidiMessage;


PyObject *PyMidiMessage_new();
PyTypeObject *getMidiMessageType();
bool PyMidiMessage_Check(PyObject*);
PyObject *PyMidiMessage_FromMidiMessage(const MidiMessage &);