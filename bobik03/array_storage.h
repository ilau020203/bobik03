#pragma once
#include"storage.h"
#include"iofile.h"
class array_storage
{
public:
	int n;
	storage* ptr;
	array_storage();
	~array_storage();
	int load(const char* filename);
	void save(const char* filename);
	void pushback(storage input);
	void print();
	array_storage& find_by_name();
	array_storage& find_by_num();
	array_storage& sort_by_quant();
	array_storage& sort_by_saldo();

};

