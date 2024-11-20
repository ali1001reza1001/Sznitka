/**
 * @file PictureObserver.h
 * @author julia
 *
 *Observer base class for a picture.
 *
 * This class implements the base class functionality for
 * an observer in the observer pattern.
 */
#ifndef PICTUREOBSERVER_H
#define PICTUREOBSERVER_H

class Picture;

/**
 * Observer base class for a picture
 */
class PictureObserver {
private:

 /// Picture we are observing
 std::shared_ptr<Picture> mPicture;


protected:
 /// Constructor
 PictureObserver() {}

public:
 virtual ~PictureObserver();
 void SetPicture(std::shared_ptr<Picture> picture);

 /**
  *  Get the picture
  * @return picture
  */
 std::shared_ptr<Picture> GetPicture() const {return mPicture;}

 /// Copy Constructor (Disabled)
 PictureObserver(const PictureObserver &) = delete;
 /// Assignment Operator (Disabled)
 void operator=(const PictureObserver &) = delete;

 /// This function is called to update any observers
 virtual void UpdateObserver() = 0;
};



#endif //PICTUREOBSERVER_H
