OBJS = main.o
OUT = main
IN = main.cpp src/glad.c
CXX = g++
CXXFLAGS = -lGLEW -ldl -lglfw -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -o main
CXXINCLUDE = -Iinclude -I/usr/include
main: main.cpp
	$(CXX)  $(IN) $(CXXINCLUDE) $(CXXFLAGS) 
clean:
	rm -f $(OBJS) $(OUT)