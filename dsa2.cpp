#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void delete_element(vector<int>& arr, int value = -1, int position = -1) {
    if (value != -1) {
        auto it = find(arr.begin(), arr.end(), value);
        if (it != arr.end()) {
            arr.erase(it);
        } else {
            cout << "Element not found" << endl;
        }
    } 
    else if (position != -1 && position >= 0 && position < arr.size()) {
        arr.erase(arr.begin() + position);
    } 
    else {
        cout << "Invalid position" << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    
    delete_element(arr, 3);
    delete_element(arr, -1, 1);
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
