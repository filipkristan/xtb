#include "resizeWindow.h"
#include <stdbool.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

// NOTES: Add error handling and update it to resize the window even if its maximized.
void resizeWindow(const char *wid, unsigned int width, unsigned int height) {
    Display *display = XOpenDisplay((char *) NULL);
    Window window = strtoul(wid,NULL, 0);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    XResizeWindow(display, window, width, height);
    XFlush(display);
    XEvent event;
    bool resized = false;
    //printf("Waiting for resize confirmation...\n"); // NOTE: debug
    while (!resized) {
        XNextEvent(display, &event);
        if (event.type == ConfigureNotify) {
            XConfigureEvent *ce = &event.xconfigure;
            if (ce->window == window) {
                //printf("Window resized to: %dx%d\n", ce->width, ce->height); // NOTE: debug
                resized = true;
            }
        }
    }
    XCloseDisplay(display);
}
