//
// Created by Lautaro Cavichia on 03/04/23.
//

#include "gui.h"
#include <curses.h>
#include <string>

Menu::Menu(string &title, char trigger, int optionsSize): title(title), trigger(trigger), optionsSize(optionsSize){
    selectedOption = 0; // Default selected option
}

void Menu::nextOption() {
    selectedOption = (selectedOption + 1) % optionsSize;
}

void Menu::prevOption() {
    selectedOption = (selectedOption - 1) % optionsSize;
}

void Menu::draw(WINDOW *win) {
    mvwprintw(win, 0, startX, title.c_str());

}
