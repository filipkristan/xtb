#include <stdio.h>
#include <XTB/xtb.h>

void main() {
    Display *display = XOpenDisplay((char *) NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    RGB color = getColorAt(0,0);
    printf("%d", color.r);
}