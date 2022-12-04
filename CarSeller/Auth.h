#pragma once

#include <string>;
#include <conio.h>;
#include <fstream>
#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;

class Authentication {
public:
    Authentication() {}
    Authentication(string login, string password, string role) : login(login), password(password), role(role) {}

private:
    string login;
    string password;
    string role = "User";
    int account_point = 0;
    int access_reg = 1;
    int access_inf = 0;
    int access_log = 0;
    string file = "Auth.txt";
public:
    int auth();
    void regestration();
    int getAccessInf() { return access_inf; }
private:
    void writeEndFileAccounts();
    string setLogin();
    string setPassword();
    void upload_information(vector<Authentication>& v);

    friend istream& operator>>(istream& stream, Authentication& v) {
        stream >> v.login;
        stream >> v.password;
        stream >> v.role;

        return stream;
    }
    friend ostream& operator<<(ostream& stream, const Authentication& v) {
        stream << v.login << " " << v.password << " " << v.role;
        return stream;
    }
    Authentication& operator=(const Authentication&) = default;

};

