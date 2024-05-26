#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Patient
{
	string surname;
	string name;
	string patronymic;
	string address;
	long cardNumber;
	long insurancePolicyNumber;
};

// Функция для добавления пациента в файл
void addPatientToFile(const string& filename, const Patient& patient, bool atStart = false) {
    fstream file;
    if (atStart) {
        // Считываем существующие данные из файла
        file.open(filename, ios::in);
        string existingData((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        file.close();
        // Открываем файл для записи и добавляем нового пациента в начало
        file.open(filename, ios::out | ios::trunc);
        file << patient.surname << " " << patient.name << " " << patient.patronymic << " "
            << patient.address << " " << patient.cardNumber << " " << patient.insurancePolicyNumber << "\n";
        file << existingData;
    }
    else {
        // Добавляем пациента в конец файла
        file.open(filename, ios::out | ios::app);
        file << patient.surname << " " << patient.name << " " << patient.patronymic << " "
            << patient.address << " " << patient.cardNumber << " " << patient.insurancePolicyNumber << "\n";
    }
    file.close();
}

void removePatientFromFile(const string& filename, long cardNumber) {
    ifstream file(filename);
    string line;
    string tempData;
    // Читаем файл построчно
    while (getline(file, line)) {
        // Ищем номер медицинской карты в текущей строке
        size_t pos = line.find(to_string(cardNumber));
        // Если номер не найден, добавляем строку во временные данные
        if (pos == string::npos) {
            tempData += line + "\\n";
        }
    }
    file.close();
    // Перезаписываем файл без удаленного пациента
    ofstream outFile(filename, ios::trunc);
    outFile << tempData;
    outFile.close();
}

int main(){
    system("chcp 1251>null");
    string filename = "patients.txt";
    string surname, name, patronymic, address;
     int cardNumber, insurancePolicyNumber;
    cout << "Введите фамилию пациента" << "\n";
    cin >> surname;
    cout << "Введите имя пациента" << "\n";
    cin >> name;
    cout << "Введите отчество пациента" << "\n";
    cin >> patronymic;
    cout<<"Введите адресс пациента" << "\n";
    cin >> address;
    cout<< "Введите номер карты пациента" << "\n";
    cin >> cardNumber;
    cout<< "Введите номер страхового полиса пациента" << "\n";
    cin >> insurancePolicyNumber;







    addPatientToFile(filename, {surname, name, patronymic,address, cardNumber, insurancePolicyNumber});
}



