#pragma once

#include <TFT_eSPI.h>

// TFT_UI object
class TFT_UI {
public:
    inline TFT_UI(TFT_eSPI* pTFT);

private:
    TFT_eSPI* tft;
}