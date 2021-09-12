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

##### AcWing 788. 逆序对的数量

```c++
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e5+10;
int nums[N], tmp[N];

LL merge_sort(int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    LL res = merge_sort(l, mid) + merge_sort(mid+1, r);
    int k = 0, i = l, j = mid+1;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
            res += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k++] = nums[i++];
    while (j <= r) tmp[k++] = nums[j++];
    
    for (i = l, k = 0; i <= r; i++, k++) {
        nums[i] = tmp[k];
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    cout << merge_sort(0, n-1) << endl;
    return 0;
}
```

## 二分

##### AcWing 789. 数的范围

```c++
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e5+10;
int nums[N], n, m;

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    while (m--) {
        int x;
        scanf("%d", &x);
        
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= x) r = mid;
            else l = mid + 1;
        }
        
        if (nums[l] != x) {
            cout << "-1 -1" << endl;
        } else {
            cout << l << " ";
            l = 0, r = n-1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (nums[mid] <= x) l = mid;
                else r = mid - 1;
            }
            
            cout << l << endl;
        }
    }
    return 0;
}
```

##### AcWing 790. 数的三次方根

```c++
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e5+10;

int main(int argc, const char * argv[]) {
    double x;
    cin >> x;
    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        double mid = (l+r)/2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    printf("%lf\n", l);
    return 0;
}
```

## 高精度

##### AcWing 791. 高精度加法

```c++
```

##### AcWing 792. 高精度减法

```c++
```

##### AcWing 793. 高精度乘法

```c++
```

##### AcWing 794. 高精度除法

```c++
```

