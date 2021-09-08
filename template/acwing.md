# 基础算法

## 快速排序

##### AcWing 785. 快速排序

```c++
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int nums[N];

void quick_sort(int nums[], int l, int r) {
    if (l >= r) return;
    
    int i = l-1, j = r+1, x = nums[l + r >> 1];
    while (i < j) {
        do i++; while(nums[i] < x);
        do j--; while(nums[j] > x);
        if (i < j) swap(nums[i], nums[j]);
    }
    
    quick_sort(nums, l, j);
    quick_sort(nums, j+1, r);
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &nums[i]);
    }
    
    quick_sort(nums, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ",nums[i]);
    }
}
```

##### AcWing 786. 第k个数

```c++
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n, k;
int nums[N];

int quick_sort(int l, int r, int k) {
    if (l == r) return nums[l];
    
    int x = nums[l], i = l-1, j = r+1;
    
    while (i < j) {
        while (nums[++i] < x);
        while (nums[--j] > x);
        if (i < j) swap(nums[i], nums[j]);
    }
    
    int sl = j-l+1;
    if (k <= sl) return quick_sort(l, j, k);
    else return quick_sort(j+1, r, k-sl);
}

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d ", &nums[i]);
    }
    
    cout << quick_sort(0, n-1, k) << endl;
}
```

## 归并排序

##### AcWing 787. 归并排序

```c++
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int nums[N], tmp[N];

void merge_sort(int nums[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    
    merge_sort(nums, l, mid);
    merge_sort(nums, mid+1, r);
    
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }
    while (i <= mid) tmp[k++] = nums[i++];
    while (j <= r) tmp[k++] = nums[j++];
    
    for (i = l, k = 0; i <= r; i++, k++) {
        nums[i] = tmp[k];
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &nums[i]);
    }
    
    merge_sort(nums, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ",nums[i]);
    }
}
```

