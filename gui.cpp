//
// Created by Lautaro Cavichia on 03/04/23.
//
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "gui.h"

enum IDs {
    ID_AddActivity = 100,
    ID_StartTime = 101,
    ID_EndTime = 102,
    ID_Date = 103,
    ID_ActivityName = 110,
    ID_Description = 111,
    ID_Search = 120,
    ID_SearchDate = 121,
    ID_ActivityList = 130,
};

wxBEGIN_EVENT_TABLE(GUI, wxFrame)
                EVT_BUTTON(ID_AddActivity, GUI::OnAddActivityButton)
                EVT_TIME_CHANGED(ID_StartTime, GUI::OnSelectStartTime)
                EVT_TIME_CHANGED(ID_EndTime, GUI::OnSelectEndTime)
                EVT_DATE_CHANGED(ID_Date, GUI::OnSelectDate)
                EVT_TEXT(ID_ActivityName, GUI::OnActivityName)
                EVT_TEXT(ID_Description, GUI::OnAddDescription)
wxEND_EVENT_TABLE()

GUI::GUI(const wxString &title, const wxPoint &pos, const wxSize &size): wxFrame(nullptr, wxID_ANY, title, pos, size) {

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

   // m_spinCtrl1 = new wxSpinCtrl( this, ID_Hours, wxString::Format("%d", defaultHourValue), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 24, defaultHourValue ); //defaultHoursValue as a string defaultHoursValue
    m_startTime = new wxTimePickerCtrl(this, ID_StartTime, wxDateTime::Now().GetHour(), wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT); //TODO eliminate seconds
    bSizer4->Add( m_startTime, 0, wxALIGN_CENTER, 5 );

   // m_spinCtrl2 = new wxSpinCtrl( this, ID_Minutes, wxString::Format("%02d", defaultMinuteValue), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 59, defaultMinuteValue ); //defaultMinutesValue as a string defaultM
    m_endTime = new wxTimePickerCtrl(this, ID_EndTime, wxDateTime::Now().Add(wxTimeSpan::Hours(1)).GetHour(), wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT); //TODO eliminate seconds
    bSizer4->Add( m_endTime, 0, wxALIGN_CENTER, 5 );


    bSizer5->Add( bSizer4, 1, wxALIGN_CENTER|wxALL, 10 );

    m_datePicker1 = new wxDatePickerCtrl( this, ID_Date, wxDateTime::Today(), wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT ); //today as default date
    bSizer5->Add( m_datePicker1, 0, wxALIGN_CENTER|wxALL, 10 );

    m_textCtrl1 = new wxTextCtrl( this, ID_ActivityName, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_textCtrl1->SetMinSize( wxSize( 150,25 ) );

    bSizer5->Add( m_textCtrl1, 0, wxALIGN_CENTER|wxALL, 10 );

    m_button1 = new wxButton( this, ID_AddActivity, wxT("Add Activity"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer5->Add( m_button1, 0, wxALIGN_CENTER|wxALL, 5 );


    bSizer6->Add( bSizer5, 1, wxLEFT|wxRIGHT, 20 );


    bSizer8->Add( bSizer6, 1, wxALIGN_CENTER|wxALL, 5 );

    m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
    m_notebookPage1 = new wxTextCtrl( m_notebook1, ID_ActivityList, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );

    m_notebook1->AddPage( m_notebookPage1, wxT("Activities"), true );
    bSizer8->Add( m_notebook1, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


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

void GUI::OnSelectStartTime(wxDateEvent &event) {
    activityStartTime = event.GetDate();
    formattedActivityStartTime = activityStartTime.Format("%H:%M");
}

void GUI::OnSelectEndTime(wxDateEvent &event) {
    activityEndTime = event.GetDate();
    formattedActivityEndTime = activityEndTime.Format("%H:%M");
}

void GUI::OnSelectDate(wxDateEvent &event) {
    activityDate = event.GetDate();
    formattedDate = activityDate.Format("%d/%m/%Y");
}

void GUI::OnActivityName(wxCommandEvent &event) {
    activityName = event.GetString();
}

void GUI::OnAddDescription(wxCommandEvent &event) {
    activityDescription = event.GetString();
}

void GUI::OnAddActivityButton(wxCommandEvent &event) {

    wxLogStatus("Activity " + activityName + " added at " + formattedActivityStartTime + " to " + formattedActivityEndTime + " on " + formattedDate);
    m_notebookPage1->AppendText(activityName + " - " + formattedActivityStartTime + " - " + formattedActivityEndTime + " on " + formattedDate + "\n");


}



bool App::OnInit() {
    GUI *frame = new GUI("Activity Tracker", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}

