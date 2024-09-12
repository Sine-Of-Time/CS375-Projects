#include <fstream>
#include <vector>
#include <limits> 
#include <iostream>
#include <algorithm> 
using namespace std;

bool binarySearch(int* arr, int queryNum, int start, int end);

int main() {
    string line;
    vector<int> numbers; 
    getline(cin, line);
    int dataSize = stoi(line); 
    int i = 0;
    while (i < dataSize) {
        try {
            getline(cin, line);
            int integerValue = stoi(line); 
            numbers.push_back(integerValue);
            i++;
        } catch (const invalid_argument& ia) {
            cerr << "Error: Could not convert '" << line << "' to an integer." << endl;
        }
    }

    int* arr = numbers.data();
    int size = numbers.size();
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    getline(cin, line);
    int inputSize = stoi(line);
    int input[inputSize]; 
    int j = 0;
    while (j < inputSize) {
        try {
            getline(cin, line);
            int integerValue = stoi(line); 
            input[j] = integerValue;
            j++;
        } catch (const invalid_argument& ia) {
            cerr << "Error: Could not convert '" << line << "' to an integer." << endl;
        }
    }

    for (int k = 0; k < inputSize; k++) {
        cout << "Searching for " << input[k] << endl;
        if (!binarySearch(arr, input[k], 0, size - 1)) { 
            cout << "Number not found!" << endl; 
        }
    }
    return 0;
}

bool binarySearch(int* arr, int queryNum, int start, int end) {
    if (start <= end) {
        int middle = start + (end - start) / 2;

        if (arr[middle] == queryNum) {
            cout << "Number found at index " << middle << endl;
            return true;
        }

        if (arr[middle] > queryNum) {
            return binarySearch(arr, queryNum, start, middle - 1);
        }

        if (arr[middle] < queryNum) {
            return binarySearch(arr, queryNum, middle + 1, end);
        }
    }

    return false; 
}