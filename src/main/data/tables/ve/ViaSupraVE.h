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
  VE(15.0),  VE(15.0),  VE(13.0),  VE(15.0),  VE(15.0),  VE(15.0),  VE(15.0),  VE(15.0),  VE(15.0),  VE(15.0),  VE(15.0),  VE(15.0),  VE(15.0),  VE(15.0),  VE(15.0),  VE(15.0), //20
  VE(50.0),  VE(30.0),  VE(33.0),  VE(16.0),  VE(19.0),  VE(19.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0), //30
  VE(50.0),  VE(30.0),  VE(13.0),  VE(18.0),  VE(20.0),  VE(18.0),  VE(20.0),  VE(21.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0),  VE(20.0), //40
  VE(50.0),  VE(30.0),  VE(17.0),  VE(18.0),  VE(22.0),  VE(21.0),  VE(23.0),  VE(22.0),  VE(23.0),  VE(30.0),  VE(30.0),  VE(30.0),  VE(30.0),  VE(30.0),  VE(30.0),  VE(30.0), //50
  VE(50.0),  VE(50.0),  VE(30.0),  VE(30.0),  VE(31.0),  VE(33.0),  VE(30.0),  VE(36.0),  VE(36.0),  VE(34.0),  VE(35.0),  VE(35.0),  VE(35.0),  VE(35.0),  VE(35.0),  VE(35.0), //60
  VE(50.0),  VE(50.0),  VE(50.0),  VE(38.0),  VE(40.0),  VE(39.0),  VE(42.0),  VE(40.0),  VE(40.0),  VE(37.0),  VE(40.0),  VE(40.0),  VE(40.0),  VE(40.0),  VE(40.0),  VE(40.0), //70
  VE(50.0),  VE(50.0),  VE(50.0),  VE(40.0),  VE(40.0),  VE(41.0),  VE(42.0),  VE(42.0),  VE(44.0),  VE(44.0),  VE(44.0),  VE(44.0),  VE(45.0),  VE(45.0),  VE(45.0),  VE(45.0), //80
  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0), //90

  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0), //100
  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0), //150
  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0), //165
  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0), //180
  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0), //195
  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0), //210
  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0), //225
  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(50.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(75.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0),  VE(85.0)  //240
// 250,      500,       900,       1200,      1600,      2000,      2400,      3000,     3600,      4000,      4400,      5200,      5800,      6400,      6800,       7200
