/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../include/myworld.h"

sprite_t *create_sprite(const char *str, sfVector2f *position)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(str, NULL);
    sprite_t *data;

    if (texture == NULL)
        texture = missing_texture(sprite);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, *position);
    data = malloc(sizeof(sprite_t));
    if (data == NULL) {
        sfSprite_destroy(sprite);
        sfTexture_destroy(texture);
        return NULL;
    }
    data->sprite = sprite;
    data->texture = texture;
    return data;
}
