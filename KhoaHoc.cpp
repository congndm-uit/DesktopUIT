#include "KhoaHoc.h"

KhoaHoc::KhoaHoc() {}

KhoaHoc::~KhoaHoc() {
    for (Candidate* c : dsThiSinh) delete c;
}

bool KhoaHoc::them(Candidate* candidate) {
    if (candidate == nullptr || timTheoMaSo(candidate->getMaSo()) != nullptr)
        return false;
    candidate->setKhoaHoc(this);
    dsThiSinh.push_back(candidate);
    return true;
}

Candidate* KhoaHoc::xoa(string maso) {
    return xoa(timTheoMaSo(maso));
}

Candidate* KhoaHoc::xoa(Candidate* candidate) {
    if (candidate == nullptr) return nullptr;
    for (size_t i = 0; i < dsThiSinh.size(); i++) {
        if (dsThiSinh[i] == candidate) {
            dsThiSinh.erase(dsThiSinh.begin() + i);
            candidate->setKhoaHoc(nullptr);
            return candidate;
        }
    }
    return nullptr;
}

Candidate* KhoaHoc::timTheoMaSo(string maSoThiSinh) {
    for (Candidate* c : dsThiSinh)
        if (c->getMaSo() == maSoThiSinh) return c;
    return nullptr;
}

vector<Candidate*> KhoaHoc::timTheoHoTen(string hoTenThiSinh) {
    vector<Candidate*> kq;
    for (Candidate* c : dsThiSinh)
        if (c->getHoTen().find(hoTenThiSinh) != string::npos) kq.push_back(c);
    return kq;
}

vector<Candidate*> KhoaHoc::timTheoDTB(float dtb) {
    vector<Candidate*> kq;
    for (Candidate* c : dsThiSinh)
        if (c->getDtb() == dtb) kq.push_back(c);
    return kq;
}

void KhoaHoc::sapXep(ThuocTinh thuocTinh) {
    for (size_t i = 1; i < dsThiSinh.size(); i++) {
        Candidate* key = dsThiSinh[i];
        size_t j = i;
        while (j > 0 && soSanh(dsThiSinh[j - 1], key, thuocTinh) > 0) {
            dsThiSinh[j] = dsThiSinh[j - 1];
            j--;
        }
        dsThiSinh[j] = key;
    }
}

void KhoaHoc::xuat() const {
    for (Candidate* c : dsThiSinh) cout << *c << endl;
}

int KhoaHoc::soLuong() const { return (int)dsThiSinh.size(); }

int KhoaHoc::soSanh(Candidate* c1, Candidate* c2) {
    return soSanh(c1, c2, MA_SO);
}

int KhoaHoc::soSanh(Candidate* c1, Candidate* c2, ThuocTinh thuocTinh) {
    auto cmp = [](const auto& a, const auto& b) { return a < b ? -1 : (a > b ? 1 : 0); };
    switch (thuocTinh) {
        case MA_SO:     return cmp(c1->getMaSo(), c2->getMaSo());
        case HO_TEN:    return cmp(c1->getHoTen(), c2->getHoTen());
        case NAM_SINH:  return cmp(c1->getNamSinh(), c2->getNamSinh());
        case GIOI_TINH: return cmp(c1->getGioiTinh(), c2->getGioiTinh());
        case DTB:       return cmp(c1->getDtb(), c2->getDtb());
    }
    return 0;
}
