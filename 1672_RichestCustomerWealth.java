class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxWealth = 0;
        for(int i= 0; i < accounts.length; i++){
            int wealth = Arrays.stream(accounts[i]).sum();
            if (wealth > maxWealth){
                maxWealth = wealth;
            }
        }
        return maxWealth;
    }
}