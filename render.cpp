#include "render.h"
#include <unordered_map>

std::unordered_map<const char*, SDL_Color> colorscheme = {
    {"empty", {0, 0, 0, 0}},
    {"ui_grey", {0x25, 0x25, 0x25, 0xff}},
    {"ui_orange", {0xff, 0x99, 0x00, 0xff}},
    {"ui_lightgrey", {0x55, 0x55, 0x55, 0xff}},
};


RenderQueue::RenderQueue(SDL_Renderer *r) : m_renderer(r) {
    items.reserve(1024);
}

RenderQueue::~RenderQueue() {
    for (auto item: items) {
        SDL_DestroyTexture(item.texture);
    }
    items.clear();
}


void RenderQueue::set_draw_color(SDL_Renderer *r, const SDL_Color &c) {
    SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);
}

void RenderQueue::draw() {
    const int width = 1200;
    const int height = 900;
    const int r_dim = 200;
    const int n_items = 3;
    SDL_Rect items_to_draw[n_items];

    for (int i = 0; i < n_items; ++i) {
        SDL_Rect r = {.x = r_dim * i, .y = height / 2, .w = r_dim, .h = r_dim};
        RenderItem custom_item = {.rect = r, .texture = nullptr, .color = colorscheme["ui_grey"]};
        items.push_back(custom_item);
    }

    items[1].color = colorscheme["ui_orange"];
    items[2].color = colorscheme["ui_lightgrey"];

    for (auto &i: items) {
        set_draw_color(m_renderer, i.color);
        SDL_RenderCopy(m_renderer, i.texture, &i.rect, nullptr);
    }


}
