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
    wxTheApp->OnRun();
    wxTheApp->OnExit();
    wxEntryCleanup();

    return wxEntry(argc, argv);
}

