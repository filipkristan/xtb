#include "getColorAt.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>

// NOTES: Add error handling!
RGB getColorAt(int x, int y) {
    RGB res;
    XColor c;
    Display *display = XOpenDisplay((char *) NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    XImage *image;
    image = XGetImage(display, XRootWindow(display, XDefaultScreen(display)), x, y, 1, 1, AllPlanes, XYPixmap);
    c.pixel = XGetPixel(image, 0, 0);
    XFree(image);
    XQueryColor(display, XDefaultColormap(display, XDefaultScreen(display)), &c);
    res.r = c.red / 256;
    res.g = c.green / 256;
    res.b = c.blue / 256;

    //printf("RGB: %d %d %d \n", res.r, res.g, res.b);
    XCloseDisplay(display);
    return res;;
}
