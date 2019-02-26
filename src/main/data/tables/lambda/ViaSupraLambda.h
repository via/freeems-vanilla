/* FreeEMS - the open source engine management system
 *
 * Copyright 2012 Fred Cooke
 *
 * This file is part of the FreeEMS project.
 *
 * FreeEMS software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FreeEMS software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with any FreeEMS software.  If not, see http://www.gnu.org/licenses/
 *
 * We ask that if you make any changes to this file you email them upstream to
 * us at admin(at)diyefi(dot)org or, even better, fork the code on github.com!
 *
 * Thank you for choosing FreeEMS to run your engine!
 */


//    250,      700,     1000,     1600,     2200,     2800,     3400,     4000,     4600,     5200,     5800,     6400,     7000,     7600,     8200,     8800  // Vacuum
 LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), //  20
 LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), //  30
 LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), //  40
 LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), //  60
 LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), //  70
 LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), //  80
 LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), //  90
 LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), //  100
 LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), //  120
 LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), //  140
 LR(0.83), LR(0.83), LR(0.83), LR(0.83), LR(0.83), LR(0.78), LR(0.78), LR(0.78), LR(0.78), LR(0.78), LR(0.78), LR(0.78), LR(0.78), LR(0.78), LR(0.78), LR(0.78), //  160
 LR(0.83), LR(0.83), LR(0.83), LR(0.83), LR(0.83), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), //  180
 LR(0.81), LR(0.81), LR(0.81), LR(0.81), LR(0.81), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), // 200
 LR(0.73), LR(0.73), LR(0.73), LR(0.81), LR(0.81), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), // 220
 LR(0.75), LR(0.75), LR(0.75), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73), LR(0.73)  // 240
//    250,      700,     1000,     1600,     2200,     2800,     3400,     4000,     4600,     5200,     5800,     6400,     7000,     7600,     8200,     8800  // Boost
