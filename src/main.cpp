#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

struct Mahasiswa {
    string nrp;
    string name;
    string gender;
};

void headerData();
void writeDataMahasiswa(vector<Mahasiswa> &m, int &indexNumber);
void readDataMahasiswa(vector<Mahasiswa> &m);

int main () {
    int indexNumber = 1;
    vector<Mahasiswa> mahasiswa;
    ofstream fileWrite;
    
    // read and write header
    headerData();

    // read data mahasiswa from file daftar-nama.txt
    readDataMahasiswa(mahasiswa);
    // write data to csv file
    fileWrite.open("4210191014_Auriel Harlih Rizkinanda.csv", ios::app);
    for (int i = 0; i < mahasiswa.size(); i++) {
        fileWrite << indexNumber << ",";
        fileWrite << mahasiswa[i].nrp << ",";
        fileWrite << mahasiswa[i].name << ",";
        fileWrite << mahasiswa[i].gender << "\n";
        indexNumber += 1;
    }
    fileWrite.close();
    mahasiswa.clear();

    // read data mahasiswa from file daftar-nama.txt 
    readDataMahasiswa(mahasiswa);
    // write data to csv file ( reverse data )
    fileWrite.open("4210191014_Auriel Harlih Rizkinanda.csv", ios::app);
    for (int i = mahasiswa.size() - 1; i >= 0 ; i--) {
        fileWrite << indexNumber << ",";
        fileWrite << mahasiswa[i].nrp << ",";
        fileWrite << mahasiswa[i].name << ",";
        fileWrite << mahasiswa[i].gender << "\n";
        indexNumber += 1;
    }
    mahasiswa.clear();
    fileWrite.close();
    
}

void headerData() {
    string tempData;
    string s;
    
    ifstream fileRead("daftar-nama.txt");
    ofstream fileWrite("4210191014_Auriel Harlih Rizkinanda.csv", ios::out);

    // read and write header
    getline(fileRead, tempData);
    fileWrite << tempData << "\n";
    
    getline(fileRead, tempData);
    istringstream is(tempData);
    for (int i = 0; i < 4; i++) {
        getline(is, s, '\t');
        fileWrite << s << ",";
    }
    fileWrite << "\n";

    fileRead.close();
    fileWrite.close();
}

void readDataMahasiswa(vector<Mahasiswa> &m) {
    string tempData;
    string s;
    Mahasiswa temp;

    ifstream fileRead("daftar-nama.txt");

    getline (fileRead, tempData);
    getline (fileRead, tempData);
    while (getline(fileRead, tempData)) {
        istringstream is(tempData);
        getline(is, s, '\t');
        getline(is, s, '\t');
        temp.nrp = s;
        getline(is, s, '\t');
        temp.name = s;
        getline(is, s, '\t');
        temp.gender = s;

        m.push_back(temp);
    }

    fileRead.close();
}
