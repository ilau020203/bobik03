#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h> 
const std::string dockx_file_path = "C:/Users/Huawei60/Downloads/azszs.docx";

bool chek_file(std::string fileName) {
	std::ifstream file(fileName);
	if (!file) return false;
	file.close();
	return true;
}

std::vector<char> read(std::string fileName) {
	if (!chek_file(fileName)) std::cout << "FileName Error!" << std::endl;
	std::vector<char> buff;
	std::ifstream file(fileName, std::ios::in | std::ios::binary);
	char byte;
	while (file) {
		file.read(&byte, 1);
		if (file.fail()) {
			if (!file.eof()) std::cout << "Input error" << std::endl;
			break;
		}
		buff.push_back((char)byte);
	}
	file.close();
	return buff;
}

void read_file_and_print(std::string file_name) {
	std::vector<char> file = read(file_name);
	std::cout << file.size() << std::endl;
	for (size_t i = 0; i < file.size(); i++) {
		std::cout << file[i];
	}
}

void create_file(std::string file_name, std::string content) {
	std::ofstream fout(file_name);
	fout << content;
	fout.close();
}

void ex1() {
	std::vector<char> file_bytes = read(dockx_file_path);
	std::cout << file_bytes.size() << " bytes" << std::endl;
}

void ex2() {
	std::vector<char> file_bytes = read(dockx_file_path);
	std::map<char, float> frequencies;
	for (auto item : file_bytes) {
		auto it = frequencies.find(item);
		float frequency;
		if (it == frequencies.end()) {
			frequency = 0;
		}
		else {
			frequency = (*frequencies.find(item)).second;
		}
		frequency++;
		frequencies.emplace(item, frequency);
		std::cout << frequency;
	}
}

int main()
{
	std::cout << "Ex_1\n";
	ex1();
	std::cout << "EX_2\n";
	ex2();

}
