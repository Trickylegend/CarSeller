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
		cout << "\n\t\t\t������� �������� ���������: ";
		getline(cin, x);
		set_name(x);
		cout << "\n\t\t\t������� ���� ���������: ";
		cin >> x;
		set_color(x);
		cout << "\n\t\t\t������� �����: ";
		cin >> y;
		set_stock(y);
		cout << "\n\t\t\t������� ����: ";
		cin >> z;
		set_price(z);
		cout << "\n\t\t\t������� �������� ���������: ";
		cin >> y;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		set_horsepower(y);
		cout << "\n\t\t\t������� �������� ���������: ";
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
		cout << "\t\t\t\n�����" << "\t" << "�������� ���������" << "\t" << "����" << "\n\n";
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
		cout << "\n\t\t\t������� �������� ����������: ";
		getline(cin, x);
		set_name(x);
		cout << "\n\t\t\t������� ���� ����������: ";
		cin >> x;
		set_color(x);
		cout << "\n\t\t\t������� �����: ";
		cin >> y;
		set_stock(y);
		cout << "\n\t\t\t������� ����: ";
		cin >> z;
		set_price(z);
		cout << "\n\t\t\t������� �������� ���������: ";
		cin >> y;
		set_horsepower(y);
		cout << "\n\t\t\t������� ����������� ����������: ";
		cin >> x;
		set_transmission(x);
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n\t\t\t������� �������� ����������: ";
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
		cout << "\t\t\t\n�����" << "\t" << "�������� ����������" << "\t" << "���� ����������" << "\n\n";
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
		cout << "\n\t\t\t������� �������� ���������: ";
		getline(cin, x);
		set_name(x);
		cout << "\n\t\t\t������� ���� ���������: ";
		cin >> x;
		set_color(x);
		cout << "\n\t\t\t������� �����: ";
		cin >> y;
		set_stock(y);
		cout << "\n\t\t\t������� ����: ";
		cin >> z;
		set_price(z);
		cout << "\n\t\t\t������� ���������������� ���������: ";
		cin >> y;
		set_loading_capacity(y);
		cout << "\n\t\t\t������� �������� ���������: ";
		cin >> y;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		set_horsepower(y);
		cout << "\n\t\t\t������� �������� ���������: ";
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
		cout << "\t\t\t\n�����" << "\t" << "�������� ���������" << "\t" << "���� ���������" << "\n\n";
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
		cout << "\t\t|                        ������ �������                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t�������� ��, ������� �� ������ �������� � �������: \n\n";
		cout << "\t\t\t1. ��������." << endl;
		cout << "\t\t\t2. ������." << endl;
		cout << "\t\t\t3. ��������." << endl;
		cout << "\t\t\t4. ������� � ���������� ������" << endl;
		cout << "\t\t\t5. ���������� ������ � �������" << endl;
		cout << "\t\t\t6. ���������� �������" << endl;
		cout << "\t\t\t7. ������� � �������" << endl;
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
			cout << "\t\t\t1. ����������� ��� ���������" << endl;
			cout << "\t\t\t2. ����������� ��� ����������" << endl;
			cout << "\t\t\t3. ����������� ��� ���������\n";
			cout << "\t\t\t4. �����" << endl;
			int a;
			cin >> a;
			switch (a)
			{
			case 1:
				cout << "\n�����\t���\t\t\t�����\n\n";
				for (int i = 0; i < b.size(); i++)
				{
					cout << i + 1 << b[i];
				}
				cout << "����� ������ ������������� �� ������?" << endl;
				cout << "1)��" << endl;
				cout << "2)���" << endl;
				int choose;
				cin >> choose;
				if (choose == 1) {
					cout << "\n�����\t���\t\t\t�����\n\n";
					for (int i = 0; i < b.size(); i++)
					{
						cout << i + 1 << b[i];
					}
				}
				system("pause");
				menu(); break;
			case 2:
				cout << "\n�����\t���\t\t\t�����\n\n";
				for (int i = 0; i < c.size(); i++)
				{
					cout << i + 1 << c[i];
				}
				cout << "����� ������ ������������� �� ������?" << endl;
				cout << "1)��" << endl;
				cout << "2)���" << endl;
				cin >> choose;
				if (choose == 1) {
					cout << "\n�����\t���\t\t\t�����\n\n";
					for (int i = 0; i < b.size(); i++)
					{
						cout << i + 1 << b[i];
					}
				}
				system("pause");
				menu(); break;
			case 3:
				system("cls");
				cout << "\n�����\t���\t\t\t�����\n\n";
				for (int i = 0; i < t.size(); i++)
				{
					cout << i + 1 << t[i];
				}
				cout << "����� ������ ������������� �� ������?" << endl;
				cout << "1)��" << endl;
				cout << "2)���" << endl;
				cin >> choose;
				if (choose == 1) {
					cout << "\n�����\t���\t\t\t�����\n\n";
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
				cout << "� ������� �����, �������� ���-������" << endl;
				system("pause");
				menu();
			}
			else {
				for (int i = 0; i < cart.size(); i++) {
					cout << "� ����� ������� ��������� ��� ������:" << endl;
					cout << cart[i] << endl;;
				}
				system("pause");
				menu();
			}
		}break;
		case 7:{
			if (cart.size() == 0) {
				cout << "� ������� �����, �������� ���-������" << endl;
				system("pause");
				menu();
			}
			else {
				cout << "� ����� ������� ��������� ��� ������:" << endl;
				for (int i = 0; i < cart.size(); i++) {
					
					cout <<"�" << i << " " << cart[i] << endl;;
				}
				cout << "������� ����� ���������� �������� ������ �������:";
					int numer;
					cin >> numer;
					cart.erase(cart.begin() + numer);
					cout << "� ����� ������� ��������� ��� ������:" << endl;
					for (int i = 0; i < cart.size(); i++) {
						cout << "�" << i << " " << cart[i] << endl;;
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
		cout << "\t\t|                        ������ �������                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Bike::list();
		cout << "\n\t\t\t������� ����� ���������, ������� �� ������ �������� � �������: ";
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
		cout << "\t\t|                        ������ �������                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Car::list();
		cout << "\n\t\t\t������� ����� ������, ������� �� ������ �������� � �������:  ";
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
		cout << "\t\t|                        ������ �������                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Truck::list();
		cout << "\n\t\t\t������� ����� ���������, ������� �� ������ �������� � �������: ";
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
			cout << "�������� ���-������ � �������........" << endl;
			system("pause");
			menu();
		}
		else {
			system("CLS");
			string a;
			cout << "\n\n\t\t\t���� ������������� ����� ���������� $" << bill;
			cout << "\n\n\n\n\t\t\t����������, ������� ���� ���" << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, a);
			set_customerNmae(a);
			cout << endl << "\t\t\t����������, ������� ���� ���������� �����" << endl;
			long int b;
			cin >> b;
			set_contact(b);
			cout << endl << "\t\t\t����������, ������� ���� ����� ����������" << endl;
			string c;
			cin.clear();
			cin.ignore();
			getline(cin, c);
			cout << endl << "\t\t\t����������, ������� 16-������� ����� ����� ��������� �����" << endl;
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
				cout << endl << "\t\t\t����� ����� ������ �������� �� 16 ����! " << endl;
				cout << endl << "\t\t\t����������, ������� 16-������� ����� ����� ��������� �����" << endl;
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
			cout << endl << "\t\t\t�� �������?" << endl;
			cout << endl << "\t\t\t1.��" << endl;
			cout << endl << "\t\t\t2.���" << endl;
			string e;
			cin >> e;

			cout << endl << "\t\t\t����������, ������� ���� CVV-��� " << endl;
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
				cout << endl << "\t\t\tPIN-��� ����� ������ �������� �� 3 ����! " << endl;
				cout << endl << "\t\t\t����������, ������� ���� CVV-��� " << endl;
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
			cout << "\t\t\t\t������� �� �������" << endl;
			cout << "\t\t�� ��������� �� �����->" << bill << endl;
			cout << "\t\t������� ������� �� ���������:" << endl;
			for (int i = 0; i < cart.size(); i++) {
				cout << "\t" << "�" << i << " " << cart[i] << endl;
			}
			system("pause");
			std::cout.put('\n');
			
			this->write();
			delete this;

			system("cls");
			cout << "\n\n\n\t\t\t���������� ��� �� ������������� ������ ������������ �����������.\n\n������� ����� ������� ��� ������.";
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
			cout << "\t\t|                    � ������������, �������������                                    |" << endl;
			Sleep(50);
			cout << "\t\t|                      ********************                                           |" << endl;
			Sleep(50);
			cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
			Sleep(50);
			cout << "\t\t\t1. ��������� �����" << endl;
			cout << "\t\t\t2. �������� ������" << endl;
			cout << "\t\t\t3. ���������� ��� ������.\n";
			cout << "\t\t\t4. ������� ������.\n";
			cout << "\t\t\t5. ���������� ������� �������" << endl;
			cout << "\t\t\t6. ��������� � ������� ����" << endl;
			cout << "\t\t\t7. �����.\n";
			int a;
			cin >> a;
			system("CLS");
			switch (a)
			{
			case 1:
			{
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t|                           ��������� ��                                              |" << endl;
				Sleep(50);
				cout << "\t\t|                      *************************                                      |" << endl;
				Sleep(50);
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t\t1. ����������� ����������" << endl;
				cout << "\t\t\t2. ����������� ���������" << endl;
				cout << "\t\t\t3. ����������� ���������." << endl;
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
					cout << "\t\t|                         ���������� ��                                               |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t\t1. �������� ������." << endl;
					cout << "\t\t\t2. �������� ��������." << endl;
					cout << "\t\t\t3. �������� ��������" << endl;
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
				cout << "\n\t\t������� ����� �������, ����� ��������� � ������� ����.";
				cin.ignore();
				cin.get();
				menu();
				break;
			}
			case 3:
			{
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t|                    � ������������, �������������                                    |" << endl;
				Sleep(50);
				cout << "\t\t|                      ********************                                           |" << endl;
				Sleep(50);
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t\t1. ����������� ��� ���������" << endl;
				cout << "\t\t\t2. ����������� ��� ����������" << endl;
				cout << "\t\t\t3. ����������� ��� ���������\n";
				cout << "\t\t\t4. �����" << endl;
				int a;
				cin >> a;
				switch (a)
				{
				case 1:
					system("cls");
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                    � ������������, �������������                                    |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\n�����\t���\t\t\t�����\n\n";
					for (int i = 0; i < b.size(); i++)
					{
						cout << i + 1 << b[i];
					}
					break;
				case 2:
					system("cls");
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                    � ������������, �������������                                    |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\n�����\t���\t\t\t�����\n\n";
					for (int i = 0; i < c.size(); i++)
					{
						cout << i + 1 << c[i];
					}
					break;
				case 3:
					system("cls");
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                    � ������������, �������������                                    |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\n�����\t���\t\t\t�����\n\n";
					for (int i = 0; i < t.size(); i++)
					{
						cout << i + 1 << t[i];
					}
					break;
				default:
					cout << "\n\t\t�� ����� �������� �����\n\n ������� ����� ������� ��� ������.";
					cin.ignore();
					cin.get();
					delete this;
					exit(0);
					break;
				}
				cout << "\n\n\t\t������� ����� �������, ����� ��������� � ������� ����.";
				cin.ignore();
				cin.get();
				menu();
			}
			case 4:

				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t|                    � ������������, �������������                                    |" << endl;
				Sleep(50);
				cout << "\t\t|                      ********************                                           |" << endl;
				Sleep(50);
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t\t1. ������� ��������" << endl;
				cout << "\t\t\t2. ������� ������" << endl;
				cout << "\t\t\t3. ������� ��������\n";
				cout << "\t\t\t4. Exit" << endl;
				int a;
				cin >> a;
				switch (a)
				{
				case 1:
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                    � ������������, �������������                                    |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					Bike::list();
					cout << "\n\n\t\t������� ����� ���������,����� �������: ";
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
						cout << "\n\n\t\t\t�� ������� ������������ �������.������� ����� �������, ����� ��������.";
						cout << "\n\n\t\t������� ����� ���������,����� �������: ";
						cin >> a;
					}
					a--;
					b.erase(b.begin() + a);
					break;
				case 2:
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                    � ������������, �������������                                    |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					Car::list();
					cout << "\n\n\t\t�������� ����� ������, ������� �� ������ �������: ";
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
						cout << "\n\n\t\t\t�� ������� ������������ �������.������� ����� �������, ����� ���������.";
						cout << "\n\n\t\t�������� ����� ������, ������� �� ������ �������: ";
						cin >> a;
					}
					a--;
					c.erase(c.begin() + a);
					break;
				case 3:
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                  � ������������, �������������                                      |" << endl;
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
						cout << "\n\n\t\t\t�� ������� ������������ �������.������� ����� �������, ����� ��������";
						cout << "\n\n\t\t\t�������� ����� ���������, ������� �� ������ �������: ";
						cin >> a;
						a--;
					}
					t.erase(t.begin() + a);
					break;
				}
				cout << "\n\n\t\t\t������� ����� �������, ����� ��������� � ������� ����.\n";
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
				cout << "\n�����\t��� �������\t����� �����\t������������ �������� �������";
				cout << "\n===\t=============\t==========\t=================\n\n";
				while (file >> obj)
				{
					cout << obj;
				}
				cout << "\n\n\n\t\t\t������� ����� �������, ����� ��������� � ������� ����.";
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
	cout << "\t\t\t������� �������� ����� ����������, ������� �� ������ ��������:" << endl;
	cin >> a;
	system("CLS");
	while (a)
	{
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                         ����������� ������                                          |" << endl;
		Sleep(50);
		cout << "\t\t|                      ***********************                                        |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t\t1. �������� ����" << endl;
		cout << "\t\t\t2. �������� ����" << endl;
		cout << "\t\t\t3. �������� �����" << endl;
		cout << "\t\t\t4. ������������� ��������� ����" << endl;
		cout << "\t\t\t5. �������� ��������" << endl;
		cout << "\t\t\t6. �������� ���" << endl;
		int d;
		cin >> d;
		system("CLS");
		switch (d)
		{
		case 1:
		{
			cout << "\t\t\t����������, ������� ����� ����";
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
				cout << "\t\t\t�� ����� ������������ ����" << endl;
				cout << "\t\t\t������� � �������� ����?" << endl;
				cout << "\t\t\t1.��" << endl;
				cout << "\t\t\t2.���" << endl;
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
			cout << "\t\t\t����������, ������� ����� ����:";
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
			cout << "\t\t\t����������, ������� ����� �����:";
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
			cout << "\t\t\t����������, ������� ����� ��������� ����:";
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
			cout << "\t\t\t����������, ������� ����� ��������:";
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
			cout << "\t\t\t����������, ������� ����� ���:";
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
	cout << "\t\t\t������� �������� ����� ����������, ������� �� ������ ��������:" << endl;
	cin >> a;
	system("CLS");
	while (a)
	{
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                        ����������� ���������                                        |" << endl;
		Sleep(50);
		cout << "\t\t|                      ************************                                       |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t\t1. �������� ����" << endl;
		cout << "\t\t\t2. �������� ����" << endl;
		cout << "\t\t\t3. �������� �����" << endl;
		cout << "\t\t\t4. ������������� ��������� ����" << endl;
		cout << "\t\t\t5. �������� ��������" << endl;
		cout << "\t\t\t6. �������� ���" << endl;
		int d;
		cin >> d;
		system("CLS");
		switch (d)
		{
		case 1:
		{
			cout << "\t\t\t����������, ������� ����� ����?";
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
				cout << "\t\t\t�� ����� ������������ ����" << endl;
				cout << "\t\t\t	��������� � ������� ����?" << endl;
				cout << "\t\t\t1.��" << endl;
				cout << "\t\t\t2.���" << endl;
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
			cout << "\t\t\t����������, ������� ����� ����:";
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
			cout << "\t\t\t����������, ������� ����� �����:";
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
			cout << "\t\t\t����������, ������� ����� ��������� ����:";
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
			cout << "\t\t\t����������, ������� ����� ��������:";
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
			cout << "\t\t\t����������, ������� ����� ���:";
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
	cout << "\t\t\t������� �������� ����� ����������, ������� �� ������ ��������:" << endl;
	cin >> a;
	system("CLS");
	while (a)
	{
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                       ����������� � ����������                                      |" << endl;
		Sleep(50);
		cout << "\t\t|                      ***********************                                        |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t\t1. �������� ����" << endl;
		cout << "\t\t\t 2. �������� ����" << endl;
		cout << "\t\t\t 3. �������� �����" << endl;
		cout << "\t\t\t 4. ������������� ��������� ����" << endl;
		cout << "\t\t\t 5. �������� ��������" << endl;
		cout << "\t\t\t 6. �������� ���" << endl;
		int d;
		cin >> d;
		system("CLS");
		switch (d)
		{
		case 1:
		{
			cout << "\t\t\t����������, ������� ����� ����:";
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
				cout << "\t\t\t�� ����� ������������ ����" << endl;
				cout << "\t\t\t��������� � ������� ����?" << endl;
				cout << "\t\t\t1.��" << endl;
				cout << "\t\t\t2.���" << endl;
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
			cout << "\t\t\t\n\n����������, ������� ����� ����:";
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
			cout << "\t\t\t\n\n����������, ������� ����� �����:";
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
			cout << "\t\t\t\n\n����������, ������� ����� ��������� ����:";
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
			cout << "\t\t\t\n\n����������, ������� ����� ��������:";
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
			cout << "\t\t\t\n\n����������, ������� ����� ���:";
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
		cout << "\t\t\t\t\t\t\t����:" << endl;
		cout << "\t\t\t\t\t\t(1) ~ ����� � �������" << endl;
		cout << "\t\t\t\t\t\t(2) ~ �����������" << endl;
		cout << "\t\t\t\t\t\t(3) ~ �����" << endl;
		cout << "\t\t\t\t\t\t��� �����: ";
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
		cout << "\t\t|                          ������� ���������� �����������                             |" << endl;
		Sleep(50);
		cout << "\t\t|                                                                                     |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\n\n\n\n";
		cout << "\t\t\t����������, �������� ����:" << endl;
		cout << "\t\t\t1.����������." << endl;
		cout << "\t\t\t2.�����." << endl;
		cout << "\t\t\t3.�����." << endl;
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