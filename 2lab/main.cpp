#include <iostream>
#include <iomanip>
using namespace std;

class vect {
public:
    int dim;
    double* b;
    int num;
    static int count;

    vect(int d = 3) {
        dim = d;
        b = new double[dim];
        for (int i = 0; i < dim; i++) b[i] = i + 1;
        num = ++count;
        cout << "Создан вектор " << num << endl;
    }

    vect(const vect& v) {
        dim = v.dim;
        b = new double[dim];
        for (int i = 0; i < dim; i++) b[i] = v.b[i];
        num = ++count;
        cout << "Скопирован вектор " << num << endl;
    }

    ~vect() {
        cout << "Удалён вектор " << num << endl;
        delete[] b;
    }

    vect operator+(const vect& v) {
        if (dim != v.dim) {
            cout << "Ошибка: размерности векторов не совпадают при сложении" << endl;
            return *this;
        }
        vect res(dim);
        for (int i = 0; i < dim; i++) res.b[i] = b[i] + v.b[i];
        cout << "Сложение векторов: " << num << " + " << v.num << endl;
        return res;
    }

    vect operator-(const vect& v) {
        if (dim != v.dim) {
            cout << "Ошибка: размерности векторов не совпадают при вычитании" << endl;
            return *this;
        }
        vect res(dim);
        for (int i = 0; i < dim; i++) res.b[i] = b[i] - v.b[i];
        cout << "Вычитание векторов: " << num << " - " << v.num << endl;
        return res;
    }

    vect operator-() {
        vect res(dim);
        for (int i = 0; i < dim; i++) res.b[i] = -b[i];
        cout << "Унарный минус вектора " << num << endl;
        return res;
    }

    vect& operator=(const vect& v) {
        if (this == &v) return *this;
        delete[] b;
        dim = v.dim;
        b = new double[dim];
        for (int i = 0; i < dim; i++) b[i] = v.b[i];
        cout << "Присваивание вектора: " << num << " = " << v.num << endl;
        return *this;
    }

    vect operator*(double k) {
        vect res(dim);
        for (int i = 0; i < dim; i++) res.b[i] = b[i] * k;
        cout << "Умножение вектора " << num << " на скаляр " << k << endl;
        return res;
    }

    double operator*(const vect& v) {
        if (dim != v.dim) {
            cout << "Ошибка: размерности векторов не совпадают при скалярном произведении" << endl;
            return 0;
        }
        double sum = 0;
        for (int i = 0; i < dim; i++) sum += b[i] * v.b[i];
        cout << "Скалярное произведение векторов: " << num << " * " << v.num << endl;
        return sum;
    }

    void print() {
        cout << "Вектор " << num << ": ";
        for (int i = 0; i < dim; i++) cout << b[i] << " ";
        cout << endl;
    }
};

int vect::count = 0;

class matr {
public:
    int dim;
    double** a;
    int num;
    static int count;

    matr(int d = 3) {
        dim = d;
        a = new double*[dim];
        for (int i = 0; i < dim; i++) {
            a[i] = new double[dim];
            for (int j = 0; j < dim; j++) a[i][j] = i + j + 1;
        }
        num = ++count;
        cout << "Создана матрица " << num << endl;
    }

    matr(const matr& m) {
        dim = m.dim;
        a = new double*[dim];
        for (int i = 0; i < dim; i++) {
            a[i] = new double[dim];
            for (int j = 0; j < dim; j++) a[i][j] = m.a[i][j];
        }
        num = ++count;
        cout << "Скопирована матрица " << num << endl;
    }

    ~matr() {
        for (int i = 0; i < dim; i++) delete[] a[i];
        delete[] a;
        cout << "Удалена матрица " << num << endl;
    }

    matr operator+(const matr& m) {
        if (dim != m.dim) {
            cout << "Ошибка: размерности матриц не совпадают при сложении" << endl;
            return *this;
        }
        matr res(dim);
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
                res.a[i][j] = a[i][j] + m.a[i][j];
        cout << "Сложение матриц: " << num << " + " << m.num << endl;
        return res;
    }

    matr operator-(const matr& m) {
        if (dim != m.dim) {
            cout << "Ошибка: размерности матриц не совпадают при вычитании" << endl;
            return *this;
        }
        matr res(dim);
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
                res.a[i][j] = a[i][j] - m.a[i][j];
        cout << "Вычитание матриц: " << num << " - " << m.num << endl;
        return res;
    }

    matr operator-() {
        matr res(dim);
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
                res.a[i][j] = -a[i][j];
        cout << "Унарный минус матрицы " << num << endl;
        return res;
    }

    matr& operator=(const matr& m) {
        if (this == &m) return *this;
        for (int i = 0; i < dim; i++) delete[] a[i];
        delete[] a;
        dim = m.dim;
        a = new double*[dim];
        for (int i = 0; i < dim; i++) {
            a[i] = new double[dim];
            for (int j = 0; j < dim; j++) a[i][j] = m.a[i][j];
        }
        cout << "Присваивание матрицы: " << num << " = " << m.num << endl;
        return *this;
    }

    matr operator*(double k) {
        matr res(dim);
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
                res.a[i][j] = a[i][j] * k;
        cout << "Умножение матрицы " << num << " на скаляр " << k << endl;
        return res;
    }

    matr operator*(const matr& m) {
        if (dim != m.dim) {
            cout << "Ошибка: размерности матриц не совпадают при умножении" << endl;
            return *this;
        }
        matr res(dim);
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++) {
                res.a[i][j] = 0;
                for (int k = 0; k < dim; k++) res.a[i][j] += a[i][k] * m.a[k][j];
            }
        cout << "Умножение матриц: " << num << " * " << m.num << endl;
        return res;
    }

    vect operator*(const vect& v) {
        if (dim != v.dim) {
            cout << "Ошибка: размерности матрицы и вектора не совпадают при умножении" << endl;
            return v; 
        }
        vect res(dim);
        for (int i = 0; i < dim; i++) {
            res.b[i] = 0;
            for (int j = 0; j < dim; j++) res.b[i] += a[i][j] * v.b[j];
        }
        cout << "Умножение матрицы " << num << " на вектор " << v.num << endl;
        return res;
    }

    void print() {
        cout << "Матрица " << num << ":\n";
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) cout << setw(6) << a[i][j];
            cout << endl;
        }
    }
};

int matr::count = 0;

int main() {
    vect v1(3), v2(3);
    vect v3 = v1 + v2;
    v3.print();

    vect v4 = -v1;
    v4.print();

    double dot = v1 * v2;
    cout << "Скалярное произведение: " << dot << endl;

    vect v5 = v1 * 2.0;
    v5.print();

    matr m1(3), m2(3);
    matr m3 = m1 + m2;
    m3.print();

    matr m4 = m1 * 2.0;
    m4.print();

    matr m5 = m1 * m2;
    m5.print();

    vect v6 = m1 * v1;
    v6.print();

    return 0;
}
