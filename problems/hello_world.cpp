// hello_world: return the string "hello world" and print it.
// Example: hello_world() -> "hello world"
#include <catch_amalgamated.hpp>

#include <iostream>
#include <string>

/**
 * @brief Builds the greeting.
 * @return The string "hello world".
 */
std::string hello_world() {
    return "hello world";
}

TEST_CASE("hello_world prints and returns greeting", "[hello_world]") {
    std::cout << hello_world() << '\n';
    REQUIRE(hello_world() == "hello world");
}
