/**
 * @file Picture.h
 * @author julia
 *
 *The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */
 
#ifndef PICTURE_H
#define PICTURE_H

#include "PictureObserver.h"

class Actor;

/**
 * The picture we are drawing
 */
class Picture {
private:

 /// The picture size
 wxSize mSize = wxSize(1500, 800);

 /// The observers of this picture
 std::vector<PictureObserver *> mObservers;

 /// The root Actor
 std::shared_ptr<Actor> mRootActor;

 /// The actor in order
 std::vector<std::shared_ptr<Actor>> mActors;

public:
 /**
 *Constructor
 */
 Picture(){}

 /// Copy Constructor (Disabled)
 Picture(const Picture &) = delete;
 /// Assignment Operator (Disabled)
 void operator=(const Picture &) = delete;

 /**
     * Get the picture size
     * @return Picture size in pixels
     */
 wxSize GetSize() {return mSize;}

 /**
  * Set the picture size
  * @param size Picture size in pixels
  */
 void SetSize(wxSize size) {mSize = size;}

 void AddObserver(PictureObserver *observer);
 void RemoveObserver(PictureObserver *observer);
 void UpdateObservers();
 void Draw(std::shared_ptr<wxGraphicsContext> graphics);

 /**
  * Set the root actor for picture
  * @param actor Pointer to root actor
  */
 void SetActor(std::shared_ptr<Actor> actor) {mRootActor = actor;}

 void AddActor(std::shared_ptr<Actor> actor);
 /** Iterator that iterates over the city tiles */
 class Iter
 {
 public:

  /** Constructor
   * @param picture The city we are iterating over
   * @param pos Position in the collection
   */
  Iter(Picture* picture, int pos) : mPicture(picture), mPos(pos) {}

  /**
   * Compare two iterators
   * @param other The other iterator we are comparing to
   * @return  true if this position is not equal to the other position
  */
  bool operator!=(const Iter& other) const
  {
   return mPos != other.mPos;
  }

  /**
   * Get value at current position
   * @return Value at mPos in the collection
   */
  std::shared_ptr<Actor> operator *() const { return mPicture->mActors[mPos]; }

  /**
   * Increment the iterator
   * @return Reference to this iterator */
  const Iter& operator++()
  {
   mPos++;
   return *this;
  }

 private:
  Picture* mPicture;   ///< City we are iterating over
  int mPos;       ///< Position in the collection
 };

 /**
     * Get an iterator for the beginning of the collection
     * @return Iter object at position 0
     */
 Iter begin() { return Iter(this, 0); }

 /**
  * Get an iterator for the end of the collection
  * @return Iter object at position past the end
  */
 Iter end() { return Iter(this, mActors.size()); }
};



#endif //PICTURE_H
