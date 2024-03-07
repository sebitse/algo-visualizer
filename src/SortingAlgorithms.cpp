#include "../AlgoVisulizer.h"

void AlgoVisulizer::insertionSort() {

    uint8_t n = (uint8_t)lines.size();

    for (uint8_t i = 1u; i < n; ++i) 
    {
        int key = lines[i];
        int j = i - 1;
        while (j >= 0 && lines[j] > key) 
        {
            lines[j + 1] = lines[j];
            --j;
            
            // The magic begin here
            render(i, j);
        }
        lines[j + 1] = key;
    }
    SDL_Delay(MAX_DELAY);
}
void AlgoVisulizer::bubbleSort()
{
    uint8_t n = (uint8_t)lines.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) 
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (lines[j] > lines[j + 1]) 
            {
                std::swap(lines[j], lines[j + 1]);
                swapped = true;
                render(j, j + 1);
            }
        }
        // If no two elements were swapped in the inner loop, the array is already sorted
        if (!swapped) 
            break;
    }
    SDL_Delay(MAX_DELAY);
}

int16_t AlgoVisulizer::partition(std::vector<uint8_t>& arr, int16_t low, int16_t high) 
{
    uint8_t pivot = arr[high]; // Choose the last element as the pivot
    int16_t i = low - 1; // Index of the smaller element

    for (int16_t j = low; j < high; ++j) 
    {
        if (arr[j] < pivot) 
        {
            ++i;
            std::swap(arr[i], arr[j]);
            render(i, j);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    render(i+1, high);
    
    return i + 1;
}
void AlgoVisulizer::quickSort(int16_t low, int16_t high) 
{
    if (low < high) 
    {
        int16_t pi = partition(lines, low, high);

        quickSort(low, pi - 1); // Sort elements before partition
        quickSort(pi + 1, high); // Sort elements after partition
    }
    SDL_Delay(MAX_DELAY);
}
void AlgoVisulizer::selectionSort()
{
    uint8_t n = (uint8_t)lines.size();

    for (int16_t i = 0; i < n - 1; ++i) 
    {
        int minIndex = i;
        for (int16_t j = i + 1; j < n; ++j) 
        {
            if (lines[j] < lines[minIndex]) 
                minIndex = j;
        }
        if (minIndex != i) 
        {
            std::swap(lines[i], lines[minIndex]);
            render(i, minIndex);
        }
    }
    SDL_Delay(MAX_DELAY);
}
/*
void AlgoVisulizer::heapify(uint8_t n, uint8_t i)
{
    uint8_t largest = i; // Initialize largest as root
    uint8_t left = 2 * i + 1; // Left child
    uint8_t right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && lines[left] > lines[largest]) 
    {
        render(left, largest);
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && lines[right] > lines[largest]) 
    {
        render(right, largest);
        largest = right;
    }

    // If largest is not root
    if (largest != i) 
    {
        std::swap(lines[i], lines[largest]);
        render(i, largest);

        // Recursively heapify the affected sub-tree
        heapify(n, largest);
    }
}
void AlgoVisulizer::heapSort()
{
    uint8_t n = lines.size();

    // Build heap
    for (uint8_t i = n / 2 - 1; i >= 0; --i) 
    {
        heapify(n, i);
    }

    // Extract elements from heap one by one
    for (uint8_t i = n - 1; i > 0; --i) 
    {
        // Move current root to end
        std::swap(lines[0], lines[i]);
        render(0, i);

        // Call heapify on the reduced heap
        heapify(i, 0);
        std::cout << i << " ";
    }
    SDL_Delay(MAX_DELAY);

    for(int i : lines)
        std::cout<<i<<" ";
}
*/