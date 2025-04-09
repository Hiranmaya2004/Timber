# all: compile link

# compile:
# 	g++ -c timber.cpp -I"D:\SFML\Sources\SFML-2.6.2\include" -DSFML_STATIC

# link:
# 	g++ timber.o -o timber -L"D:\SFML\Sources\SFML-2.6.2\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lfreetype -lopengl32 -lwinmm -lgdi32 -lmingw32 -lstdc++ -mwindows -luser32 -ladvapi32 -lshell32
# clean:
# 	rm -f timber *.o


CXX = g++
SFML_DIR = D:\SFML\Sources\SFML-2.6.2
INCLUDE_DIR = $(SFML_DIR)\include
LIB_DIR = $(SFML_DIR)\lib

CXXFLAGS = -c -std=c++11 -I"$(INCLUDE_DIR)"
LDFLAGS = -L"$(LIB_DIR)" -static-libgcc -static-libstdc++

LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s \
       -lfreetype -lopengl32 -lwinmm -lgdi32 -luser32 \
       -ladvapi32 -lkernel32 -lshell32 -mwindows \
       -lstdc++ -lm

all: compile link

compile:
	$(CXX) $(CXXFLAGS) -DSFML_STATIC timber.cpp

link:
	$(CXX) timber.o -o timber $(LDFLAGS) $(LIBS)

clean:
	rm -f timber.o timber.exe