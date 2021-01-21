# Quick Sort

- time complexity: nlogn (average case)
- effective than other sorts in the computation performance
- c++ build-in library sort implementation by quick sort

## Prove
### Best case: O(nlogn)
T(n) = 2 * T(n/2) + c1 * n \
     = 2 [2 * T(n/4) + c2 * n] + c1 * n \
     = 2^2 * T(n/4) + (c1 + c2) * n \
     = 2^2 [2 * T(n/8) + c3 * n] + (c1 + c2) * n \
     = 2^3 * T(n/8) + (c1 + c2 + c3) *n \
     = ... \
     = 2^k * T(n/2^k) + (c1 + c2 + ... + ck) * n \ 
     // T(n/2^k) = T(1) -> 2^k = n -> k = logn \
     = 2^logn + logn * n \
     = O(n + nlogn) ∈ O(nlogn) \

### Worst case: O(n^2)
T(n) = T(n-1) + c1 * n \
     = T(n-2) + (c1 + c2) * n \
     = .... \
     = (c1 + c2 + ... + cn) * n \
     = O(n^2) \

### Average case: O(nlogn)
T(n) = T(1) + T(n-1) + c1 * n \
                + \
       T(2) + T(n-2) + c2 * n \
                + \
               ... \
                + \
       T(n-1) + T(1) + cn * n \
    --------------------------- \
       ∈ O(nlogn) \