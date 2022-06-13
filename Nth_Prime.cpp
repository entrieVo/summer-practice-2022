#include<iostream>

// Given a number n, determine what the nth prime is.
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
// we can see that the 6th prime is 13.

bool isPrime(unsigned int num) {
    for(size_t i = 2; i < 10; i++)
    if(num % i == 0 && num != i) return false;
 return true;
}
unsigned int PrimeOf(size_t count) {

    size_t prime = 1;
    while(count != 0) {

        prime++;
        if(isPrime(static_cast<unsigned int>(prime))) count--;
    }
 return prime;
}

int main() {

    std::cout << "Input number of prime: ";
    size_t n; std::cin >> n;

    std::cout << "The " << n << "th prime number is " << PrimeOf(n);

}