/**
 * @file PictureObserverTest.cpp
 * @author julia
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <PictureObserver.h>

#include <Picture.h>

class PictureObserverMock : public PictureObserver
{
public:
 PictureObserverMock() : PictureObserver() {}
 bool mUpdated = false;
 void UpdateObserver() override { mUpdated = true; }

};

TEST(PictureObserverTest, Construct) {
 PictureObserverMock observer;
}

TEST(PictureObserverTest, OneObserver) {
 // Allocate a Picture object
 auto picture = std::make_shared<Picture>();

 // Create a mock observer object
 PictureObserverMock observer;

 // And set it for the observer:
 observer.SetPicture(picture);

 picture->UpdateObservers();

 ASSERT_TRUE(observer.mUpdated);
}

TEST(PictureObserverTest, GetPicture)
{
 auto picture = std::make_shared<Picture>();

 PictureObserverMock observer;

 picture->UpdateObservers();

 // Test if false when empty
 ASSERT_FALSE(observer.mUpdated);

 // Test if observer and picture do not match as not set yet
 ASSERT_NE(observer.GetPicture(), picture);

 observer.SetPicture(picture);

 picture->UpdateObservers();

 // Check if observer has a picture
 ASSERT_TRUE(observer.mUpdated);

 // Check if observer matches the orginial picture
 ASSERT_EQ(observer.GetPicture(), picture);

 auto picture2 = std::shared_ptr<Picture>();

 // Test if observer is not set to new picture
 ASSERT_NE(observer.GetPicture(), picture2);

}

TEST(PictureObserverTest, TwoObservers)
{
 auto picture = std::make_shared<Picture>();
 PictureObserverMock observer;

 observer.SetPicture(picture);
 picture->UpdateObservers();

 // Test if one observer
 ASSERT_TRUE(observer.mUpdated);

 PictureObserverMock observer2;
 observer2.SetPicture(picture);
 picture->UpdateObservers();

 // Test if second observer good
 ASSERT_TRUE(observer2.mUpdated);

 auto picture2 = std::make_shared<Picture>();
 PictureObserverMock observer3;
 observer3.SetPicture(picture2);
 picture2->UpdateObservers();

 // Test if third observer is good
 ASSERT_TRUE(observer3.mUpdated);

 // Test if previous observers still true
 ASSERT_TRUE(observer.mUpdated);
 ASSERT_TRUE(observer2.mUpdated);

}

TEST(PictureObserverTest, ObserverDestroyed)
{
 auto picture = std::make_shared<Picture>();
 PictureObserverMock observer;
 observer.SetPicture(picture);

 {
  PictureObserverMock observer2;

  // And set it for the observer2;
  observer2.SetPicture(picture);
 }
 picture->UpdateObservers();

 // Test if original observer still good
 ASSERT_TRUE(observer.mUpdated);
}
