g++ -c src/main.cpp -o build/main.o
g++ build/main.o -o bin/a.exec -lglfw -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lGLEW
bin/a.exec
