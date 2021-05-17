﻿// bobik03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"array_storage.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	int q = 1;
    array_storage ar;
    if (ar.load(filename_1)) {
		std::cout << "Вы первый раз зашли в программу, введите депозиты" << std::endl;
		while (q) {
			storage x;
			x.input();
			ar.pushback(x);

			std::cout << "Введите 0 ,чтобы больше никогда не вводить депозиты" << std::endl;
			std::cin >> q;
		}
    }
	do {

		std::cout << "Добавить товар 1" << std::endl;
		std::cout << "Найти по имени 2 " << std::endl;
		std::cout << "Найти по номеру  3 " << std::endl;
		std::cout << "сортировать по количеству 4" << std::endl;
		std::cout << "сортировать по сальдо 5" << std::endl;
		std::cout << "печать 6" << std::endl;

		


		std::cout << "Выйти из программы 0" << std::endl;
		std::cin >> q;

		switch (q)
		{
		case 1: {

			storage x;
			x.input();
			ar.pushback(x);
			break;
		}
		case 2:
			ar.find_by_name().print();
			break;
		case 3:
			ar.find_by_num().print();
			break;
		case 4:
			ar.sort_by_quant().print();
			break;
		case 5:
			ar.sort_by_saldo().print();
			break;
		case 6:
			ar.print();
			break;
		}
	} while (q != 0);


	ar.save(filename_1);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
