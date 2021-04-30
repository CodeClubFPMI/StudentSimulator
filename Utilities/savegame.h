#ifndef SAVEGAME_H
#define SAVEGAME_H

#include "Game/student.h"

#include <QString>


class SaveGame
{
public:
    SaveGame() = default;
    ~SaveGame() = default;
    bool save_game_to_JSON(Student * player, QString file_name = "load_game_config.json");
};

#endif // SAVEGAME_H
