#include <iostream>
#include "gui.h"

using namespace std;

int main() {
    initscr(); // Initialize the screen
    noecho();
    curs_set(0);

    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX); // Get the max size of the screen

    WINDOW *Win = newwin(maxY/2, maxX/2, maxY/4, maxX/4); // Create a new window
    box(Win, 0, 0); // Draw a box around the window

    Menu menu((string &) "File", 'f', 3); // Create a new menu item
    menu.draw(Win); // Draw the menu item
    wgetch(Win); // Wait for a key press
}
