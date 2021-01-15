class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        maxWealth = max(map(sum, accounts))
        return maxWealth