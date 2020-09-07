TEST_FILES=./test/*.cpp ./test/unit_tests/*.cpp

.PHONY: build
build:
	g++ -std=c++11 -o ./build/UnitTest $(TEST_FILES) $(OBJECT_FILES)

debug:
	g++ -g -std=c++11 -o ./build/UnitTest $(TEST_FILES) $(OBJECT_FILES)


clean:
	rm ./build/UnitTest

install:
	mkdir -p build

dlltest:
	g++ -g -std=c++11 -o ./build/DLLTest DoublyLinkedList.h ./test/unit_tests/dlltest.cpp