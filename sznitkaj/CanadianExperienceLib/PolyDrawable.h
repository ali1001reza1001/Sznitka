/**
 * @file PolyDrawable.h
 * @author julia
 *
 *
 */
 
#ifndef POLYDRAWABLE_H
#define POLYDRAWABLE_H
#include "Drawable.h"


/**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */
class PolyDrawable : public Drawable {
private:
 /// The polygon color
 wxColour mColor = *wxBLACK;

 /// The array of point objects
 std::vector<wxPoint> mPoints;

 /// Path for drawing
 wxGraphicsPath mPath;

public:
 /// Destructor
 virtual ~PolyDrawable() {}

 /// Default constructor (disabled)
 PolyDrawable() = delete;

 /// Copy constructor (disabled)
 PolyDrawable(const PolyDrawable &) = delete;

 /// Assignment operator
 void operator=(const PolyDrawable &) = delete;


 /**
  * Gets color of polygon
  * @return color
  */
 wxColour GetColor() { return mColor; }

 /**
  * Sets color of polygon
  * @param color
  */
 void SetColor(wxColour color) { mColor = color; }

 /// Constructor
 PolyDrawable(const std::wstring& name);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics);

 /**
  *  Check hit test
  * @param point Test point
  * @return True if point falls on hit test
  */
 bool HitTest(wxPoint point) override {return mPath.Contains(point.x, point.y);};
 void AddPoint(wxPoint point);
};



#endif //POLYDRAWABLE_H
