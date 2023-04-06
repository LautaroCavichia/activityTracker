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




using namespace std;

class GUI : public wxFrame{ // Inherit from wxFrame to create a frame
public:
    GUI(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    wxPanel *panel; // A panel is a container for widgets
    void OnExit(wxCommandEvent &event);
    void test(wxCommandEvent &event);
    void OnSelectStartTime(wxDateEvent &event);
    void OnSelectEndTime(wxDateEvent &event);
    void OnSelectDate(wxDateEvent &event);
    void OnActivityName(wxCommandEvent &event);
    void OnAddDescription(wxCommandEvent &event);
    void OnAddActivityButton(wxCommandEvent &event);

    wxString activityName;
    wxString activityDescription;
    wxDateTime activityDate;
    wxDateTime activityStartTime;
    wxDateTime activityEndTime;
    wxString formattedActivityStartTime = wxDateTime::Now().Format(wxT("%H:00")); //Now as default value
    wxString formattedActivityEndTime = wxDateTime::Now().Add(wxTimeSpan::Hours(1)).Format(wxT("%H:00")); //Now + one hour as default value
    wxString formattedDate = wxDateTime::Now().Format("%d/%m/%Y"); //Now as default value

protected:
    wxStaticText* m_staticText1;
   // wxSpinCtrl* m_spinCtrl1;
  //  wxSpinCtrl* m_spinCtrl2;
    wxTimePickerCtrl *m_startTime;
    wxTimePickerCtrl *m_endTime;
    wxDatePickerCtrl* m_datePicker1;
    wxTextCtrl* m_textCtrl1;
    wxButton* m_button1;
    wxNotebook* m_notebook1;
    wxTextCtrl* m_notebookPage1;
    wxScrolledWindow* m_scrolledWindow1;
    wxToolBar* m_toolBar2;
    wxToolBarToolBase* m_tool1;
    wxToolBarToolBase* m_tool2;

    DECLARE_EVENT_TABLE()
};

class App : public wxApp{  // Inherit from wxApp to create an application
public:
    virtual bool OnInit();
};




#endif //ACTIVITYTRACKER_GUI_H
