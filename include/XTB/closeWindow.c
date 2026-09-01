#include "closeWindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

// NOTES: Add error handling!
void closeWindow(const char *wid) {
    Display *display = XOpenDisplay((char *) NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    Window window = strtoul(wid,NULL, 0);
    XDestroyWindow(display, window);
    XFlush(display);
    XCloseDisplay(display);
}
