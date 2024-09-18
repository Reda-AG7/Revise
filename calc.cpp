#include<iostream>
#include<format>
#include<concepts>

template<class T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<typename T>
T add(T a, T b) requires Numeric<T>{
	return a + b;
}
template<typename T>
T devide(T a, T b) requires Numeric<T>{
	if (b == 0) throw std::format("Denominator cannot be zero");
	return a / b;
}

template<typename T>
T sub(T a, T b) requires Numeric<T>{
	return a - b;
}

int main() {
	int a = 10;
	int b = 0;
	std::cout<<std::format("{} + {} = {}\n", a, b, add(a,b));
	std::cout<<std::format("{} - {} = {}\n", a, b, sub(a,b));
	try{
		int x = devide(a,b);
		std::cout<<std::format("{} / {} = {}\n", a, b, x); 
	}
	catch(std::string error){
		std::cout<<error<<std::endl;
	}
}
