# Screenshot-Tray Prototype
*A prototype of a system-trayed screenshot application written in C++14 and with Qt 5.*

## Requirements
* [Qt](https://www.qt.io/download-qt-installer) 5.10.x
* [Visual Studio](https://visualstudio.microsoft.com/) or [MinGW](http://mingw.org/)

## Building
### MSBuild
To compile and link the application with the MSBuild toolchain run:
```
"C:\Program Files (x86)\Microsoft Visual Studio\[YYYY]\[product]\VC\Auxiliary\Build\vcvarsall.bat" [target]
qmake screenshot-tray-prototype.pro
nmake [debug|release]
mt.exe -manifest ..\screenshot-tray-prototype.mf -outputresource:screenshot-tray-prototype.exe
```

### MinGW
To compile and link the application with MinGW toolchain run:
```
qmake screenshot-tray-prototype.pro
mingw32-make
```

### Todo
- [ ] Integrate a QTimer for shooting screenshot at an predefined interval
- [ ] Fix display bug with QGraphicsScene containing multiple Qixmaps
- [ ] Implement a quick way to convert QPixmap to WebP with libwebp
- [ ] Implement a way to encode WebP Images to WebM using libvpx