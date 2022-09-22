/*
 * File: testRandomReadouts.cpp
 * Project: arduino-frequency-analyzer
 * Created Date: 22.09.2022 15:38:44
 * Author: 3urobeat
 * 
 * Last Modified: 22.09.2022 15:49:40
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "helpers.h"

/**
 * Helper function that draws random readouts for testing the display related code
 */
void testRandomReadouts() {

    // Draw random readouts for all 30 frequencies
    for (int i = 0; i < 30; i++) {
        drawSpectrumBar(i, rand() % 100);
    }

    // Draw two random bars for L and R channel
    drawVolumeBar(0, rand() % 100);
    drawVolumeBar(1, rand() % 100);

    // Draw two random readouts for L and R channel
    drawVolumeReadout(0, (rand() % 60) * -1);
    drawVolumeReadout(1, (rand() % 60) * -1);

}