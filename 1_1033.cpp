#include <iostream>
using std::cin;
using std::cout;

/*
 * 采用逆序数的方法求行列式
 * 采用C++自带的数组存储矩阵，不属于STL
 */


int arr[10]; // 用于求全排列
int reverse_order = 0; // 逆序数
int** matrix; // 存储矩阵
int n;
int ans = 0;

void InilData()
{
    cin >> n;
    // 生成序列
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    // 获取矩阵
    matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
}


// 运算过程处理
void DataPocess()
{
    int temp = 1;
    for (int j = 0; j < n; j++)
    {
        temp = temp * matrix[j][arr[j]];
    }
    if (reverse_order % 2 == 0)
    {
        ans = ans + temp;
    }
    if (reverse_order % 2 == 1)
    {
        ans = ans - temp;
    }
}


void swap(int i, int k)
{
    if (i != k)
        reverse_order++;
    int temp = arr[i];
    arr[i] = arr[k];
    arr[k] = temp;
}


// 获取所有的全排列
void GetAllSequence(int k)
{
    if (k == n)
    {
        DataPocess();
    }
    else
        for (int i = k; i < n; i++)
        {
            swap(i, k);
            GetAllSequence(k + 1);
            swap(i, k);
        }
}


// 回收空间
void EndProcess()
{
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}


int main()
{
    InilData();
    GetAllSequence(0);
    cout << ans;
    EndProcess();
    return 0;
}
