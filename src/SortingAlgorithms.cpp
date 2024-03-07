#include "../AlgoVisulizer.h"

void AlgoVisulizer::insertionSort() {

    uint8_t n = (uint8_t)lines.size();

    for (uint8_t i = 1u; i < n; ++i) {
        int key = lines[i];
        int j = i - 1;
        while (j >= 0 && lines[j] > key) {
            lines[j + 1] = lines[j];
            --j;
            
            // The magic begin here
            render(i, j);
        }
        lines[j + 1] = key;
    }
    SDL_Delay(MAX_DELAY);
}