/*
 * File: drawBars.cpp
 * Project: arduino-frequency-analyzer
 * Created Date: 21.09.2022 20:12:32
 * Author: 3urobeat
 * 
 * Last Modified: 22.09.2022 14:59:51
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "helpers.h"

const int startX = 44;
const int startY = 32;
const int barWidth = 7;
const int barHeight = 120;
const int space = 2;


/**
 * Draws a bar at the right position on the spectrum diagram
 * @param num Number 0-32 which bar to draw
 * @param percentage Number 0-100 how long the bar should be
 */
void drawSpectrumBar(int num, int percentage) {

    // Calculate offset where this bar should be printed
    int xOffset = startX + (space * num) + (barWidth * num);

    // first clear the last bar by printing a 100% black bar
    tft.fillRect(xOffset, startY, barWidth, barHeight, TFT_BLACK);

    // then print the green bar
    int percToPix = percentage * 1.2;               // percentage * 1.20 since our 100% is 120 pixels
    int yOffset = startY + (barHeight - percToPix); // offset so we practically print from the bottom up

    tft.fillRect(xOffset, yOffset, barWidth, percToPix, TFT_GREEN);

}


const int vbarWidth = 225;
const int vbarHeight = 13;

/**
 * Draws L and R channel volume bars
 */
void drawVolumeBar(int channel, int percentage) {

    // Add offset if R channel (1) is selected
    int yOffset = channel * 20;

    // Print green bar
    int percToPix = percentage * 2.25; // percentage * 2.25 since our 100% is 225 pixels

    tft.fillRect(30, 194 + yOffset, percToPix, vbarHeight, TFT_GREEN);

    // Then fill remaining space with a black bar to clear any remains from a previous bar that was longer
    tft.fillRect(30 + percToPix, 194 + yOffset, vbarWidth - percToPix, vbarHeight, TFT_BLACK);

}