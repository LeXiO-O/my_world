/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static unsigned int size_of_matrix_box(scene_menu_t *menu)
{
    menu->box = sfRectangleShape_create();
    if (menu->box == NULL)
        return 84;
    menu->pos_box.x = POS_X_BOX;
    menu->pos_box.y = POS_Y_BOX;
    sfRectangleShape_setSize
    (menu->box, (sfVector2f){BOX_MENU_POS_X, BOX_MENU_POS_Y});
    sfRectangleShape_setFillColor(menu->box, sfBlue);
    sfRectangleShape_setPosition(menu->box, menu->pos_box);
    sfRectangleShape_setOutlineColor(menu->box, sfGreen);
    sfRectangleShape_setOutlineThickness(menu->box, (float)(BOX_MENU_OUTLINE));
    return 0;
}

static unsigned int font_of_box(scene_menu_t *menu)
{
    menu->font_box = sfFont_createFromFile("asset/menu/jersey.ttf");
    if (menu->font_box == NULL)
        return 84;
    return 0;
}

static unsigned int text_of_box(scene_menu_t *menu)
{
    menu->pos_text.x = BOX_TEXT_POS_X;
    menu->pos_text.y = BOX_TEXT_POS_Y;
    menu->text = sfText_create();
    if (menu->text == NULL)
        return 84;
    sfText_setFont(menu->text, menu->font_box);
    sfText_setCharacterSize(menu->text, 50);
    sfText_setFillColor(menu->text, sfWhite);
    sfText_setPosition(menu->text, menu->pos_text);
    menu->lenght_std_user = 0;
    menu->std_user[0] = '\0';
    return 0;
}

unsigned int handle_box_menu(scene_menu_t *menu)
{
    if (size_of_matrix_box(menu) == 84)
        return 84;
    if (font_of_box(menu) == 84)
        return 84;
    if (text_of_box(menu) == 84)
        return 84;
    return 0;
}
