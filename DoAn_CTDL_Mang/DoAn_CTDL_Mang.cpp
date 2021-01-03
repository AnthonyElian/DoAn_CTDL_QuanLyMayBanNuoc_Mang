#include <iostream>
#include<string.h>

#define MAX 100
using namespace std;

typedef struct MayBanNuocGiaiKhat
{
    string sTenSanPham;
    int iSoLuongSanPham;
    string sMaSanPham;
    double dGiaBan;
}SanPham;

void Nhap(SanPham& x);
void NhapList(SanPham A[], int& n);
void Xuat(SanPham x);
void XuatList(SanPham A[], int n);
void Remove(SanPham A[], int& n, int pos);
void InsertRandom(SanPham A[], int& n, int pos, SanPham x);
void InsertSort(SanPham A[], int& n, SanPham x);
int TongSanPhamCoTrongMayBan(SanPham A[], int n);
double TongGiaTri(SanPham A[], int n);
void MenuMayBan(SanPham A[], int n, SanPham& x);
SanPham* Search(SanPham A[], int n);
void SapXepTheoGiaBan(SanPham A[], int left, int right);
void SapXepTheoSoLuong(SanPham A[], int n);
void CacSanPhamCoCungSoLuong(SanPham A[], int n);
void MuaHang(SanPham A[], int& n, double& tien);

int main()
{
    SanPham A[MAX], x;
    int n;
    NhapList(A, n);
    MenuMayBan(A, n, x);
    return 0;
}

void MenuMayBan(SanPham A[], int n, SanPham& x)
{
    int flag = 1;
    while (flag)
    {
        cout << "\t\t\t******************************Menu******************************\t\t\t" << endl;
        cout << "\t\t\t***             1. Them San Pham vao vi tri bat ki           ***\t\t\t" << endl;
        cout << "\t\t\t***             2. Them San Pham (mang da sap xep)           ***\t\t\t" << endl;
        cout << "\t\t\t***             3. Xoa San Pham khoi danh sach               ***\t\t\t" << endl;
        cout << "\t\t\t***             4. Tong So Luong San Pham hien co            ***\t\t\t" << endl;
        cout << "\t\t\t***             5. Tong Gia Tri cua tat ca san pham          ***\t\t\t" << endl;
        cout << "\t\t\t***             6. Tim kiem San Pham theo ten                ***\t\t\t" << endl;
        cout << "\t\t\t***             7. Sap xep theo Gia Ban                      ***\t\t\t" << endl;
        cout << "\t\t\t***             8. Sap xep theo So Luong                     ***\t\t\t" << endl;
        cout << "\t\t\t***             9. Xuat San Pham co cung so luong            ***\t\t\t" << endl;
        cout << "\t\t\t***            10. Mua Hang                                  ***\t\t\t" << endl;
        cout << "\t\t\t***            11. Thoat                                     ***\t\t\t" << endl;
        cout << "\t\t\t****************************************************************\t\t\t" << endl;
        int choice;
        cout << "Your choice: "; cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Moi nhap thong tin San Pham muon them vao!!\n";
            Nhap(x); int pos;
            cout << "Moi nhap Vi Tri muon them vao: "; cin >> pos;
            InsertRandom(A, n, pos, x);
            XuatList(A, n);
            break;
        }
        case 2:
        {
            cout << "Moi nhap thong tin San Pham muon them vao!!\n";
            Nhap(x);
            InsertSort(A, n, x);
            XuatList(A, n);
            break;
        }
        case 3:
        {
            XuatList(A, n); int pos;
            cout << "Ban muon xoa San Pham thu may: "; cin >> pos;
            Remove(A, n, pos - 1);
            XuatList(A, n);
            break;
        }
        case 4:
        {
            cout << "Tong so luong tat ca san pham: " << TongSanPhamCoTrongMayBan(A, n) << " (San Pham)" << endl;
            break;
        }
        case 5:
        {
            cout << "Tong Gia Tri cua cac san pham tren la: " << TongGiaTri(A, n) << " (VND)" << endl;
            break;
        }
        case 6:
        {
            SanPham* temp = Search(A, n);
            if (temp != nullptr)
                cout << "Ten: " << temp->sTenSanPham << " \ MaSP: " << temp->sMaSanPham << " \ SoLuong: " << temp->iSoLuongSanPham << " \ GiaBan: " << temp->dGiaBan << endl;
            else
                cout << "Khong ton tai san pham\n";
            break;
        }
        case 7:
        {
            SapXepTheoGiaBan(A, 0, n - 1);
            XuatList(A, n);
            break;
        }
        case 8:
        {
            SapXepTheoSoLuong(A, n);
            XuatList(A, n);
            break;
        }
        case 9:
        {
            CacSanPhamCoCungSoLuong(A, n);
            break;
        }
        case 10:
        {
            cout << "Moi nhap so tien cua ban: "; double tien;
            cin >> tien;
            int flag1 = 1;
            while (flag == 1 && tien > 0)
            {
                MuaHang(A, n, tien);
                cout << "1_continue : ";
                cin >> flag;
            }
            break;
        }
        case 11:
        {
            flag = 0;
            break;
        }
        default:
        {
            cout << "Nhap sai vui long nhap lai!!" << endl;
            break;
        }
        }
    }
}

void MuaHang(SanPham A[], int& n, double& tien)
{

    cout << "Danh sach san pham ban co the mua: \n";
    for (int i = 0; i < n; i++)
    {
        if (A[i].dGiaBan <= tien)
        {
            cout << "San Pham: " << A[i].sTenSanPham << " ____ " << "So Luong con lai: " << A[i].iSoLuongSanPham << " ____ " << "Gia ban: " << A[i].dGiaBan << endl;
        }
    }
    cout << "Ban muon mua san pham ten gi?: ";
    string key;
    cin.ignore();
    cin >> key;
    int flag = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i].sTenSanPham == key)
        {
            flag = i;
            break;
        }
    }
    if (flag != -1)
    {
        cout << "Giao Dich Thanh Cong" << endl;
        A[flag].iSoLuongSanPham = A[flag].iSoLuongSanPham - 1;
        tien = tien - A[flag].dGiaBan;
        cout << "Tien con lai: " << tien << endl;
        if (A[flag].iSoLuongSanPham == 0)
            Remove(A, n, flag);
        for (int i = 0; i < n; i++)
        {
            cout << "San Pham: " << A[i].sTenSanPham << " ____ " << "So Luong con lai: " << A[i].iSoLuongSanPham << " ____ " << "Gia ban: " << A[i].dGiaBan << endl;
        }
    }
    else
    {
        cout << "Giao Dich That Bai_San pham da het hang!!\n";
    }
}

void CacSanPhamCoCungSoLuong(SanPham A[], int n)
{
    int temp;
    cout << "Moi nhap san pham co cung so luong bao nhieu: ";
    cin >> temp;
    for (int i = 0; i < n; i++)
    {
        if (A[i].iSoLuongSanPham == temp)
            Xuat(A[i]);
    }
}

void SapXepTheoSoLuong(SanPham A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        SanPham x = A[i]; int pos = i - 1;
        while ((pos >= 0) && (A[pos].iSoLuongSanPham > x.iSoLuongSanPham))
        {
            A[pos + 1] = A[pos];
            pos--;
        }
        A[pos + 1] = x;
    }
}

void SapXepTheoGiaBan(SanPham A[], int left, int right)
{
    int i = left, j = right;
    SanPham x = A[(i + j) / 2];
    while (i < j)
    {
        while (A[i].dGiaBan < x.dGiaBan) i++;
        while (A[j].dGiaBan > x.dGiaBan) j--;
        if (i <= j)
        {
            swap(A[i], A[j]);
            i++; j--;
        }
    }
    if (i < right) SapXepTheoGiaBan(A, i, right);
    if (left < j) SapXepTheoGiaBan(A, left, j);
}

SanPham* Search(SanPham A[], int n)
{
    string key;
    cout << "Moi nhap ten San Pham muon tim kiem: ";
    cin.ignore();
    cin >> key;
    SanPham* temp = nullptr;
    for (int i = 0; i < n; i++)
    {
        if (A[i].sTenSanPham == key)
        {
            temp = &A[i];
        }
    }
    return temp;
}

double TongGiaTri(SanPham A[], int n)
{
    double temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp + A[i].dGiaBan * A[i].iSoLuongSanPham;
    }
    return temp;
}

int TongSanPhamCoTrongMayBan(SanPham A[], int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp + A[i].iSoLuongSanPham;
    }
    return temp;
}

//Sap xep theo So Luong
void InsertSort(SanPham A[], int& n, SanPham x)
{
    if (n >= MAX)
    {
        cout << "Warning, cant Insert" << endl;
        return;
    }
    else
    {
        int temp = -1;
        for (int i = 0; i < n; i++)
        {
            if (A[i].iSoLuongSanPham > x.iSoLuongSanPham)
            {
                temp = i;
                break;
            }
        }
        if (temp == -1)
        {
            A[n] = x;
            n = n + 1;
        }
        else
        {
            InsertRandom(A, n, temp, x);
        }
    }
}

void InsertRandom(SanPham A[], int& n, int pos, SanPham x)
{
    if (n >= MAX || pos < 0 || pos > n)
    {
        cout << "Warning, cant Insert" << endl;
        return;
    }
    else
    {
        for (int i = n; i > pos; i--)
        {
            A[i] = A[i - 1];
        }
        A[pos] = x;
        n = n + 1;
    }
}

void Remove(SanPham A[], int& n, int pos)
{
    if (n <= 0 || pos < 0 || pos > n - 1)
    {
        cout << "Warning, cant Insert" << endl;
        return;
    }
    else
    {
        if (pos == n - 1)
            n = n - 1;
        else
        {
            for (int i = pos; i < n - 1; i++)
            {
                A[i] = A[i + 1];
            }
            n = n - 1;
        }
    }
}

void XuatList(SanPham A[], int n)
{
    cout << "XUAT!!\n";
    cout << "So Luong San Pham dang co: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "San Pham Thu " << i + 1 << ": " << endl;
        Xuat(A[i]);
    }
}

void Xuat(SanPham x)
{
    cout << "Ten San Pham la: " << x.sTenSanPham << endl;
    cout << "Ma San Pham la: " << x.sMaSanPham << endl;
    cout << "So Luong San Pham hien tai la: " << x.iSoLuongSanPham << endl;
    cout << "Gia Ban San Pham la: " << x.dGiaBan << " (VND)" << endl;
    cout << endl;
}

void NhapList(SanPham A[], int& n)
{
    cout << "NHAP!!\n";
    cout << "Moi nhap So Luong San Pham trong May Ban: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Moi nhap thong tin san pham thu " << i + 1 << ": " << endl;
        Nhap(A[i]);
    }
}

void Nhap(SanPham& x)
{
    cout << "Moi nhap Ten San Pham: ";
    cin.ignore();
    cin >> x.sTenSanPham;

    cout << "Moi nhap So Luong San Pham hien co: ";
    cin >> x.iSoLuongSanPham;

    cout << "Moi nhap Ma San Pham: ";
    cin.ignore();
    cin >> x.sMaSanPham;

    cout << "Moi nhap Gia Ban: ";
    cin >> x.dGiaBan;
    cout << endl;
}
