// =================================================================
//
// File: main.cpp
// Author: Maxime Vilcocq Parra
// Date: 11 / 09 / 2023
//
// =================================================================

#include <vector> //permite utilizar vectores (funcionan como arreglos de longitud variable)
#include <string>
#include <iostream>
#include <algorithm> // permite utilizar la función sort
using namespace std;

// struct se utiliza para emplear variables de distintos tipos en un mismo vector
struct Cadena {
    // se declaran los elementos de la estructura
    string Secuencia; // aqui se guarda la secuencia
    int inversiones, index; //Guarda el numero de inversiones y el numero de cadena
    // el numero de cadena se utiliza para saber como ordenar dos cadenas cuando tienen el mismo num de inversiones

    Cadena(const string& cad, int inv, int ind){ //es un constuctor que recibe la cadena, num de inversiones e index
        // se guardan los valores en la estructura Cadena
        Secuencia = cad;
        inversiones = inv;
        index = ind;
    }
};


int cuentaInversiones(const string& cad, int car) { // calcula las inversiones
    int inv = 0; // la cuenta inicia en 0

    for (int i = 0; i < car; i++) { //car el la longitud de cadena o num de caracteres

        for (int j = i + 1; j < car; j++) {

            if (cad[i] > cad[j]) { //compara la posicion i con la j, si la i es mayor agrega una inversion
                inv= inv + 1;
                //cuando termine de comparar el primer valor i con todos los valores j, repite el proceso para la sig i
            }

        }

    }
    return inv; // regresa las veces que se necesita invertir la cadena para ordenarla
}

// se compara el num de inversiones de las cadenas
bool comparaInv(const Cadena& cad1, Cadena& cad2) {

    if (cad1.inversiones == cad2.inversiones) {
        return cad1.index < cad2.index; // regresa si el indice de la cadena 1 es menor al de la 2
    }

    else {
        return cad1.inversiones < cad2.inversiones; // regresa si la cadena 1 tiene menos inversiones que la 2
    }

}

int main() {
    string cadena;
    int car, lines, inversiones; // car es el num de caracteres, lines es el num de cadenas distintas
    cin >> car >> lines;

    vector<Cadena> cadenas; // se crea un vector con el contenido cadenas

    for (int i = 0; i < lines; ++i) { //para cada linea o secuencia
        cin >> cadena; //guarda la secuencia
        inversiones = cuentaInversiones(cadena, car); // Cuenta las inversiones de la cadena
        cadenas.push_back(Cadena(cadena, inversiones, i)); //guarda la cadena y las inversiones en el vector
    }

    sort(cadenas.begin(), cadenas.end(), comparaInv); //ordena el vector respecto a las inversiones o indice

    cout <<"\n"; //salto de linea para mostrar de forma mas clara el resultado

    for (int i = 0; i < lines; ++i) {
        cout << cadenas[i].Secuencia << endl; //imprime las cadenas en orden de inversiones o indice
    }

    return 0;
}