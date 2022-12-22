
#include <iostream>
using namespace std;

void separator() {
    cout << "---------------------" << endl;
}

enum class Exception :int {
    Range,
    Future,
    NEGNUM,
};

class BirthdayException : public std::exception {
private:
    Exception year;

public:
    BirthdayException(Exception year) : year(year) {}    

    const char* what() const throw() override
    {
        if (year == Exception::Range)
        {
            return "Что-то не верится...\n";            
        }

        if (year == Exception::Future)
        {
            return "Вы ещё не родились\n";            
        }

        if (year == Exception::NEGNUM)
        {
            return "Вы ввели отрицательное число!\n";            
        }        
    }
};

enum class MyException :int {
    Range2,
    Future2,
    NEGNUM2,
};

class BirthdayMyException : public std::exception
{
private:
    MyException year2;

public:
    BirthdayMyException(MyException year2) : year2(year2) {}

    const char* what() const throw() override
    {
        if (year2 == MyException::Range2)
        {
            return "Хммм...долгожитель. Может ты из Японии?\n";
        }

        if (year2 == MyException::Future2)
        {
            return "Смешно, смешно...\n";
        }

        if (year2 == MyException::NEGNUM2)
        {
            return "Вампир!\n";
        }
    }
};

int main()
{
    setlocale(LC_ALL, "");

    try {

        int num;

        cout << "Введите цифру 1, 2 или 3\t";
        cin >> num;

        switch (num) {

        case 1:
            cout << "Один" << endl;
            break;
        case 2:
            cout << "Два" << endl;
            break;
        case 3:
            cout << "Три" << endl;
            break;
        default:
            std::cout << "Некорректное значение" << endl;
        }
    }

    catch (const char* error)
    {
        cout << error << endl;
    }

    separator();

    try
    {        
        int year;

        cout << endl<<"Класс исключений с перечислением (условия преподавателя)" << endl << endl;

        cout <<"Введите дату рождения\t";
        cin >> year;
                
        if (year >= 0 && year < 1850)
        {
            throw BirthdayException(Exception::Range);
        }
               
        if (year > 2022)
        {
            throw BirthdayException(Exception::Future);
        }
                
        if (year < 0)
        {
            throw BirthdayException(Exception::NEGNUM);
        }

        cout << "Спасибо!" << endl;        
    }
    catch (BirthdayException& error)
    {
        cout << error.what();

    }

    separator();

    try
    {
        int year2;

        cout << endl << "Класс исключений с перечислением (собственные условия)" << endl << endl;

        cout << "Введите дату рождения\t";
        cin >> year2;

        if (year2 >= 1900 && year2 < 1957)
        {
            throw BirthdayMyException(MyException::Range2);
        }

        if (year2 > 2022)
        {
            throw BirthdayMyException(MyException::Future2);
        }

        if (year2 < 1890)
        {
            throw BirthdayMyException(MyException::NEGNUM2);
        }

        cout << "Спасибо!" << endl;
    }
    catch (BirthdayMyException& error)
    {
        cout << error.what();

    }

    return 0;
}

