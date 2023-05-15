#include <iostream>
#include "activity.h"
#include "activity_log.h"
#include "gui.h"
#include "wx/app.h" // This is the wxWidgets app class
using namespace std;

wxIMPLEMENT_APP_NO_MAIN(App); // This is the wxWidgets macro to create the app class

int main(int argc, char *argv[]) {

    wxEntryStart(argc, argv);
    wxTheApp->CallOnInit();

    Activity activity1("Workout", "04/04/2023 09:45:00", "04/04/2023 10:00:00", "Cardio workout");
    Activity activity2("Meeting", "05/04/2023 11:00:00", "05/04/2023 12:00:00", "Team meeting");
    Activity activity3("Lunch", "05/04/2023 18:00:00", "04/04/2023 14:00:00", "Lunch break");

    ActivityLog activityLog;
    activityLog.addActivity(activity1);
    activityLog.addActivity(activity2);
    activityLog.addActivity(activity3);

    cout << "Activities on 04/04/2023:" << endl;
    vector<Activity> activitiesOnDate = activityLog.searchByDate("05/04/2023");
    for (const Activity& activity : activitiesOnDate) {
        cout << activity.getName() << " - " << activity.getDescription() <<" - " << activity.getStartTimeString() <<" - " << activity.getEndTimeString()  << " - " << activity.getDuration() << endl;
    }


    wxTheApp->OnRun();
    wxTheApp->OnExit();
    wxEntryCleanup();

    return wxEntry(argc, argv);
}

