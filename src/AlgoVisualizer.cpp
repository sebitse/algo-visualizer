#include "../AlgoVisulizer.h"

AlgoVisulizer::AlgoVisulizer() 
{
    // Constructor implementation
}

AlgoVisulizer::~AlgoVisulizer() 
{
    // Destructor implementation
}

void AlgoVisulizer::populate(uint8_t population = 100)
{
    // A vector (lines) is populated with a fixed number of values 
    // generated according to a uniform distribution

    std::random_device random;
    std::uniform_int_distribution<> distrib(DISTRIBUTION_LIMITS);

    for (uint8_t i = 0; i < population; ++i) 
    {
        lines.push_back(distrib(random));
    }
}
void AlgoVisulizer::init()
{
    // Populate the vector lines
    populate();

    // Creating the window
    SDL_CreateWindowAndRenderer(RECTANGLE, 0, &window, &renderer);

    // Set the drawing scale for rendering on the current target
    SDL_RenderSetScale(renderer, SCALE);
}
void AlgoVisulizer::clear()
{
    // Set the background color to the default value(BLACK)
    // *Update the screen*
    SDL_SetRenderDrawColor(renderer, BLACK);
    SDL_RenderClear(renderer);
}
void AlgoVisulizer::draw(uint8_t red, uint8_t blue)
{
    // The two working lines are colored according to their index in the vector

    uint8_t index = 0;
    for (uint8_t i : lines) 
    {
        if (index == red)
            SDL_SetRenderDrawColor(renderer, RED);
        else if (index == blue)
            SDL_SetRenderDrawColor(renderer, BLUE);
        else
            SDL_SetRenderDrawColor(renderer, WHITE);

        SDL_RenderDrawLine(renderer, index, 99, index, i);

        // Increment the index in order to find the coresponding line
        ++index; 
    }
}
void AlgoVisulizer::render(uint8_t red, uint8_t blue)
{
    // Clear the screen
    clear();

    // Draw the two major lines
    draw(red, blue);

    // Update and set a delay for the screen
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
}
