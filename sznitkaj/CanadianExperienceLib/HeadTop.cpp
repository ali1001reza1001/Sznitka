/**
 * @file HeadTop.cpp
 * @author julia
 */

#include "pch.h"
#include "HeadTop.h"

/**
 * Constructor
 * @param name The drawable name
 * @param filename The filename for the image
 */
HeadTop::HeadTop(const std::wstring &name, const std::wstring &filename) :
        ImageDrawable(name, filename)
{
 mHead = std::make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
 mEyeX =
 mMovable = true;
}

/**
 * Checks if head is movable
 * @return True if head can be moved
 */
bool HeadTop::IsMovable()
{
 return mMovable;
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* @param  p Point to transform
* @returns Transformed point
*/
wxPoint HeadTop::TransformPoint(wxPoint p)
{
 // Make p relative to the image center
 p = p - GetCenter();

 // Rotate as needed and offset
 return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/**
 * Draws the head and its features
 * @param graphics the graphics context we use to draw head
 */
void HeadTop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
 ImageDrawable::Draw(graphics);
 auto eyePos = GetEyePos();
 auto browPos = GetBrowPos();
 DrawBrow(graphics, browPos);
 DrawEyes(graphics, eyePos);

 eyePos.x = eyePos.x + 30;
 browPos.x = browPos.x + 35;

 DrawBrow(graphics, browPos);
 DrawEyes(graphics, eyePos);
}

/**
 * Draw the eyebrow for the head
 * @param graphics The graphics context we used
 * @param point The position of the eyebrow
 */
void HeadTop::DrawBrow(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point)
{
 auto p1 = TransformPoint(point);
 auto p2 = TransformPoint(point+wxPoint(15,0));

 wxPen eyebrowPen(*wxBLACK, 2);
 graphics->SetPen(eyebrowPen);
 graphics->StrokeLine(p1.x, p1.y, p2.x, p2.y);
}

/**
 * Draw the eyes for the head
 * @param graphics The graphics context we used
 * @param point The position of the eye
 */
void HeadTop::DrawEyes(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point)
{
 auto e1 = TransformPoint(point);

 graphics->SetBrush(*wxBLACK);

 float wid = 15.0f;
 float hit = 20.0f;

 graphics->PushState();
 graphics->Translate(e1.x, e1.y);
 graphics->Rotate(-mPlacedR);
 graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
 graphics->PopState();
}