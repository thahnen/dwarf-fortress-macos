# Using the macOS bundled GCC version
CC = gcc

# Necessary for Eclipse CDT
all: clean dflauncher

# Create the actual launcher
dflauncher: dflauncher.c
	$(CC) dflauncher.c -o dflauncher

# Necessary for Eclipse CDT
clean:
	rm -f dflauncher
