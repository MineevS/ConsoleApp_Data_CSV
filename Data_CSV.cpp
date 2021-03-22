#include "Data_CSV.h"
#include "str_switch.h"
#include <windows.h>
#include <sstream>
#include <thread>

Data_CSV::Data_CSV()
{
}

Data_CSV::~Data_CSV()
{
}

Data_CSV::Data_CSV(const Data_CSV& data_csv)
{
}

Data_CSV& Data_CSV::operator+(const Data_CSV& data_csv)
{
    // TODO: вставьте здесь оператор return

    return *this;
}

Data_CSV::Data_CSV(Data_CSV&& data_csv) noexcept
{
}

Data_CSV& Data_CSV::operator+(Data_CSV&& data_csv)
{
    // TODO: вставьте здесь оператор return

    return *this;
}

void func_1(std::string& str) {

    if (!str.empty()) {

        if (str[0] == '\"') {

            str.erase(0, 1);
            func_1(str); // Если сначала удалится первый ", то рекуксивно удалится и конечный ".
        }
        else if (str[str.size() - 1] == '\"') {

            str.erase(str.size() - 1, 1);
            func_1(str);
        }
        else if (str[0] == '"') {

            str.erase(0, 1);
            func_1(str);
        }
        else if (str[str.size() - 1] == '"') {

            str.erase(str.size() - 1, 1);
            func_1(str);
        }
        else if (str == " ")
        {
            str = "-";
        }
    }
    else if (str == "") {
    
    
    }else{
    
        str = "-";
    }

}

std::ostream& operator<<(std::ostream& ost, std::ifstream& ifs) {

	if (!ifs.eof()) {

		size_t pos = ifs.tellg(); // Получение  текущую позицию в файле, чтобы потом снова к ней вернуться.

		ifs.seekg(0, std::ios::end);
		unsigned long long int size = ifs.tellg();
		ifs.seekg(0, std::ios::beg);

		char* str = new char[size]();

		ifs.read(str, size);

		ost << str << std::endl;

		delete[] str;

		ifs.clear();    // Очистка eof() состояния;
		ifs.seekg(pos); // Установка абсолютной позиции pos.
	}

	return ost;
}

void func_3(std::string& str, std::ifstream& ifs) {

    if ((str[0] == '\"') and ((str[str.size() - 1] == '\"') or (str[str.size() - 1] == ' ') or ((str[str.size() - 1] == '0') or ((str[str.size() - 1] == 'я'))))) //- // or (str[str.size() - 1] == ' ') or (str[str.size() - 1] == ';'))
    {
        //...
    }
    else if(str[0] == '\"')
    {
        std::string str_a;
        std::getline(ifs, str_a);
    
        str += '\+';
        str += str_a;

        func_3(str, ifs);
    }
}

std::vector<std::string>& delim_1(std::string& str_1, std::vector<std::string>& str_v_1) {

    std::string delimiter = "\",\"";
    std::string token;

    size_t pos = 0;

    while (((pos = str_1.find(delimiter)) != std::string::npos)) {
        
        token = str_1.substr(0, pos);
        

        if (token.size() >= 15) {

            //std::cout << token[0];
            //std::cout << token[1];
            //std::cout << token[14];
            //std::cout << token[15];

        }

        while ((count(token.begin(), token.end(), '\"')) % 2 == 1) {

            std::stringstream strf(str_1);
            std::string str_c_1;
            std::getline(strf, str_c_1, '\"');
            str_c_1 += '\"';

            std::string str_c_2;
            std::getline(strf, str_c_2, '\n');

            str_1 += (str_c_1 + str_c_2);


        }
        
        /*
        while (((count(token.begin(), token.end(), '\"') - (count(token.begin(), token.end(), '\"\"') % 2 == 1)) % 2 == 1) ) {

            std::stringstream strf(str_1);
            std::string str_c_1;
            std::getline(strf, str_c_1, '\"');
            str_c_1 += '\"';

            std::string str_c_2;
            std::getline(strf, str_c_2, '\n');

            str_1 += (str_c_1 + str_c_2);

        
        }*/

        func_1(token);
        
        size_t pos_3 = 0;
        std::string token_2;
        std::string del= ",\"";

        if ((pos_3 = token.find(del)) != std::string::npos) {
        
            token_2 = str_1.substr(0, pos_3 + 1);
            func_1(token_2);

            size_t pos_6;
            std::string token_4;

            if ((pos_6 = token_2.find("\",")) != std::string::npos) {
            
                token_4 = token_2.substr(0, pos_6);
                func_1(token_4);

                str_v_1.push_back(token_4);
                //std::cout << token_4 << std::endl;
            
                token_2 = token_2.substr(pos_6 + 2);
            }

            str_v_1.push_back(token_2);
            //std::cout << token_2 << std::endl;

            token = token.substr(pos_3 + 2);
        }

        func_1(token);
        str_v_1.push_back(token);
        //std::cout << token << std::endl;

        str_1.erase(0, pos + delimiter.length());
    }

    std::string delim = "\";";
    size_t pos_2 = 0;

    while ( (pos_2 = str_1.find(delim)) != std::string::npos) {
    
        token = str_1.replace(pos_2, str_1.length() - pos_2, "");
        //token = str_1.substr(0, pos);
        

        std::string delim_4 = "\",";
        size_t pos_4 = 0;

        if ((str_1.find(delim_4)) != std::string::npos) {
            
            while ((pos_4 = str_1.find(delim_4)) != std::string::npos) {

                token = token.replace(pos_4, token.length() - pos_4, "");
                //token = str_1.substr(0, pos);
                func_1(token);
                str_v_1.push_back(token);
                //std::cout << token << std::endl;
                str_1.erase(0, pos_4 + delim_4.length());
            }
        }
        else {

            func_1(token);
            str_v_1.push_back(token);

            //std::cout << token << std::endl;
            str_1.erase(0, pos_2 + delim.length());
        
        }
    }

    if (isalnum(str_1[0]) == (isalpha(str_1[0])) and (strcmp(str_v_1[str_v_1.size() - 1].c_str(), str_1.c_str()) == 1)) {
    
        func_1(str_1);
        str_v_1.push_back(str_1);
        str_1.erase(0, str_1.length());
    
    }

    bool fl_2 = false;
    for (size_t i = 0; i < str_1.length(); i++) {
    
        if (isalnum(str_1[i])) {

            fl_2 = true;

            break;
        }
    }

    if (!fl_2) {
    
        str_1.clear();
    }

    return str_v_1;
}

std::vector<std::string>& delim_2(std::string& str_1, std::vector<std::string>& str_v_1) {

    std::string delim_2 = "\",";
    std::string tok_2;
    size_t pos_2;

    while ((pos_2 = str_1.find(delim_2)) != std::string::npos) {

        tok_2 = str_1.substr(0, pos_2);
        func_1(tok_2);
        str_v_1.push_back(tok_2);
        //std::cout << tok_2 << std::endl;
        str_1.erase(0, pos_2 + delim_2.length());//
    }

    return str_v_1;
}

std::vector<std::string>& delim_3(std::string& str_1, std::vector<std::string>& str_v_1, int& FLAG_1) {

    std::string delim_3 = ",";
    std::string tok_3;
    size_t pos_3;

    while (((pos_3 = str_1.find(delim_3)) != std::string::npos) && ((str_1.find('\"') == std::string::npos))) {

        tok_3 = str_1.substr(0, pos_3);
        func_1(tok_3);
        str_v_1.push_back(tok_3);
        //std::cout << tok_3 << std::endl;
        str_1.erase(0, pos_3 + delim_3.length());//
        FLAG_1 = 2;
    }

    return str_v_1;
}

std::vector<std::string>& delim_3_1(std::string& str_1, std::vector<std::string>& str_v_1, int& FLAG_1) {

    std::string delim_3 = ",";
    std::string tok_3;
    size_t pos_3;
    bool fl = false;

    while (((pos_3 = str_1.find(delim_3)) != std::string::npos)) {

        tok_3 = str_1.substr(0, pos_3);

        if (count(tok_3.begin(), tok_3.end(), '\"') % 2 == 1) {
        
            std::string str_c_1;

            std::stringstream fil(str_1);

            std::getline(fil, str_c_1, '\"');
            //str_c_1 += '\"';

            std::string str_c_2;
            std::getline(fil, str_c_2, '\n');

            std::stringstream st(str_c_2);
            std::getline(st, str_c_1, '\"');
            //str_c_1 = '\"';

            tok_3 = str_c_1;
            fl = true;
        
        }

        func_1(tok_3);
        str_v_1.push_back(tok_3);
        //std::cout << tok_3 << std::endl;
        if (fl == true) {
            str_1.erase(0, pos_3 + delim_3.length() + tok_3.length());//
            fl = false;
        }
        else {
            str_1.erase(0, pos_3 + delim_3.length());//
        
        }
       

        FLAG_1 = 2;
    }

    return str_v_1;
}

std::vector<std::string>& delim_4(std::string& str_1, std::vector<std::string>& str_v_1, int& FLAG_1) {

    std::string delim_5 = ";";
    std::string tok_5;
    size_t pos_5;

    while ((pos_5 = str_1.find(delim_5)) != std::string::npos) {

        tok_5 = str_1.substr(0, pos_5);
        func_1(tok_5);
        str_v_1.push_back(tok_5);
        //std::cout << tok_5 << std::endl;
        str_1.erase(0, pos_5 + delim_5.length());//
        FLAG_1 = 1;
    }

    return str_v_1;
}

void ParSER_v1_0(std::ifstream& file, Data_CSV* tab) 
{
    int FLAG_1 = 0;
    std::string str_1;

     
    while (std::getline(file, str_1, (char)'\n')) // Обработка каждой строчки.
    {
        tab->getLOCK().lock();
        std::vector<std::string> str_v_1;

        //std::cout << str_1 << std::endl;

        while(count(str_1.begin(), str_1.end(), '\"') % 2 == 1) {
            
            std::string str_c_1;
            std::getline(file, str_c_1, '\"');
            str_c_1 += '\"';

            std::string str_c_2;
            std::getline(file, str_c_2, '\n');

            str_1 += (str_c_1 + str_c_2);
        }

        /*
            A | B | C    | D
            A | B |\" C1 | 
              |   | C2   | 
              |   | C3 \"| D
            A | B | C    | D
        */

        /*
        * Требуется рассмотреть случаи:
        * Когда внешним разделителем на ячейки является знак ","
        * Когда внешним разделителем на ячейки является знак "\","
        * Когда внешним разделителем на ячейки является знак "\",\"" // +
        * Когда внешним разделителем на ячейки является знак ";" //+
        */

        /*
        size_t r = tab->getSTRING();
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, (( 4 << 4) | 0));
        std::cout << "[ " << r << " ]";
        SetConsoleTextAttribute(h, (( 0 << 4) | 15));
        std::cout << std::endl;
        */
        
        if (FLAG_1 == 0) {

            delim_1(str_1, str_v_1);//+
            delim_2(str_1, str_v_1);
            delim_3(str_1, str_v_1, FLAG_1);
            delim_4(str_1, str_v_1, FLAG_1);
        }
        else if(FLAG_1 == 1){

            delim_4(str_1, str_v_1, FLAG_1);

            if (FLAG_1 == 1) {

                func_3(str_1, file);//+
                delim_4(str_1, str_v_1, FLAG_1);
            }
        }
        else if(FLAG_1 == 2) {
        
            delim_3_1(str_1, str_v_1, FLAG_1);

            if (FLAG_1 == 2) {

                func_3(str_1, file);//+
                delim_3(str_1, str_v_1, FLAG_1);
            }
        }

        func_1(str_1);

        if (!(str_1 == "")) {

            //std::cout << str_1 << std::endl;
            str_v_1.push_back(str_1);
        }
        
        tab->setRecord(str_v_1);

        tab->getLOCK().unlock();
    }
}

void f_thread(Data_CSV* tab) 
{
    int x = 0;

    tab->getLOCK().lock();
    std::cout << "\x1b[6;32;40mИдет загрузка данных !\x1b[0m";
    system("cls");
    x = tab->getSTRING();
    std::cout << "\x1b[6;31;40mИдет загрузка данных !\x1b[0m";
    tab->getLOCK().unlock();
    //system("cls");
    //std::cout << tab->getSTRING() << std::endl;
    system("cls");

    while (x != tab->getSTRING()) {
    
        tab->getLOCK().lock();
        std::cout << "\x1b[6;32;40mИдет загрузка данных !\x1b[0m";

        if (tab->getSTRING() % 150 == 1) {
            
            system("cls");
        }
        
        x = tab->getSTRING();
        //std::cout << "\x1b[6;31;40mИдет загрузка данных !\x1b[0m";
        tab->getLOCK().unlock();
        //system("cls");
        //std::cout << tab->getSTRING() << std::endl;
        system("cls");
    }

    std::cout << "Загружено записей: " << tab->getSTRING() << std::endl;
}

void Analiz_tab(Data_CSV& data_csv)
{
    auto tab = data_csv.getTAB();

    //
    std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
                          "абвгдеёжщийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

    std::vector<std::string> _meta_data;
   //
    for (auto ta : tab) {

        if (ta == tab[0]) {
            continue;
        }
        else {
            size_t _i = 0;

            for (auto sa : ta) {

                ++_i;

                if (_i > data_csv.getCOLUMN())
                {
                    continue;
                }

                std::string letters_2 = "0123456789";
                std::string data_delim = "- ; :";
            
                if ((sa.find_first_of(letters) != std::string::npos)) // Проверка на RU, EN
                {
                    if (ta == tab[1]) {
                        _meta_data.push_back("VARCHAR");//type
                    }
                    //_meta_data.push_back("STRING");//type
                } else if ((sa.find_first_of(letters_2) != std::string::npos) and (sa.find_first_of(letters) == std::string::npos) and (sa.find_first_of(data_delim) == std::string::npos)) // Проверка на числа
                {
                    if (ta == tab[1]) {
                        _meta_data.push_back("NUMERIC");//type
                    }
                } else if ((sa.find_first_of(letters_2) != std::string::npos) and (sa.find_first_of(data_delim) != std::string::npos)) // Проверка на числа
                {
                    if (ta == tab[1]) {
                        _meta_data.push_back("TIMESTAMP");//type
                    }
                }

                if (ta == tab[1]) {

                        int size = sa.length();
                        char* buff_1 = new char[std::to_string(size).length() + 1];
                        _itoa_s(size, buff_1, std::to_string(size).length() + 1, 10);

                        _meta_data.push_back(buff_1);//min
                        _meta_data.push_back(buff_1);//max 
                }
                else {
                    
                    // _i - номер триплета в _meta_data.

                    if (atoi(_meta_data[3*_i - 2].c_str()) > sa.length()) // MIN
                    {
                        int size = sa.length();
                        char* buff_1 = new char[std::to_string(size).length() + 1];
                        _itoa_s(size, buff_1, std::to_string(size).length() + 1, 10);

                        _meta_data[3 * _i - 2] = buff_1;
                    }

                    if (atoi(_meta_data[3 * _i - 1].c_str()) < sa.length()) // MAX
                    {
                        int size = sa.length();
                        char* buff_1 = new char[std::to_string(size).length() + 1];
                        _itoa_s(size, buff_1, std::to_string(size).length() + 1, 10);

                        _meta_data[3 * _i - 1] = buff_1;
                    }
                }
            }
        }
    }

    data_csv.setMDT(_meta_data);
}

Data_CSV::Data_CSV(const char* data_file)
{
    std::ifstream file(data_file);

    if (!file.is_open()) {
    
        _meta_data_file.eof = file.eof();
        _meta_data_tab.eof = file.eof();
    }
    else if(!(_meta_data_file.eof = file.eof())) 
    {
        //std::cout << file << std::endl; // Проверка

        std::thread  thread_1(f_thread, this); // Сообщение о загрузки
        std::thread thread_2(ParSER_v1_0, std::ref(file), this); // Загрузка данных

        thread_1.join();
        thread_2.join();

        //ParSER_v1_0(file, this);

        Analiz_tab(*this);

        this->_meta_data_tab.eof = false;
    }

    file.close();
}

bool Data_CSV::eof() const
{
    return this->_meta_data_tab.eof;
}

void Data_CSV::setRecord(std::vector<std::string> str_v)
{
    this->_STRING++;
    this->_COLUMN = str_v.size();
    this->_data.push_back(str_v);
}

unsigned long long int Data_CSV::getCOLUMN() const
{
    return this->_COLUMN;
}

unsigned long long int Data_CSV::getSTRING() const
{
    return this->_STRING;
}

std::recursive_mutex& Data_CSV::getLOCK()
{
    // TODO: вставьте здесь оператор return
    return this->_lock;
}

std::vector<std::vector<std::string>>& Data_CSV::getTAB() const
{
    // TODO: вставьте здесь оператор return

    return const_cast<std::vector<std::vector<std::string>>&>(this->_data);
}

std::vector<std::string>& Data_CSV::setMDT(std::vector<std::string> meta_data_tab)
{
    // TODO: вставьте здесь оператор return
    return this->_meta_data_tab._data_columns = meta_data_tab;
}

meta_data_tab& Data_CSV::getMDT()
{
    // TODO: вставьте здесь оператор return
    return this->_meta_data_tab;
}

bool Data_CSV::CREATE_DUMP_FILE(std::string name_file, std::string name_tab)
{
    std::ofstream file(name_file + ".sql");

    std::string Create_begin = "CREATE TABLE " + name_tab + " (\n";
    std::string Create_end = ");";

    file << Create_begin; // Записываем CREATE TABLE

    this->getTAB()[0];// Заголовок таблицы

    size_t _i = 0;

    for (auto COLUMN: this->getTAB()[0]) {
    
        ++_i;

        if (_i < this->getCOLUMN()) {
        
            file << COLUMN;
            file << " ";
            file << this->_meta_data_tab._data_columns[3 * (_i - 1)];
            file << ",\n";
        }
        else {


            file << COLUMN;

            if (COLUMN != "") {
                file << " ";
                file << this->_meta_data_tab._data_columns[3 * (_i - 1)];
                file << "\n";
            } 
        }
    }

    file << Create_end;
    file << "\n";
    //

    std::string INSERT_INTO = "INSERT INTO";
    std::string VALUES = "VALUES";

    file << INSERT_INTO;
    file << " ";
    file << name_tab;
    file << " ";
    file << VALUES;
    file << " " << "(";



    //
    for (auto COLUMN : this->getTAB()[1]) {
    
        std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "абвгдеёжщийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        std::string letters_2 = "0123456789";
        std::string data_delim = "- ; :";

        if (COLUMN != this->getTAB()[1][0]) {
            file << ",";
        }

        if ((COLUMN.find_first_of(letters) != std::string::npos)) // Проверка на RU, EN
        {

               // _meta_data.push_back("VARCHAR");//type

            file << "'" << COLUMN << "'";

        }
        else if ((COLUMN.find_first_of(letters_2) != std::string::npos) and (COLUMN.find_first_of(letters) == std::string::npos) and (COLUMN.find_first_of(data_delim) == std::string::npos)) // Проверка на числа
        {
            file << COLUMN;
                //_meta_data.push_back("NUMERIC");//type
        }
        else if ((COLUMN.find_first_of(letters_2) != std::string::npos) and (COLUMN.find_first_of(data_delim) != std::string::npos)) // Проверка на числа
        {
            file << "'" << COLUMN << "'";
                //_meta_data.push_back("TIMESTAMP");//type
        }
    }

    file << ");";


    return false;
}
