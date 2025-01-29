#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();  // Default constructor
    Fixed(const int value);  // Constructor with int
    Fixed(const float value);  // Constructor with float
    Fixed(const Fixed &other);  // Copy constructor
    Fixed &operator=(const Fixed &other);  // Copy assignment operator
    ~Fixed();  // Destructor

    int getRawBits(void) const;  // Get raw bits
    void setRawBits(int const raw);  // Set raw bits

    float toFloat(void) const;  // Convert to float
    int toInt(void) const;  // Convert to int

    // Overload the << operator
    friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif