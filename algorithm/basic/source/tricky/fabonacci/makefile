SrcFile=$(wildcard *.cpp)
ObjFile=$(patsubst %.cpp,%.o,$(SrcFile))

app:$(ObjFile)
	g++ -o app -I ./include $(ObjFile) -std=c++11

%.o:%.cpp
	g++ -c $< -I ./include -o $@

clean:
	-@rm *.o
	rm -rf app
