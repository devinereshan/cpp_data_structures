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

}