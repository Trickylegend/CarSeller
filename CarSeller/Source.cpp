#include"Header.h"
#include "SmartPointer.cpp"
#include "Auth.h"

vector<Bike> b;
vector<Car> c;
vector<Truck> t;

class Vehicle
{
private:
	string name, color;
	int stock, horsepower;
	string description;
	double price;
public:
	void set_price(double x)
	{
		price = x;
	}
	void set_color(string c) {
		color = c;
	}
	void set_name(string n) {
		name = n;
	}
	void set_stock(int s) {
		stock = s;
	}
	void set_horsepower(int h) {
		horsepower = h;
	}
	void set_description(string d) {
		description = d;
	}
	double get_price()
	{
		return price;
	}
	string get_color() {
		return color;
	}
	string get_name() {
		return name;
	}
	int get_stock() {
		return stock;
	}
	int get_horsepower() {
		return horsepower;
	}
	string get_description() {
		return description;
	}
	virtual void getdata() = 0;
};
class Bike :public Vehicle
{
public:
	void getdata()
	{
		string x;
		int y;
		double z;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n\t\t\tВведите название мотоцикла: ";
		getline(cin, x);
		set_name(x);
		cout << "\n\t\t\tВведите цвет мотоцикла: ";
		cin >> x;
		set_color(x);
		cout << "\n\t\t\tВведите запас: ";
		cin >> y;
		set_stock(y);
		cout << "\n\t\t\tВведите цену: ";
		cin >> z;
		set_price(z);
		cout << "\n\t\t\tВведите мощность двигателя: ";
		cin >> y;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		set_horsepower(y);
		cout << "\n\t\t\tВведите описание мотоцикла: ";
		getline(cin, x);
		set_description(x);
	}
	static void read()
	{
		Bike arr;
		fstream file;
		file.open("bikes.txt", ios::in);
		while (file >> arr)
			b.push_back(arr);
		file.close();
	}
	static void write()
	{
		fstream file;
		file.open("bikes.txt", ios::out);
		for (int i = 0; i < b.size(); ++i)
		{
			file << b[i];
		}
		file.close();
	}
	static void list()
	{
		cout << "\t\t\t\nНомер" << "\t" << "Название мотоцикла" << "\t" << "Цена" << "\n\n";
		for (int i = 0; i < b.size(); i++)
		{
			cout << i + 1 << "\t" << b[i].get_name() << "\t$" << b[i].get_price() << "\n";
		}
	}
};
fstream& operator<<(fstream& file, Bike& obj)
{
	file << ' ' << obj.get_name() << ';' << obj.get_color() << ' ' << obj.get_stock() << ' ' << obj.get_price() << ' ' << obj.get_horsepower() << ' ' << obj.get_description() << ';' << ' ';
	return file;
}
fstream& operator>>(fstream& file, Bike& obj)
{
	string x;
	int y;
	double z;
	file.get();
	getline(file, x, ';');
	obj.set_name(x);
	file >> x;
	obj.set_color(x);
	file.get();
	file >> y;
	obj.set_stock(y);
	file.get();
	file >> z;
	obj.set_price(z);
	file.get();
	file >> y;
	obj.set_horsepower(y);
	file.get();
	getline(file, x, ';');
	obj.set_description(x);
	file.get();
	return file;
}
class Car :public Vehicle
{
	string transmission;
public:
	void getdata()
	{
		string x;
		int y;
		double z;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n\t\t\tВведите название автомобиля: ";
		getline(cin, x);
		set_name(x);
		cout << "\n\t\t\tВведите цвет автомобиля: ";
		cin >> x;
		set_color(x);
		cout << "\n\t\t\tВведите запас: ";
		cin >> y;
		set_stock(y);
		cout << "\n\t\t\tВведите цену: ";
		cin >> z;
		set_price(z);
		cout << "\n\t\t\tВведите мощность двигателя: ";
		cin >> y;
		set_horsepower(y);
		cout << "\n\t\t\tВведите трансмиссию автомобиля: ";
		cin >> x;
		set_transmission(x);
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n\t\t\tВведите описание автомобиля: ";
		getline(cin, x);
		set_description(x);
	}
	void set_transmission(string& x)
	{
		transmission = x;
	}
	string get_transmission()
	{
		return transmission;
	}
	static void read()
	{
		Car arr;
		fstream file;
		file.open("cars.txt", ios::in);
		while (file >> arr)
		{
			c.push_back(arr);
		}
		file.close();
	}
	static void write()
	{
		fstream file;
		file.open("cars.txt", ios::out);
		for (int i = 0; i < c.size(); ++i)
		{
			file << c[i];
		}
		file.close();
	}
	static void list()
	{
		cout << "\t\t\t\nНомер" << "\t" << "Название Автомобиля" << "\t" << "Цена Автомобиля" << "\n\n";
		for (int i = 0; i < c.size(); i++)
		{
			cout << i + 1 << ": " << c[i].get_name() << "                 " << "$" << c[i].get_price() << "\n";
		}
	}
};
fstream& operator<<(fstream& file, Car& obj)
{
	file << ' ' << obj.get_name() << ';' << obj.get_color() << ' ' << obj.get_stock() << ' ' << obj.get_price() << ' ' << obj.get_horsepower() << ' ' << obj.get_description() << ';' << obj.get_transmission() << ' ';
	return file;
}
fstream& operator>>(fstream& file, Car& obj)
{
	string x;
	int y;
	double z;
	file.get();
	getline(file, x, ';');
	obj.set_name(x);
	file >> x;
	obj.set_color(x);
	file.get();
	file >> y;
	obj.set_stock(y);
	file.get();
	file >> z;
	obj.set_price(z);
	file.get();
	file >> y;
	obj.set_horsepower(y);
	file.get();
	getline(file, x, ';');
	obj.set_description(x);
	file >> x;
	obj.set_transmission(x);
	file.get();
	return file;
}
class Truck : public Vehicle
{
	int loading_capacity;
public:
	void getdata()
	{
		string x;
		int y;
		double z;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n\t\t\tВведите название грузовика: ";
		getline(cin, x);
		set_name(x);
		cout << "\n\t\t\tВведите цвет грузовика: ";
		cin >> x;
		set_color(x);
		cout << "\n\t\t\tВведите запас: ";
		cin >> y;
		set_stock(y);
		cout << "\n\t\t\tВведите цену: ";
		cin >> z;
		set_price(z);
		cout << "\n\t\t\tВведите грузоподъемность грузовика: ";
		cin >> y;
		set_loading_capacity(y);
		cout << "\n\t\t\tВведите мощность двигателя: ";
		cin >> y;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		set_horsepower(y);
		cout << "\n\t\t\tВведите описание грузовика: ";
		getline(cin, x);
		set_description(x);
	}
	void set_loading_capacity(int& x)
	{
		loading_capacity = x;
	}
	int get_loading_capacity()
	{
		return loading_capacity;
	}
	static void write()
	{
		fstream file;
		file.open("trucks.txt", ios::out);
		for (int i = 0; i < t.size(); ++i)
		{
			file << t[i];
		}
		file.close();
	}
	static void read()
	{
		Truck arr;
		fstream file;
		file.open("trucks.txt", ios::in);
		while (file >> arr)
		{
			t.push_back(arr);
		}
		file.close();
	}
	static void list()
	{
		cout << "\t\t\t\nНомер" << "\t" << "Название грузовика" << "\t" << "Цена грузовика" << "\n\n";
		for (int i = 0; i < t.size(); i++)
		{
			cout << i + 1 << "\t" << t[i].get_name() << "\t$" << t[i].get_price() << "\n";
		}
	}
};
fstream& operator<<(fstream& file, Truck& obj)
{
	file << ' ' << obj.get_name() << ';' << obj.get_color() << ' ' << obj.get_stock() << ' ' << obj.get_price() << ' ' << obj.get_horsepower() << ' ' << obj.get_description() << ';' << obj.get_loading_capacity() << ' ';
	return file;
}
fstream& operator>>(fstream& file, Truck& obj)
{
	string x;
	int y;
	double z;
	file.get();
	getline(file, x, ';');
	obj.set_name(x);
	file >> x;
	obj.set_color(x);
	file.get();
	file >> y;
	obj.set_stock(y);
	file.get();
	file >> z;
	obj.set_price(z);
	file.get();
	file >> y;
	obj.set_horsepower(y);
	file.get();
	getline(file, x, ';');
	obj.set_description(x);
	file >> y;
	obj.set_loading_capacity(y);
	file.get();
	return file;
}
class customer {
	string name;
	long int num, CNIC, credit_card;
	bool Filer;
	int pin;
	double bill;
	vector<string> cart;
public:
	friend ostream& operator<<(ostream& dout, customer& obj);
	~customer()
	{
		Bike::write();
		Car::write();
		Truck::write();
	}
	customer()
	{

		b.clear();
		c.clear();
		t.clear();
		Bike::read();
		Car::read();
		Truck::read();
	}
	void write()
	{
		fstream file("customer.txt", ios::app);
		file << *this;
	}
	void menu()
	{
		system("cls");
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                        ПОРТАЛ КЛИЕНТА                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\tВыберите тс, которое вы хотите добавить в корзину: \n\n";
		cout << "\t\t\t1. Мотоцикл." << endl;
		cout << "\t\t\t2. Машина." << endl;
		cout << "\t\t\t3. Грузовик." << endl;
		cout << "\t\t\t4. Перейти к оформлению заказа" << endl;
		cout << "\t\t\t5. Посмотреть записи о машинах" << endl;
		cout << "\t\t\t6. Посмотреть корзину" << endl;
		cout << "\t\t\t7. Удалить в корзине" << endl;
		int s;
		cin >> s;
		switch (s)
		{
		case 1:
			bike_menu();
			break;
		case 2:
			car_menu();
			break;
		case 3:
			truck_menu();
			break;
		case 4:
			checkout();
			break;
		case 5: {
			cout << "\t\t\t1. Просмотреть все мотоциклы" << endl;
			cout << "\t\t\t2. Просмотреть все автомобили" << endl;
			cout << "\t\t\t3. Просмотреть все грузовики\n";
			cout << "\t\t\t4. Выход" << endl;
			int a;
			cin >> a;
			switch (a)
			{
			case 1:
				cout << "\nНомер\tИмя\t\t\tЗапас\n\n";
				for (int i = 0; i < b.size(); i++)
				{
					cout << i + 1 << b[i];
				}
				cout << "Может хотите отсортировать по номеру?" << endl;
				cout << "1)Да" << endl;
				cout << "2)Нет" << endl;
				int choose;
				cin >> choose;
				if (choose == 1) {
					cout << "\nНомер\tИмя\t\t\tЗапас\n\n";
					for (int i = 0; i < b.size(); i++)
					{
						cout << i + 1 << b[i];
					}
				}
				system("pause");
				menu(); break;
			case 2:
				cout << "\nНомер\tИмя\t\t\tЗапас\n\n";
				for (int i = 0; i < c.size(); i++)
				{
					cout << i + 1 << c[i];
				}
				cout << "Может хотите отсортировать по номеру?" << endl;
				cout << "1)Да" << endl;
				cout << "2)Нет" << endl;
				cin >> choose;
				if (choose == 1) {
					cout << "\nНомер\tИмя\t\t\tЗапас\n\n";
					for (int i = 0; i < b.size(); i++)
					{
						cout << i + 1 << b[i];
					}
				}
				system("pause");
				menu(); break;
			case 3:
				system("cls");
				cout << "\nНомер\tИмя\t\t\tЗапас\n\n";
				for (int i = 0; i < t.size(); i++)
				{
					cout << i + 1 << t[i];
				}
				cout << "Может хотите отсортировать по номеру?" << endl;
				cout << "1)Да" << endl;
				cout << "2)Нет" << endl;
				cin >> choose;
				if (choose == 1) {
					cout << "\nНомер\tИмя\t\t\tЗапас\n\n";
					for (int i = 0; i < b.size(); i++)
					{
						cout << i + 1 << b[i];
					}
				}
				system("pause");
				menu(); break;
			}
		}
		case 6: {
			if (cart.size() == 0) {
				cout << "В корзине пусто, добавьте что-нибудь" << endl;
				system("pause");
				menu();
			}
			else {
				for (int i = 0; i < cart.size(); i++) {
					cout << "В вашей корзине находятся эти товары:" << endl;
					cout << cart[i] << endl;;
				}
				system("pause");
				menu();
			}
		}break;
		case 7:{
			if (cart.size() == 0) {
				cout << "В корзине пусто, добавьте что-нибудь" << endl;
				system("pause");
				menu();
			}
			else {
				cout << "В вашей корзине находятся эти товары:" << endl;
				for (int i = 0; i < cart.size(); i++) {
					
					cout <<"№" << i << " " << cart[i] << endl;;
				}
				cout << "Введите номер автомобиля которого хотите удалить:";
					int numer;
					cin >> numer;
					cart.erase(cart.begin() + numer);
					cout << "В вашей корзине находятся эти товары:" << endl;
					for (int i = 0; i < cart.size(); i++) {
						cout << "№" << i << " " << cart[i] << endl;;
					}
				system("pause");
				menu();
			}
			}

		}
		

	}
	void bike_menu()
	{
		system("cls");
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                        ПОРТАЛ КЛИЕНТА                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Bike::list();
		cout << "\n\t\t\tВведите номер мотоцикла, который вы хотите добавить в корзину: ";
		int n;
		cin >> n;
		n--;
		cart.push_back(b[n].get_name());
		bill += b[n].get_price();
		b[n].set_stock(b[n].get_stock() - 1);
		menu();
	}
	void car_menu()
	{
		system("cls");
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                        ПОРТАЛ КЛИЕНТА                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Car::list();
		cout << "\n\t\t\tВведите номер машины, который вы хотите добавить в корзину:  ";
		int n;
		cin >> n;
		n--;
		cart.push_back(c[n].get_name());
		system("CLS");
		bill += c[n].get_price();
		c[n].set_stock(c[n].get_stock() - 1);
		menu();
	}
	void truck_menu()
	{
		system("cls");
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                        ПОРТАЛ КЛИЕНТА                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Truck::list();
		cout << "\n\t\t\tВойдите номер грузовика, который вы хотите добавить в корзину: ";
		int n;
		cin >> n;
		n--;
		cart.push_back(t[n].get_name());
		bill += t[n].get_price();
		t[n].set_stock(t[n].get_stock() - 1);
		menu();
	}
	void set_customerNmae(string c) {
		name = c;
	}
	void set_contact(long int con) {
		num = con;
	}
	void set_CNIC(long int n) {
		CNIC = n;
	}
	void set_CREDIT_card(long int r) {
		credit_card = r;
	}
	void set_Filer(bool f) {
		Filer = f;
	}
	void set_pin(int p) {
		pin = p;
	}
	string get_customerName() {
		return name;
	}
	long int get_contact() {
		return num;
	}
	long int get_CNIC() {
		return CNIC;
	}
	long int get_CREDIT_card() {
		return credit_card;
	}
	bool get_Filer() {
		return Filer;
	}
	int get_pin() {
		return pin;
	}
	double get_bill()
	{
		return bill;
	}
	void checkout()
	{
		if (bill == 0) {
			cout << "Добавьте что-нибудь в корзину........" << endl;
			system("pause");
			menu();
		}
		else {
			system("CLS");
			string a;
			cout << "\n\n\t\t\tВаша причитающаяся сумма составляет $" << bill;
			cout << "\n\n\n\n\t\t\tПожалуйста, введите свое имя" << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, a);
			set_customerNmae(a);
			cout << endl << "\t\t\tПожалуйста, введите свой контактный номер" << endl;
			long int b;
			cin >> b;
			set_contact(b);
			cout << endl << "\t\t\tПожалуйста, введите свое место нахождение" << endl;
			string c;
			cin.clear();
			cin.ignore();
			getline(cin, c);
			cout << endl << "\t\t\tПожалуйста, введите 16-значный номер вашей дебетовой карты" << endl;
			string cnumber;
			int ch;
			while ((ch = _getch()) != '\r') {
				if (ch == '\b') {
					if (cnumber.size() > 0) {
						cnumber.erase(cnumber.size() - 1, 1);
						cout << "\b \b";
					}
				}
				else {
					cnumber.push_back(ch);
					cout.put('*');
				}
			}
			auto z = cnumber.length();
			try
			{
				if (z != 16)
					throw 1;
			}
			catch (int)
			{
				cout << endl << "\t\t\tНОМЕР КАРТЫ ДОЛЖЕН СОСТОЯТЬ ИЗ 16 ЦИФР! " << endl;
				cout << endl << "\t\t\tПожалуйста, введите 16-значный номер вашей дебетовой карты" << endl;
				string cnumber;
				int ch;
				while ((ch = _getch()) != '\r') {
					if (ch == '\b') {
						if (cnumber.size() > 0) {
							cnumber.erase(cnumber.size() - 1, 1);
							cout << "\b \b";
						}
					}
					else {
						cnumber.push_back(ch);
						cout.put('*');
					}
				}
				
			}
			std::cout.put('\n');
			cout << endl << "\t\t\tВы уверены?" << endl;
			cout << endl << "\t\t\t1.Да" << endl;
			cout << endl << "\t\t\t2.Нет" << endl;
			string e;
			cin >> e;

			cout << endl << "\t\t\tПожалуйста, введите свой CVV-код " << endl;
			string code;
			int ch1;
			while ((ch1 = _getch()) != '\r') {
				if (ch1 == '\b') {
					if (code.size() > 0) {
						code.erase(code.size() - 1, 1);
						cout << "\b \b";
					}
				}
				else {
					code.push_back(ch);
					cout.put('*');
				}
			}
			auto we = code.length();
			try
			{
				if (we != 3)
					throw 1;
			}
			catch (int)
			{
				cout << endl << "\t\t\tPIN-КОД КАРТЫ ДОЛЖЕН СОСТОЯТЬ ИЗ 3 ЦИФР! " << endl;
				cout << endl << "\t\t\tПожалуйста, введите свой CVV-код " << endl;
				string code;
				int ch1;
				while ((ch1 = _getch()) != '\r') {
					if (ch1 == '\b') {
						if (code.size() > 0) {
							code.erase(code.size() - 1, 1);
							cout << "\b \b";
						}
					}
					else {
						code.push_back(ch);
						cout.put('*');
					}
				}
			}
			system("cls");
			cout << "\t\t\t\tСпасибо за покупку" << endl;
			cout << "\t\tВы приобрели на сумму->" << bill << endl;
			cout << "\t\tПозиции которые вы приобрели:" << endl;
			for (int i = 0; i < cart.size(); i++) {
				cout << "\t" << "№" << i << " " << cart[i] << endl;
			}
			system("pause");
			std::cout.put('\n');
			
			this->write();
			delete this;

			system("cls");
			cout << "\n\n\n\t\t\tБлагодарим Вас за использование нашего программного обеспечения.\n\nНажмите любую клавишу для выхода.";
			cin.ignore();
			cin.get();
			exit(0);
		}
	}
	friend fstream& operator<<(fstream& file, customer& obj);
	friend fstream& operator>>(fstream& file, customer& obj);

};
ostream& operator<<(ostream& dout, customer& obj)
{
	int static i = 1;
	cout << "\n" << i << ")" << "\t" << obj.name << "\t$" << obj.bill << "\n";
	for (int f = 0; f < obj.cart.size(); f++)
	{
		cout << "\t\t\t\t\t" << obj.cart[f] << "\n";
	}
	i++;
	return dout;
}
fstream& operator<<(fstream& file, customer& obj)
{
	file << obj.get_customerName() << ';' << obj.get_CNIC() << ' ' << obj.get_contact() << ' ' << obj.get_bill() << ' ';
	for (int i = 0; i < obj.cart.size(); i++)
	{
		if (i == (obj.cart.size() - 1))
		{
			file << obj.cart[i] << ';' << '*';
		}
		else
			file << obj.cart[i] << ';' << ' ';
	}
	return file;
}
fstream& operator>>(fstream& file, customer& obj)
{
	string x;
	getline(file, obj.name, ';');
	file >> obj.CNIC;
	file.get();
	file >> obj.num;
	file.get();
	file >> obj.bill;
	file.get();
	obj.cart.clear();
	do
	{
		getline(file, x, ';');
		obj.cart.push_back(x);
	} while (file.get() == ' ');

	return file;
}
class admin
{
public:
	void car();
	void truck();
	void bike();
	admin()
	{
		Truck::read();
		Car::read();
		Bike::read();
	}
	void password()
	{
		menu();


	}
	void menu()
	{

		{
			system("CLS");
			cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
			Sleep(50);
			cout << "\t\t|                    С ВОЗВРАЩЕНИЕМ, АДМИНИСТРАТОР                                    |" << endl;
			Sleep(50);
			cout << "\t\t|                      ********************                                           |" << endl;
			Sleep(50);
			cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
			Sleep(50);
			cout << "\t\t\t1. Изменение машин" << endl;
			cout << "\t\t\t2. Добавить машину" << endl;
			cout << "\t\t\t3. Посмотреть все машины.\n";
			cout << "\t\t\t4. Удалить машину.\n";
			cout << "\t\t\t5. Посмотреть историю покупок" << endl;
			cout << "\t\t\t6. Вернуться в главное меню" << endl;
			cout << "\t\t\t7. Выход.\n";
			int a;
			cin >> a;
			system("CLS");
			switch (a)
			{
			case 1:
			{
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t|                           ИЗМЕНЕНИЕ ТС                                              |" << endl;
				Sleep(50);
				cout << "\t\t|                      *************************                                      |" << endl;
				Sleep(50);
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t\t1. Модификация автомобиля" << endl;
				cout << "\t\t\t2. Модификация грузовика" << endl;
				cout << "\t\t\t3. Модификация мотоцикла." << endl;
				int a;
				cin >> a;
				system("CLS");
				switch (a)
				{
				case 1:
				{
					car();
				}
				case 2:
				{
					truck();
				}
				case 3:
				{
					bike();
				}
				}

			}
			case 2:
			{
				{
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                         ДОБАВЛЕНИЕ ТС                                               |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t\t1. Добавить машину." << endl;
					cout << "\t\t\t2. Добавить грузовик." << endl;
					cout << "\t\t\t3. Добавить мотоцикл" << endl;
					int s;
					cin >> s;
					system("CLS");
					switch (s)
					{
					case 1:
					{
						Car obj1;
						obj1.getdata();
						c.push_back(obj1);
						break;
					}
					case 2:
					{
						Truck obj2;
						obj2.getdata();
						t.push_back(obj2);
						break;
					}
					case 3:
					{
						Bike obj3;
						obj3.getdata();
						b.push_back(obj3);
						break;
					}
					case 4:
						menu();

					}

				}
				cout << "\n\t\tНажмите любую клавишу, чтобы вернуться в главное меню.";
				cin.ignore();
				cin.get();
				menu();
				break;
			}
			case 3:
			{
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t|                    С ВОЗВРАЩЕНИЕМ, АДМИНИСТРАТОР                                    |" << endl;
				Sleep(50);
				cout << "\t\t|                      ********************                                           |" << endl;
				Sleep(50);
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t\t1. Просмотреть все мотоциклы" << endl;
				cout << "\t\t\t2. Просмотреть все автомобили" << endl;
				cout << "\t\t\t3. Просмотреть все грузовики\n";
				cout << "\t\t\t4. Выход" << endl;
				int a;
				cin >> a;
				switch (a)
				{
				case 1:
					system("cls");
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                    С ВОЗВРАЩЕНИЕМ, АДМИНИСТРАТОР                                    |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\nНомер\tИмя\t\t\tЗапас\n\n";
					for (int i = 0; i < b.size(); i++)
					{
						cout << i + 1 << b[i];
					}
					break;
				case 2:
					system("cls");
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                    С ВОЗВРАЩЕНИЕМ, АДМИНИСТРАТОР                                    |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\nНомер\tИмя\t\t\tЗапас\n\n";
					for (int i = 0; i < c.size(); i++)
					{
						cout << i + 1 << c[i];
					}
					break;
				case 3:
					system("cls");
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                    С ВОЗВРАЩЕНИЕМ, АДМИНИСТРАТОР                                    |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\nНомер\tИмя\t\t\tЗапас\n\n";
					for (int i = 0; i < t.size(); i++)
					{
						cout << i + 1 << t[i];
					}
					break;
				default:
					cout << "\n\t\tВы ввели неверный выбор\n\n Нажмите любую клавишу для выхода.";
					cin.ignore();
					cin.get();
					delete this;
					exit(0);
					break;
				}
				cout << "\n\n\t\tНажмите любую клавишу, чтобы вернуться в главное меню.";
				cin.ignore();
				cin.get();
				menu();
			}
			case 4:

				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t|                    С ВОЗВРАЩЕНИЕМ, АДМИНИСТРАТОР                                    |" << endl;
				Sleep(50);
				cout << "\t\t|                      ********************                                           |" << endl;
				Sleep(50);
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t\t1. Удалить мотоцикл" << endl;
				cout << "\t\t\t2. Удалить машину" << endl;
				cout << "\t\t\t3. Удалить грузовик\n";
				cout << "\t\t\t4. Exit" << endl;
				int a;
				cin >> a;
				switch (a)
				{
				case 1:
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                    С ВОЗВРАЩЕНИЕМ, АДМИНИСТРАТОР                                    |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					Bike::list();
					cout << "\n\n\t\tВведите номер мотоцикла,чтобы удалить: ";
					cin >> a;
					try
					{
						if (a > b.size())
						{
							throw 1;
						}
					}
					catch (int)
					{
						cout << "\n\n\t\t\tВы выбрали неправильный вариант.Нажмите любую клавишу, чтобы повторно.";
						cout << "\n\n\t\tВведите номер мотоцикла,чтобы удалить: ";
						cin >> a;
					}
					a--;
					b.erase(b.begin() + a);
					break;
				case 2:
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                    С ВОЗВРАЩЕНИЕМ, АДМИНИСТРАТОР                                    |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					Car::list();
					cout << "\n\n\t\tВвведите номер машины, который вы хотите удалить: ";
					cin >> a;
					try
					{
						if (a > c.size())
						{
							throw 1;
						}
					}
					catch (int)
					{
						cout << "\n\n\t\t\tВы выбрали неправильный вариант.Нажмите любую клавишу, чтобы повторить.";
						cout << "\n\n\t\tВвведите номер машины, который вы хотите удалить: ";
						cin >> a;
					}
					a--;
					c.erase(c.begin() + a);
					break;
				case 3:
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                  С ВОЗВРАЩЕНИЕМ, АДМИНИСТРАТОР                                      |" << endl;
					Sleep(50);
					cout << "\t\t|                      ******************                                             |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					Truck::list();
					try
					{
						if (a > t.size())
						{
							throw 1;
						}
					}
					catch (int)
					{
						cout << "\n\n\t\t\tВы выбрали неправильный вариант.Нажмите любую клавишу, чтобы повторно";
						cout << "\n\n\t\t\tВвведите номер грузовика, который вы хотите удалить: ";
						cin >> a;
						a--;
					}
					t.erase(t.begin() + a);
					break;
				}
				cout << "\n\n\t\t\tНажмите любую клавишу, чтобы вернуться в главное меню.\n";
				cin.ignore();
				cin.get();
				menu();
				break;
			case 6:
			{
				main();
			}
			case 5:
			{
				fstream file("customer.txt", ios::in);
				customer obj;
				cout << "\nНомер\tИмя клиента\tСумма счета\tТранспортное средство куплено";
				cout << "\n===\t=============\t==========\t=================\n\n";
				while (file >> obj)
				{
					cout << obj;
				}
				cout << "\n\n\n\t\t\tНажмите любую клавишу, чтобы вернуться в главное меню.";
				cin.ignore();
				cin.get();
				menu();
				break;
			}

			case 7:
				delete this;
				exit(0);
			}

		}

	}
	~admin()
	{
		Truck::write();
		Car::write();
		Bike::write();
	}
};

void admin::car()
{
	Car::list();
	cout << endl;
	int a;
	cout << "\t\t\tВведите серийный номер автомобиля, который вы хотите изменить:" << endl;
	cin >> a;
	system("CLS");
	while (a)
	{
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                         МОДИФИКАЦИЯ МАШИНЫ                                          |" << endl;
		Sleep(50);
		cout << "\t\t|                      ***********************                                        |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t\t1. Изменить цену" << endl;
		cout << "\t\t\t2. Изменить цвет" << endl;
		cout << "\t\t\t3. Изменить запас" << endl;
		cout << "\t\t\t4. Модифицируйте лошадиную силу" << endl;
		cout << "\t\t\t5. Изменить описание" << endl;
		cout << "\t\t\t6. Изменить имя" << endl;
		int d;
		cin >> d;
		system("CLS");
		switch (d)
		{
		case 1:
		{
			cout << "\t\t\tПожалуйста, введите новую цену";
			float b;
			cin >> b;
			system("CLS");
			try
			{
				if (b < 0)
					throw 1;
			}
			catch (int)
			{
				cout << "\t\t\tВы ввели неправильную цену" << endl;
				cout << "\t\t\tперейти к главному меню?" << endl;
				cout << "\t\t\t1.Да" << endl;
				cout << "\t\t\t2.Нет" << endl;
				int k;
				cin >> k;
				if (k == 1)
				{
					system("CLS");
					menu();
				}
				else
				{
					delete this;
					exit(0);
				}
			}

			for (int i = a - 1; i < a; i++)
			{
				c[i].set_price(b);
			}
			system("CLS");
			menu();
		}
		case 2:
		{
			cout << "\t\t\tПожалуйста, введите новый цвет:";
			string b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				c[i].set_color(b);
			}
			system("CLS");
			menu();
		}
		case 3:
		{
			cout << "\t\t\tПожалуйста, введите новые акции:";
			int b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				c[i].set_stock(b);
			}
			system("CLS");
			menu();
		}
		case 4:
		{
			cout << "\t\t\tПожалуйста, введите новую лошадиную силу:";
			int b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				c[i].set_horsepower(b);
			}
			system("CLS");
			menu();
		}
		case 5:
		{
			cout << "\t\t\tПожалуйста, введите новое описание:";
			string b;
			cin.ignore();
			getline(cin, b);
			for (int i = a - 1; i < a; i++)
			{
				c[i].set_description(b);
			}
			system("CLS");
			menu();
		}
		case 6:
		{
			cout << "\t\t\tПожалуйста, введите новое имя:";
			string b;
			cin.ignore();
			getline(cin, b);
			for (int i = a - 1; i < a; i++)
			{
				c[i].set_name(b);
			}
			system("CLS");
			menu();
		}
		case 7:
		{
			menu();
		}
		}
	}
}
void admin::truck()
{
	Truck::list();
	cout << endl;
	int a;
	cout << "\t\t\tВведите серийный номер автомобиля, который вы хотите изменить:" << endl;
	cin >> a;
	system("CLS");
	while (a)
	{
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                        МОДИФИКАЦИЯ ГРУЗОВИКА                                        |" << endl;
		Sleep(50);
		cout << "\t\t|                      ************************                                       |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t\t1. Изменить цену" << endl;
		cout << "\t\t\t2. Изменить цвет" << endl;
		cout << "\t\t\t3. Изменить запас" << endl;
		cout << "\t\t\t4. Модифицируйте лошадиную силу" << endl;
		cout << "\t\t\t5. Изменить описание" << endl;
		cout << "\t\t\t6. Изменить имя" << endl;
		int d;
		cin >> d;
		system("CLS");
		switch (d)
		{
		case 1:
		{
			cout << "\t\t\tПожалуйста, введите новую цену?";
			float b;
			cin >> b;
			system("CLS");
			try
			{
				if (b < 0)
					throw 1;
			}
			catch (int)
			{
				cout << "\t\t\tВы ввели неправильную цену" << endl;
				cout << "\t\t\t	вернуться в главное меню?" << endl;
				cout << "\t\t\t1.Да" << endl;
				cout << "\t\t\t2.Нет" << endl;
				int k;
				cin >> k;
				if (k == 1)
				{
					system("CLS");
					menu();

				}
				else
				{
					delete this;
					exit(0);
				}

			}
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_price(b);
			}
			system("CLS");
			menu();
		}
		case 2:
		{
			cout << "\t\t\tПожалуйста, введите новый цвет:";
			string b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_color(b);
			}
			system("CLS");
			menu();
		}
		case 3:
		{
			cout << "\t\t\tПожалуйста, введите новые акции:";
			int b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_stock(b);
			}
			system("CLS");
			menu();
		}
		case 4:
		{
			cout << "\t\t\tПожалуйста, введите новую лошадиную силу:";
			int b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_horsepower(b);
			}
			system("CLS");
			menu();
		}
		case 5:
		{
			cout << "\t\t\tПожалуйста, введите новое описание:";
			string b;
			cin.ignore();
			getline(cin, b);
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_description(b);
			}
			system("CLS");
			menu();
		}
		case 6:
		{
			cout << "\t\t\tПожалуйста, введите новое имя:";
			string b;
			cin.ignore();
			getline(cin, b);
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_name(b);
			}
			system("CLS");
			menu();
		}
		case 7:
		{
			menu();
		}
		}
	}
}
void admin::bike()
{
	Bike::list();
	cout << endl;
	int a;
	cout << "\t\t\tВведите серийный номер автомобиля, который вы хотите изменить:" << endl;
	cin >> a;
	system("CLS");
	while (a)
	{
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                       МОДИФИКАЦИЯ В МОТОЦИКЛОВ                                      |" << endl;
		Sleep(50);
		cout << "\t\t|                      ***********************                                        |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t\t1. Изменить цену" << endl;
		cout << "\t\t\t 2. Изменить цвет" << endl;
		cout << "\t\t\t 3. Изменить запас" << endl;
		cout << "\t\t\t 4. Модифицируйте лошадиную силу" << endl;
		cout << "\t\t\t 5. Изменить описание" << endl;
		cout << "\t\t\t 6. Изменить имя" << endl;
		int d;
		cin >> d;
		system("CLS");
		switch (d)
		{
		case 1:
		{
			cout << "\t\t\tПожалуйста, введите новую цену:";
			float x;
			cin >> x;
			system("CLS");
			try
			{
				if (x < 0)
					throw 1;
			}
			catch (int)
			{
				cout << "\t\t\tВы ввели неправильную цену" << endl;
				cout << "\t\t\tвернуться в главное меню?" << endl;
				cout << "\t\t\t1.Да" << endl;
				cout << "\t\t\t2.Нет" << endl;
				int k;
				cin >> k;
				if (k == 1)
				{
					system("CLS");
					menu();
				}
				else
				{
					delete this;
					exit(0);
				}

			}
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_price(x);
			}
			system("CLS");
			menu();
		}
		case 2:
		{
			cout << "\t\t\t\n\nПожалуйста, введите новый цвет:";
			string x;
			cin >> x;
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_color(x);
			}
			system("CLS");
			menu();
		}
		case 3:
		{
			cout << "\t\t\t\n\nПожалуйста, введите новые акции:";
			int x;
			cin >> x;
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_stock(x);
			}
			system("CLS");
			menu();
		}
		case 4:
		{
			cout << "\t\t\t\n\nпожалуйста, введите новую лошадиную силу:";
			int x;
			cin >> x;
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_horsepower(x);
			}
			system("CLS");
			menu();
		}
		case 5:
		{
			cout << "\t\t\t\n\nПожалуйста, введите новое описание:";
			string x;
			cin.ignore();
			getline(cin, x);
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_description(x);
			}
			system("CLS");
			menu();
		}
		case 6:
		{
			cout << "\t\t\t\n\nПожалуйста, введите новое имя:";
			string x;
			cin.ignore();
			getline(cin, x);
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_name(x);
			}
			system("CLS");
			menu();
		}
		case 7:
		{
			menu();
		}
		}
	}
}
ostream& operator<<(ostream& dout, Vehicle& obj)
{
	cout << "\t" << obj.get_name() << "\t\t\t" << obj.get_stock() << "\n";
	return dout;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color 0A");

	menu_screen();
}
void menu_screen() {
	bool flag = TRUE;
	bool flag_admin = FALSE;
	SmartPointer<Authentication> auth = new Authentication();
	while (flag) {
		cout << "\t\t\t\t\t\t\tМеню:" << endl;
		cout << "\t\t\t\t\t\t(1) ~ Войти в аккаунт" << endl;
		cout << "\t\t\t\t\t\t(2) ~ Регистрация" << endl;
		cout << "\t\t\t\t\t\t(3) ~ Выход" << endl;
		cout << "\t\t\t\t\t\tВаш Выбор: ";
		int choose;
		cin >> choose;
		switch (choose) {
		case 1: flag = auth->auth(); system("cls"); break;
		case 2: auth->regestration(); system("cls"); break;
		case 3: flag = false; break;
		}
	}
	if (auth->getAccessInf() == 1) {
		admin* obj = new admin();
		Sleep(50);
		cout << "\n\n\n\n";
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		cout << "\t\t|                                                                                     |" << endl;
		Sleep(50);
		cout << "\t\t|                          СИСТЕМА УПРАВЛЕНИЯ АВТОСАЛОНОМ                             |" << endl;
		Sleep(50);
		cout << "\t\t|                                                                                     |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\n\n\n\n";
		cout << "\t\t\tПожалуйста, выберите вход:" << endl;
		cout << "\t\t\t1.Покупатель." << endl;
		cout << "\t\t\t2.Админ." << endl;
		cout << "\t\t\t3.Выход." << endl;
		int a;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			customer* obj1 = new customer();
			obj1->menu();
			break;
		}
		case 2:
		{
			obj->password();
			break;
		}
		case 3:
		{
			delete obj;
			exit(0);
		}
		}
	}
	else {
		customer* obj1 = new customer();
		obj1->menu();
	}
}