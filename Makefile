CC = zig cc

CFLAGS = -O3 -march=native -mtune=native \
         -std=c23 -pedantic-errors \
         -Wall -Wextra -Wpedantic -Werror \
         -Wshadow -Wconversion -Wsign-conversion \
         -Wformat=2 -Wstrict-prototypes -Wmissing-prototypes \
         -Wold-style-definition -Wmissing-declarations -Wredundant-decls \
         -Wnested-externs -Wundef -Wcast-align -Wcast-qual \
         -Wwrite-strings -Wpointer-arith -Wenum-conversion -Wvla \
         -Wfloat-equal -Wdouble-promotion -Wmissing-field-initializers \
         -g -fno-omit-frame-pointer -fdiagnostics-color=always \
         -fstack-protector-strong -D_FORTIFY_SOURCE=2


# For a debug build with sanitizers (uncomment or make a separate target)
# CFLAGS_SAN = $(CFLAGS) -fsanitize=address,undefined

default: run

all: out/main

out/main: main.c
	@mkdir -p out
	$(CC) -target native $(CFLAGS) -o $@ $<

run: out/main
	./out/main

clean:
	rm -rf out
