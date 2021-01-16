class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxCandies = max(candies)
        return [True if candy + extraCandies >= maxCandies else False for candy in candies]