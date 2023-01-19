#include<fstream>
#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;

struct sinhvien
{
	string ten;
	string diachi;
	string number;
	double diemtb;
};
struct date
{
	int d, m, y;
};
bool check(date d1);
double findhighestpoints(sinhvien a[], int n);
void reducearray(int a[], int& n);
void xoaphantutrung(int a[], int& n);
long long power(int x, int y);
int waystodivide(int a[], int n, int d, int m);
int main(int argc, const char* argv[])
{
	
	int choice ;
	while (true) {
		cout << "1. Do task 1" << endl;
		cout << "2. Do task 2" << endl;
		cout << "3. Do task 3" << endl;
		cout << "4. Do task 4" << endl;
		cout << "5. Do task 5" << endl;
		cout << "6. Do task 6" << endl;
		cout << "7. Do task 7" << endl;
		cout << "8. Do task 8" << endl;
		cout << "9. Do task 9" << endl;
		cout << "0. Exit" << endl;

		cout << "Your choice: ";
		cin >> choice;
		
		//char mssv[100];
		//char ten[100];
		//char gioitinh[50];
		sinhvien a[200]; int sl = 0;
		// Muon doc file co nhieu dong thi dung vong lap while(!fin.eof())
		//--> Y nghia: khi chua toi cuoi File thi tiep tuc thuc hien chuong trinh.
		if (choice == 1)
		{
			const char* pathin = "0123.txt";
			const char* pathout = "out0123.txt";
			ofstream fout;
			ifstream fin;
			fin.open(pathin);
			while (!fin.eof())
			{
				getline(fin, a[sl].ten, '(');
				//cin >> n;

				getline(fin, a[sl].diachi, ')');

				getline(fin, a[sl].number);

				//fin.ignore();
				sl++;
			}

			fin.close();
			for (int i = 0; i < sl; i++)
			{
				cout << a[i].ten << "(" << a[i].diachi << ")" << a[i].number << endl;
			}

			fout.open(pathout, ios::trunc);
			for (int i = 0; i < sl; i++)
			{
				if (a[i].number[0] == '0' && a[i].number[1] == '9' && a[i].number[2] == '8')
					fout << a[i].ten << "(" << a[i].diachi << ")" << a[i].number << endl;
			}
			fout.close();
		}
		else if (choice == 2)
		{
			const char* pathin = "tranductung.txt";
			ifstream fin;
			fin.open(pathin);
				int n; fin >> n; int a[100];
				for (int i = 0; i < n; i++)
				{

					fin >> a[i];
				}
				int d, m; fin >> d >> m;
				fin.close();
				int dem = waystodivide(a, n, d, m);
				cout << dem << endl;
		
		
		}
		else if (choice == 3)
		{
			int socach = 0;
			
			int n; cout << "To tien can doi co menh gia la:" << endl; cin >> n;
			int n1 = n / 5; // So tien 5d toi da co the doi 
			int n2 = n / 2;// So tien 2d toi da co the doi 
			int n3 = n;  // So tien 1d toi da co the doi 
			for (int x = 0; x <= n1; x++)
			{
				for (int y = 0; y <= n2; y++)
				{
					for (int z = 0; z <= n3; z++)
					{
						if (z + y * 2 + x * 5 == n)
						{
							socach++;
						}
					}
				}
			}
			cout << socach << endl;
		}
		else	if (choice == 4)
		{
			cout << "Rut gon mang bang cach cong cac so chan lien tiep vao voi nhau" << endl;
			int a[100]; int b; cout << "Nhap vao so luong phan tu cua mang:" << endl;
			cin >> b;
			cout << "Nhap vao cac phan tu cua mang:" << endl;
	// Nhap vao mang.
			for (int i = 0; i < b; i++)
			{
				cin >> a[i];
			}
    //Goi ham thuc hien rut gon cac phan tu chan.
			reducearray(a, b);
	// Xuat ra ket qua.		
			cout << "Mang sau khi da rut gon la:" << endl;
			for (int i = 0; i < b; i++)
			{
				cout << a[i]<<" ";
			}
			cout << endl;
		}
		else if (choice == 5)
		{
			cout << "Rut gon mang bang cach xoa cac phan tu trung nhau, uu tien giu lai phan tu co chi so nho hon trong mang"<< endl;
			int a[100]; int b; cout << "Nhap vao so luong phan tu cua mang:" << endl;
			cin >> b;
			cout << "Nhap vao cac phan tu cua mang:" << endl;
			// Nhap vao mang.
			for (int i = 0; i < b; i++)
			{
				cin >> a[i];
			}
			//Goi ham xu li de xoa phan tu trung nhau trong mang.
			xoaphantutrung(a, b);
			// Xuat ra ket qua.
			cout << "Cac phan tu cua mang sau khi da xoa cac phan tu trung nhau la:" << endl;
			for (int i = 0; i < b; i++)
			{
				cout<< a[i]<<" ";
			}
			cout << endl;
		}
		else if (choice == 6)
		{
			date x;
			cin >> x.d >> x.m >> x.y;
			if (check(x)==true)
			{
				cout << x.d << "/" << x.m << "/" << x.y << " la nam hop le." << endl;
			}
			else if (check(x)==false)
			{
				cout << x.d << "/" << x.m << "/" << x.y << " la nam khong hop le." << endl;
			}
		}
		else if (choice == 7)
		{
			const char* pathout = "output0120.txt";
			ofstream fout;
			fout.open(pathout,ios::trunc);
			int x = 2; int y = 1; int n1 = x, n2 = y;
			for (int z = 0; z < 2; z++)
			{
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (x * y >= 10)
						{
							fout << x << " x " << y << " = " << x * y << "  ";

						}
						else
						{
							fout << x << " x " << y << " =  " << x * y << "  ";
						}
						x++;
					}
					fout << endl;
					x = n1; y++;
				}
				fout << endl<<endl;
				x = 6; y = 1; n1 = 6;
			}
			fout.close();
		}
		else if (choice == 8)
		{
		int x; int y;
		cout << "Nhap vao x:" << endl;
		cin >> x;
		cout << "Nhap vao y:" << endl;
		cin >> y;
		long long n= power(x, y);
		cout << n<<endl;

         }
		else if (choice == 9)
		{
		int n, m;  int a[100][100];
		char strdest[500]; char strsource[500]; char space[2] = " "; char endline[3] = "\n";
		cin >> n>> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}

		}
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				num = a[i][j];
				strcpy(strdest, to_string(num).c_str());
				
				strcpy(strdest, space);
				
			}
		
		}
		cout << strdest;
		
        }
		else if (choice == 0)
		{
			cout << "Exiting" << endl;
			break;
		}
		else 
		{
			cout << "Incorrect" << endl;
		}
	}

	return 0;
}
double findhighestpoints(sinhvien a[], int n)
{
	double max = a[0].diemtb;
	for (int i = 1; i < n; i++)
	{
		if (a[i].diemtb > max)
		{
			max = a[i].diemtb;
		}
	}
	return max;
}
void reducearray(int a[], int& n)
{
	int vt[100];
	int sl = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 1)
		{
			vt[sl++] = i;
		}
	}
	vt[0] = -1; vt[sl] = n; int sum = 0; 
	for (int i = 0; i < sl; i++)
	{
		if (vt[i + 1] - vt[i] > 2)
		{
			for (int j = vt[i] + 1; j < vt[i + 1]; j++)
			{
				sum = sum + a[j];
			}
			a[vt[i] + 1] = sum; sum = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i]%2 ==0 && a[i-1]%2 ==0)
		{
				for (int x = i; x < n-1; x++)
				{
					a[x] = a[x + 1];
				}
				--n; --i;
				
		}
	}
	
}
void xoaphantutrung(int a[], int& n)
// chhua xong, phan tu nao trung nhau thi xoa het.
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ( a[i] == a[j])
			{
				for (int k = j; k < n - 1; k++)
				{
					a[k] = a[k + 1];
				}
				--n; --j;
			}
		
		}

	}
}
bool check(date d1)
{
	bool check = true;
	if (d1.y % 400 == 0 || (d1.y%100!=0 && d1.y % 4==0))
	{
		switch (d1.m)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		{
			if (d1.d < 1 || d1.d>31)
			{
				check = false;
			}
			break;
		}
		case 4: case 6: case 9: case 11: 
		{
			if (d1.d < 1 || d1.d>30)
			{
				check = false;
			}
			break;
		}
		case 2:
		{
			if (d1.d < 1 || d1.d>29)
			{
				check = false;
			}
			break;
		}
		default:
		{
			check = false;
		}
		}
		}
	else
	{
		switch (d1.m)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		{
			if (d1.d < 1 || d1.d>31)
			{
				check = false;
			}
			break;
		}
		case 4: case 6: case 9: case 11:
		{
			if (d1.d < 1 || d1.d>30)
			{
				check = false;
			}
			break;
		}
		case 2:
		{
			if (d1.d < 1 || d1.d>28)
			{
				check = false;
			}
			break;
		}
		default:
		{
			check = false;
		}
		}
	}
	return check;
}
long long power(int x, int y)
{
	long long sum = x; long long sum1 = 0;
	for (int i = 0; i < y-1; i++)
	{
		for (int j = 0; j < x - 1; j++)
		{
			sum1 = sum1 + sum;
		}
		sum = sum + sum1; sum1 = 0;
	}
	return sum;
}
int waystodivide(int a[], int n, int d, int m)
{
	int sum = 0; int dem = 0; int sl = 0;
	for (int i = 0; i < n; i++)
	{
		sl = i;
		for (int j = 0; j < m; j++)
		{
			sum = sum + a[sl];
			sl++;
		}
		if (sum == d)
		{
			dem++;
		}
		sum = 0;
	}
	return dem;
}