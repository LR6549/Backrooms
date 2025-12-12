#ifndef COLORSTRUCT
#define COLORSTRUCT

struct Color {
    int c_r;
    int c_g;
    int c_b;
    int c_a;

    Color(int r = 255, int g = 255, int b = 255, int a = 255) {
        c_r = r;
        c_g = g;
        c_b = b;
        c_a = a;
    }
};

namespace COLORS {
    Color WHITE         = {255, 255, 255};
    Color BLACK         = {  0,   0,   0};
    
    Color SETTINGSCOLOR = { 56,  56,  56};
}

#endif