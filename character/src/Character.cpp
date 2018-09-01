#include "Character.h"

Character::Character()
{
    this->CharacterAlignment = Character::Neutral;
}

void Character::Name(std::string name)
{
    this->CharacterName = name;
}

std::string Character::GetName()
{
    return this->CharacterName;
}

void Character::Alignment(AlignmentValues alignment)
{
    this->CharacterAlignment = alignment;
}

std::string Character::GetAlignment()
{
    switch (this->CharacterAlignment)
    {
    case Character::Good : return "Good";
    case Character::Evil : return "Evil";
    case Character::Neutral : return "Neutral";
    }
}
