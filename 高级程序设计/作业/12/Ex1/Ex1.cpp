#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
    string str;
    in >> str;
    string::size_type pos = str.find("+");
    complex.real = stod(str.substr(0, pos));
    complex.image = stod(str.substr(pos + 1));
    return in;
}

ostream& operator << (ostream& out, Complex& complex)
{
    out << complex.real;
    if (complex.image >= 0)
    {
        out << "+" << complex.image << "i";
    }
    else
    {
        out << complex.image << "i";
    }
    return out;
}

template <class Type>
class Matrix
{
private:
    Type** p_data; //��ʾ��������
    int row, col; //��ʾ���������������
public:
    Matrix(); //���캯��
    Matrix(int r, int c); //���캯��
    Matrix(const Matrix <Type>& m); //�������캯��
    ~Matrix(); //��������
    Type*& operator[] (int i); //����[], ����Matrix����m, �ܹ�ͨ��m[i][j]���ʵ�i+1�С���j+1��Ԫ��
    Matrix<Type>& operator = (const Matrix<Type>& m); //����=, ʵ�־������帳ֵ, ����/�в���, �黹�ռ䲢���·���
    bool operator == (const Matrix<Type>& m) const; //����==, �жϾ����Ƿ����
    Matrix<Type> operator + (const Matrix<Type>& m) const; //����+, ��ɾ���ӷ�, �ɼ�������������ӷ�����(�������С��зֱ����)
    Matrix<Type> operator * (const Matrix<Type>& m) const; //����*, ��ɾ���˷�, �ɼ�������������˷�����(this.col = m.row)

    friend istream& operator >> <Type>(istream& input, Matrix<Type>& m); //��������룬��һ��Ϊ ����n ����m����������n��m�еľ���Ԫ��
    friend ostream& operator << <Type>(ostream& output, const Matrix<Type>& m); //�����������������Ϊ ���� ���� �س� ��������
};

template <class Type>
Matrix<Type>::Matrix()
{
    ;
}

template <class Type>
Matrix<Type>::Matrix(int r, int c)
{
    row = r;
    col = c;
    p_data = new Type * [row];
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
    p_data = new Type * [row];
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
        p_data = new Type * [m.row];
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
istream& operator >> (istream& input, Matrix<Type>& m)
{
    input >> m.row >> m.col;
    m.p_data = new Type * [m.row];
    for (int i = 0; i < m.row; i++)
    {
        m.p_data[i] = new Type[m.col];
        for (int j = 0; j < m.col; j++)
            m.p_data[i][j] = 0;
    }
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            input >> m.p_data[i][j];
        }
    }
    return input;
}

template <class Type>
ostream& operator << (ostream& output, const Matrix<Type>& m)
{
    output << m.row << ' ' << m.col << endl;
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            output << m.p_data[i][j] << ' ';
        }
        output << endl;
    }
    return output;
}

int main()
{
    Complex C;
    cin >> C;
    cout << endl << "���C:" << endl << C << endl << endl;
    Matrix<Complex> m1, m2, m3;
    cin >> m1;
    cout << endl << "���m1:" << endl << m1;
    ifstream in_file("C:\\��\\�����\\�߼��������\\��ҵ\\12\\matrix_test.txt", ios::in);
    if (!in_file)
        exit(-1);
    in_file >> m2;
    cout << endl << "���m2:" << endl << m2 << endl;
    in_file.close();
    m3 = m1 * m2;
    cout << "���m3=m1*m2:" << endl << m3;
    return 0;
}