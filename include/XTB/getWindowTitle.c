#include "getWindowTitle.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>

// NOTES: Add error handling!
char *getWindowTitle(const char *wid) {
    Display *display = XOpenDisplay((char *) NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    Window window = strtoul(wid,NULL, 0);
    XTextProperty textProperty;
    char **TextListReturn = NULL;
    int count = 0;

    XGetWMName(display, window, &textProperty);
    Xutf8TextPropertyToTextList(display, &textProperty, &TextListReturn, &count);

    XFree(textProperty.value);
    XCloseDisplay(display);
    return TextListReturn[0];
}
