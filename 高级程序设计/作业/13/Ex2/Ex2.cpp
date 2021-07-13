#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
    int** p_data; //��ʾ��������
    int row, col; //��ʾ���������������
public:
    Matrix(int r, int c); //���캯��
    Matrix(const Matrix& m); //�������캯��
    ~Matrix(); //��������
    int*& operator[] (int i); //����[], ����Matrix����m, �ܹ�ͨ��m[i][j]���ʵ�i+1�С���j+1��Ԫ��
    Matrix& operator = (const Matrix& m); //����=, ʵ�־������帳ֵ, ����/�в���, �黹�ռ䲢���·���
    bool operator == (const Matrix& m) const; //����==, �жϾ����Ƿ����
    Matrix operator + (const Matrix& m) const; //����+, ��ɾ���ӷ�, �ɼ�������������ӷ�����(�������С��зֱ����)
    Matrix operator * (const Matrix& m) const; //����*, ��ɾ���˷�, �ɼ�������������˷�����(this.col = m.row)
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
                    cout << "��������Ҫ���е��������(\"+\" �� \"*\")��" << endl;
                    cin >> ch;
                    if (ch != '+' && ch != '*')
                        throw -1.0;
                    break;
                }
                catch (double)
                {
                    cout << "�������������Ϸ������������룡" << endl;
                }
            }
            cout << "�������������һ�����������������ݣ�" << endl;
            int row1, col1;
            cin >> row1 >> col1;
            Matrix m1(row1, col1);
            for (int i = 0; i < m1.row; i++)
                for (int j = 0; j < m1.col; j++)
                    cin >> m1.p_data[i][j];
            cout << "�������������������������������ݣ�" << endl;
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
            cout << "����������Ϊ��" << endl;
            m3.print();
            break;
        }
        catch (int)
        {
            cout << "����������������ľ������������룡" << endl;
        }
    }
}

int main()
{
    f();
    return 0;
}