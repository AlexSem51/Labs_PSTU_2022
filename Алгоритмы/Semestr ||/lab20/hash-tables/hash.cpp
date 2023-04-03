#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string get_random_fio();
string get_random_phone();
string get_random_date();
int get_random_number();
int sum_date(string str);

string surnames[10] = { "Петров","Иванов","Матвеев","Алексеев","Терентьев","Логинов","Шестаков","Пономарёв","Костин","Абрамов" };
string names[10] = { "Виссарион","Моисей","Евгений","Платон","Пантелей","Тимофей","Федор","Евгений","Иван","Кассиан" };
string patronymic[10] = { "Донатович","Яковлевич","Яковович","Геннадиевич","Вениаминович","Валентинович","Арсеньевич","Дмитрьевич","Антонович","Владленович" };
string phones[10] = { "73266480147","71882910822","77421674490","71122061535","72675740681","78921547279","71169111413","77503986701","79929112030","78968605764" };
string dates[10] = { "03.08.1970","11.07.1969","13.08.1967","12.11.1996","14.10.1966","17.12.1985","01.01.1981","14.04.1966","15.08.1965","16.06.1986" };
int collision_count = 0;

struct Human
{
	Human()
	{
		fio = "NULL";
		phone = "NULL";
		date = "NULL";
	}
	string fio;
	string phone;
	string date;
};

struct hash_table
{
	Human* arr;
	hash_table(int size)
	{
		arr = new Human[size];
	}
	void add(Human tmp, int size);
	void pop(string delete_date, int size);
	void search_index(string date, int size);
};

Human create_random_human()
{
	Human tmp;
	tmp.fio = get_random_fio();
	tmp.phone = get_random_phone();
	tmp.date = get_random_date();
	return tmp;
}

int hash_function(string str, int size)
{
	double f = 0.1337 * sum_date(str);
	double g = (f - int(f)) * size;
	return int(g);
}

void hash_table::add(Human tmp, int size)
{
	int idx = hash_function(tmp.date, size);
	int hash = idx;
	if (arr[idx].fio == "NULL")
	{
		arr[idx] = tmp;
		return;
	}
	else
	{
		while (idx < size)
		{
			if (arr[idx].fio == "NULL")
			{
				arr[idx] = tmp;
				return;
			}
			idx++;
			collision_count++;
		}
		if (idx >= size)
		{
			idx = 0;
			collision_count++;
			while (idx < hash)
			{
				if (arr[idx].fio == "NULL")
				{
					arr[idx] = tmp;
					return;
				}
				idx++;
				collision_count++;
			}
		}
	}
}

void hash_table::pop(string delete_date, int size)
{
	int idx = hash_function(delete_date, size);
	int hash = idx;
	if (arr[idx].date == delete_date)
	{
		arr[idx] = Human();
		return;
	}
	else
	{
		while (idx < size)
		{
			if (arr[idx].date == delete_date)
			{
				arr[idx] = Human();
				return;
			}
			idx++;
		}
		if (idx >= size)
		{
			idx = 0;
			while (idx < hash)
			{
				if (arr[idx].date == delete_date)
				{
					arr[idx] = Human();
					return;
				}
				idx++;
			}
		}
	}
}

void hash_table::search_index(string date, int size)
{
	int idx = hash_function(date, size);
	int hash = idx;
	while (arr[idx].date != date && idx < size)
	{
		idx++;
	}
	if (idx >= size)
	{
		idx = 0;
		while (arr[idx].date != date && idx < hash)
		{
			idx++;
		}
		if (idx >= hash)
		{
			cout << "Человека с датой рождения " << date << " нет " << endl;
		}
	}
	else
	{
		cout << "Человек с датой рождения " << date << " находится по индексу " << idx << endl;
	}
}

void fill_arr_of_random_humans(Human* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = create_random_human();
	}
}

void show(Human tmp)
{
	cout << "ФИО: " << tmp.fio << endl;
	cout << "Номер телефона: " << tmp.phone << endl;
	cout << "Дата рождения: " << tmp.date << endl;
}

void print_arr_of_humans(Human* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		show(arr[i]);
	}
}

void show_hash_table(hash_table* table, int size)
{
	for (int i = 0; i < size; i++)
	{
		show(table->arr[i]);
	}
}

int sum_date(string str)
{
	return stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
}

string get_random_fio()
{
	return (surnames[get_random_number()] + ' ' + names[get_random_number()] + ' ' + patronymic[get_random_number()]);
}

string get_random_phone()
{
	return phones[get_random_number()];
}

string get_random_date()
{
	return dates[get_random_number()];
}

int get_random_number()
{
	return rand() % 10;
}

int	main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int size;
	cout << "Введите количество элементов в массиве (не менее 100)" << endl;
	cin >> size;
	Human* arr = new Human[size];
	hash_table table(size);
	fill_arr_of_random_humans(arr, size);
	for (int i = 0; i < size; i++)
	{
		table.add(arr[i], size);
	}
	show_hash_table(&table, size);
	cout << endl << endl;
	table.search_index("01.01.1981", size);
	cout << endl << endl;
	table.pop("01.01.1981", size);
	cout << endl << endl;
	show_hash_table(&table, size);
	cout << endl << endl;
	cout << "Количество колизий: " << collision_count << endl;
	delete[] arr;
	return 0;
}
