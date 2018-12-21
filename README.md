## kcmouse ##
minimal window manager

requires Xdotool for focus and killing a window, it should be available in most linux distributions.

Edit the code if you want to change default programs, Here is the current setup:

Mod4 + q - kills the selected window (using xdotool)
Mod4 + z - focus the selected window (using xdotool)
Mod4 + w - launch firefox
Mod4 + e - launch pcmanfm-qt
Mod4 + r - launch dmenu
Mod4 + t - launch urxvt
Mod4 + a - launch alsamixer
Mod4 + s - launch slock

Mod4 + Button1 - make focused window fullscreen and move to left monitor.
Mod4 + Button3 - make focused window fullscreen and move to right monitor.
Mod4 + Button4 (scrollwheel) - cycle up through open programs.
Mod4 + Button5 (scrollwheel) - cycle down through open programs. 

To compile:  gcc -o keywm keywm.c -lX11

add into your .xinitrc to start with X11 or make a new .desktop file under /usr/share/xsessions
if using a login manager
