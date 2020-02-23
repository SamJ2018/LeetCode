SrcFile=$(wildcard .cpp && source/*.cpp)
ObjFile=$(patsubst %.cpp,%.o,$(SrcFile))

result:$(ObjFile)
	g++ -o result -I ../include $(ObjFile)

%.o:%.cpp
	g++ -c $< -I ../include -o $@

clean:
	-@rm *.o source/*.o
	rm -rf result
