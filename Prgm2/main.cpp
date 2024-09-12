#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void mergeSort(vector<int>& arr,int low,int high);
void merge(vector<int>& arr,int low,int mid,int high);
void printVector(const vector<int>& vec); 
void printVectorWithIndex(const vector<int>& vec); 
void mergeSortReal(vector<int>& arr,int low,int high);
void printVectorInRange(const vector<int>& vec, int low, int high);
//Most of these comments are so I can understand what I'm doing or doc issues
//So it is sorting 50 numbers fine, same with 100, and 500. It's also nlogn

int main(int argc, char* argv[]) {
    string line;
    vector<int> numbers; 
    getline(cin, line);

    int low = 0;
    int high = 0;
    if (argc > 1) low = atoi(argv[1]);
    if (argc > 2) high = atoi(argv[2]);

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
    cout << "Array has a size of " << dataSize << endl;
    cout << "Array before sorting: ";
    printVector(numbers);
    mergeSort(numbers,0,dataSize);

    cout << "-------------------------------------------------------------------------------------------------" << endl;
    if(high-low>0){
        cout << "Array after sorting in range " << high - low << ":" << endl;
        printVectorInRange(numbers,low,high);
    }else{
        cout << "Array after sorting:" << endl;
        printVector(numbers);
    }
    
    return 0;
}

void mergeSort(vector<int>& arr,int low,int high) {
    mergeSortReal(arr,low,high-1);//This fixes an issues with only appears when compiled on the remote sever
}    

void mergeSortReal(vector<int>& arr,int low,int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSortReal(arr, low, mid);
    mergeSortReal(arr, mid + 1, high);
    merge(arr, low, mid, high); //Only called when the og arr is fully divided
}    

void merge(vector<int>& arr, int low, int mid, int high) {
    int tmpL = mid - low + 1;//Calc size of left
    int tmpH = high - mid;//Calc size of right
    vector<int> arrL(tmpL);
    vector<int> arrR(tmpH);

    //Copy data to temp vectors
    for (int i = 0; i < tmpL; i++) {arrL[i] = arr[low + i];}
    for (int j = 0; j < tmpH; j++) {arrR[j] = arr[mid + 1 + j];}

    int i = 0;// idx of first sub-array
    int j = 0;// idx of second sub-array
    int k = low;// idx of merged sub-array

    // Merge the temp vectors back into main
    while (i < tmpL && j < tmpH) {
        if (arrL[i] <= arrR[j]) arr[k] = arrL[i++];
        else arr[k] = arrR[j++];
        k++;
    }
   
    while (i < tmpL) {arr[k++] = arrL[i++];} // Copy remaining elements of arrL
    while (j < tmpH) {arr[k++] = arrR[j++];}// Copy remaining elements of arrR 
}

void printVector(const vector<int>& vec) {
    for (int element : vec) {cout << element << "| ";}
    cout << endl; 
}

void printVectorWithIndex(const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {cout << "[" << i << "]=" << vec[i] << " "; }
    cout << endl; 
}

void printVectorInRange(const vector<int>& vec, int low, int high) {
    for (int i=low;i<=high;i++) {
            cout << vec[i] << "| ";
    }
    cout << endl;
}