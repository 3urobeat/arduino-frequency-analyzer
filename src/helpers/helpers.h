/*
 * File: helpers.h
 * Project: arduino-frequency-analyzer
 * Created Date: 2022-09-19 13:45:43
 * Author: 3urobeat
 *
 * Last Modified: 2024-02-09 22:06:18
 * Modified By: 3urobeat
 *
 * Copyright (c) 2022 - 2024 3urobeat <https://github.com/3urobeat>
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "main.h"


void drawSpectrumSnowPeak(int num, int xOffset, int yOffset);
void drawVolumeSnowPeak(int channel, int xOffset, int yOffset);

void drawSpectrumBar(int num, int percentage);
void drawVolumeBar(int channel, int percentage);
void drawVolumeReadout(int channel, float value);

void testRandomReadouts();

extern const int barWidth;
extern const int vbarHeight;
