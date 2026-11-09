// binary_search: try to find target integer "num" in an increasing array without duplicates,
// if the integer does not exist, return -1.
#include <catch_amalgamated.hpp>

// Pseudocode
// 1. int search(vector<int> nums, int target)
// 2. start with low at the first index and high at the last index
// 3. while there's still something between low and high
//    4. find the middle (low + (high - low) / 2)
//    5. if the middle number is the target, return middle
//    6. if the target is smaller, move high to just left of the middle
//    7. otherwise, move low to just right of the middle
// 8. we ran out of places to look, so return -1

#include <vector>

using namespace std;

int search(vector<int> nums, int target) {
  int low = 0;
  int high = nums.size() - 1;
  while(low <= high) {
      int middle = low + (high-low) / 2;
      if(nums[middle] == target) {
          return middle;
      }
      if(target < nums[middle]) {
          high = middle - 1;
      } else {
          low = middle + 1;
      }
  }
  return -1;
}

TEST_CASE("two_sum examples", "[two_sum]") {
  // REQUIRE(solve(...) == expected);
  REQUIRE(search({-1,0,2,4,6,8}, 4) == 3);
  REQUIRE(search({-1,0,2,4,6,8}, 3) == -1);
  REQUIRE(search({-1,0,2,4,6,8,9}, 0) == 1);
  REQUIRE(search({-1,0,2,4,6,8,9}, 9) == 6);
  REQUIRE(search({-1,0,2,4,6,8,9}, 10) == -1);

}

TEST_CASE("two_sum edge cases", "[two_sum][edge]") {
  // empty input, single element, duplicates, negatives, max size
}
