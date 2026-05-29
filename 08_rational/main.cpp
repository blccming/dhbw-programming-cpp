#include <iostream>
#include <numeric>


class Q {
    public:
        Q(int n, int d = 1): mNominator(n), mDenominator(d) {
            makeCanonical();
        }

        // Getter methods:
        int getNominator() const {
            return mNominator;
        }
        int getDenominator() const {
            return mDenominator;
        }

        Q operator+(const Q &rhs) const {
            int n = mNominator * rhs.mDenominator + rhs.mNominator * mDenominator;
            int m = mDenominator * rhs.mDenominator;
            // The constructor makes the result canonical.
            return Q(n, m);
        }

        Q &operator*=(const Q &rhs) {
            // We can directly access private members of
            // other objects of te same class.
            mNominator *= rhs.mNominator;
            mDenominator *= rhs.mDenominator;
            makeCanonical();
            return *this;  // return reference to "this" object
        }

    private:
        int mNominator;    // Zaehler
        int mDenominator;  // Nenner

        void makeCanonical() {
            if (mNominator == 0) {
                mDenominator = 1;
                return;
            }
            int d = std::gcd(mNominator, mDenominator);
            mNominator /= d;
            mDenominator /= d;
        }
};


// Overload the output operator for objects of class Q
// Output operator: (out << value) << value2
// To make this work, the return value of the output operator
// must be the output stream
std::ostream &operator<<(std::ostream &out, const Q &value) {
    out << value.getNominator() << '/' << value.getDenominator();
    return out;
}


// Operators can be defined outside of class Q, but then
// we cannot access private members directly.
Q &operator+=(Q &a, const Q &b) {
    a = a + b;  // inefficient!!!
    return a;
}


int main() {
    Q a(1, 2);
    std::cout << "a = " << a << std::endl;
    a *= Q(1, 3) *= Q(2, 3);
    std::cout << "a = " << a << std::endl;

    // The compiler uses constructor Q(int) to implicitly
    // convert the integer 3 to an object of class Q.
    a *= 3;
    std::cout << "a = " << a << std::endl;
    // just to show, what is happening
    a.operator*=(2);
    operator<<(std::cout, "a = ") << a << std::endl;

    Q d(4, 8), e(6, 9);
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "e + d = " << e + d << std::endl;

    d += 4;
    std::cout << "d = " << d << std::endl;

    return 0;
}
