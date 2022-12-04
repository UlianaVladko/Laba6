#include <iostream>
using namespace std;

class MyException :public exception {
public:
	MyException(const char* msg, int dataState) :exception(msg) {
		this->dataState = dataState;
	}
	int GetDataState() { return dataState; }
private:
	int dataState;
};

/*void Birthday(int dr) {

	if (dr < 0) {
		throw logic_error("Вы ввели отрицательное число!");
	}

	if (0 <= dr and dr< 1850) {
		//throw range_error("Что-то не верится...");
		//throw MyException("Фига ты старый...",dr);
	}

	if (dr >= 1850 and dr <= 1950) {
			throw MyException("В годы твоего рождения зародилось и развивалось программирование", dr);
		}

	if (dr > 2022) {
		throw exception("Вы ещё не родились.");
	}

	cout << "Спасибо!" << endl;
}*/

int main()
{
    setlocale(LC_ALL, "");

    int num;
    cout << "Введите цифру 1, 2 или 3\t";
    cin >> num;

    switch (num){

    case 1:
        cout << "Один"<<endl;
        break;
    case 2:
        cout << "Два"<<endl;
        break;
    case 3:
        cout << "Три"<<endl;
        break;
    default:
        std::cout << "Некорректное значение"<<endl;

    }

	int dr;
	cout << "\nВведите год рождения\t";
	cin >> dr;

	try {

		//Birthday(22);
		if (dr < 0) {
			throw logic_error("Вы ввели отрицательное число!");
		}

		if (0 <= dr and dr < 1850) {
			throw range_error("Что-то не верится...");
			//throw MyException("Фига ты старый!!!",dr);
		}

		if (dr >= 1850 and dr <= 1950) {
			throw MyException("В годы твоего рождения зародилось и развивалось программирование", dr);
		}

		if (dr > 2022) {
			throw exception("Вы ещё не родились.");
		}

		cout << "Спасибо!" << endl;

	}

	catch (logic_error& ex) {
		cout << ex.what() << endl;
	}

	/*catch (range_error& ex) {
		cout << ex.what() << endl;
	}*/

	catch (MyException& ex) {
		cout << ex.what() << endl;
		cout << "Состояние данных\t" << ex.GetDataState() << " год рождения" << endl;
	}

	catch (exception& ex) {
		cout << ex.what() << endl;
	}

	catch (char* ex) {
		cout << ex << endl;
	}

}