#pragma once
#define NOMINMAX
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<Windows.h>
using namespace std;
//All Declarations

void menu_screen();
class Vehicle;
class Bike;
class Car;
class Truck;
class customer;
class admin;
int main();
fstream& operator<<(fstream& file, Bike& obj);
fstream& operator>>(fstream& file, Bike& obj);
fstream& operator<<(fstream& file, Car& obj);
fstream& operator>>(fstream& file, Car& obj);
fstream& operator<<(fstream& file, Truck& obj);
fstream& operator>>(fstream& file, Truck& obj);
ostream& operator<<(ostream& dout, Vehicle& obj);
ostream& operator<<(ostream& dout, customer& obj);
