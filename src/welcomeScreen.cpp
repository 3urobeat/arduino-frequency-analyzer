/*
 * File: welcomeScreen.cpp
 * Project: arduino-frequency-analyzer
 * Created Date: 2022-09-19 14:28:53
 * Author: 3urobeat
 *
 * Last Modified: 2024-02-09 22:06:52
 * Modified By: 3urobeat
 *
 * Copyright (c) 2022 - 2024 3urobeat <https://github.com/3urobeat>
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "main.h"


/**
 * Shows the welcome screen and clears it after a few seconds
 * Printing centered: https://github.com/Bodmer/TFT_eSPI/discussions/1978#discussioncomment-3457333
 *
 * @param clearDelay Amount of ms to wait before clearing welcome screen again
 */
void showWelcomeScreen(unsigned int clearDelay) {

    // Print project name somewhere mid-ish
    tft.setTextColor(TFT_GOLD, TFT_BLACK, true);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("arduino-frequency-analyzer", tft.width() / 2, 100);

    // Print version number below, leave some space between
    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
    tft.setTextDatum(MC_DATUM);
    tft.drawString(version, tft.width() / 2, 120);

    // Clear welcome screen again after a few seconds, device will enter loop shortly
    delay(clearDelay);

    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);

}
