output = bin
source = src
include = -Iinclude
dependencias = -lftxui-screen -lftxui-dom -lftxui-component
flags = -std=c++2a $(dependencias) $(include)

$(output)/tron : $(source)/main.cpp 
	g++ -o $@ $< $(flags)

run : $(output)/tron
	./$<

runPantalla : $(output)/pantalla
	./$<

$(output)/pantalla : $(source)/pantalla.cpp 
	g++ -o $@ $< $(flags)
