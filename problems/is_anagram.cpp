// is_anagram: identify if a word s contains the same characters as a word t
#include <catch_amalgamated.hpp>

// Brute force solution:
// Store a hashmap of seen characters as you iterate through word s.
// Remove the characters that you see as you iterate through word t.
// If the hashmap has no KV pairs left, then the two words are anagrams.
// Time complexity: O(2n), which reduces to O(n)
// Space complexity: O(n) for all characters seen

// Pseudocode:
// 1. bool is_anagram(string s, string t)
// 2. return false if strings are not the same size
// 2. unorderd_map<char, int> seen = empty unordered map to store seen chars
// 3. iterate over string s
//      4. if seen has the current character, increase its value by 1
//      5. else (if seen does not have the char), set the value to 1
// 6. iterate over t
//      7. if the current char of t is in seen decrease
//      the value by one
//        8. if the current char's value is 0, delete the key
// 10. if seen has no pairs, return true

#include <unordered_map>
#include <iostream>

using namespace std;

void print_map(unordered_map<char, int> map) {
  for(auto i : map){
    cout << i.first << ": " << i.second << endl;
  }
}

bool is_anagram(string s, string t) {
  // Strings are not guaranteed to be the same, so check first
  if(s.length() != t.length()) return false;

  unordered_map<char, int> seen = {};
  for (char c : s) {
    if(seen[c]){
      seen[c] += 1;
    } else {
      seen[c] = 1;
    }
  }

  for(char c : t) {
    if(seen[c] > 0){
      seen[c] -= 1;
      if(seen[c] == 0){
        seen.erase(c);
      }
    }
  }
  return seen.empty();
}

TEST_CASE("is_anagram examples", "[is_anagram]") {
  // REQUIRE(solve(...) == expected);
  REQUIRE(is_anagram("raj", "jar") == true);
  REQUIRE(is_anagram("racecar", "carrace") == true);
  REQUIRE(is_anagram("jam", "jar") == false);
}

TEST_CASE("is_anagram edge cases", "[is_anagram][edge]") {
  REQUIRE(is_anagram("x", "x") == true);
  REQUIRE(is_anagram("x", "y") == false);
  REQUIRE(is_anagram("abc", "y") == false);
}
