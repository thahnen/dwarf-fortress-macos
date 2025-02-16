# Dwarf Fortress for macOS

This repository contains projects to create an application bundle to wrap the distribution of Dwarf
Fortress and patch it to work as smooth as possible with macOS 11 or later.

This currently relies on the latest available Dwarf Fortress Classic version that was released for
macOS ([0.47.05 from 28.01.2021](https://www.bay12games.com/dwarves/older_versions.html)).

## Installation

Download and unpack the archive from the
[GitHub Relases](https://github.com/thahnen/dwarf-fortress-macos/releases) page. Move the
application to its final destination and open it. If this does not work immidietely, try running
the following command:

```shell
sudo codesign --force --deep --sign - df.app
```

## Projects

This repository contains the following projects:

- Create a simple Dwarf Fortress bash script launcher
- Create the application bundle

The order above is also the order of building the final application package installer. The Dwarf
Fortress bash script launcher is necessary as macOS application bundles cannot start shell scripts
as the one distributed with Dwarf Fortress (`df`).

## Development

For development only a few tools are necessary but using macOS 11 or later is required.

- make (bundled with macOS)
- gcc (bundled with macOS)
- Java Development Kit (tested with OpenJDK Temurin 17)
- Apache Ant (tested with 1.10.14)

Any IDE should be viable for development, I relied on the **Eclipse IDE** with both
*[JDT](https://projects.eclipse.org/projects/eclipse.jdt)* /
*[CDT](https://projects.eclipse.org/projects/tools.cdt)* installed for the Ant and Makefile/C
projects.
