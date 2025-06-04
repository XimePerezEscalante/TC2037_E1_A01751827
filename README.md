### TC2037_E1_A01751827
# Evidencia 1 Análisis Léxico - Implementación de Métodos Computacionales
## Descripción
Para el lenguaje de este proyecto ∑ = {a, d, e, h, i, l, n, y}, se pide que únicamente sean aceptadas las siguientes palabras:

- **Aaye or Aiya** - Quenya word for the verb 'Hail'.

- **Ada** - 'Father', spoken by Arwen to Lord Elrond

- **Adan** - 'Father of Man' (Sindarin, from the Quenya Atan, Atani) The Elves' name for those Men who first crossed the Blue Mountains (Ered Luin) during the First Age. Plural is Edain

- **Aelin** - 'lake, pool' as in Aelin-uial.

- **Adanedhel** - 'elf-man'.


Debido a que no hay patrones y se están tratando palabras que se asemejan al lenguaje natural, decidí diseñar un DFA (Deterministic Finite Automaton), que muestro a continuación. 

## Autómata:
![Automata](https://github.com/XimePerezEscalante/TC2037_E1_A01751827/blob/main/Automata_A01751827.png?raw=true)

### Elementos del diagrama
- **Q0:** estado inicial.
- **Círculos:** estados.
- **Doble círculos:** estados finales.
- **Flechas:** arcos.
- **Letras en las flechas:** símbolos.

Un autómata, también conocido como máquina de estados,  representa el cambio de un estado a otro por medio de arcos y símbolos que se encuentran en los arcos, que son los que te hacen pasar de un estado a otro.
El diagrama anterior se puede representar en la siguiente tabla de estados:

| Estado inicial | Símbolo | Estado final |
|----------------|---------|--------------|
| Q0    | A   | Q1   |
| Q1    | d   | Q2   |
| Q1    | i   | Q10   |
| Q1    |  a  | Q13   |
| Q1    |  e  | Q15   |
| Q2    |  a  |  Q3   |
| Q3    |  n  |  Q4   |
| Q4    |  e  |  Q5   |
| Q5    |  d  |  Q6   |
| Q6    |  h  |  Q7   |
| Q7    |  e  |  Q8   |
| Q8    |  l  |  Q9   |
| Q10   |  y  |  Q11  |
| Q11   |  a  |  Q12  |
| Q13   |  y  |  Q14  |
| Q14   |  e  |  Q9   |
| Q15   |  l  |  Q16  |
| Q16   |  i  |  Q17  |
| Q17   |  n  |  Q9   |


## Expresión regular
**A(da|dan|aye|iya|elin|danedhel)$**
<br>
<br>
Donde se está declarando que:
<br>
<br>
- Las palabras deben comenzar con A.
- Seguido de la A, se acepta cualquier elemento dentro del paréntesis separado por **|** mejor conocido como un or.
- El **$** significa que ahí debe terminar la palabra.

## Diferencia entre el Autómata y la Expresión Regular
La diferencia más visible es que en los autómatas se representan transiciones entre estados determinadas por un símbolo, 
mientras que en la expresión regular se definen los patrones que deben cumplir los strings. Así que para saber si una
palabra pertence a un lenguaje:

En el _autómata_ se recorre letra por letra y cuando termina la palabra, se revisa si el estado actual es un estado final.

En la _expresión regular_ se revisa que la palabra cumpla con el patrón que haya sido establecido.

## Implementación
Para el DFA en Prolog, se deben definir:
1. Las transiciones entre estados: Estado Inicial, Estado Final y el símbolo con el que se pasó al estado inicial.
2. Los estados finales: en este caso son q3, q4, q9 y q12.
3. Las reglas que van a recorrer cada letra de la palabra para ver si es válida o no.


Todo esto se muestra a continuación:
1. **Transiciones:**

    ```prolog
    traslada('A',q0,q1).
    traslada(d,q1,q2).
    traslada(i,q1,q10).
    traslada(a,q1,q13).
    traslada(e,q1,q15).
    traslada(a,q2,q3).
    traslada(n,q3,q4).
    traslada(e,q4,q5).
    traslada(d,q5,q6).
    traslada(h,q6,q7).
    traslada(e,q7,q8).
    traslada(l,q8,q9).
    traslada(y,q10,q11).
    traslada(a,q11,q12).
    traslada(y,q13,q14).
    traslada(e,q14,q9).
    traslada(l,q15,q16).
    traslada(i,q16,q17).
    traslada(n,q17,q9).
    ```
2. **Estados finales:**

    ```prolog
    estado_final(q3).
    estado_final(q4).
    estado_final(q9).
    estado_final(q12).
    ```
3. **Reglas:**

    Regla que recibe la palabra:

    ```prolog
    % comenzar a parsear desde el estado inicial (q0)
    valida(Palabra):-
        parse(Palabra, q0).
    ```

    Regla que establece el caso base, que es cuando la lista queda vacía. Recibe el estado, para ver si coincide con un estado final y de ser así, la palabra es válida:

    ```prolog
    % caso base
    parse([], Estado_inicial):-
        estado_final(Estado_inicial).
    ```
    Regla en la que se recorre la palabra usando recursividad, lleva a cabo la transición y vuelve a usar parse:

    ```prolog
    % parsear la palabra con recursividad
    parse([Head|Rest], Estado_inicial) :-
        traslada(Head, Estado_inicial, Estado_final),
        parse(Rest, Estado_final).
    ```
## Tests
### Prolog

En la carpeta **Tests Autómata** se encuentran fotos con las pruebas que se mencionan en este apartado.

A continuación se muestra por cada palabra, el input que debe escribirse en Prolog para comprobar que el Autómata acepta las palabras del lenguaje:
1. **Ada**
   ```prolog
   valida(['A',d,a]).
   ```
2. **Adan**
   ```prolog
   valida(['A',d,a,n]).
   ```
3. **Adanedhel**
   ```prolog
   valida(['A',d,a,n,e,d,h,e,l]).
   ```
4. **Aelin**
   ```prolog
   valida(['A',e,l,i,n]).
   ```
5. **Aaye**
    ```prolog
   valida(['A',a,y,e]).
    ```
6. **Aiya**
    ```prolog
    valida(['A',i,y,a]).
    ```
  
**Contraejemplos**

A continuación se muestran diferentes input para demostrar que el Autómata no acepta palabras no pertenecientes al lenguaje:
```prolog
valida(['A']).
valida(['A',d,a,n,n]).
valida(['A',i,y,e]).
valida([a]).
valida([a,d,a]).
valida([a,d,a,n]).
valida(['A',d,e,n,e,d,h,e,l]).
```
### Expresión regular en C++

Para validar que la expresión regular, se usó la librería `std::regex` en C++.

**Compilar el archivo**
```bash
g++ expresion_regular.cpp
```

**Ejecutar el programa**
```bash
./a.out
```

**¿Cómo funciona?**

Primero se tiene que crear la instancia de la clase regex (en este caso fue de manera global). Tiene el nombre `regExpression` y se le manda la expresión.
```C++
std::regex regExpression(R"(A(da|dan|aye|iya|elin|danedhel)$)");
```

Posteriormente se usa la función `std::regex_match()`, que recibe un string y la expresión regular. Y sólo devuelve `true` si el string coincide completamente con la expresión.
```C++
std::regex_match(std::string, std::regex);
```

**Programa**

El programa cuenta con dos opciones:
1. Revisar los ejemplos predeterminados.
2. Ingresar una palabra.

Si se elige la primera opción, se revisan las siguientes palabras:

**Ejemplos**

Se encuentran en el arreglo `inputAccepted`.

1. Ada
2. Adan
3. Adanedhel
4. Aelin
5. Aaye
6. Aiya

**Contraejemplos**

Se encuentran en el arreglo `inputNotAccepted`.

1. A
2. Adaaaaa
3. Adaan
4. empty string
5. adanedh
6. a

Para ambos casos se iteran los arreglos usando un ciclo for y se manda llamar la función `isValid(std::string)`:

```C++
bool isValid(std::string word) {
    if (std::regex_match(word,regExpression)) {
        return true;
    }
    else {
        return false;
    }
}
```

**Ouput esperado**

- *Ejemplos:* `La palabra [word] cumple con la gramática`.
- *Contraejemplos:* `La palabra [word] NO cumple con la gramática`.

Por otro lado, si se escoge la segunda opción, el usuario debe ingresar una palabra *sin espacios* y se revisa de la misma manera.

**Referencias**

CPlusPlus. _Regex_. CPlusPlus.com. Recuperado de: https://cplusplus.com/reference/regex/regex/
