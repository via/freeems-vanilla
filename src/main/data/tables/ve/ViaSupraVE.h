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


// 250,      500,       900,       1200,      1600,      2000,      2400,      3000,     3600,      4000,      4400,      5200,      5800,      6400,      6800,       7200
  VE(70.0),  VE(70.0),  VE(50.0),  VE(50.0),  VE(55.0),  VE(65.0),  VE(61.0),  VE(63.0),  VE(59.0),  VE(61.0),  VE(61.0),  VE(67.0),  VE(67.0),  VE(70.0),  VE(22.0),  VE(23.0), //20
  VE(70.0),  VE(70.0),  VE(49.0),  VE(50.0),  VE(55.0),  VE(51.0),  VE(47.0),  VE(49.0),  VE(50.0),  VE(50.0),  VE(54.0),  VE(70.0),  VE(70.0),  VE(70.0),  VE(32.0),  VE(32.0), //30
  VE(70.0),  VE(70.0),  VE(49.0),  VE(61.0),  VE(60.0),  VE(58.0),  VE(60.0),  VE(59.0),  VE(56.0),  VE(70.0),  VE(64.0),  VE(70.0),  VE(70.0),  VE(70.0),  VE(66.0),  VE(66.0), //40
  VE(70.0),  VE(70.0),  VE(64.0),  VE(63.0),  VE(60.0),  VE(62.0),  VE(66.0),  VE(61.0),  VE(63.0),  VE(77.0),  VE(77.0),  VE(77.0),  VE(70.0),  VE(70.0),  VE(65.0),  VE(65.0), //50
  VE(70.0),  VE(70.0),  VE(67.0),  VE(62.0),  VE(64.0),  VE(65.0),  VE(73.0),  VE(73.0),  VE(68.0),  VE(79.0),  VE(87.0),  VE(85.0),  VE(70.0),  VE(70.0),  VE(68.0),  VE(68.0), //60
  VE(70.0),  VE(70.0),  VE(73.0),  VE(68.0),  VE(68.0),  VE(68.0),  VE(67.0),  VE(68.0),  VE(72.0),  VE(82.0),  VE(87.0),  VE(85.0),  VE(74.0),  VE(75.0),  VE(75.0),  VE(75.0), //70
  VE(70.0),  VE(70.0),  VE(73.0),  VE(73.0),  VE(72.0),  VE(74.0),  VE(76.0),  VE(76.0),  VE(83.0),  VE(83.0),  VE(87.0),  VE(85.0),  VE(76.0),  VE(76.0),  VE(76.0),  VE(76.0), //80
  VE(70.0),  VE(70.0),  VE(77.0),  VE(79.0),  VE(80.0),  VE(90.0),  VE(81.0),  VE(78.0),  VE(98.0),  VE(92.0),  VE(87.0),  VE(85.0),  VE(83.0),  VE(82.0),  VE(82.0),  VE(82.0), //90

  VE(70.0),  VE(70.0),  VE(77.0),  VE(81.0),  VE(83.0),  VE(86.0),  VE(87.0),  VE(90.0),  VE(88.0),  VE(92.0),  VE(91.0),  VE(92.0),  VE(92.0),  VE(92.0),  VE(92.0),  VE(82.0), //100
  VE(65.0),  VE(60.0),  VE(77.0),  VE(81.0),  VE(83.0),  VE(86.0),  VE(87.0),  VE(90.0),  VE(90.0),  VE(92.0),  VE(91.0),  VE(92.0),  VE(92.0),  VE(92.0),  VE(92.0),  VE(95.0), //150
  VE(65.0),  VE(60.0),  VE(77.0),  VE(81.0),  VE(83.0),  VE(86.0),  VE(85.0),  VE(87.0),  VE(90.0),  VE(92.0),  VE(91.0),  VE(92.0),  VE(92.0),  VE(95.0),  VE(95.0),  VE(95.0), //165
  VE(65.0),  VE(60.0),  VE(77.0),  VE(81.0),  VE(83.0),  VE(86.0),  VE(85.0),  VE(87.0),  VE(90.0),  VE(92.0),  VE(91.0),  VE(92.0),  VE(92.0),  VE(95.0),  VE(95.0),  VE(95.0), //180
  VE(65.0),  VE(60.0),  VE(77.0),  VE(81.0),  VE(83.0),  VE(86.0),  VE(85.0),  VE(87.0),  VE(90.0),  VE(92.0),  VE(91.0),  VE(92.0),  VE(92.0),  VE(95.0),  VE(95.0),  VE(95.0), //195
  VE(65.0),  VE(60.0),  VE(77.0),  VE(81.0),  VE(83.0),  VE(86.0),  VE(85.0),  VE(87.0),  VE(90.0),  VE(92.0),  VE(91.0),  VE(92.0),  VE(92.0),  VE(95.0),  VE(95.0),  VE(95.0), //210
  VE(65.0),  VE(60.0),  VE(77.0),  VE(81.0),  VE(83.0),  VE(86.0),  VE(85.0),  VE(87.0),  VE(90.0),  VE(92.0),  VE(91.0),  VE(92.0),  VE(92.0),  VE(95.0),  VE(95.0),  VE(95.0), //225
  VE(65.0),  VE(60.0),  VE(77.0),  VE(81.0),  VE(83.0),  VE(86.0),  VE(85.0),  VE(87.0),  VE(90.0),  VE(92.0),  VE(91.0),  VE(92.0),  VE(92.0),  VE(95.0),  VE(95.0),  VE(95.0)  //240
// 250,      500,       900,       1200,      1600,      2000,      2400,      3000,     3600,      4000,      4400,      5200,      5800,      6400,      6800,       7200
