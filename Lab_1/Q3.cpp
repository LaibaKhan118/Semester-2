// Q3: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.You can return the answer in any order.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {2,7,11,15};
    int target = 9, size = sizeof(arr)/ sizeof(arr[0]);
    int index_1, index_2;
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
                if (arr[i] + arr[j] == target) {
                    index_1 = i;
                    index_2 = j;
                    break;
                }
        }
    }
    cout << "The Indices are " << index_1 << " and " << index_2 << endl;
}
