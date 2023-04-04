//
// Created by Lautaro Cavichia on 03/04/23.
//
#include <wx/wx.h>
#include "gui.h"

GUI::GUI(const wxString &title, const wxPoint &pos, const wxSize &size): wxFrame(nullptr, wxID_ANY, title, pos, size) {  //TODO center the widgets

    panel = new wxPanel(this, wxID_ANY); // Create a panel to hold the widgets

    wxStaticText *label = new wxStaticText(panel, wxID_ANY, "Activity Tracker", wxPoint(10, 10), wxSize(100, 20));
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(label, 0,wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

    wxMenu *menuFile = new wxMenu; // Create a menu
    menuFile->Append(1,"&Test Ctrl -H", "Test");
    menuFile->AppendSeparator(); // Add a separator
    menuFile->Append(wxID_EXIT);

    CreateStatusBar(); // Create a status bar
    SetStatusText("Welcome to Activity Tracker!"); // Set the status bar text

    wxButton *button = new wxButton(panel, 1, "Test", wxPoint(10, 50), wxSize(100, 20)); // Create a button
    button->Bind(wxEVT_BUTTON, &GUI::test, this); // Bind the button to the test function
    sizer->Add(button, 0, wxALIGN_CENTER_HORIZONTAL| wxALL, 5);

    wxTextCtrl *text = new wxTextCtrl(panel, wxID_ANY, "bla bla bla", wxPoint(10, 80), wxSize(100, 20)); // Create a text box
    wxPoint(10, 80), wxSize(100, 20);
    sizer->Add(text, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

    wxBoxSizer *hSizer = new wxBoxSizer(wxHORIZONTAL); // Create a horizontal box sizer
    hSizer->Add(sizer,1, wxEXPAND);
    panel->SetSizer(hSizer); // Set the sizer to the panel

}

void GUI::OnExit(wxCommandEvent &event) {
    Close(true);
}

void GUI::test(wxCommandEvent &event) {
    wxMessageBox("Hello World", "Test", wxOK | wxICON_INFORMATION);
}

bool App::OnInit() {
    GUI *frame = new GUI("Activity Tracker", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}