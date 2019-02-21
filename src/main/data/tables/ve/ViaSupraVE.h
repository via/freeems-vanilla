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


// 250,      500,       900,       1200,      1600,      2000,      2400,      3000,     3600,      4000,      4600,      5200,      5800,      6400,      6800,       7200
  VE(10.0),  VE(16.0),  VE(16.0),  VE(20.0),  VE(20.0),  VE(22.0),  VE(22.0),  VE(23.0),  VE(29.0),  VE(29.0),  VE(29.0),  VE(30.0),  VE(30.0),  VE(30.0),  VE(30.0),  VE(30.0),
  VE(58.0),  VE(45.0),  VE(27.0),  VE(27.0),  VE(27.0),  VE(28.0),  VE(35.0),  VE(36.0),  VE(36.0),  VE(48.0),  VE(48.0),  VE(48.0),  VE(48.0),  VE(48.0),  VE(42.0),  VE(42.0),
  VE(58.0),  VE(53.0),  VE(45.0),  VE(43.0),  VE(43.0),  VE(49.0),  VE(48.0),  VE(45.0),  VE(47.0),  VE(65.0),  VE(66.0),  VE(66.0),  VE(66.0),  VE(66.0),  VE(66.0),  VE(66.0),
  VE(58.0),  VE(46.0),  VE(45.0),  VE(52.0),  VE(60.0),  VE(60.0),  VE(60.0),  VE(64.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(65.0),
  VE(58.0),  VE(50.0),  VE(45.0),  VE(68.0),  VE(70.0),  VE(67.0),  VE(68.0),  VE(70.0),  VE(72.0),  VE(68.0),  VE(68.0),  VE(68.0),  VE(68.0),  VE(68.0),  VE(68.0),  VE(68.0),
  VE(58.0),  VE(60.0),  VE(45.0),  VE(72.0),  VE(72.0),  VE(68.0),  VE(72.0),  VE(65.0),  VE(70.0),  VE(70.0),  VE(70.0),  VE(70.0),  VE(70.0),  VE(70.0),  VE(70.0),  VE(70.0),
  VE(58.0),  VE(66.0),  VE(50.0),  VE(73.0),  VE(75.0),  VE(72.0),  VE(73.0),  VE(73.0),  VE(72.0),  VE(77.0),  VE(80.0),  VE(80.0),  VE(80.0),  VE(80.0),  VE(85.0),  VE(75.0),
  VE(60.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(67.0),  VE(67.0),  VE(73.0),  VE(75.0),  VE(75.0),  VE(79.0),  VE(80.0),  VE(80.0),  VE(82.0),  VE(82.0),  VE(95.0),  VE(95.0),
  VE(60.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(67.0),  VE(67.0),  VE(76.0),  VE(77.0),  VE(80.0),  VE(80.0),  VE(82.0),  VE(82.0),  VE(82.0),  VE(82.0),  VE(95.0),  VE(95.0),
  VE(60.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(67.0),  VE(67.0),  VE(76.0),  VE(77.0),  VE(80.0),  VE(82.0),  VE(88.0),  VE(86.0),  VE(86.0),  VE(86.0),  VE(100.0),  VE(100.0),
  VE(60.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(72.0),  VE(80.0),  VE(85.0),  VE(80.0),  VE(80.0),  VE(82.0),  VE(83.0),  VE(84.0),  VE(100.0),  VE(100.0),  VE(100.0),  VE(100.0),
  VE(60.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(72.0),  VE(82.0),  VE(80.0),  VE(80.0),  VE(85.0),  VE(90.0),  VE(92.0),  VE(95.0),  VE(97.0),  VE(100.0),  VE(101.0),  VE(102.0),
  VE(60.0),  VE(65.0),  VE(65.0),  VE(67.0),  VE(72.0),  VE(76.0),  VE(76.0),  VE(80.0),  VE(82.0),  VE(83.0),  VE(80.0),  VE(85.0),  VE(91.0),  VE(105.0),  VE(108.0),  VE(110.0),
  VE(60.0),  VE(65.0),  VE(65.0),  VE(65.0),  VE(74.0),  VE(86.0),  VE(87.0),  VE(88.0),  VE(94.0),  VE(98.0),  VE(102.0),  VE(104.0),  VE(110.0),  VE(111.0),  VE(112.0),  VE(114.0),
  VE(60.0),  VE(68.0),  VE(68.0),  VE(68.0),  VE(76.0),  VE(88.0),  VE(90.0),  VE(90.0),  VE(100.0),  VE(105.0),  VE(109.0),  VE(110.0),  VE(113.0),  VE(116.0),  VE(118.0),  VE(122.0),
  VE(60.0),  VE(68.0),  VE(68.0),  VE(68.0),  VE(80.0),  VE(90.0),  VE(92.0),  VE(94.0),  VE(105.0),  VE(110.0),  VE(115.0),  VE(117.0),  VE(119.0),  VE(122.0),  VE(124.0),  VE(125.0)
// 250,      500,       900,       1200,      1600,      2150,      2400,      3000,     3600,      4000,      4600,      5200,      5800,      6400,      6800,       7200
