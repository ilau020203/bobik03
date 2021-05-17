#include "array_storage.h"

array_storage::array_storage()
{
	ptr = nullptr;
	n = 0;
}

array_storage::~array_storage()
{
	delete[] ptr;
}

int array_storage::load(const char* filename)
{
	return loads(filename, this->ptr, this->n);
}

void array_storage::save(const char* filename)
{
	saves(filename, this->ptr, n);
}

void array_storage::pushback(storage input)
{
	this->n += 1;
	storage* ar = new storage[this->n];
	for (int i = 0; i < this->n - 1; i++) {
		ar[i] = this->ptr[i];
	}
	ar[this->n - 1] = input;
	this->ptr = ar;
}

void array_storage::print()
{
	storage::print_hedder();
	for (int i = 0; i < n; i++) {
		 this->ptr[i].print();
	}

}

array_storage& array_storage::find_by_name()
{
	char buf[256];
	std::cout << "input name" << std::endl;
	std::cin >> buf;
	array_storage out;
	for (int i = 0; i < n; i++) {
		if (ptr[i].cmp_name(buf) == 0)
		{
			out.pushback(ptr[i]);
		}
	}
	return out;
}

array_storage& array_storage::find_by_num()
{
	int buf;
	std::cout << "input num" << std::endl;
	std::cin >> buf;
	array_storage out;
	for (int i = 0; i < n; i++) {
		if (ptr[i].get_num()==buf)
		{
			out.pushback(ptr[i]);
		}
	}
	return out;
}

array_storage& array_storage::sort_by_quant()
{
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (ptr[i].get_quant() < ptr[j].get_quant()) {
				storage q = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = q;
			}
		}
	}
	return *this;
}

array_storage& array_storage::sort_by_saldo()
{
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (ptr[i].get_saldo() < ptr[j].get_saldo()) {
				storage q = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = q;
			}
		}
	}
	return *this;
}

