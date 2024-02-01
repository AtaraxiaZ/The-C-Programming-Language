#include <stdio.h>

#define LEN 2000

int binsearch(int x, int v[], int n);

int main(){
    int a = 13;
    int res;
    int list[LEN];
    for (int i = 0; i < LEN; i++) {
        list[i] = i;
    }
    for (int i = 0; i < 10000000; i++){
        res = binsearch(a, list, LEN); 
    }
    printf("%d\n", res);

    return 0;
}

int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
// Flat profile:
//
// Each sample counts as 0.01 seconds.
//   %   cumulative   self              self     total           
//  time   seconds   seconds    calls  ns/call  ns/call  name    
//  99.41      0.52     0.52 10000000    51.69    51.69  binsearch
//   1.95      0.53     0.01                             main
//
// 			Call graph
//
//
// granularity: each sample hit covers 2 byte(s) for 1.90% of 0.53 seconds
//
// index % time    self  children    called     name
//                                                  <spontaneous>
// [1]    100.0    0.01    0.52                 main [1]
//                 0.52    0.00 10000000/10000000     binsearch [2]
// -----------------------------------------------
//                 0.52    0.00 10000000/10000000     main [1]
// [2]     98.1    0.52    0.00 10000000         binsearch [2]
// -----------------------------------------------
//
// Index by function name
//
//    [2] binsearch               [1] main
