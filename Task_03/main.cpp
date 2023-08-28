#include <iostream>
#include <vector>
#include <algorithm>

//подсчитывает сумму и количество чисел, делящихся на 3.
//[IN]: 4 1 3 6 25 54
//[OUT]: get_sum() = 63
//[OUT] : get_count() = 3

class Functor{
	int sum_;
	int counter_;
public:
	Functor() : sum_{ 0 }, counter_{ 0 } {};
	~Functor() = default;

	int operator()(int el) {
		if (el % 3 == 0) {
			sum_ += el;
			counter_++;
		}
		return sum_;
	}
	int get_sum() {
		return sum_;
	}

	int get_count() {
		return counter_;
	}
};

int main() {
	std::vector<int> vInt = { 4, 1, 3, 6, 25, 54 };
	std::cout << "[IN]: ";
	std::for_each(vInt.begin(), vInt.end(), [](const int& el) {std::cout << el << " "; });

	auto a = std::for_each(vInt.cbegin(), vInt.cend(), Functor());
	std::cout << "\n[OUT]: get_sum() = " << a.get_sum();
	std::cout << "\n[OUT]: get_count() = " << a.get_count();
	return 0;
}