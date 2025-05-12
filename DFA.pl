% transiciones
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

% estados finales
estado_final(q3).
estado_final(q4).
estado_final(q9).
estado_final(q12).

% comenzar a parsear desde el estado inicial (q0)
valida(Palabra):-
    parse(Palabra, q0).

% caso base
parse([], Estado_inicial):-
    estado_final(Estado_inicial).

% parsear la palabra con recursividad
parse([Head|Rest], Estado_inicial) :-
    traslada(Head, Estado_inicial, Estado_final),
    parse(Rest, Estado_final).
