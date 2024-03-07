#include "../AlgoVisulizer.h"

AlgoVisulizer::AlgoVisulizer() {
    // Constructor implementation
}

AlgoVisulizer::~AlgoVisulizer() {
    // Destructor implementation
}

void AlgoVisulizer::populate(uint8_t population = 100)
{
    std::random_device r;
    std::uniform_int_distribution<> distrib(DISTRIBUTION_LIMITS);

    for (uint8_t i = 0; i < population; ++i) 
    {
        lines.push_back(distrib(r));
    }
}
void AlgoVisulizer::init()
{
    populate();

    SDL_CreateWindowAndRenderer(RECTANGLE, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, SCALE);
}
void AlgoVisulizer::clear()
{
    if(renderer == nullptr)
        return;

    SDL_SetRenderDrawColor(renderer, BLACK);
    SDL_RenderClear(renderer);
}
void AlgoVisulizer::draw(uint8_t red, uint8_t blue)
{
    if(renderer == nullptr)
        return;

    uint8_t index = 0;
    for (int i : lines) {

        if (index == red)
            SDL_SetRenderDrawColor(renderer, RED);
        else if (index == blue)
            SDL_SetRenderDrawColor(renderer, BLUE);
        else
            SDL_SetRenderDrawColor(renderer, WHITE);

        SDL_RenderDrawLine(renderer, index, 99, index, i);
        ++index;
    }
}
void AlgoVisulizer::render(uint8_t red, uint8_t blue)
{
    clear();
    draw(red, blue);
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
}
