# Simple C Redirector

This a very small server application (using Libmicrohttpd for the webserver
part) for providing HTTP redirects.

The redirects are defined compile time in the `link_redirects.h` file (which
you'll need to create). See the `example_redirects.h` for an example of what
the file should look like.

## Requirements

* C compiler (only tested with GCC)
* make

### libmicrohttpd

To install follow these instructions:
    https://www.gnu.org/software/libmicrohttpd/

Or use your operating system's package manager, probably something like:

```
sudo apt-get install libmicrohttpd-dev
```

## Installation

Rename the `example_redirects.h` file to `link_redirects.h` and edit to include
whatever link redirects you want.

```
mv example_redirects.h link_redirects.h
```

Compiling should _just work_, I have only tested on my a few PCs running Debian
based distros, so may be other quirks I haven't come across

```
make all
```

You'll see the binary created named `linkredr`. Copy it wherever you need to

### Compile time options

#### Links
All of the links are baked into the binary at compile time. Mainly because it'd
be easier to not have to bother with all of that stuff. Modify the links in
`link_redirects.h`. Hopefully it's obvious how it works, if not, just raise an
issue.

#### Port
The port this service runs on can be modified at compile time by changing
`#define PORT` in `main.h`.

#### Pages
If you're really keen, have a play around with the HTML in the `*_PAGE`
`#define`s in `main.h`. They're _pretty_ basic at the moment, but there's no reason you
couldn't include something a little fancier with CSS or something.

## Usage

```
./linkredr
```

That's it. No runtime options possible - everything is done compile time.

Just point your browser to the server (probable `localhost:8080`) and have a
play around. It really is stupidly simple.

## Licence
AGPLv3
