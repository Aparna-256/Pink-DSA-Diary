#include <vector>
using namespace std;

class Solution {
public:
    // Function to merge two sorted arrays
    vector<int> merge(vector<int>& left, vector<int>& right) {
        vector<int> result;
        int i = 0, j = 0;

        // Compare elements of both arrays and push smaller one
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                result.push_back(left[i]);
                i++;
            } else {
                result.push_back(right[j]);
                j++;
            }
        }

        // If elements are left in left array
        while (i < left.size()) {
            result.push_back(left[i]);
            i++;
        }

        // If elements are left in right array
        while (j < right.size()) {
            result.push_back(right[j]);
            j++;
        }

        return result;
    }

    // Merge Sort function
    void mergesort(vector<int>& arr) {
        // Base case: single element is already sorted
        if (arr.size() <= 1) {
            return;
        }

        int mid = arr.size() / 2;

        // Divide array into two halves
        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        // Recursively sort both halves
        mergesort(left);
        mergesort(right);

        // Merge sorted halves
        arr = merge(left, right);
    }
};
