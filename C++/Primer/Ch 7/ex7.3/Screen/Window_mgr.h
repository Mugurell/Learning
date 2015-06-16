//
// Created by Lingurar Petru-Mugurel on 24.05.2015.
//

#ifndef SCREEN_WINDOW_MGR_H
#define SCREEN_WINDOW_MGR_H

#include <vector>
#include "Screen.cc"


class Window_mgr {
public:
    // location ID for each screen on the window
    using ScreenIndex = std::vector<Screen>::size_type;

    // reset the Screen at the given position to all blanks
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen&);
private:
    // Screens this Window_mgr is tracking
    // by default, a Window_mgr has one standardized blank screen.
    // Screen(24, 80, ' ') will in-class initialize ( = / {} )
    // a Screen constructor !!!!!!
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};


#endif //SCREEN_WINDOW_MGR_H
