// missing_number: identify the missing number in an array from [0, n]
#include <catch_amalgamated.hpp>
#include <vector>

// Brainstorm
// Calculate the sum of an array from O to n, subtract the sum of the actual
// array we get as an input and that is your answer. Algorithm to calculate sum
// of an array from 0 to N is: sum = n * (n + 1) / 2
// Time comexplity: O(n)
// Space complexity: O(1)
//
// Pseudocode
// 1. Calculate target sum using Gauss's formula
// 2. Initialize integer to store sum of num array
// 3. Iterate over nums and sum values of target array
// 4. Subtract actual sum from target sum and return value

using namespace std;

int missing_number(const vector<int> &nums) {
  int target_sum = nums.size() * (nums.size() + 1) / 2;
  int sum = 0;
  for (int n : nums) {
    sum += n;
  }
  return target_sum - sum;
}

TEST_CASE("missing_number examples", "[missing_number]") {
  // REQUIRE(solve(...) == expected);
  REQUIRE(missing_number({0, 1, 2, 3, 4, 5, 6, 7, 8}) == 9);
  REQUIRE(missing_number({0, 1, 2, 4, 5, 6, 7, 8, 9}) == 3);
  // Could have asked clarifying question here whether or not the answer was 1,
  // since the missing element is at the end of the array in this case
  REQUIRE(missing_number({0}) == 1);
}
