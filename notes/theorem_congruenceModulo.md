# Congruence Modulo

- sign: ≡
- see wiki: https://zh.wikipedia.org/wiki/%E5%90%8C%E9%A4%98

## Theorem
When two integer a, b have the same remainder after divided by integer m, we call that a and b are congruent modulo m.
= a ≡ b (mod m)

## Example
Try it on leetCode 1015. To find the digits of positive integer N, which formed with 1. \
Ex. \
    if K == 3, 111 can be divided by 3 -> return 3. \
    if K == 2, no such positive integer. \
    if K == 17, 1111111111111111 can be divided by 17 -> return 16. \

Process of K == 17: \
a starts from 1, and the rule is next a will be: 10 * b + 1. \
a ≡ b (mod K) \
1 ≡ 1 (mod 17)                      → digit++ \
a = 10 * b + 1 = 11, b = a % 17 \
11 ≡ 11 (mod 17)                    → digit++ \
111 ≡ 9 (mod 17)                    → digit++ \
91 ≡ 6 (mod 17)                     → digit++ \
... \
find untill b % K == 0, return digits count.

```
int smallestRepunitDivByK(int K) {      
    int digits = 1;
    // int N = 1;
    int remainder = 1;
    set<int> remainders;
    
    while (remainder % K != 0 ) {
        remainders.insert(remainder);
        remainder = (remainder * 10 + 1) % K;
        
        if (remainders.find(remainder) != remainders.end()) return -1;
        digits++;
    }
    
    return digits;
}
```
