/*
 * File: main.cpp
 * Project: arduino-frequency-analyzer
 * Created Date: 10.09.2022 14:42:22
 * Author: 3urobeat
 * 
 * Last Modified: 19.09.2022 14:45:01
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "main.h"

const char *version = "v0.1.0";

// Call display lib constructor
TFT_eSPI tft = TFT_eSPI();


// Setup stuff on poweron
void setup() {

    // Init display and show welcome screen
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0, 1); // last param is the font to use, use it everywhere

    showWelcomeScreen(5000); // show the welcome screen 

}


void loop() {
    
}