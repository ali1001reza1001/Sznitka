/**
 * @file HeadTop.h
 * @author julia
 *
 *
 */
 
#ifndef HEADTOP_H
#define HEADTOP_H
#include "ImageDrawable.h"


/**
 * Class for moving and drawing the top part of head
 */
class HeadTop : public ImageDrawable{
private:
 /// True if head is movable
 bool mMovable;

 /// X position of eye
 double mEyeX;

 /// Y position of eye
 double mEyeY;

 /// X position of eyebrow
 double mBrowX;

 /// Y position of eyebrow
 double mBrowY;

protected:
 /// The image we are drawing
 std::unique_ptr<wxImage> mHead;

public:
 /// Constructor
 HeadTop(const std::wstring& name, const std::wstring& filename);
 bool IsMovable() override;
 wxPoint TransformPoint(wxPoint p);
 void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
 void DrawBrow(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point);
 void DrawEyes(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point);

 /**
  *  Set position of eyes for actor
  * @param point Position of eyes
  */
 void SetEyePos(wxPoint point) {mEyeX = point.x; mEyeY = point.y;}

 /**
  *  Set position of eyebrows for actor
  * @param point Position of brows
  */
 void SetBrowPos(wxPoint point) {mBrowX = point.x; mBrowY = point.y;}

 /**
  * Get position of eyes for actor
  * @return Point of eyes
  */
 wxPoint GetEyePos() {return wxPoint(mEyeX, mEyeY);};

 /**
  * Get position of eyebrows
  * @return Point of brows
  */
 wxPoint GetBrowPos() {return wxPoint(mBrowX, mBrowY);};
};



#endif //HEADTOP_H
