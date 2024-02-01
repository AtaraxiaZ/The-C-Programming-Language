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
        else
            low = mid + 1;
    }

    if (v[mid] == x){
        return mid;
    } else {
        return -1;
    }
}
// Flat profile:
//
// Each sample counts as 0.01 seconds.
//   %   cumulative   self              self     total           
//  time   seconds   seconds    calls  ns/call  ns/call  name    
//  95.83      0.53     0.53 10000000    52.71    52.71  binsearch
//   5.53      0.56     0.03                             main
//
// 			Call graph
//
//
// granularity: each sample hit covers 2 byte(s) for 1.79% of 0.56 seconds
//
// index % time    self  children    called     name
//                                                  <spontaneous>
// [1]    100.0    0.03    0.53                 main [1]
//                 0.53    0.00 10000000/10000000     binsearch [2]
// -----------------------------------------------
//                 0.53    0.00 10000000/10000000     main [1]
// [2]     94.5    0.53    0.00 10000000         binsearch [2]
// -----------------------------------------------
//
// Index by function name
//
//    [2] binsearch               [1] main
