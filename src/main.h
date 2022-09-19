/*
 * File: main.h
 * Project: arduino-frequency-analyzer
 * Created Date: 10.09.2022 14:42:27
 * Author: 3urobeat
 * 
 * Last Modified: 19.09.2022 14:42:45
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include <SPI.h>
#include <TFT_eSPI.h>

extern const char *version;
extern TFT_eSPI tft;

void showWelcomeScreen(unsigned int clearDelay);



// Display Pins:
// SCLK: 14
// MOSI: 13
// MISO: 12
// CS: 15
// RES: 32
// DC: 33
// BLK: 25
// Touch_CS: 2
// INT: 4
// SDCS: 16