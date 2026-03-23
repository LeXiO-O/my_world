/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static unsigned int menu_set_sound_for_button(scene_menu_t *menu, int i)
{
    menu->buttons[i].sound_buffer =
        sfSoundBuffer_createFromFile("asset/click.wav");
    menu->buttons[i].sound = sfSound_create();
    if (menu->buttons[i].sound_buffer == NULL ||
        menu->buttons[i].sound == NULL)
        return 84;
    sfSound_setBuffer
    (menu->buttons[i].sound, menu->buttons[i].sound_buffer);
    return 0;
}

static unsigned int create_sprite_menu
(scene_menu_t *scene_menu)
{
    scene_menu->background = create_sprite
        ("asset/menu/menu_background.png",
        &(sfVector2f){BACKGROUND_POS, BACKGROUND_POS});
    if (scene_menu->background == NULL)
        return 84;
    scene_menu->title = create_sprite
        ("asset/menu/myworld.png",
        &(sfVector2f){TITLE_POS_X, TITLE_POS_Y});
    if (scene_menu->title == NULL)
        return 84;
    scene_menu->helper = create_sprite
        ("asset/menu/helper_menu.png",
        &(sfVector2f){POS_X_HELPER, POS_Y_HELPER});
    if (scene_menu->helper == NULL)
        return 84;
    return 0;
}

static unsigned int play_button(scene_menu_t *menu)
{
    menu->buttons[0].isnt_click = create_sprite
        ("asset/menu/play_button_1.png",
        &(sfVector2f){BTN_PLAY_POS_X, BTN_PLAY_POS_Y});
    if (menu->buttons[0].isnt_click == NULL)
        return 84;
    menu->buttons[0].is_click = create_sprite
        ("asset/menu/play_button_2.png",
        &(sfVector2f){BTN_PLAY_POS_X, BTN_PLAY_POS_Y});
    if (menu->buttons[0].is_click == NULL)
        return 84;
    menu->buttons[0].on_click = on_click_play;
    menu->buttons[0].data = menu;
    if (menu_set_sound_for_button(menu, 0) == 84)
        return 84;
    return 0;
}

static unsigned int quit_button_menu(scene_menu_t *menu)
{
    menu->buttons[1].isnt_click = create_sprite
        ("asset/menu/quit_button1.png",
        &(sfVector2f){BTN_QUIT_POS_X, BTN_QUIT_POS_Y});
    if (menu->buttons[1].isnt_click == NULL)
        return 84;
    menu->buttons[1].is_click = create_sprite
        ("asset/menu/quit_button2.png",
        &(sfVector2f){BTN_QUIT_POS_X, BTN_QUIT_POS_Y});
    if (menu->buttons[1].is_click == NULL)
        return 84;
    menu->buttons[1].on_click = on_click_quit;
    menu->buttons[1].data = menu;
    if (menu_set_sound_for_button(menu, 1) == 84)
        return 84;
    return 0;
}

static unsigned int create_buttons_menu(scene_menu_t *menu)
{
    if (play_button(menu) == 84)
        return 84;
    if (quit_button_menu(menu) == 84)
        return 84;
    return 0;
}

unsigned int create_all_sprite
(scene_menu_t *scene_menu, scene_ingame_t *scene_ingame)
{
    if (create_sprite_menu(scene_menu) == 84)
        return 84;
    if (create_buttons_menu(scene_menu) == 84)
        return 84;
    if (handle_box_menu(scene_menu) == 84)
        return 84;
    if (create_sprite_ingame(scene_ingame) == 84)
        return 84;
    if (handle_box_ingame(scene_ingame) == 84)
        return 84;
    if (create_buttons_ingame(scene_ingame) == 84)
        return 84;
    return 0;
}
