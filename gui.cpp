#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-suspicious-enum-usage"
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
    ID_SearchDate = 120,
    ID_ActivityList = 130,
};

wxBEGIN_EVENT_TABLE(GUI, wxFrame)
                EVT_BUTTON(ID_AddActivity, GUI::OnAddActivityButton)
                EVT_TIME_CHANGED(ID_StartTime, GUI::OnSelectStartTime)
                EVT_TIME_CHANGED(ID_EndTime, GUI::OnSelectEndTime)
                EVT_DATE_CHANGED(ID_Date, GUI::OnSelectDate)
                EVT_TEXT(ID_ActivityName, GUI::OnActivityName)
                EVT_TEXT(ID_Description, GUI::OnAddDescription)
                EVT_BUTTON(ID_SearchDate, GUI::OnSearchByDate)
wxEND_EVENT_TABLE()

GUI::GUI(const wxString &title, const wxPoint &pos, const wxSize &size): wxFrame(nullptr, wxID_ANY, title, pos,wxSize(600,400), wxDEFAULT_FRAME_STYLE) {


    //disable resizing
    this->SetSizeHints( 600, 400 );
    wxSize maxSize = (wxSize(600, 400));
    this->SetMaxSize(maxSize);
    SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX));

    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer8;
    bSizer8 = new wxBoxSizer( wxHORIZONTAL );

    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer( wxHORIZONTAL );

    wxBoxSizer* bSizer5;
    bSizer5 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer( wxHORIZONTAL );

    wxBoxSizer* bSizer3;
    bSizer3 = new wxBoxSizer( wxHORIZONTAL );

    //Start time picker
    m_startTime = new wxTimePickerCtrl(this, ID_StartTime, wxDateTime::Now().GetHour(), wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT); //TODO eliminate seconds
    bSizer4->Add( m_startTime, 0, wxALIGN_CENTER, 5 );
    //End time picker
    m_endTime = new wxTimePickerCtrl(this, ID_EndTime, wxDateTime::Now().Add(wxTimeSpan::Hours(1)).GetHour(), wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT); //TODO eliminate seconds
    bSizer4->Add( m_endTime, 0, wxALIGN_CENTER, 5 );


    bSizer5->Add( bSizer4, 1, wxALIGN_CENTER|wxALL, 10 );


    //Date picker
    m_datePicker1 = new wxDatePickerCtrl( this, ID_Date, wxDateTime::Today(), wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT ); //today as default date
    bSizer3->Add( m_datePicker1, 0, wxALIGN_CENTER|wxALL, 10 );

    //Search date button
    //wxBitmap bpm(wxT("images/search2.png"), wxBITMAP_TYPE_PNG); //FIXME: search icon
    //m_searchButton = new wxBitmapButton( this, ID_SearchDate, bpm);
    m_searchButton = new wxButton( this, ID_SearchDate, wxT("Search"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer3->Add( m_searchButton, 0, wxALIGN_CENTER|wxALL, 10 );

    bSizer5->Add( bSizer3, 1, wxALIGN_CENTER|wxALL, 10 );

    //Activity name text box
    m_ActivityName = new wxTextCtrl( this, ID_ActivityName, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_ActivityName->SetHint( wxT("Activity Name") );
    m_ActivityName->SetMinSize( wxSize( 150,25 ) );
    bSizer5->Add( m_ActivityName, 0, wxALIGN_CENTER|wxALL, 5 );

    //Description text box
    m_Description = new wxTextCtrl( this, ID_Description, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_Description->SetHint( wxT("Description") );
    m_Description->SetMinSize( wxSize( 150,70 ) );
    bSizer5->Add( m_Description, 0, wxALIGN_CENTER|wxALL, 5 );

    //Add activity button
    m_button1 = new wxButton( this, ID_AddActivity, wxT("Add Activity"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer5->Add( m_button1, 0, wxALIGN_CENTER|wxALL, 5 );


    bSizer6->Add( bSizer5, 1, wxLEFT|wxRIGHT, 20 );


    bSizer8->Add( bSizer6, 1, wxALIGN_CENTER|wxALL, 5 );

    //Activities list
    m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
    m_notebook1->SetMinSize( wxSize( 250,300 ) );
    m_notebookPage1 = new wxTextCtrl( m_notebook1, ID_ActivityList, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
    m_notebookPage1->SetEditable(false);

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

    //check if all fields are filled
if(wxIsEmpty(activityName) || wxIsEmpty(formattedActivityStartTime) || wxIsEmpty(formattedActivityEndTime) || wxIsEmpty(formattedDate) || wxIsEmpty(activityDescription)){
        wxMessageBox("Please fill all fields", "Error", wxOK | wxICON_ERROR);
        return;
    }

    //check if start time is before end time
    if(activityStartTime > activityEndTime){
        wxMessageBox("Start time must be before end time", "Error", wxOK | wxICON_ERROR);
        return;
    }

    //TODO check if activity with same name already exists


    wxDateTime startDateTime = wxDateTime(m_datePicker1->GetValue().GetDay(), m_datePicker1->GetValue().GetMonth(), m_datePicker1->GetValue().GetYear(), m_startTime->GetValue().GetHour(), 0);
    wxDateTime endDateTime = wxDateTime(m_datePicker1->GetValue().GetDay(), m_datePicker1->GetValue().GetMonth(), m_datePicker1->GetValue().GetYear(), m_endTime->GetValue().GetHour(), 0);
    wxString formattedDateActivityStartTime = startDateTime.Format("%d/%m/%Y %H:%M:%S");
    wxString formattedDateActivityEndTime = endDateTime.Format("%d/%m/%Y %H:%M:%S");

    std::cout << formattedDateActivityStartTime.ToStdString() << " " << formattedDateActivityEndTime.ToStdString()<< std::endl;

    //Add activity to database calling activity class constructor
    Activity activity(activityName.ToStdString(),formattedDateActivityStartTime.ToStdString(), formattedDateActivityEndTime.ToStdString(), activityDescription.ToStdString());
    activityLog.addActivity(activity); //FIXME


    wxLogStatus("Activity " + activityName + " added at " + formattedActivityStartTime + " to " + formattedActivityEndTime + " on " + formattedDate);
    m_notebookPage1->AppendText(activity.getName() + " - " + activity.getStartTimeString() + " - " + activity.getEndTimeString() + " on " + activity.getDateString() + "\n");



}

void GUI::OnSearchByDate(wxCommandEvent &event) {
    wxString searchDate = m_datePicker1->GetValue().Format("%d/%m/%Y");
    std::vector<Activity> activitiesOnDate = activityLog.searchByDate(searchDate.ToStdString());
    m_notebookPage1->Clear();
    for (const Activity& activity : activitiesOnDate) {
        wxString listItem = activity.getName() + wxT(" - ") + activity.getStartTimeString() + wxT(" to ") + activity.getEndTimeString() + wxT("\n");
        std::cout << listItem.ToStdString() << std::endl;
        m_notebookPage1->AppendText(listItem);
    }
}

bool App::OnInit() {
    GUI *frame = new GUI("Activity Tracker", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}


#pragma clang diagnostic pop