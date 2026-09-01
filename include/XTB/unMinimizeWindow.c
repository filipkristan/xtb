#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <string.h>

// NOTES: Needs checks for when a window doesn't exist or if it failed to unminimize a window
void unMinimizeWindow(const char *wid) {
    Display *display = XOpenDisplay((char *) NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    Window win = strtoul(wid,NULL, 0);
    XMapWindow(display, win);
    XRaiseWindow(display, win);

    printf("Successfully unminimized window!\n");
    XCloseDisplay(display);
    XFlush(display);
}
