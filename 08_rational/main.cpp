#include <iostream>
#include <numeric>

class Q {
    public:
        Q(int n, int d = 1) : mNumerator(n), mDenominator(d) { makeCanonical();}

        // Getter methods
        int getNumerator() const { return mNumerator; }
        int getDenominator() const { return mDenominator; }

        Q &operator*=(const Q &rhs) {
            // We can directly access private members of other objects of the same class
            mNumerator *= rhs.mNumerator;
            mDenominator *= rhs.mDenominator;
            makeCanonical();
            return *this; // return referance to "this" object
        }

        Q operator+(const Q &rhs) const {
           int n = mNumerator * rhs.mDenominator + rhs.mNumerator * mDenominator;
           int m = mDenominator * rhs.mDenominator;
           // The constructor makes the result canonical
           return Q(n, m);
        }
    private:
        int mNumerator; // Zähler
        int mDenominator; // Nenner

        void makeCanonical() {
            if (mNumerator == 0) {
                mDenominator = 1;
                return;
            }
            int d = std::gcd(mNumerator, mDenominator);
            mNumerator /= d;
            mDenominator /= d;
        }
};

// Overload the output operator for objects of class Q
// Output operator: (out << value) << value2
// To make this work, the return value of the output operator
// must be a reference to the output stream
std::ostream &operator<<(std::ostream &out, const Q &value) {
    out << value.getNumerator() << "/" << value.getDenominator() << std::endl;
    return out;
}

// Operators can be defined outside of class Q, but then
// we cannot access private members directly
Q &operator+=(Q &lhs, const Q &rhs) {
    lhs = lhs + rhs; // inefficient!!!
    return lhs;
}


int main() {
    Q a(1, 2);
    std::cout << "a = " << a << std::endl;
    a *= Q(2, 3);
    std::cout << "a = " << a << std::endl;

    // The compiler uses constructor Q(int) to
    // implicitly convert the integer 3 to a Q object
    a*=3;
    std::cout << "a = " << a << std::endl;

    Q d(4, 8), e(6, 9);
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "d + e = " << d + e << std::endl;

    d += 4;
    std::cout << "d = " << d << std::endl;

    return 0;
}
