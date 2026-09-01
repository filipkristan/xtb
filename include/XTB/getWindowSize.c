#include "getWindowSize.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

// NOTES: Add error handling!
WH getWindowSize(const char *wid) {
    Display *display = XOpenDisplay((char *) NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }

    Window window = strtoul(wid,NULL, 0);
    XWindowAttributes window_attributes_return;
    XGetWindowAttributes(display, window, &window_attributes_return);
    WH windowSize;
    windowSize.width = window_attributes_return.width;
    windowSize.height = window_attributes_return.height;

    XCloseDisplay(display);
    //printf("width: %d, height: %d", windowSize.width, windowSize.height);
    return windowSize;
}
