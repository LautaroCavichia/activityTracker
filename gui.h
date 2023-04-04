//
// Created by Lautaro Cavichia on 03/04/23.
//

#ifndef ACTIVITYTRACKER_GUI_H
#define ACTIVITYTRACKER_GUI_H

#include <wx/frame.h>
#include <wx/wx.h>
#include <string>
using namespace std;

class GUI : public wxFrame{ // Inherit from wxFrame to create a frame
public:
    GUI(const wxString &title, const wxPoint &pos, const wxSize &size);


private:
    wxPanel *panel; // A panel is a container for widgets
    void OnExit(wxCommandEvent &event);
    void test(wxCommandEvent &event);
};

class App : public wxApp{  // Inherit from wxApp to create an application
public:
    virtual bool OnInit();
};

#endif //ACTIVITYTRACKER_GUI_H
