/**
 * @param {number[]} nums
 * @return {number}
 */

function fraction(n){
    if (n === 0){
      return 1
    }
    return n * fraction(n-1)
  } 
  
  var numIdenticalPairs = function(nums) {    
      var ans = 0;
      var hash= {}; // hash table, num: countOfnum
      
      for(var i = 0; i < nums.length; i++)
      {
          if (hash[String(nums[i])] !== undefined)
          {
              ans += fraction(hash[String(nums[i])] - 1);  
          }        
          else // initialize
          {
              hash[String(nums[i])] = 0;
          }
          hash[String(nums[i])]++;
          
          if (i === 4) return ans; // hash['1'];
      }
      
      return ans;
  };
  
  // can find a O(n) solution