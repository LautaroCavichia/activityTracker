#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-suspicious-enum-usage"
//
// Created by Lautaro Cavichia on 03/04/23.
//
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "gui.h"
#include "TimeUtilities.h"

enum IDs {
    ID_AddActivity = 100,
    ID_StartTime = 101,
    ID_EndTime = 102,
    ID_Date = 103,
    ID_ActivityName = 110,
    ID_Description = 111,
    ID_SearchDate = 120,
    ID_ActivityList = 130,
    ID_ActivityDelete = 140,
    ID_ActivityEdit = 141,
    ID_AboutMe = 150,
    ID_Export = 160
};

wxBEGIN_EVENT_TABLE(GUI, wxFrame)
                EVT_BUTTON(ID_AddActivity, GUI::OnAddActivityButton)
                EVT_BUTTON(ID_Export, GUI::OnExportActivitiesButton)
                EVT_TIME_CHANGED(ID_StartTime, GUI::OnSelectStartTime)
                EVT_TIME_CHANGED(ID_EndTime, GUI::OnSelectEndTime)
                EVT_DATE_CHANGED(ID_Date, GUI::OnSelectDate)
                EVT_TEXT(ID_ActivityName, GUI::OnActivityName)
                EVT_TEXT(ID_Description, GUI::OnAddDescription)
                EVT_BUTTON(ID_SearchDate, GUI::OnSearchByDate)
                EVT_LISTBOX_DCLICK(ID_ActivityList, GUI::OnActivityRightClick)
                EVT_MENU(ID_ActivityDelete, GUI::OnActivityDelete)
                EVT_MENU(ID_ActivityEdit, GUI::OnActivityEdit)
wxEND_EVENT_TABLE()

GUI::GUI(const wxString &title, const wxPoint &pos, const wxSize &size): wxFrame(nullptr, wxID_ANY, title, pos,wxSize(600,400), wxDEFAULT_FRAME_STYLE){

    //disable resizing
    SetSizeHints( 600, 400 );
    wxSize maxSize = (wxSize(600, 400));
    SetMaxSize(maxSize);
    SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX));
    SetBackgroundColour(wxColour(0, 53, 89));

    // Menubar

    wxMenuBar* m_menubar1 = new wxMenuBar( 0 );
    wxMenu* m_menu1 = new wxMenu();
    m_menu1->Append( ID_AboutMe, wxT("About me") );
    m_menubar1->Append( m_menu1, wxT("About") );
    SetMenuBar(m_menubar1);
    Bind(wxEVT_MENU, &GUI::OnAboutMe, ID_AboutMe);


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
    m_startTime->SetTime(wxDateTime::Now().GetHour(), 0, 0); //setting default time
    bSizer4->Add( m_startTime, 0, wxALIGN_CENTER, 5 );
    m_startTime->SetBackgroundColour(wxColour(0, 53, 89));
    //End time picker
    m_endTime = new wxTimePickerCtrl(this, ID_EndTime, wxDateTime::Now().Add(wxTimeSpan::Hours(1)).GetHour(), wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT); //TODO eliminate seconds
    m_endTime->SetTime(wxDateTime::Now().Add(wxTimeSpan::Hours(1)).GetHour(),0,0); //setting default time
    bSizer4->Add( m_endTime, 0, wxALIGN_CENTER, 5 );
    m_endTime->SetBackgroundColour(wxColour(0, 53, 89));

    bSizer5->Add( bSizer4, 1, wxALIGN_CENTER|wxALL, 10 );

    //Date picker
    m_datePicker1 = new wxDatePickerCtrl( this, ID_Date, wxDateTime::Now(), wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
    m_datePicker1->SetValue(wxDateTime::Now()); //setting default date
    bSizer3->Add( m_datePicker1, 0, wxALIGN_CENTER|wxALL, 10 );
    m_datePicker1->SetBackgroundColour(wxColour(0, 53, 89));

    //Search date button
    m_searchButton = new wxButton( this, ID_SearchDate, wxT("Search"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer3->Add( m_searchButton, 0, wxALIGN_CENTER|wxALL, 10 );
    m_searchButton->SetBackgroundColour(wxColour(16, 25, 53));

    bSizer5->Add( bSizer3, 1, wxALIGN_CENTER|wxALL, 10 );

    //Activity name text box
    m_activityName = new wxTextCtrl( this, ID_ActivityName, wxEmptyString, wxDefaultPosition, wxDefaultSize,0);
    m_activityName->SetHint( wxT("Activity Name") );
    m_activityName->SetMinSize( wxSize( 150,25 ) );
    bSizer5->Add( m_activityName, 0, wxALIGN_CENTER|wxALL, 5 );

    //Description text box
    m_description = new wxTextCtrl( this, ID_Description, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_description->SetHint( wxT("Description") );
    m_description->SetMinSize( wxSize( 150,70 ) );
    bSizer5->Add( m_description, 0, wxALIGN_CENTER|wxALL, 5 );

    //Add activity button
    m_addActivityButton = new wxButton( this, ID_AddActivity, wxT("Add Activity"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer5->Add( m_addActivityButton, 0, wxALIGN_CENTER|wxALL, 5 );
    m_addActivityButton->SetBackgroundColour(wxColour(16, 25, 53));

    //Export button
    m_exportButton = new wxButton( this, ID_Export, wxT("Export"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer5->Add( m_exportButton, 0, wxALIGN_CENTER|wxALL, 5 );
    m_exportButton->SetBackgroundColour(wxColour(16, 25, 53));


    bSizer6->Add( bSizer5, 1, wxLEFT|wxRIGHT, 20 );


    bSizer8->Add( bSizer6, 1, wxALIGN_CENTER|wxALL, 5 );

    //Activities list
    m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
    m_notebook1->SetMinSize( wxSize( 250,300 ) );
    m_notebook1->SetWindowStyleFlag(wxCENTER); // centering the text
    m_notebookPage1 = new wxTextCtrl( m_notebook1, ID_ActivityList, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    m_notebookPage1->SetEditable(false);

    m_notebook1->AddPage( m_notebookPage1, wxT("Activities"), true );
    bSizer8->Add( m_notebook1, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    m_activityListBox = new wxListBox(m_notebookPage1, wxID_ANY, wxDefaultPosition, wxDefaultSize); // Listbox for activities, better than textctrl for this purpose
    m_activityListBox->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(GUI::OnActivityRightClick), nullptr, this);
    m_notebookPage1->SetSizer(new wxBoxSizer(wxVERTICAL));
    m_notebookPage1->GetSizer()->Add(m_activityListBox, 1, wxEXPAND);



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
if(wxIsEmpty(activityName) || wxIsEmpty(activityDescription)){
        wxMessageBox("Please fill all fields", "Error", wxOK | wxICON_ERROR);
        return;
    }

    //if values have not been changed, set them to current time
    if(!activityStartTime.IsValid()){
        activityStartTime = wxDateTime::Now();
    }
    if(!activityEndTime.IsValid()){
        activityEndTime = wxDateTime::Now();
    }
    if(!activityDate.IsValid()){
        activityDate = wxDateTime::Now();
    }

    //check if start time is before end time
    if(activityStartTime > activityEndTime){
        wxMessageBox("Start time must be before end time", "Error", wxOK | wxICON_ERROR);
        return;
    }

    if(!activityStartTime.IsValid() || !activityEndTime.IsValid() || !activityDate.IsValid()){
        wxMessageBox("Invalid date or time", "Error", wxOK | wxICON_ERROR);
        return;
    }

    wxDateTime startDateTime = wxDateTime(m_datePicker1->GetValue().GetDay(), m_datePicker1->GetValue().GetMonth(), m_datePicker1->GetValue().GetYear(), m_startTime->GetValue().GetHour(), 0);
    wxDateTime endDateTime = wxDateTime(m_datePicker1->GetValue().GetDay(), m_datePicker1->GetValue().GetMonth(), m_datePicker1->GetValue().GetYear(), m_endTime->GetValue().GetHour(), 0);
    wxString formattedDateActivityStartTime = startDateTime.Format("%d/%m/%Y %H:%M:%S");
    wxString formattedDateActivityEndTime = endDateTime.Format("%d/%m/%Y %H:%M:%S");

    std::cout << formattedDateActivityStartTime.ToStdString() << " " << formattedDateActivityEndTime.ToStdString()<< std::endl;

    //Add activity to database calling activity class constructor
    Activity activity(activityName.ToStdString(),formattedDateActivityStartTime.ToStdString(), formattedDateActivityEndTime.ToStdString(), activityDescription.ToStdString());

    activityLog.addActivity(activity);
    m_activityName->Clear();
    m_description->Clear();
    m_activityName->SetFocus();

    wxLogStatus("Activity " + activityName + " added from " + formattedActivityStartTime + " to " + formattedActivityEndTime + " on " + formattedDate);
    m_activityListBox->Append(activity.getName() + " - " + TimeUtilities::timePointToString(activity.getStartTime())+ " to " + TimeUtilities::timePointToString(activity.getEndTime()) + "\n"); //listbox version


}

void GUI::OnExportActivitiesButton(wxCommandEvent &event) {
    std::string fileName = "activities.txt";
    activityLog.exportActivities(fileName);
}

void GUI::OnSearchByDate(wxCommandEvent &event) {
    wxString searchDate = m_datePicker1->GetValue().Format("%d/%m/%Y");
    auto activitiesOnDate = activityLog.searchByDate(searchDate.ToStdString());
    m_activityListBox->Clear(); //listbox version
    for (const Activity& activity : activitiesOnDate) {
        wxString listItem = activity.getName() + wxT(" - ") + TimeUtilities::timePointToString(activity.getStartTime()) + wxT(" to ") + TimeUtilities::timePointToString(activity.getEndTime()) + wxT("\n");
        std::cout << listItem.ToStdString() << std::endl;
        m_activityListBox->Append(listItem); //listbox version

    }
}

void GUI::OnActivityRightClick(wxCommandEvent &event) {
    wxMenu menu;
    menu.Append(ID_Description,wxT("See Description"));
    menu.Append(ID_ActivityDelete, wxT("Delete"));
    menu.Append(ID_ActivityEdit, wxT("Edit"));
    Bind(wxEVT_COMMAND_MENU_SELECTED, &GUI::OnSeeDescription, this, ID_Description);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &GUI::OnActivityDelete, this, ID_ActivityDelete);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &GUI::OnActivityEdit, this, ID_ActivityEdit);
    PopupMenu(&menu);
}


void GUI::OnActivityDelete(wxCommandEvent &event) {
    int selection = m_activityListBox->GetSelection();
        m_activityListBox->Delete(selection);
        activityLog.removeActivity(selection);
        wxLogStatus("Activity deleted successfully");
    }


void GUI::OnActivityEdit(wxCommandEvent &event) {
int selection = m_activityListBox->GetSelection();
m_addActivityButton->SetLabel("Update");
m_activityName->SetValue(activityLog.getActivity(selection).getName());
m_description->SetValue((activityLog.getActivity(selection).getDescription()));
OnActivityDelete(event);
m_addActivityButton->SetLabel("Add Activity");
wxLogStatus("Activity edited successfully");
}

void GUI::OnSeeDescription(wxCommandEvent &event) {
    int selection = m_activityListBox->GetSelection();
    wxString description = activityLog.getActivity(selection).getDescription();
    wxMessageBox(description, "Description", wxOK | wxICON_INFORMATION);
}

void GUI::OnAboutMe(wxCommandEvent &event) {
    wxMessageBox("This is a simple activity tracker application", "About", wxOK | wxICON_INFORMATION);

}

bool App::OnInit() {
    GUI *frame = new GUI("Activity Tracker", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}
