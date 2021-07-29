### 冒泡

```c++
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int len) {
    if (len < 2) return;
    for (int i = len - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void bubbleSortRecur(int arr[], int len) {
    if (len < 2) return;
    for (int i = 0; i < len-1; i++) {
        if (arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSortRecur(arr, len-1);
}

int main(int argc, const char * argv[]) {
    int arr[] = {1, 4, 5, 3, 10, 7, 8, 2, 9, 6};
    
    bubbleSort(arr, sizeof(arr) / sizeof(int));
    //bubbleSortRecur(arr, sizeof(arr) / sizeof(int));
    
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

