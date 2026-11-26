//
// Created by Sử Nhật Hạ on 18/11/2026.
//

#ifndef DEMOCODEB04_CANDIDATE_H
#define DEMOCODEB04_CANDIDATE_H

#include <iostream>
#include <string>

using namespace std;

class KhoaHoc;

class Candidate {
    string maSo;
    string hoTen;
    bool gioiTinh;
    int namSinh;
    float dtb;
    KhoaHoc* khoaHoc;

public:
    Candidate();
    Candidate(
        string maSo,
        string hoTen,
        bool gioiTinh,
        int namSinh,
        float dtb,
        KhoaHoc* khoaHoc = nullptr);
    Candidate(const Candidate& candidate);
    virtual ~Candidate();

    void input();
    void output() const;
    int getTuoi() const;

    const string& getMaSo() const { return maSo; }
    const string& getHoTen() const { return hoTen; }
    bool getGioiTinh() const { return gioiTinh; }
    int getNamSinh() const { return namSinh; }
    float getDtb() const { return dtb; }

    KhoaHoc* getKhoaHoc() const;
    void setKhoaHoc(KhoaHoc* khoaHoc);

    friend istream& operator>>(istream& is, Candidate& candidate);
    friend ostream& operator<<(ostream& os, const Candidate& candidate);
};


#endif //DEMOCODEB04_CANDIDATE_H
