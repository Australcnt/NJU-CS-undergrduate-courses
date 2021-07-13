#include <iostream>
#include <vector>

using namespace std;

class Complex
{
private:
    double real;
    double image;
public:
    Complex(double _real = 0.0, double _image = 0.0) :real{ _real }, image{ _image } {}
    Complex(const Complex& complex) :real{ complex.real }, image{ complex.image } {}
    bool operator == (const Complex& complex) {
        return real == complex.real && image == complex.image;
    }
    bool operator != (const Complex& complex) {
        return real != complex.real || image != complex.image;
    }
    Complex operator + (const Complex& complex) {
        return Complex(real + complex.real, image + complex.image);
    }

    Complex operator - (const Complex& complex) {
        return Complex(real - complex.real, image - complex.image);
    }

    Complex operator * (const Complex& complex) {
        double _real = real * complex.real - image * complex.image;
        double _image = image * complex.real + real * complex.image;
        return Complex(_real, _image);
    }

    Complex operator / (const Complex& complex) {
        double _real = (real * complex.real + image * complex.image) / (complex.real * complex.real + complex.image * complex.image);
        double _image = (image * complex.real - real * complex.image) / (complex.real * complex.real + complex.image * complex.image);
        return Complex(_real, _image);
    }
    Complex& operator = (const Complex& complex)
    {
        if (this != &complex)
        {
            real = complex.real;
            image = complex.image;
        }
        return *this;
    }
    Complex& operator += (const Complex& complex) {
        real += complex.real;
        image += complex.image;
        return *this;
    }
    friend istream& operator >> (istream& in, Complex& complex);
    friend ostream& operator << (ostream& out, Complex& complex);
};

istream& operator >> (istream& in, Complex& complex) {
    in >> complex.real >> complex.image;
    return in;
}

ostream& operator << (ostream& out, Complex& complex)
{
    out << "(" << complex.real;
    if (complex.image >= 0)
    {
        out << "+" << complex.image << "i)";
    }
    else
    {
        out << complex.image << "i)";
    }
    return out;
}

template <class Type>
class Matrix
{
private:
    Type** p_data; //表示矩阵数据
    int row, col; //表示矩阵的行数和列数
public:
    Matrix(int r, int c); //构造函数
    Matrix(const Matrix <Type>& m); //拷贝构造函数
    ~Matrix(); //析构函数
    Type*& operator[] (int i); //重载[], 对于Matrix对象m, 能够通过m[i][j]访问第i+1行、第j+1列元素
    Matrix<Type>& operator = (const Matrix<Type>& m); //重载=, 实现矩阵整体赋值, 若行/列不等, 归还空间并重新分配
    bool operator == (const Matrix<Type>& m) const; //重载==, 判断矩阵是否相等
    Matrix<Type> operator + (const Matrix<Type>& m) const; //重载+, 完成矩阵加法, 可假设两矩阵满足加法条件(两矩阵行、列分别相等)
    Matrix<Type> operator * (const Matrix<Type>& m) const; //重载*, 完成矩阵乘法, 可假设两矩阵满足乘法条件(this.col = m.row)
    void print();
};

template <class Type>
Matrix<Type>::Matrix(int r, int c)
{
    row = r;
    col = c;
    p_data = new Type* [row];
    for (int i = 0; i < row; i++)
    {
        p_data[i] = new Type[col];
        for (int j = 0; j < col; j++)
            p_data[i][j] = 0;
    }
}

template <class Type>
Matrix<Type>::Matrix(const Matrix<Type>& m)
{
    row = m.row;
    col = m.col;
    p_data = new Type* [row];
    for (int i = 0; i < row; i++)
    {
        p_data[i] = new Type[col];
        for (int j = 0; j < col; j++)
        {
            p_data[i][j] = m.p_data[i][j];
        }
    }
}

template <class Type>
Matrix<Type>::~Matrix()
{
    for (int i = 0; i < row; i++)
        delete[]p_data[i];
    delete[]p_data;
}

template <class Type>
Type*& Matrix<Type>::operator[] (int i)
{
    return p_data[i];
}

template <class Type>
Matrix <Type>& Matrix<Type>::operator = (const Matrix<Type>& m)
{
    if (row != m.row || col != m.col)
    {
        this->~Matrix();
        p_data = new Type* [m.row];
        for (int i = 0; i < m.row; i++)
        {
            p_data[i] = new Type[m.col];
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

template <class Type>
bool Matrix<Type>::operator == (const Matrix<Type>& m) const
{
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

template <class Type>
Matrix<Type> Matrix<Type>::operator + (const Matrix<Type>& m) const
{
    Matrix<Type> matrix(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix.p_data[i][j] = p_data[i][j] + m.p_data[i][j];
        }
    }
    return matrix;
}

template <class Type>
Matrix<Type> Matrix<Type>::operator * (const Matrix<Type>& m) const
{
    Matrix<Type> matrix(row, m.col);
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

template <class Type>
void Matrix<Type>::print()
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

int main()
{/*
    Matrix<int> m1(5, 3), m2(3, 4);
    for (int i = 0; i < m1.row; i++)
        for (int j = 0; j < m1.col; j++)
            cin >> m1.p_data[i][j];
    for (int i = 0; i < m2.row; i++)
        for (int j = 0; j < m2.col; j++)
            cin >> m2.p_data[i][j];
    Matrix<int> m3(5, 3);
    m3 = m1 + m1;
    m3.print();
    Matrix<int> m4(5, 4);
    m4 = m1 * m2;
    m4.print();*/
    return 0;
}