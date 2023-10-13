#pragma once
#pragma once
#ifndef dOIBONG_H 
#define dOIBONG_H 

#include<iostream>
#include"CAUTHU.H"
#include<string>
#include<vector>
using namespace std;

class doibong {
public:
    doibong(string, string, string, vector<CauThu>& danhsachcauthu);
    void suadoibong(string, string, string);
    void themcauthuvaodanhsach(CauThu& t);
    void xoacauthukhoids(string);

    string getTenDoiBong() const;
    string getDiaPhuong() const;
    string getHuanLuyenVien() const;
    vector<CauThu> getdscauthu() const;
    int getdodaidscauthu() const;
    void getdanhsachcauthu();
    void inThongTin();

private:
    string tenDoiBong;
    string diaPhuong;
    string huanLuyenVien;
    vector<CauThu> danhsachcauthu;
};

#endif
