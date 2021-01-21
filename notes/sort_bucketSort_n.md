# Bucket Sort

- sort with condition (need to know the digit of the maximum number)

## Explain with example
Given input array: nums = [321, 76, 84, 99, 732, 1234, 51, 34],
and there are 10 buckets to record each digits.

Each round see 1 digit, and collect them back at the end of each round.

- Round one: see the first digit
[bucket 0] 
[bucket 1] 321, 51
[bucket 2] 732
[bucket 3]
[bucket 4] 84, 1234, 34
[bucket 5]
[bucket 6] 76
[bucket 7]
[bucket 8]
[bucket 9] 99

-> nums = [321, 51, 732, 84, 1234, 34, 76, 99]

- Round two: see the second digit
[bucket 0] 
[bucket 1] 
[bucket 2] 321
[bucket 3] 732, 1234, 34,
[bucket 4] 
[bucket 5] 51
[bucket 6] 
[bucket 7] 76
[bucket 8] 84
[bucket 9] 99

-> nums = [321, 732, 1234, 34, 51, 76, 84, 99]

- Round three: see the hundred digit
[bucket 0] 34, 51, 76, 84, 99
[bucket 1] 
[bucket 2] 1234
[bucket 3] 321
[bucket 4] 
[bucket 5]
[bucket 6] 
[bucket 7] 732
[bucket 8]
[bucket 9] 

-> nums = [34, 51, 76, 84, 99, 1234, 321, 732]

... do untill all done

## Conclusion
If you know the count of digits k, the time complexity is k * n since you have to iterate through the whole array. k is constant if we know it exactly.
-> O(k*n) ∈ O(n)