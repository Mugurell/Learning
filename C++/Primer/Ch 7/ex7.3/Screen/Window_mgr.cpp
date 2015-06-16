//
// Created by Lingurar Petru-Mugurel on 24.05.2015.
//

#include "Window_mgr.h"


inline void
Window_mgr::clear(ScreenIndex i) {
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = std::string(s.height * s.width, ' ');
}

inline Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}