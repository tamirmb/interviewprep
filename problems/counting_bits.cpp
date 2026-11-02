// counting_bits: return an array where each item is the number of 1's for a
// value's binary representation in the range of [0,n]
#include <catch_amalgamated.hpp>
#include <vector>

// Brainstorm
// Brute force: Iterate up to 'n' and convert every integer i to a string of its
// binary representation; count the number of 1's in each string and store in a
// separate array.

// Pseudocode
// vector<int> count_bits(int n)
// 1. vector<int> num_of_bits -- to store number of 1's in each number
// 2. iterate from 0 up to n inclusive
//      3. convert integer to binary string
//      4. iterate through string and count number of ones
//      5. push back value from 4 to num_of_bits
// 6. return num_of_bits

using namespace std;

string to_binary(int n) {
  string binary_string = "";
  while (n > 0) {
    int bit = n % 2;
    binary_string.push_back('0' + bit);
    n /= 2;
  }
  return binary_string;
}

vector<int> count_bits(int n) {
  vector<int> num_of_bits = {};
  for (int i = 0; i <= n; i++) {
    string in_binary = to_binary(i);
    int total_num_ones = 0;
    for (char c : in_binary) {
      if (c == '1') {
        total_num_ones += 1;
      }
    }
    num_of_bits.push_back(total_num_ones);
  }
  return num_of_bits;
}

TEST_CASE("counting_bits", "[counting_bits]") {
  // REQUIRE(solve(...) == expected);
  REQUIRE(count_bits(4) == vector<int>{0, 1, 1, 2, 1});
}

TEST_CASE("counting_bits n == 0", "[counting_bits][edge]") {
  REQUIRE(count_bits(0) == vector<int>{0});
}

TEST_CASE("counting_bits n == 1", "[counting_bits][edge]") {
  REQUIRE(count_bits(1) == vector<int>{0, 1});
}
