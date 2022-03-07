#include <iostream>
using namespace std;

void merge(int array[], int const left, int const mid, int const right){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++){
        L[i] = array[left + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = array[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }
        else{
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        array[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int const left, int const right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main(int argc, char const *argv[])
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(array) / sizeof(array[0]);
    for ( int i = 0; i < n; i++ )
        cout << array[i] << " ";
    cout << endl;
    mergeSort(array, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
