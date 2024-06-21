/*
** EPITECH PROJECT, 2023
** load music
** File description:
** load music
*/

#include "../header.h"

int play_music(s_music *ms)
{
    ms->music_game = sfMusic_createFromFile("music/game_music.ogg");
    if (!ms->music_game) {
        return (84);
    }
    sfMusic_play(ms->music_game);
    sfMusic_setLoop(ms->music_game, sfTrue);
}
