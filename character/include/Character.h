#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
public:
    // enum with valid alignment values
    enum AlignmentValues { Good, Evil, Neutral };

    Character();
    void Name(std::string name);
    std::string GetName();
    void Alignment(AlignmentValues);
    std::string GetAlignment();

private:
    std::string CharacterName;
    AlignmentValues CharacterAlignment;
};

#endif // CHARACTER_H
