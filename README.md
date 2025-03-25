# TC2037_E1_A01751827
Evidencia 1 Análisis Léxico - Implementación de Métodos Computacionales
<h2>Descripción</h2>
Para el lenguaje de este proyecto ∑ = {a, d, e, h, i, l, n, y}, se pide que únicamente sean aceptadas las siguientes palabras:

- <strong> Aaye or Aiya  </strong> - Quenya word for the verb 'Hail'.

- <strong> Ada </strong> - 'Father', spoken by Arwen to Lord Elrond

- <strong> Adan </strong> - 'Father of Man' (Sindarin, from the Quenya Atan, Atani) The Elves' name for those Men who first crossed the Blue Mountains (Ered Luin) during the First Age. Plural is Edain

- <strong> Aelin </strong> - 'lake, pool' as in Aelin-uial.

- <strong> Adanedhel </strong> - 'elf-man'.


Debido a que no hay patrones y se están tratando palabras que se asemejan al lenguaje natural, decidí diseñar un DFA (Deterministic Finite Automaton), que muestro a continuación. 

<h2>Automata:</h2>
<img src="https://github.com/XimePerezEscalante/TC2037_E1_A01751827/blob/main/Automata_A01751827.png?raw=true" alt="automata">

<h2>Expresión regular</h2>
<strong> A(da|dan|aye|iya|elin|danedhel)$ </strong>
<br>
Donde se está declarando que:
<br>
<ul>
  <li>Las palabras deben comenzar con A.</li>
  <li>Seguido de la A, se acepta cualquier elemento dentro del paréntesis separado por | que sirve como un or.</li>
  <li>El $ significa que ahí debe terminar la palabra.</li>
</ul>
