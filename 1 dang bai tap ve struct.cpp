#include<iostream>
#include<string>
using namespace std;
struct sinhvien
{

	string mssv;
	string hoten;
	double diemtb;
 };

void inputstudent(sinhvien a[], int n);
void timsinhviencodiemtrungbinhcaonhat(sinhvien a[], int n);
void swap(sinhvien& a, sinhvien& b);
int main() 
{
	sinhvien a[100];
	cout << "Nhap vao so luong sinh vien" << endl;
	int n; cin >> n;
	
	
	
		inputstudent(a, n);
	
	timsinhviencodiemtrungbinhcaonhat(a, n);
	cout << "--------DANH SACH SINH VIEN CO THUONG---------" << endl;
	for (int i = 0; i <2; i++)
	{
		cout << endl;
		cout << a[i].mssv << endl;
		cout << a[i].hoten << endl;
		cout << a[i].diemtb << endl;
		cout << endl;
	}
}

void inputstudent(sinhvien a[], int n)
{  
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vao thong tin cua sinh vien thu " << i + 1 << " : " << endl;
		while (cin.get() != '\n');
		cout << "Nhap mssv:" << endl;
		getline(cin, a[i].mssv);
		cout << "Nhap ho ten:" << endl;
		getline(cin, a[i].hoten);
		cout << "Nhap diem trung binh:" << endl;
		cin >> a[i].diemtb;
	}
}
void timsinhviencodiemtrungbinhcaonhat(sinhvien a[], int n )
{    
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[i].diemtb <a[j].diemtb)
		    {
				swap(a[i], a[j]);
		    }
			else if (a[i].diemtb == a[j].diemtb)
			{
				if (a[i].mssv > a[j].mssv)
				{
					swap(a[i], a[j]);
				}
			}

	}
}
void swap(sinhvien&a, sinhvien&b)
{
	sinhvien tmp;
	tmp = a;
	a = b;
	b = tmp;
	
}
