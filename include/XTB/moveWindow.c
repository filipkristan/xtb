#include "moveWindow.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

// NOTES: Add error handling
void moveWindow(const char *wid, int x, int y) {
    Display *display = XOpenDisplay((char *) NULL);
    Window window = strtoul(wid,NULL, 0);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    XMoveWindow(display, window, x, y);
    XCloseDisplay(display);
}
