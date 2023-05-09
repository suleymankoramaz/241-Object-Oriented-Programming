#include <iostream>
using namespace std;

class Polynomial
{
public:
    Polynomial();
    Polynomial(const Polynomial &);
    Polynomial(double coefficient[], int size);
    ~Polynomial();

    double &operator[](int degree);

    const double &operator[](int degree) const;
    const Polynomial &operator=(const Polynomial &rhs);
    int mySize();

    friend double evaluate(const Polynomial &ploy, double arg);
    friend Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs);

    friend Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs);

    friend Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs);

private:
    double *coef;
    int size;
};

int main()
{
    Polynomial empty;
    double one[] = {7};
    Polynomial One(one, 4);
    double quad[] = {9, 3, 6};
    double cubic[] = {1, 0, 1, 5};
    Polynomial q(quad, 9);
    Polynomial c(cubic, 8);
    Polynomial p = q;
    Polynomial x;
    x = q;
    x = c;

    cout << "Polynomial q " << endl;
    {
        for (int i = 0; i < 3; i++)
            cout << "term with degree " << i << " has coefficient " << q[i] << endl;
    }
    cout << "Polynomial c " << endl;
    {
        for (int i = 0; i < 4; i++)
            cout << "term with degree " << i << " has coefficient " << c[i] << endl;
    }
    cout << "value of q(2) is " << evaluate(q, 2) << endl;
    cout << "value of p(2) is " << evaluate(p, 2) << endl;
    cout << "value of x(2) is " << evaluate(x, 2) << endl;
    cout << "value of c(2) is " << evaluate(c, 2) << endl;

    x = q + c;
    cout << "value of (q + c)(2) is " << evaluate(x, 2) << endl;

    x = q - c;
    cout << "value of (q - c)(2) is " << evaluate(x, 2) << endl;

    x = q * c;
    cout << "size of q*c is " << x.mySize() << endl;
    cout << "Polynomial x (= q*c) " << endl;

    for (int i = 0; i < x.mySize(); i++)
        cout << "term with degree " << i << " has coefficient " << x[i] << endl;

    cout << "value of (q * c)(2) is " << evaluate(x, 2) << endl;
    return 0;
}

int Polynomial::mySize()
{
    return size;
}

Polynomial::Polynomial() : coef(0), size(0)
{
}

const Polynomial &Polynomial::operator=(const Polynomial &rhs)
{
    if (rhs.coef == coef)
    {
        return rhs;
    }
    else
    {
        delete[] coef;
        coef = new double[rhs.size];
        for (int i = 0; i < rhs.size; i++)
        {
            coef[i] = rhs.coef[i];
        }
        size = rhs.size;
    }
    return rhs;
}

Polynomial::Polynomial(const Polynomial &rhs) : size(rhs.size)
{
    coef = new double[rhs.size];
    for (int i = 0; i < rhs.size; i++)
    {
        coef[i] = rhs.coef[i];
    }
}

Polynomial::Polynomial(double coefficient[], int newSize) : size(newSize)
{
    coef = new double[size];
    for (int i = 0; i < size; i++)
    {
        coef[i] = coefficient[i];
    }
}

Polynomial::~Polynomial()
{
    delete[] coef;
}

const double &Polynomial::operator[](int degree) const
{
    return coef[degree];
}

double &Polynomial::operator[](int degree)
{
    return coef[degree];
}

double max(double lhs, double rhs)
{
    return (lhs > rhs) ? lhs : rhs;
}

Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs)
{
    const int sumSize = max(lhs.size, rhs.size);
    double *sumCoefs = new double[sumSize];

    for (int i = 0; i < sumSize; i++)
    {
        sumCoefs[i] = lhs.coef[i] + rhs.coef[i];
    }

    Polynomial q(sumCoefs, sumSize);

    delete[] sumCoefs;

    return q;
}

Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs)
{
    int sumSize = max(lhs.size, rhs.size);
    double *sumCoefs = new double[sumSize];

    for (int i = 0; i < sumSize; i++)
    {
        sumCoefs[i] = lhs.coef[i] - rhs.coef[i];
    }

    Polynomial q(sumCoefs, sumSize);

    delete[] sumCoefs;

    return q;
}

Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs)
{
    int i;
    int j;
    int prodSize = lhs.size + rhs.size;
    double *prodCoefs = new double[prodSize];

    for (i = 0; i < prodSize; i++)
    {
        prodCoefs[i] = 0;
    }

    for (i = 0; i < lhs.size; i++)
    {
        for (j = 0; j < rhs.size; j++)
        {
            prodCoefs[i + j] += lhs[i] * rhs[j];
        }
    }
    return Polynomial(prodCoefs, prodSize);
}

double evaluate(const Polynomial& poly, double arg){
    double value = 0;
    int i;

    for(i= poly.size - 1; i>=0; i--){
        value = poly[i] + arg * value;
    }

    return value;
}
