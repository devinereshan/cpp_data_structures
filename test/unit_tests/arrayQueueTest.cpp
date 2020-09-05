#include "../catch.hpp"
#include "../../ArrayQueue.h"

TEST_CASE("Queue maintains order through multiple enqueue and dequeue operations", "[arrayqueue]") {
    ArrayQueue<int> a;

    REQUIRE(a.size() == 0);

    SECTION("queue maintains order after resize") {
        for (int i = 0; i < 20; i++)
            a.enqueue(i);

        for(int i = 0; i < 20; i++)
            REQUIRE(a.dequeue() == i);
    }

    SECTION("queue maintains order through mixed operations") {
        for (int i = 0; i < 20; i++)
            a.enqueue(i);


        for (int i = 0; i < 15; i++)
            a.dequeue();

        for (int i = 20; i < 25; i++)
            a.enqueue(i);

        for (int i = 15; i < 25; i++)
            REQUIRE(a.dequeue() == i);
    }

    SECTION("peek returns expected value") {
        a.enqueue(10);
        a.enqueue(9);
        a.enqueue(8);
        a.enqueue(7);

        REQUIRE(a.peek() == 10);
        a.dequeue();
        REQUIRE(a.peek() == 9);
    }

    SECTION("queue maintains functionality through successive alternate enqueue/dequeue operations") {
        a.enqueue(0);
        for (int i = 1; i < 33; i++) {
            a.enqueue(i);
            REQUIRE(a.dequeue() == i - 1);
            REQUIRE(a.size() == 1);
        }
    }

    SECTION("queue reports correct size") {
        for (int i = 0; i < 10; i++)
            a.enqueue(i);

        REQUIRE(a.size() == 10);

        for (int i = 0; i < 7; i++)
            a.dequeue();

        REQUIRE(a.size() == 3);
    }
}