/* Copyright 2020 Nicholas LaBonte
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

                                                                                                    Default:
ANALOG_JOYSTICK_X_AXIS_PIN      (Required) The pin used for the vertical/X axis.	                        not defined
ANALOG_JOYSTICK_Y_AXIS_PIN	    (Required) The pin used for the horizontal/Y axis.	                        not defined
ANALOG_JOYSTICK_AXIS_MIN	    (Optional) Sets the lower range to be considered movement.	                0
ANALOG_JOYSTICK_AXIS_MAX	    (Optional) Sets the upper range to be considered movement.	                1023
ANALOG_JOYSTICK_AUTO_AXIS	    (Optional) Sets ranges to be considered movement automatically.	            not defined
ANALOG_JOYSTICK_SPEED_REGULATOR	(Optional) The divisor used to slow down movement. (lower makes it faster)	20
ANALOG_JOYSTICK_READ_INTERVAL	(Optional) The interval in milliseconds between reads.	                    10
ANALOG_JOYSTICK_SPEED_MAX	    (Optional) The maximum value used for motion.	                            2
ANALOG_JOYSTICK_CLICK_PIN    	(Optional) The pin wired up to the press switch of the analog stick.	    not defined
ANALOG_JOYSTICK_WEIGHTS	        (Optional) Use custom weights for lever positions.	                        not defined
ANALOG_JOYSTICK_CUTOFF	        (Optional) Cut off movement when joystick returns to start position.	    not defined


 */

 

#pragma once

#define ANALOG_JOYSTICK_X_AXIS_PIN F0
#define ANALOG_JOYSTICK_Y_AXIS_PIN F1
#define MOUSE_BTN1_PIN F6  
#define MOUSE_BTN2_PIN F5
#define MOUSE_BTN3_PIN F4
#define ANALOG_JOYSTICK_AXIS_MIN 350
#define ANALOG_JOYSTICK_AXIS_MAX 600	
#define ANALOG_JOYSTICK_AUTO_AXIS	
// #define ANALOG_JOYSTICK_SPEED_REGULATOR 50
// #define ANALOG_JOYSTICK_SPEED_MAX 7
#define ANALOG_JOYSTICK_SPEED_MAX 2

// #define ANALOG_JOYSTICK_WEIGHTS {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100}	
// #define ANALOG_JOYSTICK_CUTOFF 85
#define ANALOG_JOYSTICK_CUTOFF 95

#define MK_COMBINED
