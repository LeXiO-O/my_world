/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static void destroy_sprite_menu(scene_menu_t *menu)
{
    sfTexture_destroy(menu->background->texture);
    sfTexture_destroy(menu->title->texture);
    sfTexture_destroy(menu->helper->texture);
    sfSprite_destroy(menu->background->sprite);
    sfSprite_destroy(menu->title->sprite);
    sfSprite_destroy(menu->helper->sprite);
}

void free_asset_menu(scene_menu_t *menu)
{
    destroy_sprite_menu(menu);
    sfRectangleShape_destroy(menu->box);
    sfFont_destroy(menu->font_box);
    sfText_destroy(menu->text);
    for (int i = 0; i < NB_BUTTONS_MENU; i++) {
        sfSound_destroy(menu->buttons[i].sound);
        sfSoundBuffer_destroy(menu->buttons[i].sound_buffer);
        sfText_destroy(menu->buttons[i].help_key);
        sfFont_destroy(menu->buttons[i].helper_font);
        sfText_destroy(menu->buttons[i].help_button);
        sfTexture_destroy(menu->buttons[i].isnt_click->texture);
        sfSprite_destroy(menu->buttons[i].isnt_click->sprite);
        sfTexture_destroy(menu->buttons[i].is_click->texture);
        sfSprite_destroy(menu->buttons[i].is_click->sprite);
        free(menu->buttons[i].isnt_click);
        free(menu->buttons[i].is_click);
    }
    free(menu->background);
    free(menu->title);
    free(menu->helper);
}

static void destroy_button_ingame(scene_ingame_t *ingame)
{
    for (int i = 0; i < NB_BUTTONS_INGAME; i++) {
        sfSound_destroy(ingame->buttons[i].sound);
        sfSoundBuffer_destroy(ingame->buttons[i].sound_buffer);
        sfText_destroy(ingame->buttons[i].help_key);
        sfFont_destroy(ingame->buttons[i].helper_font);
        sfText_destroy(ingame->buttons[i].help_button);
        sfTexture_destroy(ingame->buttons[i].isnt_click->texture);
        sfSprite_destroy(ingame->buttons[i].isnt_click->sprite);
        sfTexture_destroy(ingame->buttons[i].is_click->texture);
        sfSprite_destroy(ingame->buttons[i].is_click->sprite);
        free(ingame->buttons[i].isnt_click);
        free(ingame->buttons[i].is_click);
    }
}

void free_asset_ingame(scene_ingame_t *ingame)
{
    sfTexture_destroy(ingame->tool_bar->texture);
    sfSprite_destroy(ingame->tool_bar->sprite);
    for (int i = 0; i < NB_TEXT_BOX; i++) {
        sfRectangleShape_destroy(ingame->text_box[i].box);
        sfFont_destroy(ingame->text_box[i].font_box);
        sfText_destroy(ingame->text_box[i].text);
    }
    destroy_button_ingame(ingame);
    free(ingame->tool_bar);
}

void free_asset_window(game_state_t *window)
{
    free_array(window->matrix);
    for (int i = 0; i < window->size_matrix_x; i++)
        free(window->matrix_size[i]);
    free(window->matrix_size);
    for (int i = 0; i < window->size_matrix_x; i++)
        free(window->map2d[i]);
    free(window->map2d);
    sfTexture_destroy(window->texture.dirt);
    sfTexture_destroy(window->texture.grass);
    sfTexture_destroy(window->texture.lava);
    sfTexture_destroy(window->texture.obsidian);
    sfTexture_destroy(window->texture.stone);
    sfTexture_destroy(window->texture.water);
}
