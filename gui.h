//
// Created by Lautaro Cavichia on 03/04/23.
//

#ifndef ACTIVITYTRACKER_GUI_H
#define ACTIVITYTRACKER_GUI_H

#include <wx/frame.h>
#include <string>
using namespace std;

class Menu{
public:
    Menu(const string &title, char trigger, int optionsSize);
    void nextOption();
    void prevOption();
protected:
    string title;
    char trigger;
    int optionsSize;
    int selectedOption;
    int startX = 2;
};

class SubMenu: public Menu{
public:
    SubMenu(const string &title, char trigger, int optionsSize, Menu *parentMenu);
private:
    Menu *parentMenu;
};

#endif //ACTIVITYTRACKER_GUI_H
