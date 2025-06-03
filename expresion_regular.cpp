//
//  main.cpp
//  ExpresiónRegular
//
//  Created by Ximena Perez Escalante on 16/05/25.
//

#include <iostream>
#include <string>
#include <regex>

// Expresión regular que acepta las palabras del arreglo inputAccepted
std::regex regExpression(R"(A(da|dan|aye|iya|elin|danedhel)$)");

/*
 Funcion que usa regex_match para ver si la palabra coincide
 con la expresion regular.
 Input:
 word: std::string - palabra que se va a revisar
 
 Se usa regex_match, que recibe la palabra y la expresion regular y
 unicamente devuelve true si la palabra coincide completamente.
 */
bool isValid(std::string word) {
    if (std::regex_match(word,regExpression)) {
        return true;
    }
    else {
        return false;
    }
}

/*
 Funcion para iterar ejemplos y contraejemplos predeterminados
 */
void ejemplos() {
    // Arreglo con las palabras que sí deben ser aceptadas
    std::string inputAccepted[6] = {"Ada","Adan", "Aiya", "Aaye", "Aelin", "Adanedhel"};
    
    // Arreglo con input que no debe ser aceptado
    std::string inputNotAccepted[6] = {"A", "Adaaaaa", "Adaan", "", "adanedh", "a"};
    
    // Calcular el tamano del arreglo
    int arraySize = sizeof(inputAccepted) / sizeof(inputAccepted[0]);
    
    std::cout << "Ejemplos:" << std::endl;

    // Iterar las palabras que deben ser aceptadas usando regex_match
    for (int i = 0;i < arraySize;i++){
        if (isValid(inputAccepted[i])) {
            std::cout << inputAccepted[i] <<
            " cumple con la gramática.\n" << std::endl;
        }
        else {
            std::cout << inputAccepted[i] <<
            " NO cumple con la gramática pero sí debería :(\n" << std::endl;
        }
    }
    
    std::cout << "\n\nContraejemplos:" << std::endl;
    
    // Iterar las palabras que NO deben ser aceptadas usando regex_match
    for (int i = 0;i < arraySize;i++){
        if (isValid(inputNotAccepted[i])) {
            std::cout << inputNotAccepted[i] <<
            " cumple con la gramática pero no debería :(\n" << std::endl;
        }
        else {
            std::cout << inputNotAccepted[i] <<
            " NO cumple con la gramática.\n" << std::endl;
        }
    }
}

/*
 Funcion que recibe una palabra del usuario y revisa que
 pertenezca al lenguaje.
 */
void checkUserWord() {
    int again = 1;
    std::string inputWord;
    
    std::cout << " - Por favor no ingreses espacios -" << std::endl;
    
    while (again == 1) {
        std::cout << "Ingresa la palabra: ";
        std::cin >> inputWord;
        
        if (isValid(inputWord)) {
            std::cout << inputWord <<
            " cumple con la gramática.\n" << std::endl;
        }
        else {
            std::cout << inputWord <<
            " NO cumple con la gramática.\n" << std::endl;
        }
        
        std::cout << "¿Quieres ingresar otra palabra?\n1. Si\n2. No" << std::endl;
        std::cin >> again;
        
        while (again != 1 && again != 2) {
            std::cout << "Selecciona una opcion\n1. Si\n2. No" << std::endl;
            std::cin >> again;
        }
    }
}

int main() {
    
    std::cout << "¡Bienvenid@!\n Selecciona una opcion:" <<
    "\n1. Ejemplos predeterminados\n2. Ingresar palabra" << std::endl;
    
    int option;
    
    std::cin >> option;
    
    while (option != 1 && option != 2) {
        std::cout << "Selecciona una opción" <<
        "\n1. Ejemplos predeterminados\n2. Ingresar palabra" << std::endl;
        std::cin >> option;
    }
    
    if (option == 1) {
        int op;
        
        ejemplos();
        
        std::cout << "¿Quieres ingresar una palabra?\n1. Si\n2. No" << std::endl;
        std::cin >> op;
        
        if (op == 1) {
            checkUserWord();
        }
    }
    else {
        int op;
        
        checkUserWord();
        
        std::cout <<
            "¿Quieres ver los ejemplos predeterminados?\n1. Si\n2. No" << std::endl;
        std::cin >> op;
        
        if (op == 1) {
            ejemplos();
        }
    }
    return 0;
}
