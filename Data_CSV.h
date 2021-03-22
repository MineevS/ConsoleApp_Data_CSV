#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <mutex>

//unsigned long long int _STR;

struct meta_data_file
{
	bool eof; // Храним состояние файла: eof = True - файл пустой. eof = False - файл не пустой.

};

struct meta_data_tab
{
	bool eof; // Храним состояние таблицы: eof = True - таблица пустая. eof = False - таблица не пустая.

	std::vector<std::string> _data_columns;// Храним данные о типе столбцов, минимальной и максимальной размере содержимого столбцов.
};

class Data_CSV
{
private:
	unsigned long long int _COLUMN = 0;	// Число столбцов в таблице.
	unsigned long long int _STRING = 0;	// Число записей в таблице.

	std::vector<std::vector<std::string>> _data; // Данные;

	meta_data_file _meta_data_file; // Храним метаданные файла.
	meta_data_tab  _meta_data_tab; // Храним метаданные таблицы.

	std::recursive_mutex _lock;

public:
	Data_CSV();
	~Data_CSV();

	Data_CSV(const Data_CSV& data_csv);
	Data_CSV& operator+(const Data_CSV& data_csv);

	Data_CSV(Data_CSV&& data_csv) noexcept;
	Data_CSV& operator+(Data_CSV&& data_csv);

	Data_CSV(const char* data_file);

	bool eof() const; // Вернуть состояние таблицы. Если пустая - true, иначе false;

	void setRecord(std::vector<std::string> str_v);

	unsigned long long int getCOLUMN() const;

	unsigned long long int getSTRING() const;

	std::recursive_mutex& getLOCK();

	std::vector<std::vector<std::string>>& getTAB() const;

	std::vector<std::string>& setMDT(std::vector<std::string> meta_data_tab);

	meta_data_tab& getMDT();

	bool CREATE_DUMP_FILE(std::string name_file, std::string name_tab);
};


