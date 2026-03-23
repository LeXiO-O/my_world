/*
** EPITECH PROJECT, 2026
** CSFML
** File description:
** replace missing texture by an other one
*/

#include "../../include/csfml_ws.h"

sfTexture *missing_texture(sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getLocalBounds(sprite);
    float height = bounds.height;
    float left = bounds.left;
    float top = bounds.top;
    float width = bounds.width;
    int size = 200;
    sfImage *image = sfImage_create(size, size);
    sfColor c;
    sfColor pink = sfColor_fromRGBA(255, 0, 255, 255);
    sfColor black = sfColor_fromRGBA(0, 0, 0, 255);
    sfTexture *missing_texture;

    for (unsigned int y = 0; y < size; y++) {
        for (unsigned int x = 0; x < size; x++) {
            c = ((x / 8 + y / 8) % 2 == 0) ? pink : black;
            sfImage_setPixel(image, x, y, c);
        }
    }
    missing_texture = sfTexture_createFromImage(image, NULL);
    sfImage_destroy(image);
    return (missing_texture);
}
