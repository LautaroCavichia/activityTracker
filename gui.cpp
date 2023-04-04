//
// Created by Lautaro Cavichia on 03/04/23.
//

#include "gui.h"
#include <wx/frame.h>
#include <string>

Menu::Menu(const string &title, char trigger, int optionsSize): title(title), trigger(trigger), optionsSize(optionsSize){
    selectedOption = 0; // Default selected option
}

void Menu::nextOption() {
    selectedOption = (selectedOption + 1) % optionsSize;
}

void Menu::prevOption() {
    selectedOption = (selectedOption - 1) % optionsSize;
}

SubMenu::SubMenu(const string &title, char trigger, int optionsSize, Menu *parentMenu): Menu(title, trigger, optionsSize), parentMenu(parentMenu) {

}
