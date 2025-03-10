
Developer documentation for MRVN-radiant
======================================

Getting the source
==================

The latest source is available from the git repository:

  - https://github.com/F1F7Y/MRVN-radiant

Libs for Windows:

  - https://www.dropbox.com/s/hcgkwzzmja3m6c0/netradiant-custom-extra-win.zip



Linux(using X-windows)
======================

environment:
- gcc >= version 3.1 (preferably)
- GNU make
- svn >= 1.1 (some build steps use svn)

dependencies:
- gtk+ >= 2.4.0 (requires glib, atk, pango, iconv, etc)
- gtkglext >= 1.0.0 (requires opengl)
- libxml2 >= 2.0.0
- zlib >= 1.2.0 (for archivezip module)
- libpng >= 1.2.0 (for imagepng module)

build:
run 'make'

run:
Execute 'install/radiant.x86'


Win32 (using MSYS2)(recommended)
==================

environment:
- MSYS2 (http://www.msys2.org/)
- from msys2_shell:
  pacman -S --needed base-devel
    32 bit:
  pacman -S --needed mingw-w64-i686-{toolchain,gtk2,gtkglext}
    64 bit:
  pacman -S mingw-w64-x86_64-{toolchain,gtk2,gtkglext}
    these are only strictly required for gamepacks:
  pacman -S --needed unzip svn git

build:
- Start respective mingw shell
- Switch to the directory with NetRadiant-custom source
- Typical release build:
  `make MAKEFILE_CONF=msys2-Makefile.conf BUILD=release -j$(nproc)`
- Typical developer's build:
  `make MAKEFILE_CONF=msys2-Makefile.conf DEPENDENCIES_CHECK=off INSTALL_DLLS=no BUILD=debug RADIANT_ABOUTMSG="MRVN-radiant dev build" -j$(nproc)`
- run:
- in the "install" directory, double click radiant.exe


Win32 (using MinGW)
==================

environment:
- MinGW (http://www.mingw.org/wiki/Getting_Started)
  Install this to c:\mingw, and select the components C compiler, C++ compiler
  and MSYS Basic System
- Start the MSYS shell once, then exit it
- Prepackaged Radiant dependencies (Gtk and other stuff):
  http://www.icculus.org/netradiant/files/netradiant-dependencies-mingw32-20101211-7z.exe
  Extract this one to
  c:\mingw\msys\1.0\home\username
  (if you do this with 7zip, keep the "netradiant-dependencies-mingw32" folder
  name of the contents)
- now download the source from the MSYS shell, if you don't already have it:
  ~/netradiant-dependencies-mingw32/util/bin/git clone git://git.icculus.org/divverent/netradiant.git

build:
- Start the MSYS shell
- Switch to the directory with NetRadiant-custom source
- `make MAKEFILE_CONF=mingw-Makefile.conf`

run:
- in the "install" directory, double click radiant.exe
- if you get a DLL not found error, copy the DLL from either c:\mingw\bin or
  from c:\mingw\msys\1.0\bin to the "install" directory


OSX(using X-windows)(UNTESTED)
====================

environment:
- OS X 10.5 or 10.6
- Xcode developer tools installed (OSX DVD)
- X11 (from the OS X DVD)
- MacPorts or fink or homebrew installed
- the following packages installed:
Macports (reported as working in 10.15.3):
  gtkglext pkgconfig glib2-devel libxml2 gtk2 pango atk gettext wget
Fink:
  gtkglext1 pkgconfig glib2-dev libxml2 gtk+2 gtk+2-dev pango1-xft2-ft219-dev atk1 gettext-dev wget
homebrew (does not work due to X11->Quartz switch, requires patched gtkglext):
  gtk+ gtkglext

build:
run 'make'

homebrew build:
run 'export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:/opt/X11/lib/pkgconfig
make'

run:
Switch into the install folder, and run NetRadiant.app
