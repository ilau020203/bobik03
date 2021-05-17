#pragma once
#include"String.h"
#include"konfig.h"
#include"Date.h"
#include"supplier.h"
#include<iomanip>
/*
База данных: Склад (товары).
Создать класс storage со следующими элементами:
данные-члены класса:
char* name ;	(pri )   //Название товара
double price;	(pri )   // цена
int quant;	         // количество
int num;	         // номер секции
static int count;        // счетчик существующих объектов класса
функции-члены класса
1.	Создать обязательные функции, указанные в общих требованиях (МК).
2.	Создать функции для данного варианта:
•	Поиск товара по названию (МК)
•	Фильтр по номеру секции (найти изделия заданной секции) (МК)
•	Сортировать по уменьшению количества (ДФ)

*/


class storage
{
private:
	supplier base;
	double price;
	int quant;
	int num;
	Date date;
public:
	storage(const char* name = "bobik",const char *uadres="dobik" ,int type=1,double saldo =0, double price = -0.1, int quant = -1, int num = -1, int number = 1, int month = 1, int year = -1);
	storage(std::ifstream& is);
	~storage();
	void save(std::ofstream & os)const;
	int cmp_name(const storage& right)const;
	int cmp_name(const char* right)const;

	storage& operator= (const storage&);

	static void print_hedder();
	void print()const;
	void input();
	const char* get_name()const;
	int get_num()const;
	double get_saldo()const;

	double get_price()const;
	int get_quant()const;
	int friend  cmp_price(const storage& left ,const storage& right);

	static int count;
};

