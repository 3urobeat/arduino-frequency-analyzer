/*
 * File: readoutScreen.cpp
 * Project: arduino-frequency-analyzer
 * Created Date: 19.09.2022 14:53:19
 * Author: 3urobeat
 * 
 * Last Modified: 22.09.2022 15:10:02
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
    int cursorPosX = 36; // track current x pos locally to increment it easily, start with first label at x = 36

    // set font and color once
    tft.setTextFont(2);
    tft.setTextColor(TFT_LIGHTGREY, TFT_BLACK, true);

    // We need to print 15 numbers
    const char freqs[15][4] = {" 25", " 40", " 63", "100", "157", "250", "400", "630", " 1k", "1k6", "2k5", " 4k", "6k3", "10k", "16k"};

    for (int i = 0; i <= 14; i++) {
        
        // Because of limited space, we need to print at alternating height
        if (i % 2 == 0) {
            tft.drawFastVLine(cursorPosX + 11, 156, 12, TFT_LIGHTGREY); // Draw (long) line pointing label to corresponding bar. Move to the label middle, start at y = 156 and draw down 12 pixels
            tft.setCursor(cursorPosX, 170); // Set height for the label
        } else {
            tft.drawFastVLine(cursorPosX + 12, 154, 1, TFT_LIGHTGREY); // Draw (short) line pointing label to corresponding bar
            tft.setCursor(cursorPosX, 155); // Set height for the label
        }

        tft.print(freqs[i]); // print the correct number for this iteration
        cursorPosX += 18;    // move cursor right
    }


    /* ------ Show left/right channel volume label ------ */
    tft.setFreeFont(FMB9);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setCursor(10, 205);
    tft.print("L");
    tft.setCursor(10, 225);
    tft.print("R");
    

    /* ------ Show left/right channel volume dummy readout ------ */
    tft.drawString(" 00.0", 291, 198);
    tft.drawString(" 00.0", 291, 218);

}