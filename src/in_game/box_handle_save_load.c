/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static unsigned int create_ingame_box
(scene_ingame_t *ingame, int i, int size_x, int size_y)
{
    ingame->text_box[i].box = sfRectangleShape_create();
    if (ingame->text_box[i].box == NULL)
        return 84;
    sfRectangleShape_setSize
    (ingame->text_box[i].box, (sfVector2f){size_x, size_y});
    sfRectangleShape_setFillColor(ingame->text_box[i].box, sfBlue);
    sfRectangleShape_setPosition
    (ingame->text_box[i].box, ingame->text_box[i].pos_box);
    sfRectangleShape_setOutlineColor(ingame->text_box[i].box, sfBlack);
    sfRectangleShape_setOutlineThickness
    (ingame->text_box[i].box, BOX_THICKNESS);
    return 0;
}

static unsigned int size_of_text_box(scene_ingame_t *ingame, int i)
{
    int size_x;
    int size_y;

    if (i == 0) {
        size_x = BOX_LOAD_GAME_SIZE_X;
        size_y = BOX_LOAD_GAME_SIZE_Y;
    } else {
        size_x = BOX_SAVE_GAME_SIZE_X;
        size_y = BOX_SAVE_GAME_SIZE_Y;
    }
    create_ingame_box(ingame, i, size_x, size_y);
    return 0;
}

static unsigned int font_of_box(scene_ingame_t *ingame, int i)
{
    ingame->text_box[i].font_box =
        sfFont_createFromFile("asset/menu/jersey.ttf");
    if (ingame->text_box[i].font_box == NULL)
        return 84;
    return 0;
}

static void manage_sf_cond(scene_ingame_t *ingame, int i)
{
    sfText_setFont(ingame->text_box[i].text, ingame->text_box[i].font_box);
    sfText_setCharacterSize(ingame->text_box[i].text, 50);
    sfText_setFillColor(ingame->text_box[i].text, sfBlack);
    sfText_setPosition(ingame->text_box[i].text, ingame->text_box[i].pos_text);
    ingame->text_box[i].lenght_std_user = 0;
    ingame->text_box[i].std_user[0] = '\0';
}

static unsigned int text_of_box(scene_ingame_t *ingame, int i)
{
    int text_x = 0;
    int text_y = 0;

    if (i == 0) {
        text_x = BOX_TEXT1_GAME_SIZE_X;
        text_y = BOX_TEXT1_GAME_SIZE_Y;
    } else {
        text_x = BOX_TEXT2_GAME_SIZE_X;
        text_y = BOX_TEXT2_GAME_SIZE_Y;
    }
    ingame->text_box[i].pos_text.x = text_x;
    ingame->text_box[i].pos_text.y = text_y;
    ingame->text_box[i].text = sfText_create();
    if (ingame->text_box[i].text == NULL)
        return 84;
    manage_sf_cond(ingame, i);
    return 0;
}

unsigned int handle_box_ingame(scene_ingame_t *ingame)
{
    ingame->text_box[0].pos_box = (sfVector2f)
    {BOX_LOAD_GAME_POS_X, BOX_LOAD_GAME_POS_Y};
    ingame->text_box[1].pos_box = (sfVector2f)
    {BOX_SAVE_GAME_POS_X, BOX_SAVE_GAME_POS_Y};
    for (int i = 0; i != NB_TEXT_BOX; i++) {
        if (size_of_text_box(ingame, i) == 84)
            return 84;
        if (font_of_box(ingame, i) == 84)
            return 84;
        if (text_of_box(ingame, i) == 84)
            return 84;
    }
    return 0;
}
