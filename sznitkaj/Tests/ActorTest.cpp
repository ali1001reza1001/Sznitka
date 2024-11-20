/**
 * @file ActorTest.cpp
 * @author julia
 */


#include <pch.h>
#include <gtest/gtest.h>
#include <Actor.h>

using namespace std;

TEST(ActorTest, Constructor)
{
    Actor actor(L"Harold");
    ASSERT_EQ(std::wstring(L"Harold"), actor.GetName());

    Actor actor2(L"Second");
    ASSERT_EQ(std::wstring(L"Second"), actor2.GetName());
}

TEST(ActorTest, CheckEnabled)
{
    Actor actor(L"Harold");

    // Test default for enabled
    ASSERT_TRUE(actor.IsEnabled());

    // Test setter for enabled
    actor.SetEnabled(false);

    // Test getter for enabled
    ASSERT_FALSE(actor.IsEnabled());
}

TEST(ActorTest, CheckClickable)
{
    Actor actor(L"Harold");

    // Test default for clickable
    ASSERT_TRUE(actor.IsClickable());

    // Test setter for clickable
    actor.SetClickable(false);

    // Test getter for clickable
    ASSERT_FALSE(actor.IsClickable());
}

TEST(ActorTest, CheckPosition)
{
    Actor actor(L"Harold");

    // Test default for position
    ASSERT_EQ(actor.GetPosition(), wxPoint(0,0));

    // Test setter for position
    actor.SetPosition(wxPoint(100,100));

    // Test getter for position
    ASSERT_EQ(actor.GetPosition(), wxPoint(100,100));
}