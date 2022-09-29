/*
 * File: drawBars.cpp
 * Project: arduino-frequency-analyzer
 * Created Date: 21.09.2022 20:12:32
 * Author: 3urobeat
 * 
 * Last Modified: 29.09.2022 21:14:52
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

int lastPercentages[30] = {};

/**
 * Draws a bar at the right position on the spectrum diagram
 * @param num Number 0-32 which bar to draw
 * @param percentage Number 0-100 how long the bar should be
 */
void drawSpectrumBar(int num, int percentage) {

    // Check if we can abort here when nothing changed compared to the last readout to avoid flickering
    if (lastPercentages[num] == percentage) return;

    // Calculate offset where this bar should be printed
    int xOffset = startX + (space * num) + (barWidth * num);

    // Convert percentage to pixels (percentage * 1.20 since our 100% is 120 pixels)
    int percToPix = percentage * 1.2;

    // First clear the last bar by printing a black bar but only as long as needed to avoid flickering
    tft.fillRect(xOffset, startY, barWidth, barHeight - percToPix, TFT_BLACK);

    // Calculate new offset, starting at the end of the black bar
    int yOffset = startY + (barHeight - percToPix); // offset so we practically print from the bottom up, +2 to not overwrite spectrum snow peak

    // Call snow peak handler now as we are already at the right place to print
    drawSpectrumSnowPeak(num, xOffset, yOffset); // don't run when percToPix is too small so we don't write into the labels

    // Now print the green bar
    tft.fillRect(xOffset, yOffset + 2, barWidth, percToPix, TFT_GREEN);

    // Update storage
    lastPercentages[num] = percentage;

}


const int vbarWidth = 225;
const int vbarHeight = 13;

int lastPercentageL = 0;
int lastPercentageR = 0;

/**
 * Draws L and R channel volume bars
 * @param channel Number 0-1, 0 for left channel, 1 for right channel
 * @param percentage Number 0-100 how long the bar should be
 */
void drawVolumeBar(int channel, int percentage) {

    // Check if we can abort here when nothing changed compared to the last readout to avoid flickering
    if ((channel == 0 && lastPercentageL == percentage) || (channel == 1 && lastPercentageR == percentage)) return;

    // Add offset if R channel (1) is selected
    int yOffset = channel * 20;

    // Print green bar
    int percToPix = percentage * 2.25; // percentage * 2.25 since our 100% is 225 pixels

    tft.fillRect(30, 194 + yOffset, percToPix, vbarHeight, TFT_GREEN);

    // Then fill remaining space with a black bar to clear any remains from a previous bar that was longer
    tft.fillRect(30 + percToPix, 194 + yOffset, vbarWidth - percToPix, vbarHeight, TFT_BLACK);

    // Update storage
    if (channel == 0) lastPercentageL = percentage;
        else lastPercentageR = percentage;

}


char readoutBuffer[6] = "";
char shortBuffer[4]   = "";

char lastReadoutL[6]   = "";  // stores last shown string so we can abort the next reprint if nothing changed to avoid flickering
char lastDecimalL      = '0'; // stores last shown decimal to decide if it needs to be reprinted to avoid flickering
char lastReadoutR[6]   = "";
char lastDecimalR      = '0';

/**
 * Draws L and R channel volume readout
 * @param channel Number 0-1, 0 for left channel, 1 for right channel
 * @param value Number to print
 */
void drawVolumeReadout(int channel, float value) {

    // We don't support longer numbers
    if (value < -99.9) value = -99.9;
    if (value >  99.9) value =  99.9;

    // Convert value to char array
    dtostrf(value, 5, 1, readoutBuffer); // dtostrf() already aligns the number to the right with preceding spaces which is very cool

    // Make value have a fixed length if <10 to reduce "flickering"/shifting on the display
    if (value > -10 && value < 0) {
        readoutBuffer[0] = '-'; // move minus one char to the left
        readoutBuffer[1] = '0'; // replace minus with another 0
    }

    if (value < 10 && value >= 0) {
        readoutBuffer[1] = '0'; // add another 0
    }

    // Check if we can abort here when nothing changed compared to the last readout to avoid flickering
    if (channel == 0 && strcmp(readoutBuffer, lastReadoutL) == 1) return;
    if (channel == 1 && strcmp(readoutBuffer, lastReadoutR) == 1) return;

    // Add offset if R channel (1) is selected
    int yOffset = channel * 20;

    // Draw the result with decimal or without depending if same as lastDecimal to avoid flickering
    if ((channel == 0 && readoutBuffer[4] == lastDecimalL) || (channel == 1 && readoutBuffer[4] == lastDecimalR)) { // we can use == here as we only compare one char
        strncpy(shortBuffer, readoutBuffer, 3);          // cut away dot and decimal number
        tft.drawString(shortBuffer, 280, 198 + yOffset); // I'm confused why I need a different x here but it works only like this?
    } else {
        tft.drawString(readoutBuffer, 291, 198 + yOffset);
    }

    // Update storage
    if (channel == 0) {
        strcpy(readoutBuffer, lastReadoutL);
        lastDecimalL = readoutBuffer[4];
    } else {
        strcpy(readoutBuffer, lastReadoutR);
        lastDecimalR = readoutBuffer[4];
    }
}