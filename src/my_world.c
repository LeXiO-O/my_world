/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../include/myworld.h"

static unsigned int texture_water_mode
(game_state_t *window)
{
    window->texture.water =
        sfTexture_createFromFile("asset/ingame/quads/water.png", NULL);
    if (window->texture.water == NULL)
        return 84;
    window->texture.dirt =
        sfTexture_createFromFile("asset/ingame/quads/dirt.png", NULL);
    if (window->texture.dirt == NULL)
        return 84;
    window->texture.grass =
        sfTexture_createFromFile("asset/ingame/quads/grass.png", NULL);
    if (window->texture.grass == NULL)
        return 84;
    return 0;
}

static unsigned int texture_lava_mode
(game_state_t *window)
{
    window->texture.stone =
        sfTexture_createFromFile("asset/ingame/quads/stone.png", NULL);
    if (window->texture.stone == NULL)
        return 84;
    window->texture.lava =
        sfTexture_createFromFile("asset/ingame/quads/lava.png", NULL);
    if (window->texture.lava == NULL)
        return 84;
    window->texture.obsidian =
        sfTexture_createFromFile("asset/ingame/quads/obsidian.png", NULL);
    if (window->texture.obsidian == NULL)
        return 84;
    return 0;
}

static unsigned int initialize_texture
(game_state_t *window)
{
    if (texture_water_mode(window) == 84)
        return 84;
    if (texture_lava_mode(window) == 84)
        return 84;
    return 0;
}

static unsigned int create_window_and_asset
(game_state_t *window, scene_menu_t *scene_menu,
    scene_ingame_t *scene_ingame)
{
    window->is_running = true;
    if (create_all_sprite(scene_menu, scene_ingame) == 84)
        return 84;
    window->window =
        create_window("My_World",
        (const unsigned int[]){WINDOW_WIDTH, WINDOW_HEIGHT, BPP});
    window->scene = SCENE_MENU;
    window->zoom = 1.0f;
    window->rot = 0.0f;
    window->offset.x = OFFSET_X;
    window->offset.y = OFFSET_Y;
    if (initialize_texture(window) == 84)
        return 84;
    window->state = sfRenderStates_default();
    window->state.texture = window->texture.water;
    window->is_select = true;
    return 0;
}

int free_my_asset
(game_state_t *window, scene_menu_t *menu, scene_ingame_t *ingame)
{
    free_asset_menu(menu);
    free_asset_ingame(ingame);
    free_asset_window(window);
    sfRenderWindow_destroy(window->window);
    return 0;
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
    game_state_t window = {0};
    scene_menu_t scene_menu = {0};
    scene_ingame_t scene_ingame = {0};

    if (create_window_and_asset
        (&window, &scene_menu, &scene_ingame) == 84)
        return 84;
    while (sfRenderWindow_isOpen(window.window) && window.is_running == true) {
        handle_event(&window, &scene_menu, &scene_ingame);
        draw_all_sprites(&window, &scene_menu, &scene_ingame);
    }
    free_my_asset(&window, &scene_menu, &scene_ingame);
    return 0;
}
