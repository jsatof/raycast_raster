#include <iostream>
#include <SDL2/SDL.h>
#include <unordered_map>
#include <cmath>

#include "render.h"

int main(int argc, wchar_t **argv);

#ifdef __MINGW32__
extern "C" int wWinMain(int argc, wchar_t **argv, wchar_t **) {
    return main(argc, argv);
}
#endif

inline bool quit_pressed(const SDL_Event &event) {
    return event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q;
}

inline void set_render_color(SDL_Renderer *r, const SDL_Color &c) {
    SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);
}

std::unordered_map<const char*, SDL_Color> theme = {
    {"bg_black", {0x0b, 0x0b, 0x0b, 0xff}},
    {"canvas_black", {0x18, 0x18, 0x18, 0xff}},
    {"canvas_white", {0x40, 0x40, 0x40, 0xff}},
};

namespace my {
    constexpr double pi = acos(-1);
}

inline void draw_ellipse(SDL_Renderer *r, const double radius, const SDL_Point &origin) {
    
}

int main(int argc, wchar_t **argv) {
    SDL_Init(SDL_INIT_VIDEO);

    int win_w = 1200;
    int win_h = 900;;
    SDL_Window *window = SDL_CreateWindow("test window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_w, win_h, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;

    const int canvas_dim = 800;
    const int n_rows = 10;
    const int n_cols = 10;
    const int cell_dim = canvas_dim / n_rows;
    const SDL_Point canvas_pos = {.x = (win_w / 2) - (canvas_dim / 2), .y = (win_h - canvas_dim) / 2};

    while (true) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT || quit_pressed(event)) {
            break;
        }

        SDL_RenderClear(renderer);
        set_render_color(renderer, theme["bg_black"]);

        SDL_Rect bg = {.x = 0, .y = 0, .w = win_w, .h = win_h};
        SDL_RenderFillRect(renderer, &bg);

        SDL_Rect r = {.x = canvas_pos.x, .y = canvas_pos.y, .w = canvas_dim, .h = canvas_dim};
        set_render_color(renderer, theme["canvas_black"]);
        SDL_RenderFillRect(renderer, &r);

        // drawing grid
        set_render_color(renderer, theme["canvas_white"]);
        for (int i = 0; i <= n_rows; ++i) {
            SDL_RenderDrawLine(renderer,
                    i * cell_dim + canvas_pos.x, canvas_pos.y,
                    i * cell_dim + canvas_pos.x, canvas_pos.y + canvas_dim);
        }
        for (int j = 0; j <= n_cols; ++j) {
            SDL_RenderDrawLine(renderer,
                    canvas_pos.x,               j * cell_dim + canvas_pos.y,
                    canvas_pos.x + canvas_dim,  j * cell_dim + canvas_pos.y);
        }








        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
