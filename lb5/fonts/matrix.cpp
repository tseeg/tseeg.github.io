#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Matrix {
    private:
        int m, n;
        float** value;
    public:
        // constructor

        Matrix(int a, int b) {
            m = a;
            n = b;
            value = new float*[m];
            for (int i = 0; i < m; i++) {
                value[i] = new float[n];
                for (int j = 0; j < n; j++) {
                    value[i][j] = 0.0;
                }
            }
        }
        // destructor
        ~Matrix() {
            for (int i = 0; i < m; i++) {
                delete[] value[i];
            }
        }

        // getter
        int get_rows() const {
            return m;
        }

        int get_cols() const {
            return n;
        }

        float get_value(int i, int j) const {
            return value[i][j];
        }

        // setter 
        void set_value(int i, int j, float val) {
            value[i][j] = val;
        }

        void set_rows(int a) {
            m = a;
        }

        void set_cols(int a) {
            n = a;
        }
        // overloading operators

        Matrix operator+(Matrix a) {
        Matrix result(m,n);
        if(m==a.m && n==a.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    result.set_value(i, j, value[i][j] + a.get_value(i, j));
                }
            }
        }
        //else return NULL;
        }
        Matrix operator+(float a) {
            for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                set_value(i, j, value[i][j]+a);
            }
        }
        };

        Matrix operator-(Matrix a) {
        Matrix result(m,n);
        if(m==a.m && n==a.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    result.set_value(i, j, value[i][j] - a.get_value(i, j));
                }
            }
        }
        //else return NULL;
        };

        Matrix operator*(Matrix a) {
        Matrix result(m,n);
        if(m==a.n && n==a.m) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result.set_value(i, j, value[i][j] * a.get_value(j, i));
            }
        }
        return result;
        }
        //else return NULL;
    };
        Matrix operator=(Matrix a) {
        if(m==a.m && n==a.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    set_value(i, j, a.value[i][j]);
                }
            }
        }
        //else return NULL;
    }
    Matrix operator++() {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                set_value(i, j, value[i][j]+1);
            }
        }
    }
    Matrix operator--() {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                set_value(i, j, value[i][j]-1);
            }
        }
    }
    Matrix operator+=(float a) {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                set_value(i, j, value[i][j]+a);
            }
        }
    }
    Matrix operator-=(float a) {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                set_value(i, j, value[i][j]-a);
            }
        }
    }
    Matrix operator*=(float a) {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                set_value(i, j, value[i][j]*a);
            }
        }
    }
    // function that reverses matrix
    Matrix reverse(Matrix a) {
        Matrix result(n,m);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result.set_value(j, i, value[i][j]);
            }
        }
    }
};
int main()
{
    Matrix a(3,3);
    a.set_value(0,0,1);
    a.set_value(0,1,1);
    a.set_value(0,2,1);
    a.set_value(1,0,1);
    a.set_value(1,1,1);
    a.set_value(1,2,1);
    a.set_value(2,0,1);
    a.set_value(2,1,1);
    a.set_value(2,2,1);
    a=a+0.1;
    for(int i=0;i<a.get_rows(); i++)
    {
        for (int j = 0; j <a.get_cols(); j++)
        {
            cout<<a.get_value(i,j);
        }
        cout<<endl;
        
    }
}
