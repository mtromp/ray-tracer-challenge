#include "Character.h"
#include <gtest/gtest.h>

TEST(characterTest, characterNameCanBeSetAndRetrieved)
{
    Character character;
    character.Name("holodigm");

    EXPECT_EQ("holodigm", character.GetName());
}

TEST(characterTest, characterAlignmentIsNeutralWhenConstructed)
{
    Character character;

    EXPECT_EQ("Neutral", character.GetAlignment());
}

TEST(characterTest, characterAlignmentCanBeSetAndRetrieved)
{
    Character character;
    character.Alignment(Character::Evil);

    EXPECT_EQ("Evil", character.GetAlignment());
}

// Make this a parameterized test that goes through all values of
//   Character::AlignmentValues
TEST(characterTest, characterAlignmentCanOnlyBeGoodEvilOrNeutral)
{
    Character character;
    character.Alignment(Character::Good);

    std::string actualAlignment = character.GetAlignment();

    if (actualAlignment == "Good")
    {
        EXPECT_EQ("Good", actualAlignment);
    } else if (actualAlignment == "Evil") {
        EXPECT_EQ("Evil", actualAlignment);
    } else if (actualAlignment == "Neutral") {
        EXPECT_EQ("Neutral", actualAlignment);
    } else {
        EXPECT_EQ("Neutral", actualAlignment);
    }
}
