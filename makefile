# Use like this:

OS := $(shell uname)

ifeq ($(OS),Darwin)
#MacOS
all:
	cc -framework OpenGL -framework GLUT -framework Cocoa -Wno-deprecated-declarations main.o chess.o $(HW).c -o $(HW)

else
#Linux
all:
	g++ main.o chess.o h $(HW).c -lglut -lGL -lGLU -w -o $(HW)

endif
