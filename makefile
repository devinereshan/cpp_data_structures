TEST_FILES=./test/*.cpp ./test/unit_tests/*.cpp

.PHONY: build
build:
	mkdir -p build &&\
	g++ -std=c++11 -o ./build/UnitTest $(TEST_FILES) $(OBJECT_FILES)

clean:
	rm ./build/UnitTest
