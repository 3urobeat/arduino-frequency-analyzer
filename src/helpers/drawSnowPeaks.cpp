/*
 * File: drawSnowPeaks.cpp
 * Project: arduino-frequency-analyzer
 * Created Date: 22.09.2022 18:43:26
 * Author: 3urobeat
 * 
 * Last Modified: 29.09.2022 21:15:27
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "helpers.h"


int           lastSpectrumPeak[30] = {};
unsigned long lastSpectrumTime[30] = {};

/**
 * Handles drawing snow peaks for all spectrum diagram bars
 * @param num Number 0-32 which bar to draw for
 * @param xOffset The x axis offset of this bar
 * @param yOffset Top of this bar
 */
void drawSpectrumSnowPeak(int num, int xOffset, int yOffset) {

    // Draw new peak if higher (which is < since we draw from top to bottom), if last change is more than 2 sec ago or if no peak has been drawn before
    if (yOffset < lastSpectrumPeak[num] || millis() - lastSpectrumTime[num] > 2000 || lastSpectrumTime[num] == 0) {

        // Draw small bar at the top of current bar
        tft.fillRect(xOffset, yOffset, barWidth, 2, TFT_WHITE);

        // Update storage
        lastSpectrumPeak[num] = yOffset;
        lastSpectrumTime[num] = millis();

    } else {

        // Draw old saved peak
        tft.fillRect(xOffset, lastSpectrumPeak[num], barWidth, 2, TFT_WHITE);

    }

}


int           lastVolumePeak[2] = {};
unsigned long lastVolumeTime[2] = {};

/**
 * Handles drawing snow peaks for L and R channel volume bar
 * @param channel Number 0-1, 0 for left channel, 1 for right channel
 * @param value Bar length in pixel
 */
void drawVolumeSnowPeak(int channel, int value) {



}