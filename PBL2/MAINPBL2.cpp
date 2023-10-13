#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <sstream>
#include"CAUTHU.H"
#include"TRANDAU.H"
#include"DOIBONG.H"
using namespace std;


void setDataCTFromdataDb(vector<CauThu>& listPlayerCT, const vector<doibong>& danhsachdoibong) {
    for (const auto& doibong : danhsachdoibong) {
        for (const auto& cauthu : doibong.getdscauthu()) {
            listPlayerCT.push_back(cauthu);
        }
    }
}

void setDatDBFromFile(vector<doibong>& danhSachDoiBong) {
    ifstream file("E:\\dataD\\doibong.txt");
    if (file.is_open()) {
        int sl = 0;
        string line;
        string tenDoiBong, diaPhuong, huanLuyenVien;
        string id, fn, it, bi, he, we, po;
        while (getline(file, line)) {
            if (line.find("Ten doi bong: ") != string::npos) {
                tenDoiBong = line.substr(14);
            }
            else if (line.find("Dia phuong: ") != string::npos) {
                diaPhuong = line.substr(12);
            }
            else if (line.find("Huan luyen vien: ") != string::npos) {
                huanLuyenVien = line.substr(17);
            }
            vector<CauThu> danhsachcauthu;
            if (line.find("Danh sach cau thu: ") != string::npos) {
                sl = stoi(line.substr(19));
                getline(file, line);
                for (int i = 0; i < sl; i++) {
                    for (int j = 0; j < 7; j++) {
                        if (line.find("So CMND: ") != string::npos) {
                            id = line.substr(9);
                            getline(file, line);
                        }
                        else if (line.find("Ho ten: ") != string::npos) {
                            fn = line.substr(8);
                            getline(file, line);
                        }
                        else if (line.find("Quoc tich: ") != string::npos) {
                            it = line.substr(11);
                            getline(file, line);
                        }
                        else if (line.find("Ngay sinh: ") != string::npos) {
                            bi = line.substr(11);
                            getline(file, line);
                        }
                        else if (line.find("Chieu cao: ") != string::npos) {
                            he = line.substr(11);
                            getline(file, line);
                        }
                        else if (line.find("Can nang: ") != string::npos) {
                            we = line.substr(10);
                            getline(file, line);
                        }
                        else if (line.find("Vi tri thi dau: ") != string::npos) {
                            po = line.substr(16);
                            getline(file, line);
                            getline(file, line);
                            CauThu T(id, fn, it, bi, he, we, po, tenDoiBong);
                            danhsachcauthu.push_back(T);
                        }
                    }
                }
                doibong doibong1(tenDoiBong, diaPhuong, huanLuyenVien, danhsachcauthu);
                danhSachDoiBong.push_back(doibong1);
            }
        }
        file.close();
    }
    else {
        cout << "Khong the mo tep tin doibong.txt." << endl;
    }
}

void menu() {
    cout << "**********************************************" << endl;
    cout << "1. Hien thi thong tin 1 cau thu " << endl;
    cout << "2. Them moi cau thu " << endl;
    cout << "3. Xoa thong tin cau thu" << endl;
    cout << "4. Sua thong tin cau thu" << endl;
    cout << "5. Hien thi danh sach cau thu" << endl;
    cout << "6. Hien thi cau thu tre tuoi nhat" << endl;
    cout << "7. Hien thi cau thu cao nhat" << endl;
    cout << "8. Hien thi cau thu thap nhat" << endl;
    cout << "0. Ket thuc chuong trinh" << endl;
    cout << "**********************************************" << endl;
}

void luucauthuvaodoibong(vector<doibong> danhsachdoibong) {

}

void luuThongTinDoiBong(const vector<doibong>& danhSachDoiBong) {
    ofstream file("E:\\dataD\\doibong.txt");
    if (file.is_open()) {
        danhSachDoiBong.begin()->getdscauthu();
        for (const auto& doiBong : danhSachDoiBong) {
            file << "Ten doi bong: " << doiBong.getTenDoiBong() << endl;
            file << "Dia phuong: " << doiBong.getDiaPhuong() << endl;
            file << "Huan luyen vien: " << doiBong.getHuanLuyenVien() << endl;
            file << "Danh sach cau thu: " << doiBong.getdodaidscauthu() << endl;
            for (const auto& cauThu : doiBong.getdscauthu()) {
                file << "So CMND: " << cauThu.getID() << endl;
                file << "Ho ten: " << cauThu.getFullname() << endl;
                file << "Quoc tich: " << cauThu.getInternational() << endl;
                file << "Ngay sinh: " << cauThu.getBirth() << endl;
                file << "Chieu cao: " << cauThu.getHeight() << endl;
                file << "Can nang: " << cauThu.getWeight() << endl;
                file << "Vi tri thi dau: " << cauThu.getPosition() << endl;
                file << "--------------------------" << endl;
            }
            file << "--------------------------" << endl;
        }
        file.close();
    }
    else {
        cout << "Khong the mo tep tin doibong.txt." << endl;
    }
}

void luuThongTinCauThu(const vector<CauThu>& listPlayerCT) {
    ofstream file("E:\\dataD\\dsplayer.txt");
    if (file.is_open()) {
        for (const auto& cauThu : listPlayerCT) {
            file << "So CMND: " << cauThu.getID() << endl;
            file << "Ho ten: " << cauThu.getFullname() << endl;
            file << "Quoc tich: " << cauThu.getInternational() << endl;
            file << "Ngay sinh: " << cauThu.getBirth() << endl;
            file << "Chieu cao: " << cauThu.getHeight() << endl;
            file << "Can nang: " << cauThu.getWeight() << endl;
            file << "Vi tri thi dau: " << cauThu.getPosition() << endl;
            file << "Thuoc doi bong: " << cauThu.getTendoibong() << endl;
            file << "--------------------------" << endl;
        }
        file.close();
    }
    else {
        cout << "Khong the mo tep tin doibong.txt." << endl;
    }
}
int main() {
    vector<doibong> danhSachDoiBong;
    setDatDBFromFile(danhSachDoiBong);
    vector<CauThu> listPlayerCT;
    setDataCTFromdataDb(listPlayerCT, danhSachDoiBong);
    luuThongTinCauThu(listPlayerCT);
    int luaChon;

    do {
        cout << "========== Menu ==========" << endl;
        cout << "1. Quan ly Doi bong" << endl;
        cout << "2. Quan ly Cau thu" << endl;
        cout << "3. Quan ly Tran dau" << endl;
        cout << "4. Hien thi thong tin" << endl;
        cout << "5. Thoat" << endl;
        cout << "===========================" << endl;
        cout << "Nhap lua chon cua ban (1-5): ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            //{
            cout << "1. Them Doi bong" << endl;
            cout << "2. Sua Doi bong" << endl;
            cout << "3. Xoa Doi bong" << endl;
            cout << "4. Hien thi thong tin 1 doi bong" << endl;
            int luaChonDoiBong;
            cout << "Nhap lua chon cua ban (1-4): ";
            cin >> luaChonDoiBong;

            if (luaChonDoiBong == 1) {
                string tenDoiBong, diaPhuong, huanLuyenVien;
                cout << "Nhap ten doi bong: ";
                cin.ignore();
                getline(cin, tenDoiBong);
                cout << "Nhap dia phuong: ";
                getline(cin, diaPhuong);
                cout << "Nhap ten huan luyen vien: ";
                getline(cin, huanLuyenVien);
                int dem;
                vector<CauThu> danhsachcauthu;
                cout << "Nhap danh sach cau thu: " << endl;
                cout << "So luong cau thu can them: ";
                cin >> dem;
                cin.ignore();
                for (int i = 0; i < dem; i++) {
                    string id, ten, quoctich, sinhnhat, chieucao, cannang, vitritd;
                    cout << "Nhap cau thu thu: " << i + 1 << endl;
                    cout << "nhap CCCD : "; getline(cin, id);
                    for (int j = 0; j < listPlayerCT.size(); j++) {
                        if (listPlayerCT[i].getID() == id) {
                            cout << "so can cuoc cong dan da ton tai!!" << endl << "Vui long nhap lai." << endl;
                            i--;
                            break;
                        }
                        if (j == listPlayerCT.size() - 1) {
                            cout << "nhap ho va ten : ";  getline(cin, ten);
                            cout << "nhap quoc tich : "; getline(cin, quoctich);
                            cout << "nhap ngay thang nam sinh : "; getline(cin, sinhnhat);
                            cout << "nhap chieu cao : "; getline(cin, chieucao);
                            cout << "nhap can nang : "; getline(cin, cannang);
                            cout << "nhap vi tri thi dau : "; getline(cin, vitritd);
                            danhsachcauthu.push_back(CauThu(id, ten, quoctich, sinhnhat, chieucao, cannang, vitritd, tenDoiBong));
                            listPlayerCT.push_back(CauThu(id, ten, quoctich, sinhnhat, chieucao, cannang, vitritd, tenDoiBong));
                            break;
                        }
                    }
                }

                danhSachDoiBong.push_back(doibong(tenDoiBong, diaPhuong, huanLuyenVien, danhsachcauthu));
                cout << "Them doi bong thanh cong." << endl;

                auto i = danhSachDoiBong.end() - 1;
                cout << i->getTenDoiBong();

                // Lưu thông tin vào tệp tin
                luuThongTinDoiBong(danhSachDoiBong);
                luuThongTinCauThu(listPlayerCT);
            }
            // Xử lý sửa thông tin Đội bóng
            else if (luaChonDoiBong == 2) {
                string tenDoiBong;
                cout << "Nhap ten doi bong can sua: ";
                cin.ignore();
                getline(cin, tenDoiBong);

                // Tìm đội bóng cần sửa
                int index = -1;
                for (int i = 0; i < danhSachDoiBong.size(); ++i) {
                    if (danhSachDoiBong[i].getTenDoiBong() == tenDoiBong) {
                        index = i;
                        break;
                    }
                }

                if (index != -1) {
                    string diaPhuong, huanLuyenVien;
                    int luaChon;
                    cout << "Nhap dia phuong moi: ";
                    getline(cin, diaPhuong);
                    cout << "Nhap ten huan luyen vien moi: ";
                    getline(cin, huanLuyenVien);
                    cout << "1. Them cau thu vao danh sach." << endl;
                    cout << "2. Xoa cau thu khoi danh sach." << endl;
                    cout << "0. Khong thay doi danh sach cau thu." << endl;
                    cin >> luaChon;
                    switch (luaChon) {
                    case 1:
                    {
                        string id, ten, quoctich, sinhnhat, chieucao, cannang, vitritd;
                        cout << "nhap CCCD : ";
                        cin.ignore();
                        getline(cin, id);
                        for (int i = 0; i < danhSachDoiBong[index].getdscauthu().size(); i++) {
                            if (danhSachDoiBong[index].getdscauthu()[i].getID() == id) {
                                cout << "So CCCD da ton tai!" << endl;
                                break;
                            }
                            if (i == danhSachDoiBong[index].getdscauthu().size() - 1) {
                                cout << "nhap ho va ten : ";  getline(cin, ten);
                                cout << "nhap quoc tich : "; getline(cin, quoctich);
                                cout << "nhap ngay thang nam sinh : "; getline(cin, sinhnhat);
                                cout << "nhap chieu cao : "; getline(cin, chieucao);
                                cout << "nhap can nang : "; getline(cin, cannang);
                                cout << "nhap vi tri thi dau : "; getline(cin, vitritd);
                                CauThu cauthu(id, ten, quoctich, sinhnhat, chieucao, cannang, vitritd, tenDoiBong);
                                listPlayerCT.push_back(cauthu);
                                danhSachDoiBong[index].themcauthuvaodanhsach(cauthu);
                            }
                        }
                        break;
                    }
                    case 2:
                        string id;
                        cin.ignore();
                        cout << "nhap CCCD cau thu can xoa: "; getline(cin, id);
                        danhSachDoiBong[index].xoacauthukhoids(id);
                        break;
                    }

                    //Cập nhật thông tin đội bóng
                    danhSachDoiBong[index].suadoibong(tenDoiBong, diaPhuong, huanLuyenVien);

                    // Lưu thông tin vào tệp tin
                    luuThongTinDoiBong(danhSachDoiBong);
                    luuThongTinCauThu(listPlayerCT);

                    cout << "Sua thong tin doi bong thanh cong." << endl;
                }
                else {
                    cout << "Khong tim thay doi bong co ten " << tenDoiBong << "." << endl;
                }
            }

            // Xử lý xóa Đội bóng
            else if (luaChonDoiBong == 3) {
                string tenDoiBong;
                cout << "Nhap ten doi bong can xoa: ";
                cin.ignore();
                getline(cin, tenDoiBong);

                // Tìm đội bóng cần xóa
                int index = -1;
                for (int i = 0; i < danhSachDoiBong.size(); ++i) {
                    if (danhSachDoiBong[i].getTenDoiBong() == tenDoiBong) {
                        index = i;
                        break;
                    }
                }

                if (index != -1) {
                    // Xóa đội bóng khỏi danh sách
                    danhSachDoiBong.erase(danhSachDoiBong.begin() + index);

                    // Lưu thông tin vào tệp tin
                    luuThongTinDoiBong(danhSachDoiBong);

                    cout << "Xoa doi bong thanh cong." << endl;
                }
                else {
                    cout << "Khong tim thay doi bong co ten " << tenDoiBong << "." << endl;
                }
            }
            else if (luaChonDoiBong == 4) {
                string tenDB;
                cout << "Nhap ten doi bong can tim :";
                cin.ignore();
                getline(cin, tenDB);
                for (auto i = danhSachDoiBong.begin(); i != danhSachDoiBong.end(); i++) {
                    if (i->getTenDoiBong() == tenDB) {
                        i->inThongTin();
                        continue;
                    }
                    if (i == danhSachDoiBong.end() - 1) {
                        cout << "Khong tim thay!" << endl;
                    }
                }
            }
            else {
                cout << "Lua chon khong hop le." << endl;
            }
            break;
            //}
        case 2:
            // xử lý quản lý cầu thủ
        {
            int select;
            menu();
            cout << "----------------------------------------";
            cout << "\nchon so de thuc hien : ";
            cin >> select;
            cin.ignore();
            switch (select) {
            case 1:
            {
                string cmnd;
                cout << "vui long nhap CCCD can tim : ";
                cin >> cmnd;
                for (int i = 0; i < listPlayerCT.size(); i++) {
                    if (cmnd == listPlayerCT[i].getID()) {
                        listPlayerCT[i].getPlayer();
                        break;
                    }
                    if (i == listPlayerCT.size() - 1) {
                        cout << "khong tim thay!!!!!!!!" << endl;
                    }
                }
            }
            break;
            case 2:
            {
                CauThu t;
                int check;
                do {
                    check = t.AddPlayer(listPlayerCT);
                    if (check == 2) {
                        listPlayerCT.push_back(t);
                        cout << "nhap du lieu thanh cong !" << endl;
                        break;
                    }
                } while (check);
                luuThongTinCauThu(listPlayerCT);
            }
            break;
            case 3:
            {
                CauThu t;
                t.deletePlayer(listPlayerCT);
                luuThongTinCauThu(listPlayerCT);
            }
            break;
            case 4:
            {
                CauThu t;
                t.modifyPlayer(listPlayerCT);

                luuThongTinCauThu(listPlayerCT);
            }
            break;
            case 5:
            {
                CauThu t;
                t.listingPlayer(listPlayerCT);
            }
            break;
            case 6:
            {
                CauThu t;
                cout << "cau thu tre nhat la : " << endl;
                t.getYoungestPlayer(listPlayerCT);
            }
            break;
            case 7:
            {
                CauThu t;
                cout << "cau thu cao nhat la : " << endl;
                t.getTallestPlayer(listPlayerCT);
            }
            break;
            case 8:
            {
                CauThu t;
                cout << "cau thu thap nhat la : " << endl;
                t.
                    getShortestPlayer(listPlayerCT);
            }
            break;
            }
        }
        break;
        case 3:
            // xử lý quản lý trận đấu
            break;
        case 4:
            // xử lý hiển thị thông tin
            break;
        case 5:
            cout << "thoat khoi chuong trinh." << endl;
            break;
        default:
            cout << "lua chon khong hop le. vui long chon lai." << endl;

        }
    } while (luaChon != 5);

    return 0;
}





