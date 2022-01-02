#include <iostream>
#include <time.h>
#include <math.h>
#define MAX 100
using namespace std;

/*
   tạo ma trận
*/
void taomatran(int a[][MAX],int h,int c)
{
    srand(time(NULL));
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<c; j++)
        {
            a[i][j]=rand()%118 - 39;
        }
    }
}

/*
   xuất ma trận
*/
void xuatmatran(int a[][MAX] , int h, int c)
{
    cout << "\nMa tran vua nhap la: \n";
    for(int i=0 ; i<h ; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(a[i][j] >= -39 && a[i][j] <= -10 ) cout << a[i][j] << "    ";
            if(a[i][j] >= -9 && a[i][j] <= -1 )   cout << a[i][j] << "     ";
            if(a[i][j] < 10 && a[i][j] >= 0 )     cout << " " << a[i][j] << "     ";
            if(a[i][j] <= 79 && a[i][j] >=10 )    cout << " " << a[i][j] << "    ";
        }
        cout << endl << endl;
    }
    cout << endl;
}

/*
    gán biến a_max = a[0][0] rồi so sánh với từng phần tử trong ma trận
    nếu a_max nhỏ hơn a[i][j] thì gán lại a_max = a[i][j]
    INPUT: các phần tử của ma trận a, số hàng, số cột
    OUTPUT: a_max
*/
int phantulonnhat(int a[][MAX], int h, int c)
{
    int a_max = a[0][0];
    for(int i=0; i<h; i++)
    {
        for(int j=1; j<c; j++)
        {
            if(a[i][j]> a_max) a_max=a[i][j];
        }
    }
    return a_max;
}

/*
    nếu số hàng = số cột thì xuất ra true, ngược lại xuất ra false
    INPUT: số hàng, số cột
    OUTPUT: true/ false
*/
bool kiemtra_mtvuong(int h, int c)
{
    if(h==c) return true;
    return false;
}

/*
    các phần tử nằm trên đường chéo chính có số hàng bé hơn hoặc bằng số cột
    INPUT: các phần tử của ma trận a, số hàng, số cột
    OUTPUT: a[i][j] với i <= j
*/
void duongcheochinh(int a[][MAX], int h, int c)
{
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(i<=j) cout << a[i][j] << "    ";
        }
    }
}

/*
    các phần tử a[i][j] nằm trên đường chéo phụ có tổng i+j bé hơn 1/2(số hàng+ số cột)
    INPUT: các phần tử của ma trận a, số hàng, số cột
    OUTPUT: a[i][j] với i+j< 1/2(h+c)
*/
void duongcheophu(int a[][MAX], int h, int c)
{
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<c; j++)
        {
            if((i+j) <= c-1) cout << a[i][j] << "   ";
        }
    }
}

/*
    tìm gtnn trên từng dòng
    INPUT: các phần tử của ma trận a, số hàng, số cột
    OUTPUT: gtnn của từng dòng
*/
void GTNN_dong(int a[][MAX], int h, int c)
{
    for(int i=0; i<h; i++)
    {
        int min_dong = 79;
        for(int j=0; j<c; j++)
        {
            if(a[i][j] < min_dong) min_dong=a[i][j];
        }
        cout << "  + gia tri nho nhat cua dong " << i+1 << " la: " << min_dong << endl;
    }
}

/*
    tìm gtln của từng cột
    INPUT: các phần tử của ma trận a, số hàng, số cột
    OUTPUT: gtln của từng cột
*/
void GTLN_cot(int a[][MAX], int h, int c)
{
    for(int i=0; i<c; i++)
    {
        int max_cot = -39;
        for(int j=0; j<h; j++)
        {
            if(a[j][i] > max_cot) max_cot = a[j][i];
        }
        cout << "  + gia tri lon nhat cua cot " << i+1 << " la: " << max_cot << endl;
    }
}

/*
    kiểm tra từng phần tử của ma trận có phải phần tử lẻ không, nếu lẻ thì trả về false và kết thúc,
    ngược lại kiểm tra phần tử kế tiếp đến hết và trả về true
    INPUT: các phần tử của ma trận a, số hàng, số cột
    OUTPUT: true/false
*/
bool mangchan(int a[][MAX], int h, int c)
{
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(a[i][j]%2 == 1) return false;
        }
    }
    return true;
}

/*
    kiểm tra từng phần tử có phải số nguyên tố không, nếu phải thì xuất ra phần tử đó
    INPUT: các phần tử của ma trận a, số hàng, số cột
    OUTPUT: các số nguyên tố có trong ma trận
*/
void songuyento(int a[][MAX], int h, int c)
{
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<c; j++)
        {
            int kt = 0;
            for(int k=2; k < abs(a[i][j]); k++)
            {
                if(a[i][j] % k == 0) kt = 1;
            }
            if(kt == 0) cout << a[i][j] << "    ";
        }
    }
}

/*
    kiểm tra từng số nguyên từ -39 đến 79, nếu có trong ma trận thì đếm có bao nhiêu
    phần tử bằng số nguyên đó, sau đó xuất ra số lượng
    INPUT: các phần tử của ma trận a, số hàng, số cột
    OUTPUT: số lần xuất hiện của giá trị x
*/
void tansuat(int a[][MAX], int h, int c)
{
    int i=0, j=0;
    for(int x=-39; x<79; x++)
    {
        int dem=0;
        for(i=0; i<h; i++)
        {
            for(j=0; j<c; j++)
            {
                if(a[i][j]==x) dem++;
            }
        }
        if(dem != 0) cout << "so lan xuat hien cua gia tri " << x << " la: " << dem << endl;
    }
}

int main()
{
    int a[MAX][MAX], h, c, w;
    cout << "Nhap so hang cua ma tran: ";
    cin >> h;
    cout << "Nhap so cot cua ma tran: ";
    cin >> c;

    taomatran(a, h, c);
    xuatmatran(a, h, c);

    cout << "                  MENU                   \n";
    cout << " __________________________________________\n";
    cout << "| 1. tim phan tu lon nhat cua mang.         |\n";
    cout << "| 2. kiem tra ma tran co vuong hay khong.   |\n";
    cout << "| 3. in ra cac phan tu nam nua tren duong   |\n";
    cout << "| cheo chinh.                               |\n";
    cout << "| 4. in ra cac phan tu nam nua tren duong   |\n";
    cout << "| cheo phu.                                 |\n";
    cout << "| 5. tim gia tri nho nhat tren tung dong.   |\n";
    cout << "| 6. tim gia tri lon nhat tren tung cot.    |\n";
    cout << "| 7. kiem tra mang toan gia tri chan.       |\n";
    cout << "| 8. liet ke cac so nguyen to.              |\n";
    cout << "| 9. liet ke tan suat cac gt co trong mang. |\n";
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout << "Nhap lua chon: ";
    cin >> w;
    while(w<1 || w>9)
    {
        cout << "Nhap sai gia tri, nhap lai: ";
        cin >> w;
    }
    switch (w)
    {
        case 1: cout << "phan tu lon nhat cua ma tran la: " << phantulonnhat(a, h, c) << endl;
                break;

        case 2: if(kiemtra_mtvuong(h, c)==true) cout << "\nma tran vua nhap la ma tran vuong\n";
                else cout << "\nma tran vua nhap khong phai ma tran vuong\n";
                break;

        case 3: cout << "\ncac phan tu nam nua tren duong cheo chinh la: \n";
                duongcheochinh(a, h, c);
                break;

        case 4: cout << "\n\ncac phan tu nam nua tren duong cheo phu la: \n";
                duongcheophu(a, h, c);
                break;

        case 5: cout << "\n\ncac gia tri nho nhat tren dong : \n";
                GTNN_dong(a, h, c);
                break;

        case 6: cout << "\ncac gia tri lon nhat tren cot : \n";
                GTLN_cot(a, h, c);
                break;

        case 7: if(mangchan(a, h, c)==true) cout << "\nma tran vua nhap co tat ca phan tu la so chan\n";
                else cout << "\nma tran vua nhap co mot so phan tu khong phai so chan\n";
                break;

        case 8: cout << "\ncac so nguyen to co trong mang la: \n";
                songuyento(a, h, c);
                break;

        case 9: cout << "\n\ntan suat xuat hien cua cac phan tu cua ma tran la: \n";
                tansuat(a, h, c);
                break;
    }
    return 0;
}
