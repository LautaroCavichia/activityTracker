//
// Created by Lautaro Cavichia on 03/04/23.
//
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "gui.h"

enum IDs {
    ID_AddActivity = 100,
    ID_Hours = 101,
    ID_Minutes = 102,
    ID_Date = 103,
    ID_ActivityName = 110,
    ID_Description = 111,
    ID_Search = 120,
    ID_SearchDate = 121,
    ID_ActivityList = 130,
};

wxBEGIN_EVENT_TABLE(GUI, wxFrame)
                EVT_BUTTON(ID_AddActivity, GUI::OnAddActivityButton)
                EVT_SPINCTRL(ID_Hours, GUI::OnSelectHour)
                EVT_SPINCTRL(ID_Minutes, GUI::OnSelectMinute)
                EVT_DATE_CHANGED(ID_Date, GUI::OnSelectDate)
                EVT_TEXT(ID_ActivityName, GUI::OnActivityName)
                EVT_TEXT(ID_Description, GUI::OnAddDescription)
wxEND_EVENT_TABLE()

GUI::GUI(const wxString &title, const wxPoint &pos, const wxSize &size): wxFrame(nullptr, wxID_ANY, title, pos, size) {  //TODO center the widgets

    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer( wxVERTICAL );

    m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Activity Tracker"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText1->Wrap( -1 );
    bSizer1->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );

    wxBoxSizer* bSizer8;
    bSizer8 = new wxBoxSizer( wxHORIZONTAL );

    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer( wxHORIZONTAL );

    wxBoxSizer* bSizer5;
    bSizer5 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer( wxHORIZONTAL );

    m_spinCtrl1 = new wxSpinCtrl( this, ID_Hours, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 24, 8 );
    bSizer4->Add( m_spinCtrl1, 0, wxALIGN_CENTER, 5 );

    m_spinCtrl2 = new wxSpinCtrl( this, ID_Minutes, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 59, 0 );
    bSizer4->Add( m_spinCtrl2, 0, wxALIGN_CENTER, 5 );


    bSizer5->Add( bSizer4, 1, wxALIGN_CENTER|wxALL, 10 );

    m_datePicker1 = new wxDatePickerCtrl( this, ID_Date, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
    bSizer5->Add( m_datePicker1, 0, wxALIGN_CENTER|wxALL, 10 );

    m_textCtrl1 = new wxTextCtrl( this, ID_ActivityName, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_textCtrl1->SetMinSize( wxSize( 150,25 ) );

    bSizer5->Add( m_textCtrl1, 0, wxALIGN_CENTER|wxALL, 10 );

    m_button1 = new wxButton( this, ID_AddActivity, wxT("Add Activity"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer5->Add( m_button1, 0, wxALIGN_CENTER|wxALL, 5 );


    bSizer6->Add( bSizer5, 1, wxLEFT|wxRIGHT, 20 );


    bSizer8->Add( bSizer6, 1, wxALIGN_CENTER|wxALL, 5 );

    m_simplebook1 = new wxSimplebook( this, ID_ActivityList, wxDefaultPosition, wxDefaultSize, 0 );
    m_simplebook1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );
    m_simplebook1->SetMinSize( wxSize( 200,200 ) );

    m_scrolledWindow1 = new wxScrolledWindow( m_simplebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    m_scrolledWindow1->SetScrollRate( 5, 5 );
    m_simplebook1->AddPage( m_scrolledWindow1, wxT("a page"), false );

    bSizer8->Add( m_simplebook1, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


    bSizer1->Add( bSizer8, 1, wxALIGN_CENTER, 5 );

    wxBoxSizer* bSizer7;
    bSizer7 = new wxBoxSizer( wxVERTICAL );


    bSizer1->Add( bSizer7, 1, wxALIGN_CENTER, 5 );


    this->SetSizer( bSizer1 );
    this->Layout();

    this->Centre( wxBOTH );

    CreateStatusBar();

}

void GUI::OnExit(wxCommandEvent &event) {
    Close(true);
}

void GUI::test(wxCommandEvent &event) {
    wxMessageBox("Hello World", "Test", wxOK | wxICON_INFORMATION);
}

void GUI::OnSelectHour(wxSpinEvent &event) {
    wxString hour = wxString::Format(wxT("%d"), event.GetPosition());
    wxLogStatus(hour);
}

void GUI::OnSelectMinute(wxSpinEvent &event) {
    wxString minute = wxString::Format(wxT("%d"), event.GetPosition());
    wxLogStatus(minute);
}

void GUI::OnSelectDate(wxDateEvent &event) {
    wxDateTime date = event.GetDate();
    wxLogStatus(date.Format("%d/%m/%Y"));
}

void GUI::OnActivityName(wxCommandEvent &event) {
    wxString name = event.GetString();
    wxLogStatus(name);
}

void GUI::OnAddDescription(wxCommandEvent &event) {
    wxString description = event.GetString();
    wxLogStatus(description);
}

void GUI::OnAddActivityButton(wxCommandEvent &event) {

    wxLogStatus("Activity added");

}



bool App::OnInit() {
    GUI *frame = new GUI("Activity Tracker", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}

