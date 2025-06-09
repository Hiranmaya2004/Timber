all:compile run 
compile:
	g++ timber.cpp -lsfml-graphics -lsfml-window -lsfml-system
run:
	./a.out

clean:
	rm -f timber.o timber
