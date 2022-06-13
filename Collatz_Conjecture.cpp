#include<iostream>
#include<list>

// The Collatz Conjecture or 3x+1 problem can be summarized as follows:
// 
// Take any positive integer n. If n is even, divide n by 2 to get n / 2.
// If n is odd, multiply n by 3 and add 1 to get 3n + 1. Repeat the process indefinitely.
// The conjecture states that no matter which number you start with, you will always reach 1 eventually.
// 
// Given a number n, return the number of steps required to reach 1.

#define EVEN true
#define ODD false
class CollatzConjecture {

    public: CollatzConjecture(unsigned int n) {
        this->n = n;
        steps = 0;
    }

    private: std::list<unsigned int> values;    // values of steps
    unsigned int n;                             // positive integer
    size_t steps;                               // number of steps

    bool isEven(int n) 
    { return (n % 2 == 0) ? EVEN : ODD; }

    public:
    size_t GetSteps() {

        while(n != 1) {

            n = isEven(n) ? n / 2 : 3 * n + 1;
            steps++;

            //> saving the values
            values.push_back(n);
        }
     return steps;
    }
    std::list<unsigned int> GetValues()
    { return values; }
};

int main() {
    std::cout << "Input number: ";
    unsigned int n; std::cin >> n;

    CollatzConjecture stepFinding(n);
    std::cout << "Number of steps required to reach 1: " << stepFinding.GetSteps() << std::endl;

    std::list<unsigned int> values = stepFinding.GetValues();

    size_t count = 1;
    for(auto it : values) {
        std::cout << std::endl << count << ". " << it;
        count++;
    }
}