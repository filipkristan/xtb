#include "isWindow.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

// Supress error
static int x_error_handler(Display *dpy, XErrorEvent *event) {
    return 0;
}
// NOTES: Add error handling!
bool isWindow(const char *wid) {
    Display *display = XOpenDisplay(NULL);
    if (!display) {
        return false;
    }

    Window window = strtoul(wid, NULL, 0);
    XWindowAttributes winAttrib;

    XErrorHandler old_handler = XSetErrorHandler(x_error_handler);

    Status res = XGetWindowAttributes(display, window, &winAttrib);

    XSetErrorHandler(old_handler);

    XCloseDisplay(display);
    return res != 0;
}
