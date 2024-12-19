

void galaxyMenuItem::draw(TFT_eSPI* pTFT, int& cy, bool highlight) {
    // set text size early to ensure fontHeight works
    pTFT->setTextSize(fontSize);
    // create an x cursor
    int cx = 0;

    // identify the background sizing
    int bgWidth = TFT_HEIGHT; // height is width in landscape mode
    int bgHeight = pTFT->fontHeight() + (padding * 2);

    // draw the background
    pTFT->fillRect(cx, cy, bgWidth, bgHeight, bg);
    if (highlight) {
        pTFT->fillRoundRect(cx, cy, bgWidth, bgHeight, round, hBg);
    }

    // increment the x and y cursor
    cx += padding;
    cy += padding;

    // set text wrap and color
    pTFT->setTextWrap(false, false);
    if (highlight) {
        pTFT->setTextColor(hFg);
    }
    else {
        pTFT->setTextColor(fg);
    }

    pTFT->drawString(label, cx, cy);

    // increment the y cursor for the next item
    cy += pTFT->fontHeight() + padding + marginBottom;
}

void galaxyMenu::draw(TFT_eSPI* pTFT)
{
    int cy = 0; // create the y cursor

    // draw background
    pTFT->fillScreen(bg);

    // draw menu title
    cy += titlePadding; // increment the y cursor
    pTFT->setTextSize(titleSize);
    pTFT->setTextColor(titleFg);
    pTFT->drawString(title, titlePadding, cy); // x cursor will always be the padding
    cy += pTFT->fontHeight() + titlePadding; // increment y cursor

    // draw each menu item
    for (int i = 0; i < items.size(); i++) {
        items[i].draw(pTFT, cy, (i == selectionIndex));
    }
}
void galaxyMenu::reset() {
    items.clear();
    selectionIndex = 0;
}
void galaxyMenu::moveSelection(int amount)
{
    // calculate wrap around
    int newIndex = (selectionIndex + amount) % items.size();
    if (newIndex < 0) {
        newIndex += items.size();
    }
    selectionIndex = newIndex;
}
void galaxyMenu::select() {
    func(items[selectionIndex].fnParam);
}
void galaxyMenu::select(str arg) {
    func(arg);
}

galaxyUI::galaxyUI(TFT_eSPI* pTFT, galaxyMenu& menu)
: menu(menu) {
    tft = pTFT;
}
galaxyMenu& galaxyUI::getCurrentMenu() {
    return menu;
}
void galaxyUI::draw()
{
    // draw the current menu
    menu.draw(tft);
}
void galaxyUI::processArg(str arg) {
    menu.select(arg);
}
void galaxyUI::select() {
    menu.select();
}