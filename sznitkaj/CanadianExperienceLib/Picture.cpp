/**
 * @file Picture.cpp
 * @author julia
 */

#include "pch.h"
#include "Picture.h"

#include "Actor.h"
#include "PictureObserver.h"

/**
 * Add an observer to this picture.
 * @param observer The observer to add
 */
void Picture::AddObserver(PictureObserver* observer)
{
 mObservers.push_back(observer);
}

/**
 * Remove an observer from this picture
 * @param observer The observer to remove
 */
void Picture::RemoveObserver(PictureObserver* observer)
{
 auto loc = find(std::begin(mObservers), std::end(mObservers), observer);
 if (loc != std::end(mObservers))
 {
  mObservers.erase(loc);
 }
}

/**
 * Update all observers to indicate the picture has changed.
 */
void Picture::UpdateObservers()
{
 for (auto observer : mObservers)
 {
  observer->UpdateObserver();
 }
}

/**
 * Draw this picture on a device context
 * @param graphics The device context to draw on
 */
void Picture::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
 for (auto actor : mActors)
 {
  actor->Draw(graphics);
 }
}

/**
* Add a drawable to this actor
* @param actor The drawable to add
*/
void Picture::AddActor(std::shared_ptr<Actor> actor)
{
 mActors.push_back(actor);
 actor->SetPicture(this);
}