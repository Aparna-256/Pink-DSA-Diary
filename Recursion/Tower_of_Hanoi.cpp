#include <iostream>
using namespace std;

class Solution {
public:
    // Function to solve Tower of Hanoi
    // n          → number of disks
    // source     → rod from where disks are moved
    // destination→ rod to where disks are moved
    // helper     → extra rod used for help
    int towerOfHanoi(int n, char source, char destination, char helper) {

        // BASE CASE:
        // If there are no disks, no moves are needed
        if (n == 0) {
            return 0;
        }

        int moves = 0;

        // STEP 1:
        // Move top (n-1) disks from source rod to helper rod
        // destination rod is used as temporary support
        moves += towerOfHanoi(n - 1, source, helper, destination);

        // STEP 2:
        // Move the largest disk (nth disk) directly
        // from source rod to destination rod
        cout << "Move disk " << n
             << " from " << source
             << " to " << destination << endl;

        moves++;  // count this move

        // STEP 3:
        // Move the (n-1) disks from helper rod to destination rod
        // source rod is now used as helper
        moves += towerOfHanoi(n - 1, helper, destination, source);

        // Return total number of moves made
        return moves;
    }
};
