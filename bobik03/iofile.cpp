#include"iofile.h"

int loads(const char* filename, storage*& array, int& n)
{

	std::ifstream fin(filename);
	if (fin.is_open()) {
		fin >> n;

		array = new storage[n];
		for (int i = 0; i < n; i++) {
			array[i] = storage(fin);
		}
	}
	else {
		n = 0;
		fin.close();

		return 1;
	}
	fin.close();

	return 0;
}

void saves(const char* filename, storage* array, int n)
{
	std::ofstream fout(filename);
	fout << n << std::endl;

	for (int i = 0; i < n; i++) {
		array[i].save(fout);
		fout << std::endl;
	}
	fout.close();
}
