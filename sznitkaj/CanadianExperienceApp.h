/**
 * @file CanadianExperienceApp.h
 * @author Charles B. Owen
 *
 * Main application class
 */

#ifndef CANADIANEXPERIENCEAPP_H
#define CANADIANEXPERIENCEAPP_H

#include <wx/xrc/xmlres.h>
#include <wx/stdpaths.h>

/**
 * Main application class
 */
class CanadianExperienceApp : public wxApp {
public:
    virtual bool OnInit();
};

#endif //CANADIANEXPERIENCEAPP_H
