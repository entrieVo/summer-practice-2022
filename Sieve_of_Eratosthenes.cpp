#include<iostream>
#include<vector>

//* Use the Sieve of Eratosthenes to find all the primes from 2 up to a given number.
//*
//* The Sieve of Eratosthenes is a simple, ancient algorithm for finding all prime numbers
//* up to any given limit. It does so by iteratively marking as composite (i.e. not prime)
//* the multiples of each prime, starting with the multiples of 2. It does not use any division or remainder operation.

#define PRIME true
#define NOT_PRIME false
class SieveOfEratosthenes {

    unsigned int n;                      // limit
    std::vector<bool> values;            // all the values
    std::vector<unsigned int> primes;    // prime values

    public:SieveOfEratosthenes(unsigned int n) {
        this->n = n;
        values.resize(n + 1, PRIME);
        values[0] = values[1] = NOT_PRIME;

        ModifiedMarking(); // can be changed (Marking/ModifiedMarking)
    }

    private:std::vector<bool> Marking() {

        for(size_t p = 2; p < n; p++) {           //> passing through all values to find a prime number

            if(values[p] == PRIME)
                for(size_t i = p; p*i < n; i++)   //> crossing out of values
                values[p*i] = NOT_PRIME;
        }
     return values;
    }
    std::vector<bool> ModifiedMarking() {

        for(size_t p = 2; p < n; p++) {                 //> passing through all values to find a prime number

            if(values[p] == PRIME) 
                for(size_t i = p*p; i <= n; i += p)     //> crossing out of values
                    values[i] = NOT_PRIME;
        }
     return values;
    }

    public:std::vector<unsigned int> GetPrimes() {

        for(size_t i = 2; i < values.size(); i++)
        if(values[i] == PRIME) primes.push_back(i);
     return primes;
    }
};

int main() {

    std::cout << "Input limit to find all prime numbers: ";
    unsigned int n; std::cin >> n;

    SieveOfEratosthenes solution(n);
    std::vector<unsigned int> values = solution.GetPrimes();

    std::cout << "Prime numbers:";
    for(size_t i = 0; i < values.size(); i++) {
        std::cout << std::endl << i + 1 << ". " << values[i]; 
    }
}