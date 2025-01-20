// Q4: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

#include <iostream>
using namespace std;

int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(height)/ sizeof(height[0]);
    int start = 0, end = size - 1, max_A = 0, curr_A;
    while (start < end) {
        if (height[start] < height[end]) {
            curr_A = height[start] * (start - end);
        }
        else {
            curr_A = height[end] * (end - start);
        }

        if (curr_A > max_A) {
            max_A = curr_A;
        }

        if(height[start] < height[end]) {
            start++;
        }
        else {
            end--;
        }
    }

    cout << max_A << endl;
}