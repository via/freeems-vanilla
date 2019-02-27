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
  VE(65.0),  VE(30.0),  VE(10.0),  VE(10.0),  VE(10.0),  VE(11.0),  VE(12.0),  VE(10.0),  VE(12.0),  VE(16.0),  VE(16.0),  VE(16.0),  VE(16.0),  VE(16.0),  VE(16.0),  VE(16.0), //20
  VE(65.0),  VE(50.0),  VE(10.0),  VE(11.0),  VE(10.0),  VE(11.0),  VE(14.0),  VE(12.0),  VE(15.0),  VE(20.0),  VE(24.0),  VE(25.0),  VE(26.0),  VE(26.0),  VE(26.0),  VE(26.0), //30
  VE(65.0),  VE(60.0),  VE(23.0),  VE(23.0),  VE(23.0),  VE(21.0),  VE(24.0),  VE(27.0),  VE(34.0),  VE(37.0),  VE(41.0),  VE(43.0),  VE(45.0),  VE(45.0),  VE(45.0),  VE(45.0), //40
  VE(65.0),  VE(60.0),  VE(43.0),  VE(36.0),  VE(30.0),  VE(30.0),  VE(36.0),  VE(34.0),  VE(39.0),  VE(44.0),  VE(48.0),  VE(50.0),  VE(52.0),  VE(52.0),  VE(52.0),  VE(52.0), //50
  VE(65.0),  VE(60.0),  VE(49.0),  VE(48.0),  VE(41.0),  VE(38.0),  VE(42.0),  VE(44.0),  VE(51.0),  VE(52.0),  VE(52.0),  VE(52.0),  VE(52.0),  VE(52.0),  VE(52.0),  VE(52.0), //60
  VE(65.0),  VE(60.0),  VE(49.0),  VE(49.0),  VE(46.0),  VE(45.0),  VE(51.0),  VE(49.0),  VE(61.0),  VE(59.0),  VE(58.0),  VE(60.0),  VE(63.0),  VE(63.0),  VE(63.0),  VE(63.0), //70
  VE(65.0),  VE(60.0),  VE(65.0),  VE(56.0),  VE(52.0),  VE(54.0),  VE(61.0),  VE(63.0),  VE(64.0),  VE(63.0),  VE(64.0),  VE(65.0),  VE(68.0),  VE(68.0),  VE(68.0),  VE(68.0), //80
  VE(65.0),  VE(60.0),  VE(65.0),  VE(65.0),  VE(62.0),  VE(57.0),  VE(67.0),  VE(67.0),  VE(71.0),  VE(66.0),  VE(66.0),  VE(67.0),  VE(70.0),  VE(70.0),  VE(70.0),  VE(72.0), //90
  VE(65.0),  VE(60.0),  VE(65.0),  VE(65.0),  VE(64.0),  VE(66.0),  VE(71.0),  VE(71.0),  VE(71.0),  VE(66.0),  VE(67.0),  VE(68.0),  VE(78.0),  VE(82.0),  VE(82.0),  VE(82.0), //100
  VE(65.0),  VE(60.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(78.0),  VE(78.0),  VE(72.0),  VE(68.0),  VE(75.0),  VE(79.0),  VE(78.0),  VE(80.0),  VE(82.0),  VE(82.0), //120
  VE(65.0),  VE(60.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(78.0),  VE(78.0),  VE(72.0),  VE(75.0),  VE(78.0),  VE(79.0),  VE(78.0),  VE(80.0),  VE(82.0),  VE(82.0), //140
  VE(65.0),  VE(60.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(78.0),  VE(78.0),  VE(72.0),  VE(78.0),  VE(78.0),  VE(79.0),  VE(78.0),  VE(80.0),  VE(82.0),  VE(82.0), //160
  VE(65.0),  VE(60.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(78.0),  VE(78.0),  VE(72.0),  VE(78.0),  VE(78.0),  VE(79.0),  VE(78.0),  VE(80.0),  VE(82.0),  VE(82.0), //180
  VE(65.0),  VE(60.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(78.0),  VE(78.0),  VE(72.0),  VE(78.0),  VE(78.0),  VE(79.0),  VE(78.0),  VE(80.0),  VE(82.0),  VE(82.0), //200
  VE(65.0),  VE(60.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(78.0),  VE(78.0),  VE(72.0),  VE(78.0),  VE(78.0),  VE(79.0),  VE(78.0),  VE(80.0),  VE(82.0),  VE(82.0), //220
  VE(65.0),  VE(60.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(78.0),  VE(78.0),  VE(72.0),  VE(78.0),  VE(78.0),  VE(79.0),  VE(78.0),  VE(80.0),  VE(82.0),  VE(82.0)  //240
// 250,      500,       900,       1200,      1600,      2000,      2400,      3000,     3600,      4000,      4400,      5200,      5800,      6400,      6800,       7200
