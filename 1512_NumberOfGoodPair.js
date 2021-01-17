/**
 * @param {number[]} nums
 * @return {number}
 */
var numIdenticalPairs = function(nums) {    
    var ans = 0;
    var hash= {}; // hash table, num: countOfnum
    
    for(var i = 0; i < nums.length; i++)
    {
        var tmpKey = String(nums[i]);
        if (hash[tmpKey] !== undefined)
        {
            hash[tmpKey]++;
            ans += hash[tmpKey] - 1
        }        
        else // initialize
        {
            hash[tmpKey] = 1;
        }        
    }
    
    return ans;
};