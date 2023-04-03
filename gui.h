//
// Created by Lautaro Cavichia on 03/04/23.
//

#ifndef ACTIVITYTRACKER_GUI_H
#define ACTIVITYTRACKER_GUI_H

#include <curses.h>
#include <string>
using namespace std;

class Menu{
public:
    Menu(string &title, char trigger, int optionsSize);
    void nextOption();
    void prevOption();
    void draw(WINDOW *win);
protected:
    string title;
    char trigger;
    int optionsSize;
    int selectedOption;
    int startX = 2;
};


#endif //ACTIVITYTRACKER_GUI_H
