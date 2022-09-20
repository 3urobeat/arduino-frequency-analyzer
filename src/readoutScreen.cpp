/*
 * File: readoutScreen.cpp
 * Project: arduino-frequency-analyzer
 * Created Date: 19.09.2022 14:53:19
 * Author: 3urobeat
 * 
 * Last Modified: 20.09.2022 18:50:00
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "main.h"


/**
 * Prints units, dividers, labels, etc. to setup readout screen
 */
void setupReadoutScreen() {
    
    /* ------ Show project name as title in the top left ------ */
    tft.setCursor(5, 15);
    tft.setFreeFont(FMBO9);
    tft.setTextColor(TFT_GOLD, TFT_BLACK, true);
    tft.print("Frequency Analyzer");


    /* ------ Show spectrum diagram volume labels ------ */
    int cursorPosY = 45; // track current y pos locally to increment it easily, start with first label at y = 45

    // set font and color once
    tft.setFreeFont(FMB9);
    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);

    // We need to print 7 numbers
    const char nums[7][4] = {"  0", "-10", "-20", "-30", "-40", "-50", "-60"};

    for (int i = 0; i <= 6; i++) {
        tft.setCursor(5, cursorPosY); // set cursor to current pos
        tft.print(nums[i]);           // print the correct number for this iteration
        cursorPosY += 17.5;           // move cursor down
    }


    /* ------ Show spectrum diagram frequency labels ------ */



    /* ------ Show left/right channel volume label ------ */



    /* ------ Show left/right channel volume dummy readout ------ */


}