#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <unistd.h>

static const char *wclose[] = { "xdotool", "selectwindow", "windowkill", NULL };
static const char *foc[]    = { "xdotool", "selectwindow", "windowfocus", NULL };
static const char *ff[]     = { "firefox", NULL };
static const char *fm[]     = { "pcmanfm-qt", NULL };
static const char *dmenu[]  = { "dmenu_run", NULL };
static const char *term[]   = { "urxvt", "-fn", "xft:Bitstream Vera Sans Mono:pixelsize=15", NULL };
static const char *mix[]    = { "xterm", "-e", "alsamixer", NULL };
static const char *lock[]   = { "slock", NULL };

void spawn(Display * disp, const char** com)
{
    if (fork()) return;
    if (disp) close(ConnectionNumber(disp));
    setsid();
    execvp((char*)com[0], (char**)com);
}

int main(void) {
    Display* disp;
    Window root;
    XEvent event;
    int     unusedint; 
    Window  unusedwin;
    Window  focuswin;
    
    if(!(disp = XOpenDisplay(0x0))) return 1;
    
    root = DefaultRootWindow(disp);
        XGrabKey(disp, XKeysymToKeycode(disp, XK_q), Mod4Mask, root, True, GrabModeAsync, GrabModeAsync);
        XGrabKey(disp, XKeysymToKeycode(disp, XK_w), Mod4Mask, root, True, GrabModeAsync, GrabModeAsync);
        XGrabKey(disp, XKeysymToKeycode(disp, XK_e), Mod4Mask, root, True, GrabModeAsync, GrabModeAsync);
        XGrabKey(disp, XKeysymToKeycode(disp, XK_r), Mod4Mask, root, True, GrabModeAsync, GrabModeAsync);
        XGrabKey(disp, XKeysymToKeycode(disp, XK_t), Mod4Mask, root, True, GrabModeAsync, GrabModeAsync);
        XGrabKey(disp, XKeysymToKeycode(disp, XK_a), Mod4Mask, root, True, GrabModeAsync, GrabModeAsync);
        XGrabKey(disp, XKeysymToKeycode(disp, XK_s), Mod4Mask, root, True, GrabModeAsync, GrabModeAsync);
        XGrabKey(disp, XKeysymToKeycode(disp, XK_z), Mod4Mask, root, True, GrabModeAsync, GrabModeAsync);

        XGrabButton(disp, 1, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(disp, 3, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(disp, 4, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(disp, 5, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);

    for(;;){
    XNextEvent(disp, &event);
    XQueryPointer(disp, root, &unusedwin, &focuswin, &unusedint, &unusedint, &unusedint, &unusedint, &unusedint);
        if(event.type == KeyPress &&(XLookupKeysym(&event.xkey, 0) == XK_q))
           spawn(disp, wclose);
        if(event.type == KeyPress &&(XLookupKeysym(&event.xkey, 0) == XK_w))
           spawn(disp, ff);
        if(event.type == KeyPress &&(XLookupKeysym(&event.xkey, 0) == XK_e)) 
           spawn(disp, fm);
        if(event.type == KeyPress &&(XLookupKeysym(&event.xkey, 0) == XK_r)) 
           spawn(disp, dmenu);
        if(event.type == KeyPress &&(XLookupKeysym(&event.xkey, 0) == XK_t))
           spawn(disp, term);
        if(event.type == KeyPress &&(XLookupKeysym(&event.xkey, 0) == XK_a))
           spawn(disp, mix);
        if(event.type == KeyPress &&(XLookupKeysym(&event.xkey, 0) == XK_s))
           spawn(disp, lock);
        if(event.type == KeyPress &&(XLookupKeysym(&event.xkey, 0) == XK_z))
           spawn(disp, foc);

        else if(event.type == ButtonPress && event.xbutton.subwindow != None){ 
        if(event.xbutton.button == Button1) 
           XMoveResizeWindow(disp, focuswin, 0, 0, 1920, 1080);
        if(event.xbutton.button == Button3)
           XMoveResizeWindow(disp, focuswin, 1920, 0, 1920, 1080); 
        if(event.xbutton.button == Button4)
           XCirculateSubwindowsUp(disp, root); 
        if (event.xbutton.button == Button5)
           XCirculateSubwindowsDown(disp, root);       
}
}
}
