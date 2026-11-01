// contains_duplicate: identify whether an array of integers has any duplicate
// value
#include <catch_amalgamated.hpp>
#include <unordered_set>

// Brainstorm:
// - Brute force: for every integer in the array, search the entire array for a
// duplciate value; O(n^2) time, space O(1)
// - Using a set: iterate through the integer array and check if every item
// already exists in a set for seen elements. Add each item if to the set if it
// has not been seen before; O(n) time, O(n) space

// Psuedocode:
// 1. bool contains_duplicate(integer array nums)
// 2. if nums is empty, return false
// 3. if nums has only one element, return false;
// 4. seen = unordered set of integers (finds/erase operations are O(1))
// 5. for loop over all elements of nums
//      6. if seen contains current element, return true for duplicate
//      7. else add current element to set
// 8. return false -- no duplicate in array

using namespace std;

bool contains_duplicate(vector<int> &nums) {
  if (nums.size() == 0 || nums.size() == 1)
    return false;
  unordered_set<int> seen;
  for (int item : nums) {
    if (seen.contains(item)) {
      return true;
    } else {
      seen.insert(item);
    }
  }
  return false;
}

TEST_CASE("contains duplicate", "[contains_duplicate]") {
  vector<int> nums = {1, 2, 3, 4, 5, 1};
  REQUIRE(contains_duplicate(nums) == true);
}

TEST_CASE("does not contain duplicate", "[contains_duplicate]") {
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  REQUIRE(contains_duplicate(nums) == false);
}

TEST_CASE("empty array", "[contains_duplicate][edge]") {
  vector<int> nums = {};
  REQUIRE(contains_duplicate(nums) == false);
}

TEST_CASE("single element array", "[contains_duplicate][edge]") {
  vector<int> nums = {1};
  REQUIRE(contains_duplicate(nums) == false);
}
