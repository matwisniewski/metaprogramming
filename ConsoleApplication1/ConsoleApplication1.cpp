#include "pch.h"
#include <iostream>

template <int N> class Factorial {
	public: enum
	{
		value = N*Factorial<N-1>::value
	};
};

template <> class Factorial<1>
{
	public: enum {
		value=1
	};
};

inline void swap(int & a, int & b) {
	int temp = a;
	a = b;
	b = temp;
}

template < int I, int J >
class IntSwap 
{
	public: static inline void compareAndSwap(int * data)
	{
		if (data[I] > data[J]) swap(data[I], data[J]);
	}
};

template < int I, int J >
class IntBubbleSortLoop 
{
	private: enum
	{
		go = (J <= I - 2)
	};
	public: static inline void loop(int * data)
	{
		IntSwap < J, J + 1 > ::compareAndSwap(data);
		IntBubbleSortLoop < go ? I : 0, go ? (J + 1) : 0 > ::loop(data);
	}
};

template < >
class IntBubbleSortLoop < 0, 0 >
{
	public: static inline void loop(int *) {}
};

template < int N >
class IntBubbleSort
{
	public: static inline void sort(int * data) 
	{
		IntBubbleSortLoop < N - 1, 0 > ::loop(data);
		IntBubbleSort < N - 1 > ::sort(data);
	}
};

template < >
class IntBubbleSort < 1 > 
{
	public: static inline void sort(int * data) {}
};

template < int IIn, int ISum = 1 >
struct Factorial : Factorial < IIn - 1, IIn * ISum > {};

template<int ISum>
struct Factorial<1, ISum> {
	enum { value = ISum };
};


template<int N>
class countBits {
	enum {
		bit3 = (N & 0x08) ? 1 : 0,
		bit2 = (N & 0x04) ? 1 : 0,
		bit1 = (N & 0x02) ? 1 : 0,
		bit0 = (N & 0x01) ? 1 : 0
	};
	public:
		enum { nbits = bit0 + bit1 + bit2 + bit3 };
};

#define _USE_MATH_DEFINES
#include <math.h>
template < int N, int I, int J, int K > class SineSeries {
	public: enum {
		go = (K + 1 != J)
	};
	static inline float accumulate() {
		return 1 - (I * 2 * M_PI / N) * (I * 2 * M_PI / N) / (2 * K + 2) / (2 * K + 3) * SineSeries < N * go, I * go, J * go, (K + 1) * go > ::accumulate();
	}
};

template < > class SineSeries < 0, 0, 0, 0 > {
	public: static inline float accumulate() {
		return 1;
	}
};
template < int N, int I > class Sine {
	public: static inline float sin() {
		return (I * 2 * M_PI / N) * SineSeries < N, I, 10, 0 > ::accumulate();
	}
};

template < size_t N, class T > class DotProduct {
	public: static T eval(T * a, T * b) {
		return DotProduct < 1, T > ::eval(a, b) + DotProduct < N - 1, T > ::eval(a + 1, b + 1);
	}
};
template < class T > class DotProduct < 1, T > {
	public: static T eval(T * a, T * b) {
		return (*a) * (*b);
	}
};

template < size_t N, class T > inline T dot(T * a, T * b) {
	return DotProduct < N, T > ::eval(a, b);
}

#include <ctime>
#include <windows.h>

int factorial(int n) {
	if ((n == 0) || (n == 1))
		return 1;
	else
		return n * factorial(n - 1);
}

int main()
{
    std::cout << Factorial<5>::value << "\n"; 
	system("pause");

	int array[4] = { 9, 2, 7, 6 };
	IntBubbleSort<4>::sort(array);
	for (int i = 0; i < 4; i++) {
		std::cout << array[i] << "\n";
	}
	system("pause");
	
	int i = Factorial<4>::value;
	std::cout << i << "\n";
	system("pause");

	int i = countBits<13>::nbits;
	std::cout << i << "\n";
	system("pause");
	
	float i = Sine<32, 5>::sin();
	std::cout << i << "\n";
	system("pause");
	
	int x[4] = { 1,100,0,-1 };
	int y[4] = { 2, 2, 2, 2 };
	std::cout << dot<4>(x, y) << "\n";
	system("pause");

	clock_t start_t1 = clock();
	std::cout << Factorial<16>::value;
	clock_t end_t1 = clock();
	std::cout << std::endl << float(end_t1 - start_t1) / 1000 << " sec\n";
	clock_t start_t2 = clock();
	std::cout << factorial(16);
	clock_t end_t2 = clock();
	std::cout << std::endl << float(end_t2 - start_t2) / 1000 << " sec\n";
	system("pause");
}