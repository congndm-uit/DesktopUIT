#include "Candidate.h"
#include <ctime>
#include <limits>

Candidate::Candidate()
    : maSo(""), hoTen(""), gioiTinh(true), namSinh(2000), dtb(0), khoaHoc(nullptr) {}

Candidate::Candidate(string maSo, string hoTen, bool gioiTinh,
                     int namSinh, float dtb, KhoaHoc* khoaHoc)
    : maSo(maSo), hoTen(hoTen), gioiTinh(gioiTinh),
      namSinh(namSinh), dtb(dtb), khoaHoc(khoaHoc) {}

Candidate::Candidate(const Candidate& c)
    : maSo(c.maSo), hoTen(c.hoTen), gioiTinh(c.gioiTinh),
      namSinh(c.namSinh), dtb(c.dtb), khoaHoc(c.khoaHoc) {}

Candidate::~Candidate() {}

void Candidate::input() {
    cout << "Nhap ma so: ";
    getline(cin >> ws, maSo);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap gioi tinh (1: Nam, 0: Nu): ";
    cin >> gioiTinh;
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    cout << "Nhap diem trung binh: ";
    cin >> dtb;
}

void Candidate::output() const {
    cout << *this << endl;
}

int Candidate::getTuoi() const {
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    return (t->tm_year + 1900) - namSinh;
}

KhoaHoc* Candidate::getKhoaHoc() const { return khoaHoc; }

void Candidate::setKhoaHoc(KhoaHoc* kh) { khoaHoc = kh; }

istream& operator>>(istream& is, Candidate& c) {
    c.input();
    return is;
}

ostream& operator<<(ostream& os, const Candidate& c) {
    os << "Ma so: " << c.maSo
       << " | Ho ten: " << c.hoTen
       << " | Gioi tinh: " << (c.gioiTinh ? "Nam" : "Nu")
       << " | Nam sinh: " << c.namSinh
       << " | DTB: " << c.dtb
       << " | Tuoi: " << c.getTuoi();
    return os;
}
