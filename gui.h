//
// Created by Lautaro Cavichia on 03/04/23.
//

#ifndef ACTIVITYTRACKER_GUI_H
#define ACTIVITYTRACKER_GUI_H

#include <wx/frame.h>
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/textctrl.h>
#include <wx/simplebook.h>
#include <string>
#include <wx/timectrl.h>
#include <wx/bmpbuttn.h>
#include <wx/artprov.h>
#include <wx/filename.h>

#include "activity.h"
#include "activity_log.h"

using namespace std;

class GUI : public wxFrame{ // Inherit from wxFrame to create a frame
public:
    GUI(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnSelectStartTime(wxDateEvent &event);
    void OnSelectEndTime(wxDateEvent &event);
    void OnSelectDate(wxDateEvent &event);
    void OnActivityName(wxCommandEvent &event);
    void OnAddDescription(wxCommandEvent &event);
    void OnAddActivityButton(wxCommandEvent &event);
    void OnSearchByDate(wxCommandEvent &event);
    void OnActivityRightClick(wxCommandEvent &event);
    void OnActivityDelete(wxCommandEvent &event);
    void OnActivityEdit(wxCommandEvent &event);
    void OnSeeDescription(wxCommandEvent &event);
    static void OnAboutMe(wxCommandEvent &event);

    wxString activityName;
    wxString activityDescription;
    wxDateTime activityDate;
    wxDateTime activityStartTime;
    wxDateTime activityEndTime;
    wxString formattedActivityStartTime = wxDateTime::Now().Format(wxT("%H:00")); //Now as default value
    wxString formattedActivityEndTime = wxDateTime::Now().Add(wxTimeSpan::Hours(1)).Format(wxT("%H:00")); //Now + one hour as default value
    wxString formattedDate = wxDateTime::Now().Format("%d/%m/%Y"); //Now as default value
    wxTimePickerCtrl *m_startTime;
    wxTimePickerCtrl *m_endTime;
    wxDatePickerCtrl* m_datePicker1;
    wxTextCtrl* m_activityName;
    wxTextCtrl* m_description;
    wxButton* m_searchButton;
    wxButton* m_addActivityButton;
    wxNotebook* m_notebook1;
    wxTextCtrl* m_notebookPage1;
    ActivityLog activityLog;
    wxListBox* m_activityListBox;

    DECLARE_EVENT_TABLE()
};

class App : public wxApp{  // Inherit from wxApp to create an application
public:
     bool OnInit() override;
};

#endif //ACTIVITYTRACKER_GUI_H
