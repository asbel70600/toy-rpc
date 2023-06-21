
//----------------------------------------------------------------
// 5.4

now remix and compact that answer

A. En la versión menos optimizada, %xmm0 se utiliza para almacenar dest durante la multiplicación. 
En la versión más optimizada, %xmm0 se utiliza para almacenar el resultado intermedio de la multiplicación.

B. La versión más optimizada implementa fielmente el código C de combine3, incluso cuando hay un alias de 
memoria entre dest y los datos del vector.

C. La optimización elimina una instrucción de carga de memoria innecesaria, pero podría producir resultados 
diferentes si se cambia la operación de multiplicación a división y el vector contiene un elemento igual a cero.

// ----------------------------------------------------------------
// 5.5

remix that in a more compacted way

A. El código realiza n multiplicaciones y (n-1) sumas.

B. El CPE de 5.00 es causado por las dependencias de datos entre iteraciones debido a las operaciones en las 
líneas 7-8 de la función, lo que limita el paralelismo a nivel de instrucción y resulta en un mayor número de 
ciclos por elemento.


//----------------------------------------------------------------
// 7.1

En `swap.o`:
- `bufp0`: símbolo global definido en `swap.o`, asignado a la sección `.data`.
- `bufp1`: símbolo global definido en `swap.o`, asignado a la sección `.bss`.
- `swap`: símbolo global definido en `swap.o`, asignado a la sección `.text`.

En `m.o`:
- `buf`: símbolo global definido en `m.o`, asignado a la sección `.data`.
- `main`: símbolo global definido en `m.o`, asignado a la sección `.text`.

La palabra clave `extern` en `swap.c` indica que el símbolo `buf` se referencia pero 
no se define en `swap.o`. Por lo tanto, no tendrá una entrada en la tabla de símbolos 
en `swap.o`. En cambio, habrá una entrada en la tabla de símbolos para `buf` en `m.o`, donde se define.

//----------------------------------------------------------------
// 7.2

A.
(a) REF(main.1) → DEF(main.2)
(b) REF(main.2) → DEF(main.2)

B.
(a) REF(main.1) → DEF(main.1)
(b) REF(main.2) → DEF(main.2)
C.
(a) REF(x.1) → DEF(x.1)
(b) REF(x.2) → DEF(x.2)

// ----------------------------------------------------------------
// 7.3
A
$ gcc p.o -L. -lx
B
$ gcc p.o -L. -lx -ly
C
$ gcc p.o -L. -lx -ly -lx -lp