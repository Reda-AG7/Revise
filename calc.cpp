#include<iostream>
#include<format>
#include<concepts>

template<class T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<typename T>
T add(T a, T b) requires Numeric<T>{
	return a + b;
}
int main() {
	int a = 10;
	int b = 15;
	std::cout<<std::format("{} + {} = {}\n", a, b, add(a,b));

}
