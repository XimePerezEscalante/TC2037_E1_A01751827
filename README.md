# TC2037_E1_A01751827
Evidencia 1 Análisis Léxico - Implementación de Métodos Computacionales
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
  
### Contraejemplos
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
