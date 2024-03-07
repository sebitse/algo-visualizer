#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <SDL2/SDL.h>

// MACRO

#define RED 255, 0, 0, 255
#define BLUE 0, 0, 255, 255
#define WHITE 255, 255, 255, 255
#define BLACK 0, 0, 0, 255

#define DISTRIBUTION_LIMITS 1, 99
#define WIDTH 1000
#define HEIGHT 1000
#define RECTANGLE WIDTH, HEIGHT
#define SCALE 10., 10.
#define MAX_DELAY 1000

class AlgoVisulizer
{
private:
    std::vector<uint8_t> lines;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    void populate(uint8_t);
    void clear();
    void draw(uint8_t, uint8_t);
    void render(uint8_t, uint8_t);
public:
    AlgoVisulizer();
    ~AlgoVisulizer();

    void init();

    // Sorting Algorithms
    void insertionSort();
    void bubbleSort();
    void quickSort(int16_t, int16_t);
    int16_t partition(std::vector<uint8_t>&, int16_t, int16_t);
    void selectionSort();

    /*
    void heapify(uint8_t, uint8_t);
    void heapSort();
    */
};



