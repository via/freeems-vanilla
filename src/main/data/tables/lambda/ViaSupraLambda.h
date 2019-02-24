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
 LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), //  15kPa
 LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), //  30kPa
 LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), //  45kPa
 LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), LR(1.00), //  60kPa
 LR(0.97), LR(0.97), LR(0.97), LR(0.97), LR(0.97), LR(1.00), LR(1.00), LR(1.00), LR(0.97), LR(0.97), LR(0.97), LR(0.97), LR(0.97), LR(0.97), LR(0.97), LR(0.97), //  75kPa
 LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.96), LR(0.96), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), //  90kPa
 LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), LR(0.95), // 105kPa
 LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), // 120kPa
 LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), // 135kPa
 LR(0.86), LR(0.86), LR(0.86), LR(0.86), LR(0.86), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.85), LR(0.86), LR(0.86), LR(0.86), LR(0.86), LR(0.86), LR(0.86), // 150kPa
 LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), LR(0.80), // 165kPa
 LR(0.83), LR(0.83), LR(0.83), LR(0.83), LR(0.83), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), // .76kPa
 LR(0.83), LR(0.83), LR(0.83), LR(0.83), LR(0.83), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), // 195kPa
 LR(0.81), LR(0.81), LR(0.81), LR(0.81), LR(0.81), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), // 210kPa
 LR(0.76), LR(0.76), LR(0.76), LR(0.81), LR(0.81), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), // 225kPa
 LR(0.75), LR(0.75), LR(0.75), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76), LR(0.76)  // 240kPa
//    250,      700,     1000,     1600,     2200,     2800,     3400,     4000,     4600,     5200,     5800,     6400,     7000,     7600,     8200,     8800  // Boost
