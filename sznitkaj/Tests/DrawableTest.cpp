/**
 * @file DrawableTest.cpp
 * @author julia
 */


#include <pch.h>
#include <gtest/gtest.h>
#include <Drawable.h>

using namespace std;

class DrawableMock : public Drawable
{
public:
 DrawableMock(const std::wstring &name) : Drawable(name) {}

 void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}
 bool HitTest(wxPoint pos) override { return false; }

};

TEST(DrawableTest, Constructor)
{
 DrawableMock drawable(L"Harold");
 ASSERT_EQ(std::wstring(L"Harold"), drawable.GetName());
}

TEST(DrawableTest, Position)
{
 DrawableMock drawable(L"Harold");

 // Test default value for position
 ASSERT_EQ(drawable.GetPosition(),wxPoint(0, 0));

 // Test setter for position
 drawable.SetPosition(wxPoint(100, 100));

 // Test getter for position
 ASSERT_EQ(drawable.GetPosition(),wxPoint(100, 100));
}

TEST(DrawableTest, Rotation)
{
 DrawableMock drawable(L"Harold");

 // Test default for rotation
 ASSERT_NEAR(0.0, drawable.GetRotation(), 0.0001);

 // Test setter for rotation
 drawable.SetRotation(1.23);

 // Test getter for rotation
 ASSERT_NEAR(1.23, drawable.GetRotation(), 0.0001);
}

TEST(DrawableTest, Association)
{
 DrawableMock body(L"Body");
 auto arm = std::make_shared<DrawableMock>(L"Arm");
 auto leg = std::make_shared<DrawableMock>(L"Leg");

 ASSERT_EQ(nullptr, arm->GetParent());
 ASSERT_EQ(nullptr, leg->GetParent());

 body.AddChild(arm);
 body.AddChild(leg);

 ASSERT_EQ(&body, arm->GetParent());
 ASSERT_EQ(&body, leg->GetParent());
}