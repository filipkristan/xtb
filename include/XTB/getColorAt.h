#ifndef GETCOLORAT_GETCOLORAT_HH
#define GETCOLORAT_GETCOLORAT_HH

typedef struct {
    int r, g, b;
} RGB;

RGB getColorAt(int x, int y);

#endif
