#include "../catch.hpp"
#include "../../ArrayStack.h"

TEST_CASE("Stack resizes automatically as values are added and removed", "[arraystack]") {
    ArrayStack<int> a;

    REQUIRE(a.size() == 0);
    int MIN_CAPACITY = a.capacity();

    SECTION("stack does not resize before capacity is reached") {
        for (int i = 0; i < MIN_CAPACITY - 1; i++) {
            a.push(i);
        }

        REQUIRE(a.size() == MIN_CAPACITY - 1);
        REQUIRE(a.capacity() == MIN_CAPACITY);
    }

    SECTION("stack capacity doubles when stack is full") {
        for (int i = 0; i < MIN_CAPACITY; i++) {
            a.push(i);
        }
        REQUIRE(a.size() == MIN_CAPACITY);
        REQUIRE(a.capacity() == MIN_CAPACITY * 2);
    }

    SECTION("stack capacity halves when size is reduced to 1/3 capacity") {
        for (int i = 0; i < MIN_CAPACITY; i++) {
            a.push(i);
        }

        int cap = a.capacity();
        for (int i = 0; i < cap / 3; i++) {
            a.pop();
        }

        REQUIRE(a.capacity() == MIN_CAPACITY);
    }

    SECTION("stack capacity does not fall below MIN_CAPACITY") {
        for (int i = 0; i < MIN_CAPACITY; i++) {
            a.push(i);
        }

        for (int i = 0; i < MIN_CAPACITY; i++) {
            a.pop();
        }

        REQUIRE(a.capacity() == MIN_CAPACITY);
    }
}


