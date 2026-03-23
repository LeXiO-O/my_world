/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static void create_cond_for_help_button(scene_ingame_t *ingame)
{
    char *bt = helper_text_button();

    sfText_setScale(ingame->buttons[6].help_button, (sfVector2f){1.5f, 1.5f});
    sfText_setPosition(ingame->buttons[6].help_button, (sfVector2f){100, 100});
    sfText_setFont
    (ingame->buttons[6].help_button, ingame->buttons[6].helper_font);
    sfText_setString(ingame->buttons[6].help_button, bt);
    sfText_setColor(ingame->buttons[6].help_button, sfBlack);
}

static void create_cond_for_help_key(scene_ingame_t *ingame)
{
    char *kt = helper_text_key();

    sfText_setScale(ingame->buttons[6].help_key, (sfVector2f){1.5f, 1.5f});
    sfText_setPosition(ingame->buttons[6].help_key, (sfVector2f){1300, 860});
    sfText_setFont(ingame->buttons[6].help_key, ingame->buttons[6].helper_font);
    sfText_setString(ingame->buttons[6].help_key, kt);
    sfText_setColor(ingame->buttons[6].help_key, sfBlack);
}

unsigned int helper_text(scene_ingame_t *ingame)
{
    ingame->buttons[6].helper_font =
        sfFont_createFromFile("asset/menu/jersey.ttf");
    if (ingame->buttons[6].helper_font == NULL){
        my_err_msg("missing files !\n");
        return 84;
    }
    ingame->buttons[6].help_button = sfText_create();
    create_cond_for_help_button(ingame);
    ingame->buttons[6].help_key = sfText_create();
    create_cond_for_help_key(ingame);
    return 0;
}
