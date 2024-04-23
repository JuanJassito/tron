#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <fstream>
#include <string> 
#include <dibujo.hpp>

using namespace std;
using namespace ftxui;


int main(){
    dibujo moto ("./assets/images/moto.txt");
    dibujo bloque ("./assets/images/bloque.txt");

    int fotograma = 0;
    while (true)
    {
        this_thread::sleep_for(0.1s);
        fotograma++;
        Element personaje = spinner(21,fotograma) | bold | color(Color::Red3) | bgcolor(Color::White);
        Element dibujo = hbox({personaje,moto.getElement(),bloque.getElement()});

        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla,dibujo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();
    }

    return EXIT_SUCCESS;
}