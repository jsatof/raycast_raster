#pragma once

struct Button {
    SDL_Rect dims;
    SDL_Rect pos;
    SDL_Texture *texture;
    std::function<void()> callback;
};
