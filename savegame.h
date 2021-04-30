#ifndef SAVEGAME_H
#define SAVEGAME_H

#include "student.h"

class SaveGame
{
public:
    SaveGame() = default;
    ~SaveGame() = default;
    bool save_game_to_JSON(Student *);
};

#endif // SAVEGAME_H
