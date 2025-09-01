
all: vector_test timing_test array_test receipt_bag_test

CXX = clang++
override CXXFLAGS += -g -Wall -Werror -std=c++17

HEADERS = MyVector.hpp MyArray.hpp ReceiptBag.hpp

vector_test: vector_test.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) vector_test.cpp -lgtest -lgtest_main -pthread -o "$@"

timing_test: timing_test.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) timing_test.cpp -o "$@"

array_test: array_test.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) array_test.cpp -o "$@"

receipt_bag_test: receipt_bag_test.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) receipt_bag_test.cpp -o "$@"

clean:
	rm -f vector_test timing_test array_test receipt_bag_test

test: all
	./vector_test
	echo "\n"
	./timing_test
	echo "\n"
	./array_test
	echo "\n"
	./receipt_bag_test
