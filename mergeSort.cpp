//
// Created by Muhammad Fajar Pamungkas on 2020-05-04.
//
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> arr, int left, int right, int bLeft, int bRight);

void mergeSort(vector<int> arr, int left, int right){
    if(left != right){
        int mid =(left + right) / 2;
        mergeSort(arr,left, mid);
        mergeSort(arr,mid+1, right);
        merge(arr, left, mid, mid+1, right);
    }
}

void merge(vector<int> arr, int left, int right, int bLeft, int bRight) {
    int sz = 0;
    sz = right - left + 1;
    vector<int> temp = vector<int>(sz);
    int tIndex = 0;
    int aIndex = left;
    int bIndex = bLeft;

    while(aIndex < right || bIndex < bRight) {
        if(arr[aIndex] <= arr[bIndex]){

        }
    }


}

int main()
{

}
