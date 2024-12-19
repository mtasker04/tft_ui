#pragma once

//#include <TFT_eSPI.h>
class TFT_eSPI;
class TFT_eSPRITE;

#define TFT_UI_DOUBLE_BUFFER

// double buffering
#ifdef TFT_UI_DOUBLE_BUFFER
  typedef TFT_eSPRITE tft_ui_buf_t;
#endif


// foreward declare classes
class TFT_UI;

// TFT_UI object
class TFT_UI {
public:
    // constructor
    // @param pTFT: pointer to TFT_eSPI object
    inline TFT_UI(TFT_eSPI* pTFT);

// drawing utility functions
public:
    // begin drawing to the back buffer
    inline void begin();
    // finish drawing and swap buffers
    inline void end();
    // get the back buffer
    inline tft_ui_buf_t* getBackBuffer();

// drawing functions
public:
    

private:
    TFT_eSPI* tft;
    tft_ui_buf_t buf[2];
};