#include "../AlgoVisulizer.h"

int main(void) {
    AlgoVisulizer visual;

    visual.init();
    //visual.quickSort(0, visual.getLines().size());
    visual.heapSort();

    return 0;
}
