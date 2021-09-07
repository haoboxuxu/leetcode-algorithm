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
```

## 归并排序

##### AcWing 787. 归并排序

```c++
```

