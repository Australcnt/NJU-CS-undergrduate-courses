#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
    int** p_data; //表示矩阵数据
    int row, col; //表示矩阵的行数和列数
public:
    Matrix(int r, int c); //构造函数
    Matrix(const Matrix& m); //拷贝构造函数
    ~Matrix(); //析构函数
    int*& operator[] (int i); //重载[], 对于Matrix对象m, 能够通过m[i][j]访问第i+1行、第j+1列元素
    Matrix& operator = (const Matrix& m); //重载=, 实现矩阵整体赋值, 若行/列不等, 归还空间并重新分配
    bool operator == (const Matrix& m) const; //重载==, 判断矩阵是否相等
    Matrix operator + (const Matrix& m) const; //重载+, 完成矩阵加法, 可假设两矩阵满足加法条件(两矩阵行、列分别相等)
    Matrix operator * (const Matrix& m) const; //重载*, 完成矩阵乘法, 可假设两矩阵满足乘法条件(this.col = m.row)
    void print();

    friend void f();
};

Matrix::Matrix(int r, int c)
{
    row = r;
    col = c;
    p_data = new int* [row];
    for (int i = 0; i < row; i++)
    {
        p_data[i] = new int[col];
        for (int j = 0; j < col; j++)
            p_data[i][j] = 0;
    }
}

Matrix::Matrix(const Matrix& m)
{
    row = m.row;
    col = m.col;
    p_data = new int* [row];
    for (int i = 0; i < row; i++)
    {
        p_data[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            p_data[i][j] = m.p_data[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < row; i++)
        delete[]p_data[i];
    delete[]p_data;
}

int*& Matrix::operator[] (int i)
{
    return p_data[i];
}

Matrix& Matrix::operator = (const Matrix& m)
{
    if (row != m.row || col != m.col)
    {
        this->~Matrix();
        p_data = new int* [m.row];
        for (int i = 0; i < m.row; i++)
        {
            p_data[i] = new int[m.col];
            for (int j = 0; j < m.col; j++)
                p_data[i][j] = 0;
        }
        row = m.row;
        col = m.col;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            p_data[i][j] = m.p_data[i][j];
        }
    }
    return *this;
}

bool Matrix::operator == (const Matrix& m) const
{
    if (row != m.row || col != m.col)
        return false;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (p_data[i][j] != m.p_data[i][j])
                return false;
        }
    }
    return true;
}

Matrix Matrix::operator + (const Matrix& m) const
{
    if (row != m.row || col != m.col)
        throw -1;
    Matrix matrix(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix.p_data[i][j] = p_data[i][j] + m.p_data[i][j];
        }
    }
    return matrix;
}

Matrix Matrix::operator * (const Matrix& m) const
{
    if (col != m.row)
        throw -1;
    Matrix matrix(row, m.col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            for (int k = 0; k < col; k++)
            {
                matrix.p_data[i][j] += p_data[i][k] * m.p_data[k][j];
            }
        }
    }
    return matrix;
}

void Matrix::print()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << p_data[i][j] << ' ';
        }
        cout << endl;
    }
}

void f()
{
    while (1)
    {
        char ch;
        try
        {
            while (1)
            {
                try
                {
                    cout << "请输入想要进行的运算符号(\"+\" 或 \"*\")：" << endl;
                    cin >> ch;
                    if (ch != '+' && ch != '*')
                        throw -1.0;
                    break;
                }
                catch (double)
                {
                    cout << "输入的运算符不合法！请重新输入！" << endl;
                }
            }
            cout << "请依次输入矩阵一的行数、列数和数据：" << endl;
            int row1, col1;
            cin >> row1 >> col1;
            Matrix m1(row1, col1);
            for (int i = 0; i < m1.row; i++)
                for (int j = 0; j < m1.col; j++)
                    cin >> m1.p_data[i][j];
            cout << "请依次输入矩阵二的行数、列数和数据：" << endl;
            int row2, col2;
            cin >> row2 >> col2;
            Matrix m2(row2, col2);
            for (int i = 0; i < m2.row; i++)
                for (int j = 0; j < m2.col; j++)
                    cin >> m2.p_data[i][j];
            Matrix m3(m1.row, m2.col);
            if (ch == '+')
                m3 = m1 + m2;
            else
                m3 = m1 * m2;
            cout << "矩阵运算结果为：" << endl;
            m3.print();
            break;
        }
        catch (int)
        {
            cout << "请输入符合运算规则的矩阵！请重新输入！" << endl;
        }
    }
}

int main()
{
    f();
    return 0;
}