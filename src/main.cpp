/*
 * File: main.cpp
 * Project: arduino-frequency-analyzer
 * Created Date: 2022-09-10 14:42:22
 * Author: 3urobeat
 *
 * Last Modified: 2024-02-09 22:08:08
 * Modified By: 3urobeat
 *
 * Copyright (c) 2022 - 2024 3urobeat <https://github.com/3urobeat>
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
 */



#include "main.h"
#include "helpers/helpers.h"


// Call display lib constructor
TFT_eSPI tft = TFT_eSPI();


// Setup stuff on poweron
void setup() {

    // Init display and show welcome screen
    tft.init();
    tft.setRotation(displayRotation);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.setFreeFont(FMB9);

    showWelcomeScreen(5000); // show the welcome screen

    // Setup readout screen by showing labels etc
    setupReadoutScreen();

}


void loop() {

    testRandomReadouts();

    delay(100);

}
