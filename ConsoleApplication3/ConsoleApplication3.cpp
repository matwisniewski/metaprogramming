#include "pch.h"
#include <iostream>
#include <array>

constexpr int TABLE_SIZE = 10;
/**
 * Variadic template for a recursive helper struct.
 */
template<int INDEX = 0, int ...D>
struct Helper : Helper<INDEX + 1, D..., INDEX * INDEX> { };
/**
 * Specialization of the template to end the recursion when the table
size reaches TABLE_SIZE.
 */
template<int ...D>
struct Helper<TABLE_SIZE, D...> {
	static constexpr std::array<int, TABLE_SIZE> table = { D... };
};
constexpr std::array<int, TABLE_SIZE> table = Helper<>::table;
enum {
	FOUR = table[2] // compile time use
};


int main() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		std::cout << table[i] << std::endl;
	}
	std::cout << "FOUR: " << FOUR << std::endl;
	system("pause");
}
/*
constexpr int TABLE_SIZE = 20;
constexpr int OFFSET = 12;
template <typename VALUETYPE, VALUETYPE OFFSET, VALUETYPE INDEX>
struct ValueHelper {
	static constexpr VALUETYPE value = OFFSET + INDEX * INDEX;
};
/**
 * Variadic template for a recursive helper struct.
 
template<typename VALUETYPE, VALUETYPE OFFSET, int N = 0, VALUETYPE
	...D>
	struct Helper : Helper<VALUETYPE, OFFSET, N + 1, D...,
	ValueHelper<VALUETYPE, OFFSET, N>::value> { };

template<typename VALUETYPE, VALUETYPE OFFSET, VALUETYPE ...D>
struct Helper<VALUETYPE, OFFSET, TABLE_SIZE, D...> {
	static constexpr std::array<VALUETYPE, TABLE_SIZE> table = { D... };
};
constexpr std::array<uint16_t, TABLE_SIZE> table = Helper<uint16_t, OFFSET>::table;


int main() {
	// Ex. 2
	for (int i = 0; i < TABLE_SIZE; i++) {
		std::cout << table[i] << std::endl;
	}
	system("pause");
}
*/