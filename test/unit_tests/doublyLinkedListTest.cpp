#include "../catch.hpp"
#include "../../DoublyLinkedList.h"

TEST_CASE("Class methods exhibit appropriate behaviour", "[doublylinkedlist]") {
    DoublyLinkedList<int> d;

    REQUIRE(d.size() == 0);

    SECTION("Adding values to list increases size") {
        d.add(5, 0);

        REQUIRE(d.size() == 1);

        d.add(10, 1);

        REQUIRE(d.size() == 2);

        d.add(11, 2);

        REQUIRE(d.size() == 3);
    }

    SECTION("Removing values decreases size") {
        for (int i = 0; i < 10; i++)
            d.add(i, i);

        REQUIRE(d.size() == 10);

        d.remove(0);
        REQUIRE(d.size() == 9);

        d.remove(0);
        REQUIRE(d.size() == 8);

        d.remove(0);
        REQUIRE(d.size() == 7);

        d.remove(0);
        REQUIRE(d.size() == 6);
    }

    SECTION("Can set values without changing size") {
        for (int i = 0; i < 10; i++)
            d.add(i, 0);

        REQUIRE(d.size() == 10);

        d.set(20, 0);
        REQUIRE(d.size() == 10);

        d.set(20, 1);
        REQUIRE(d.size() == 10);

        d.set(20, 3);
        REQUIRE(d.size() == 10);
    }

    SECTION("Get and remove return the expected value") {
        d.add(0, 0);
        d.add(1, 1);
        d.add(2, 2);

        REQUIRE(d.get(2) == 2);
        REQUIRE(d.remove(2) == 2);

        d.add(3, 2);
        REQUIRE(d.get(2) == 3);
        REQUIRE(d.remove(2) == 3);
        REQUIRE(d.get(1) == 1);
        REQUIRE(d.remove(1) == 1);
        REQUIRE(d.get(0) == 0);
        REQUIRE(d.remove(0) == 0);
    }
}