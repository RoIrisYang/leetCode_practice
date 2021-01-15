/**
 * @param {number[][]} accounts
 * @return {number}
 */
var maximumWealth = function(accounts) {
    var mapToSum = accounts.map(x=>x.reduce((a, b)=> a + b));
    var maxWealth = Math.max(...mapToSum);
    return maxWealth;
};