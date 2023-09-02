#include <iostream>
#include <vector>
#include <algorithm>

//template function

template <class T>
T power(T a) {
	return pow(a, 2);
}

template <class T>
std::vector <T> power(std::vector<T> vc) {
	for (auto& el : vc) {
		std::cout << power(el)<< ", ";
	}
	return vc;
}

int main() {

	int a = 4;
	std::cout << "[IN]: " << a << '\n'
			<< "[OUT]: "<< power(a) << '\n';
	std::vector<int> vi {-1, 4, 8};
	
	std::cout << "[IN]: ";
	for (auto el : vi)
		std::cout << el << ", ";
	
	std::cout << "\n[OUT]: ";
	auto y = power(vi);
	//power(vi);
	
	return 0;

}