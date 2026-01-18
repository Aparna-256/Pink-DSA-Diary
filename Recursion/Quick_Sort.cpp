#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partition(vector<int>& arr, int low, int high) {

        int pivot = arr[high];
        int pivot_index = low;

        for (int i = low; i < high; i++) {
            if (arr[i] < pivot) {
                swap(arr[i], arr[pivot_index]);
                pivot_index++;
            }
        }

        swap(arr[pivot_index], arr[high]);
        return pivot_index;
    }

    void quicksort(vector<int>& arr, int low, int high) {
        if (low >= high) return;

        int partition_index = partition(arr, low, high);

        quicksort(arr, low, partition_index - 1);
        quicksort(arr, partition_index + 1, high);
    }
};
