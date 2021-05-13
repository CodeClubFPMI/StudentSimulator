#ifndef SAVEGAME_H
#define SAVEGAME_H

#include "Game/student.h"

#include <QString>


class SaveGame
{
public:
    SaveGame() = default;
    ~SaveGame() = default;
    void save_game_to_JSON(Student * player, QString file_name = "saved_game.json");
};

#endif // SAVEGAME_H
