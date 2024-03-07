#include "../AlgoVisulizer.h"

int main(void) 
{
    AlgoVisulizer visual;

    // Setup
    visual.init();

    //visual.insertionSort();
    //visual.bubbleSort();
    visual.quickSort(ZERO, visual.nrLines());
    //visual.selectionSort();

    return 0;
}
