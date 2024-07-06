#pragma once

#include <SDL2/SDL.h>
#include <vector>

class RenderQueue {
public:
    explicit RenderQueue(SDL_Renderer *r);
    ~RenderQueue();

    void draw();

private:
    void set_draw_color(SDL_Renderer *r, const SDL_Color &c);

    SDL_Renderer *m_renderer; // we dont own this, no destroy
    struct RenderItem {
        SDL_Rect rect;
        SDL_Texture *texture;
        SDL_Color color;
    };
    std::vector<RenderItem> items;
};
