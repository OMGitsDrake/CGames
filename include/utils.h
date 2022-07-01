#include <iostream>
#include <time.h>
#include <string.h>
#include <windows.h>

using namespace std;

typedef unsigned short t;

float Q_rsqrt(float);

float Q_rsqrt(float number){
    long i;
    float y, x2;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = * (long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = * (float *) &i;
    
    y *= ( threehalfs - (x2 * y * y) );
    y *= ( threehalfs - (x2 * y * y) );

    return y;
}

// color setter
inline void SetColor(WORD color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// helper class
class Color {
    private:
        const WORD m_val;
    
    friend ostream& operator<< (ostream& os, Color& c);

    public:
        Color(WORD val) : m_val(val) { }

        void set() const {
            SetColor(m_val);
        }
};

static const Color red(4);
static const Color green(2);
static const Color blue(1);
static const Color white(7);
static const Color aqua_green(3);
static const Color yellow(13);

ostream& operator<< (ostream& os, const Color& c) {
	c.set();
	return os;
}