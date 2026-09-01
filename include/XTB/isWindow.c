#include "isWindow.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

// NOTES: Add error handling!
bool isWindow(const char *wid) {
    Display *display = XOpenDisplay((char *) NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
        return false;
    }
    Window window = strtoul(wid,NULL, 0);
    XWindowAttributes winAttrib;
    Status res = XGetWindowAttributes(display, window, &winAttrib);
    XCloseDisplay(display);
    return res != 0;
}
