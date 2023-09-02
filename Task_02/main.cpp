#include <iostream>

template <class T>
class Table {
private:
	int rows_;
	int cols_;
	T** array;
	int Size() {
		return rows_ * cols_;
	};

public:
	Table(T rows, T cols) : rows_{ rows }, cols_{ cols }
	{
		array = new T*[rows_];
		for (int i = 0; i < rows_; ++i)
			array[i] = new T[cols_];
	};
	~Table() {
		for (int i = 0; i < rows_; ++i)
			delete array[i];
		delete[] array;
	};

	Table(const Table&) = delete;
	Table& operator=(const Table&) = delete;

// operator [] overload
	T* operator[](const int index)
	{
		return array[index];
	}
	const T* operator[](const int r_index) const
	{
		return array[r_index];
	};
};


int main() {

	auto test = Table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0]; // выводит 4

	Table<int> t1(2, 3);
	Table<int> t2(2, 3);
	t1 = t2;
	return 0;
}