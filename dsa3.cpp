#include <iostream>
#include <vector>

using namespace std;

int linear_search(const vector<int>& arr, int element) {
    for(int i = 0; i < arr.size(); i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() { 
    vector<int> arr = {1, 2, 3, 4, 5};
    int index = linear_search(arr, 3);
    
    if(index != -1) {
        cout << "Element found at index: " << index << endl;
    }
    else {
        cout << "Element not found in array" << endl;
    }

    return 0;
}
