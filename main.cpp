#include "KhoaHoc.h"

int main() {

    // Đây là chỉnh sửa đầu tiên
    
    Candidate c1;
    cout << "Thi sinh mac dinh:\n" << c1 << endl;

    Candidate c2("TS001", "Nguyen Van A", true, 2004, 8.5f);
    cout << "\nThi sinh c2:\n";
    c2.output();

    Candidate c3(c2);
    cout << "\nThi sinh c3 (sao chep c2):\n" << c3 << endl;

    Candidate c4;
    cout << "\nNhap thi sinh c4:\n";
    cin >> c4;

    cout << "\nThong tin c4:\n" << c4 << endl;
    cout << "Tuoi cua c4: " << c4.getTuoi() << endl;

    KhoaHoc kh;
    kh.them(new Candidate("TS001", "Nguyen Van A", true, 2004, 8.5f));
    kh.them(new Candidate("TS002", "Tran Thi B", false, 2003, 9.0f));
    kh.them(new Candidate("TS003", "Le Van C", true, 2005, 7.0f));
    Candidate* trung = new Candidate("TS001", "Trung", true, 2000, 5);
    bool ok = kh.them(trung);
    cout << "\nThem trung ma TS001: " << (ok ? "OK" : "that bai") << endl;
    if (!ok) delete trung;

    cout << "\nSap xep theo DTB:\n";
    kh.sapXep(DTB);
    kh.xuat();

    Candidate* tim = kh.timTheoMaSo("TS002");
    if (tim) cout << "\nTim TS002: " << *tim << endl;

    Candidate* xoa = kh.xoa("TS003");
    delete xoa;
    cout << "\nSau khi xoa TS003 (" << kh.soLuong() << " thi sinh):\n";
    kh.xuat();
    return 0;
}
