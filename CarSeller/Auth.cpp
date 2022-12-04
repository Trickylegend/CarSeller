#include "Auth.h"

#include <Windows.h>

void Authentication::regestration() {
    system("cls");
    if (account_point == 0) {
        string login;
        string login_check_povtor;
        int controller = 0;
        ifstream fout(file);
        cout << "\t\t�����������:" << endl;

        cout << "������� �����:";
        login = setLogin();
        if (!fout.is_open()) {
            cout << "�� ������ ������� ��...���������� � ��������������" << endl;
        }
        else {
            while (!fout.eof()) {

                fout >> login_check_povtor;

                if (strcmp(login_check_povtor.c_str(), login.c_str()) != 0) {
                    controller = 0;
                }
                else {
                    controller = 1;
                    break;
                }
            }
        }
        if (controller == 0) {
            cout << "������� ������:";
            setPassword();
            account_point = 1;
            writeEndFileAccounts();
            cout << "����������� ������ �������" << endl;
            system("cls");
        }
        else {
            fout.close();
            system("cls");
            cout << "����� ����� ��� ���������� ��������� �������...." << endl;
            system("pause");
            system("cls");
        }

    }
    else {
        system("cls");
        cout << "�� ��� ������� �������...�������������" << endl;
        system("pause");
        system("cls");
    }
}
void Authentication::writeEndFileAccounts()
{

    ofstream fout(file, ios::app);
    fout << login << " " << password << " " << role;
    fout << endl;
    fout.close();
}
string Authentication::setLogin() {
    int controller;
    string BufForWriting;
    char symbols[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm._-1234567890";
    do {
        controller = 0;
        cin.clear();
        getline(cin, BufForWriting);
        if (BufForWriting.size() < 6)
        {
            cout << "����� ������ ��������� 6 ��� ����� ��������: ";
            controller = 1;
        }
        else
        {
            for (register int i = 0; BufForWriting[i] != '\0'; i++)
            {
                controller = 2;
                for (register int j = 0; symbols[j] != '\0'; j++)
                {
                    if (BufForWriting[i] == symbols[j]) { controller = 0; break; }
                }
                if (controller == 2)
                {
                    cout << "����� ����� ��������� ��������� �����, ����� � ����������� �������(-._): ";
                    break;
                }
            }
        }
    } while (controller != 0);
    login = BufForWriting;
    return login;
}
string Authentication::setPassword() {
    string BufForWriting;
    int controller, num, alpha;
    do {
        cin.clear();
        cin >> BufForWriting;
        controller = 0; alpha = 0; num = 0;
        if (BufForWriting.size() < 8)
        {
            cout << "\n������ ������ ��������� 8 ��� ����� ��������: \n";
            controller = -1;
        }
        else
        {
            for (register int i = 0; BufForWriting[i] != '\0'; i++)
            {
                if (isspace(BufForWriting[i]))
                {
                    cout << "\n������ �� ������ ��������� �������: \n";
                    controller = -1;
                    break;
                }
                else if (isdigit(BufForWriting[i]))
                    num++;
                else if (isalpha(BufForWriting[i]))
                    alpha++;
            }
            if (controller != -1 && (num == 0 || alpha == 0))
            {
                cout << "\n������ ������ ��������� ����� � �����: \n";
                controller = -1;
            }
        }
    } while (controller == -1);
    password = BufForWriting;
    return BufForWriting;
}





int Authentication::auth() {
    ifstream fin(file, ios::in);
    if (fin.peek() == EOF) {
        system("cls");
        cout << "�� ��������� ������ ������������� ���������!" << endl;
        cout << "������� �����:";
        login = setLogin();

        cout << "������� ������:";
        password = setPassword();
        role = "Admin";
        account_point = 1;
        writeEndFileAccounts();
        fin.close();
        system("cls");
        cout << "����������� ������ �������" << endl;
        system("pause");
        return account_point;
    }
    else {
        system("cls");
        cout << "�����������:" << endl;
        int8_t controller = 0, autho = 0, access = 0;
        cout << "Login: ";
        login = setLogin();
        cout << "Password: ";
        password = setPassword();
        cout << endl;
        ifstream fin(file, ios::in);
        string checher_login;
        string checher_password;
        string checher_role;
        fin.seekg(0, ios::beg);
        if (!fin) {
            cout << "��� ������� � �����,���������� � ������///";
        }
        else {
            while (strcmp(checher_login.c_str(), login.c_str()) != 0 && !fin.eof()) {
                fin >> checher_login;
                if (strcmp(login.c_str(), checher_login.c_str()) == 0) {
                    fin >> checher_password;
                    controller = 0;
                }
                else {
                    controller = 1;
                }
            }
            if (strcmp(password.c_str(), checher_password.c_str()) != 0) {
                controller = 1;
            }
            else {
                fin >> checher_role;
            }
            if (controller == 1) {
                cout << "����� ��� ������ ������� �������.��������� �������" << endl;
                system("pause");
                access_log = 0;
                return TRUE;
            }
            else {
                string admin = "Admin";
                if (strcmp(checher_role.c_str(), admin.c_str()) == 0) {
                    access_inf = 1;
                }
                else {
                    access_inf = 0;
                }
                access_log = 1;
                system("cls");
                system("cls");
                cout << "Loading ";
                system("cls");
                cout << "�� ������� ��������������.." << endl;
                return FALSE;
            }

        }
        fin.close();
    }
    fin.close();
}
void Authentication::upload_information(vector<Authentication>& v) {
    ifstream f(file);
    Authentication temp;
    while (f >> temp) {
        v.push_back(temp);
    }
    f.close();
}



