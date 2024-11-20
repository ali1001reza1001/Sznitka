/**
 * @file ImageDrawable.h
 * @author julia
 *
 *
 */
 
#ifndef IMAGEDRAWABLE_H
#define IMAGEDRAWABLE_H
#include "Drawable.h"

/**
 * Drawing the images
 */
class ImageDrawable : public Drawable{
private:

 /// The graphics bitmap we will use
 wxGraphicsBitmap mBitmap;

 /// Center of image
 wxPoint mCenter = wxPoint(0, 0);

protected:
 /// The image we are drawing
 std::unique_ptr<wxImage> mImage;

public:
 ImageDrawable(const std::wstring &name, const std::wstring &filename);
 void Draw(std::shared_ptr<wxGraphicsContext> graphics);
 bool HitTest(wxPoint point);

 /**
  *  Set point for center
  * @param point Point center is located
  */
 void SetCenter(wxPoint point) {mCenter = point;};

 /**
  *  Get point of center for image
  * @return center of image
  */
 wxPoint GetCenter() {return mCenter;};

};



#endif //IMAGEDRAWABLE_H
