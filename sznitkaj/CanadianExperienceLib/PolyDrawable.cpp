/**
 * @file PolyDrawable.cpp
 * @author julia
 */

#include "pch.h"
#include "PolyDrawable.h"

/**
 * Constructor
 * @param name The drawable name
 */
PolyDrawable::PolyDrawable(const std::wstring &name) : Drawable(name)
{
}

/**
 * Draw the polydrawable
 * @param graphics Graphics we will be using to draw
 */
void PolyDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
 if(!mPoints.empty()) {
  mPath = graphics->CreatePath();
  mPath.MoveToPoint(RotatePoint(mPoints[0], mPlacedR) + mPlacedPosition);
  for (auto i = 1; i<mPoints.size(); i++)
  {
   mPath.AddLineToPoint(RotatePoint(mPoints[i], mPlacedR) + mPlacedPosition);
  }
  mPath.CloseSubpath();

  wxBrush brush(mColor);
  graphics->SetBrush(brush);
  graphics->FillPath(mPath);

 }
}

/**
 * Place to draw the polydrawable
 * @param point point to draw at
 */
void PolyDrawable::AddPoint(wxPoint point)
{
 mPoints.push_back(point);
}

