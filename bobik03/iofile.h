#pragma once
#include<fstream>	
#include"storage.h"
int loads(const char* filename, storage*& array, int& n);
void saves(const char* filename, storage* array, int n);
