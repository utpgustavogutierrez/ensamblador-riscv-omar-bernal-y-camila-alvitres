[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/toYFD-FK)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=14810226&assignment_repo_type=AssignmentRepo)
# Estructuras de datos (primer examen)

- [Estructuras de datos (primer examen)](#estructuras-de-datos-primer-examen)
  - [Introducción](#introducción)
  - [Ensamblador para RISCV](#ensamblador-para-riscv)
  - [Ejercicio 1](#ejercicio-1)
  - [Ejercicio 2](#ejercicio-2)
  - [Ejercicio 3](#ejercicio-3)
  - [Ejercicio 4](#ejercicio-4)
- [Ejercicio 5](#ejercicio-5)
- [Ejercicio 6](#ejercicio-6)
- [Ejercicio 7](#ejercicio-7)
- [Ejercicio 8](#ejercicio-8)
- [Ejercicio 9](#ejercicio-9)
- [Ejercicio 10](#ejercicio-10)
- [Recursos](#recursos)
- [Resumen de instrucciones](#resumen-de-instrucciones)
  - [Tipo R](#tipo-r)
  - [Tipo I](#tipo-i)
  - [Aritméticas y lógicas](#aritméticas-y-lógicas)
  - [Corrimientos](#corrimientos)
  - [Carga en memoria](#carga-en-memoria)
  - [Saltos incondicionales](#saltos-incondicionales)
  - [Interrupciones](#interrupciones)
  - [Tipo S](#tipo-s)
  - [Tipo B](#tipo-b)
  - [Tipo J](#tipo-j)
  - [Tipo U](#tipo-u)

## Introducción

Para este examen usted requerirá de alguna documentación y de algo de código
fuente que estará disponible como parte del repositorio donde se encuentra este
archivo.

Este trabajo está diseñado para ser realizado en parejas. Es decir, grupos de
máximo dos estudiantes. Al respecto es necesario aclarar que en cualquier caso
se puede requerir una sustentación. En esas circunstancias la nota del trabajo
será la nota de la sustentación. Por tratarse de un trabajo en grupos ambos
integrantes deben estar en total capacidad de llevar a cabo la sustentación e
igual la nota será grupal.

## Ensamblador para RISCV

El trabajo consiste en la implementación de un ensamblador para el conjunto de
instrucciones de RISCV32IM. Un ensamblador es un programa que traduce código
fuente como el siguiente:

```assembly
main:
    addi x4, zero, 50
    addi x5, zero, 50
    beq x4, x5, label1
    addi x6, zero, 80
    beq zero, zero, label2
    

label1:
    addi x6, zero, 100

label2:
    add zero, zero, zero
```

en un archivo con el siguiente código:

```
03 20 02 13 03 20 02 93 00 52 06 63 05 00 03 13 
00 00 04 63 06 40 03 13 00 00 00 33 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
```

Es de anotar que la salida no es exactamente esa, fue recortada para que no
ocupara tanto espacio en el documento.

Al programa de arriba lo llamaremos el programa de entrada y al de abajo lo
llamaremos el programa de salida para los efectos de ésta tarea. Entonces
básicamente lo que usted debe presentar es un programa que tome como entrada un
archivo conteniendo código de ensamblador como el de arriba y escriba como
salida un archivo con código como el de abajo.

Lo único que queda entonces es establecer es cómo cada línea del programa de
arriba debe quedar representada en el archivo de salida. Para que el desarrollo
de este ensamblador no luzca en exceso complicado, será descrito por medio de
ejercicios. Estos irán incorporando cambios sobre su programa de manera
incremental hasta terminar en un ensamblador completo.

## Ejercicio 1

En esta primera parte usted va a realizar un programa en C/C++ que lea un
archivo de entrada y escriba en un archivo de salida de la siguiente forma:

Cada línea no vacía de la entrada puede ser de una de las siguientes entidades:

- _Etiquetas_:  marcan el inicio de una sección dentro del programa.  
- _Instrucciones_: son las que finalmente serán traducidas.
- _Directivas_:  son opciones que no pertenecen al lenguaje de programación
   pero que afectan la forma como quedará el archivo de salida.
- _Comentarios_: son anotaciones de código que no tienen relevancia durante
   la ejecución.

1. Los comentarios deben ser ignorados y no deben ir en el archivo de salida.
2. Las directivas también serán ignoradas por ahora.
3. Por cada instrucción debe aparecer en el archivo de salida una línea de 32
   bits (binario) con solamente ceros. Exceptuando la parte del código de
   operación, el cual si debe coincidir con los códigos presentados en

## Ejercicio 2

Para este momento usted ya debe contar con una implementación que, a partir de
un archivo de entrada como el siguiente:

```assembly
main:
    addi x4, zero, 520
    addi x5, zero, 1550
    beq x4, x5, label1
    addi x6, zero, 80
    beq zero, zero, label2
    

label1:
    addi x6, zero, 100

label2:
    add zero, zero, zero
```

produce lo siguiente en el archivo de salida.

```
00 00 00 00 00 00 00 00 00 00 00 00 0  0010011    
00 00 00 00 00 00 00 00 00 00 00 00 0  0010011    
00 00 00 00 00 00 00 00 00 00 00 00 0  1100011    
00 00 00 00 00 00 00 00 00 00 00 00 0  0010011    
00 00 00 00 00 00 00 00 00 00 00 00 0  1100011    
00 00 00 00 00 00 00 00 00 00 00 00 0  0010011    
00 00 00 00 00 00 00 00 00 00 00 00 0  0110011    
```

Note que hay una separación con los últimos 7 valores en cada instrucción. Esto
es simplemente para facilitar la lectura pero tal separación no va en el archivo
de salida. Los datos de la última "columna" (por llamarla de alguna forma)
corresponden al código de operación de cada instrucción del archivo de entrada.
Note también que las etiquetas no están presentes. De esas se encargará más
adelante.

Ahora lo que debe hacer es modificar su programa para adicionar la siguiente
funcionalidad.

Casi todas las instrucciones tienen un registro destino, esto se puede apreciar
en la siguiente imagen.

![](./rtype.svg)
![](./itype.svg)
![](./stype.svg)
![](./btype.svg)
![](./utype.svg)
![](./jtype.svg)

Como se puede apreciar en la figura anterior, a excepción de las instrucciones
del tipo _S_ y _B_, las demás tienen un campo _rd_. En esta parte usted
adicionará la codificación de este campo en la salida. Para este momento usted
ya habrá considerado que cada instrucción en una cadena de texto se puede
representar de una mejor manera. Por ejemplo, una secuencia con la información
realmente importante.

Por ejemplo, en la instrucción ` addi x4, x10, 520` lo realmente importante es
la información presente en la secuencia:

 $$I=\langle \text{addi}, x4, x10, 520\rangle$$
 

Asimismo se puede hacer con cualquiera de las otras instrucciones
sin importar su tipo.

Esta notación luce mucho mejor y usted cuenta con estructuras de datos que le
van a facilitar el trabajo. Teniendo cada instrucción en una estructura de datos
y otra estructura de datos que contenga todas las instrucciones luce como una
buena representación del archivo de entrada. De esta manera lo que usted hará en
adelante es simplemente procesar esta gran estructura para realizar todas las
conversiones.

El resultado de este ejercicio es entonces una gran secuencia de instrucciones,
donde cada instrucción es a su vez, una secuencia como la del ejemplo anterior.
Adicionalmente usted recorrerá esta gran secuencia para realizar la codificación
del campo _rd_ en las instrucciones que lo tengan. Esto lo escribirá en el
archivo de salida.

## Ejercicio 3

Como producto del ejercicio anterior usted ya debe contar con todos los datos de
las instrucciones en una estructura de datos. Esta estructura usted la eligió
teniendo en cuenta sus conocimientos pero si ve la necesidad la puede cambiar
más adelante. Lo importante es ir revisando las necesidades que se presentan y
de ser necesario realizar los cambios o ajustes necesarios.

Adicionalmente ya debe estar familiarizado con el tratamiento del archivo de
entrada y por ende ya debe estar en capacidad de codificar cualquier instrucción
de tipo _R_.

![](./rtype.svg)

Hay instrucciones que tienen constantes o, como también las llamaremos, valores
inmediatos. Por ejemplo las instrucciones tipo _I_ son de ese grupo.  En el caso
de estas instrucciones es necesario codificar las constantes. Este proceso es
simple pero requiere de algunas consideraciones. Las constantes de este grupo
deben ser representables en 12 bits.

![](./itype.svg)

Note que la única diferencia entre los dos tipos de instrucciones es la
constante o valor inmediato. Para codificar esta parte debe tener en cuenta dos
aspectos:

1. La constante de caer en 12 bits y de no ser el caso su programa debe fallar
   reportando el error.
2. La constante puede ser negativa. En este caso la forma de codificarla es
   utilizando el complemento a 2 en su representación binaria. 

Con la culminación de este ejercicio ya lleva un 40 porciento completado. Sin
embargo, lo más importante es que ya tiene un gran conocimiento sobre su
programa.

## Ejercicio 4

Hasta este momento falta poco para terminar con la codificación completa de las
instrucciones de tipo _R_ y tipo _I_. Para completar las tipo $R$ es cuestión de
codificar los campos _funct3_ y _funct7_ tal y como lo estipula la tabla para
cada operación. Es decir, para cada instrucción [tipo _R_](#tipo-r), usted de
los 32 bits ya codificó el _opcode_ el cual es el mismo para todas (ejercicio
1). El registro _rd_ del cuaál codificó el número. Por ejemplo `add x2, x5, x7`,
codificó el 2 en los siguientes 5 bits (después del _opcode_). Luego sigue el
_funct3_ que depende de la operación específica. Tenga cuidado que en la tabla
aparece un hexadecimal (`0x4` en el caso de la operación `xor`) que debe ir
codificado en 3 bits. Luego siguen los campos _rs1_ y _rs2_ los cuales se
traducen en la misma forma que lo hizo con _rd_ (5 bits para cada uno). Por
último queda _funct7_ que es cero para todas las instrucciones a excepción de
`sub` y `sra` donde se codifica el hexadecimal `0x20` en 7 bits.

Para completar la codificación de las instrucciones [tipo _I_](#tipo-i)
(aritméticas y de corrimientos) no es mucho lo que falta.

El _opcode_ ya debe estar codificado desde el ejercicio 1. El _funct3_ debe
codificarlo en 3 bits de la misma forma que codificó el de las tipo _R_ (tenga
en cuenta que es diferente por cada operación). La constante de estas
operaciones está en la parte donde estaban el _rs2_ y el _funct7_ para las tipo
_R_:

![](./rtype.svg)
![](./itype.svg)

todas las operaciones tipo _I_ deben llevar la constante codificada en esta
parte.

Para completar este ejercicio, lo único que falta es verificar que para las
instrucciones: __slli__, __srli__, __srai__, la constante pueda ser codificada en 5 bits únicamente como lo muestra la siguiente figura. Los demás valores deben ser 0 excepto para la operación __srai__ que por tener el mismo _funct3_ de __srli__ se diferencia de ella en el bit 30 que para __srai__ debe ser 1. En caso de no ser así
su ensamblador emitirá un error e indicará la línea en el archivo fuente donde
este ocurre.

![](./ishifttype.svg)
![](./iimm.svg)

# Ejercicio 5

Este ejercicio va dirigido a la codificación de dos grupos nuevos de
instrucciones las [tipo I](#tipo-i) para carga de información desde la memoria y
las [tipo S](#tipo-s) para almacenamiento de información. 

A continuación se muestra un ejemplo de la forma en que estas instrucciones se
presentan en los programas:

```assembly
lw x10, -12(x13)
add x10, x12, x10
sw x10, 40(x13)
```

Es claro que aquí las únicas instrucciones del grupo que nos concierne son `lw`
y `sw`. Solo se muestran estas como representativas de los dos grupos que nos
interesan para esta parte.

Note que el tipo de instrucciones de estos dos grupos son escritas de manera
diferente. La instrucción tiene tres partes: el nombre, un registro y luego una
expresión compuesta por una constante y el nombre de un registro entre
paréntesis. Usted debe tener esta estructura en cuenta a la hora de procesarla.
De todos modos la traducción funciona de manera muy similar a la de las
instrucciones anteriores. En particular, las del primer grupo (_lw_ por ejemplo)
son del tipo _I_. Esto es importante porque ya se definió como la constante debe
ser codificada: 12 bits y en complemento a dos.

La parte de la constante en las instrucciones del segundo grupo deben ser
codificadas así: 

![](./stype.svg)
![](./simm.svg)

Note que en este caso la constante debe quedar codificada en dos partes
separadas de la instrucción.

En la parte menos significativa está el _opcode_. Luego van los 5 bits menos
significativos de la constante (cuya representación es en 12 bits), al final, en
la parte más significativa van los restantes 7 bits de la constante.

Su meta con este ejercicio es completar la implementación de los siguientes dos
grupos de instrucciones. Ya con esto debe estar completo alrededor del 65% de su
trabajo.

# Ejercicio 6

Este es el siguiente grupo de instrucciones que se deberá codificar las
instrucciones [tipo B](#tipo-b).

Lo único relevante aquí ( lo nuevo a lo que se enfrenta ) es el cálculo de la
constante y su almacenamiento. Para calcular la constante es necesario tener en
cuenta la posición en la memoria de la instrucción que se está codificando y la
posición en la memoria señalada por la etiqueta referenciada. Por ejemplo,
considere el siguiente programa (prestando atención a los comentarios!):

```assembly
main:                       ; primera etiqueta
    addi x4, zero, 520      ; primera instrucción
    addi x5, zero, 1550     ; segunda instrucción
    beq x4, x5, label1      ; tercera instrucción
    addi x6, zero, 80       ; cuarta instrucción
    beq zero, zero, label2  ; quinta instrucción
    

label1:                     ; segunda etiqueta
    addi x6, zero, 100      ; sexta instrucción

label2:                     ; tercera etiqueta
    add zero, zero, zero    ; séptima instrucción
```

Ese programa quedará en la memoria de la siguiente forma:

<!-- 
| Dirección         | Instrucción                |
| ----------------- | -------------------------- |
| 0                 | addi x4, zero, 520         |
| 4                 | addi x5, zero, 1550        |
| 8                 | beq x4, x5, __label1__     |
| 12                | addi x6, zero, 80          |
| 16                | beq zero, zero, __label2__ |
| 20   (__label1__) | addi x6, zero, 100         |
| 24   (__label2__) | add zero, zero, zero       | -->


![](./exprogram.drawio.svg)

Para calcular como se debe codificar una etiqueta hay que tener en cuenta dos
partes: la parte en la que la etiqueta es definida y la parte en la que la
etiqueta es utilizada. En nuestro caso, la etiqueta _label1_ es definida para
almacenar la dirección de la sexta instrucción. Esto quiere decir que la
etiqueta va a "representar" el lugar en la memoria donde quedará la codificación
de la sexta instrucción que es 20 en este caso.

De otro lado, la etiqueta _label1_ es utilizada en la tercera instrucción que
está codificada en la dirección 8. Con estos dos valores es ahora posible
calcular la constante con la que se codificará la etiqueta para la instrucción.
El cálculo se calcula como $i = t - p$, donde $t$ es 20 y $p$ es 8. Esto da como
resultado $i=12$ para el valor de la constante. 

Cada vez que una etiqueta sea usada en una de las instrucciones de este grupo,
su codificación será diferente y dependerá de el valor de $p$ que depende de la
instrucción que está siendo codificada.

![](./exprogram-resolved.drawio.svg)

<!-- | Dirección         | Instrucción                |
| ----------------- | -------------------------- |
| 0                 | addi x4, zero, 520         |
| 4                 | addi x5, zero, 1550        |
| 8                 | beq x4, x5, __12__     |
| 12                | addi x6, zero, 80          |
| 16                | beq zero, zero, __8__ |
| 20   (__label1__) | addi x6, zero, 100         |
| 24   (__label2__) | add zero, zero, zero       | -->

Note la sustitución que se realizó en las instrucciones en las que cada etiqueta
estaba representada.

El objetivo de este ejercicio es entonces que implemente la parte que calcula
cada una de las etiquetas de su programa. En el siguiente veremos como esa
información es codificada.

# Ejercicio 7

Después de terminado el ejercicio anterior y ya habiendo calculado la constante
del salto de cada instrucción procederemos a codificarla. Es de resaltar que la
misma instrucción de salto será codificada de manera diferente a lo largo del
programa. Es decir, La dirección `beq x4, x5, label1` puede aparecer exactamente
igual en más de una posición en el programa. Como la constante a calcular es
relativa a la posición de esta instrucción, su codificación no siempre será la
misma.

La siguiente imagen muestra la distribución de la información de una instrucción tipo _B_:

![](./btype.svg)
![](./bimm.svg)

Como es posible evidenciar es muy parecida a la distribución de la información
de las instrucciones tipo _S_ que usted ya realizó en el ejercicio 5. Es decir
el inmediato o constante está separado en dos partes. La primera está
comprendida por los bits del 7 al 11 (parte menos significativa) y la segunda en
los bits del 25 al 31. Sigue siendo una constante de 12 bits pero está
distribuida de manera diferente en la codificación.

| Cod | b31 | b30 | b29 | b28 | b27 | b26 | b25 | b11 | b10 | b9  | b8  | b7  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Imm | b12 | b10 | b9  | b8  | b7  | b6  | b5  | b4  | b3  | b2  | b1  | b11 |

En la tabla anterior se presenta la correspondencia entre los bits de la
codificación y los bits de la constante. De acuerdo a esta, el bit en la
posición 31 de la codificación tendrá el valor del bit 12 del inmediato. El bit
de la posición 30 de la instrucción tendrá el bit 10 del inmediato y así
sucesivamente. Note que no existe el bit 0 del inmediato, esto es porque siempre
se tiene que ser cero y por esto, la codificación de una instrucción de este
grupo siembre tendrá 0 como el bit menos significativos.

Su trabajo en este ejercicio consiste entonces en terminar la codificación de
las instrucciones tipo _B_ que comenzó en el ejercicio anterior.

# Ejercicio 8

Hasta este punto ya deben estar codificadas la mayoría de las instrucciones,
solo quedan faltando 6 de las cuales 2 son realmente básicas así que sería más
preciso hablar de 4 aunque de esos 4 hay una instrucción que es de tipo _I_ en
la cual usted ya tiene experiencia así que se puede reducir a 3 instrucciones.

La instrucción `jalr`, que pertenece al grupo de instrucciones [Tipo J](#tipo-j)
es codificada de la siguiente forma:

![](./jtype.svg)
![](./jimm.svg)

En este caso lo único complicado es que se trata de una constante de 21 bits.
Las otras dos partes son simplemente dos valores, un _opcode_ de 7 bits y un
registro de 5. La codificación de la constante dentro de la instrucción se
realiza de la siguiente manera:

| Cod | b31 | b30 | b29 | b28 | b27 | b26 | b25 | b24 | b23 | b22 | b21 | b20 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Imm | b20 | b10 | b9  | b8  | b7  | b6  | b5  | b4  | b3  | b2  | b1  | b11 |


| Cod | b19 | b18 | b17 | b16 | b15 | b14 | b13 | b12 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Imm | b19 | b18 | b17 | b16 | b15 | b14 | b13 | b12 |

Por razones de espacio la codificación se separa en dos partes. La primera parte
presenta la correspondencia entre bits de la constante con bits de la
instrucción hasta los bits 20 y 11 respectivamente. En la segunda parte se
muestra el resto. Nuevamente note que no existe bit 0 en la constante. Esto se
debe a lo mismo del ejercicio anterior. La codificación de esta instrucción
siempre tendrá un 0 como bit menos significativo.

Su trabajo en este ejercicio es codificar la instrucción `jal`y probar que la
codificación de `jalr`esté funcionando bien. Esta última es de tipo _I_ así que
usted ya debe estar en capacidad de entenderla.

# Ejercicio 9

Las dos instrucciones que usted codificará en este ejercicio son las del [tipo
U](#tipo-u). Son realmente sencillas, más que las del punto anterior. Tienen el
siguiente formato:

![](./utype.svg)
![](./uimm.svg)

En este caso la constante es de 20 bits y será asignada a la codificación de la
siguiente manera:

| Cod | b31 | b30 | b29 | b28 | b27 | b26 | b25 | b24 | b23 | b22 | b21 | b20 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Imm | b19 | b18 | b17 | b16 | b15 | b14 | b13 | b12 | b11 | b10 | b9  | b8  |

| Cod | b19 | 18  | 17  | 16  | 15  | 14  | 13  | 12  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Imm | b7  | b6  | b5  | b4  | b3  | b2  | b1  | b0  |

# Ejercicio 10

En este ejercicio usted finalmente probará todo. Si necesita programas de
ejemplos los puede construir usted mismo en [esta](https://godbolt.org/) página
web. Usted escribe un programa en C en el editor de la izquierda y
automáticamente se compila y se emite el código en ensamblador. Tenga en cuenta las siguientes opciones a la hora de generar desde esa herramienta:

![alt text](image-17.png)

La opción `-O0` es una letra "o" en mayúscula seguida por el número cero.

# Recursos

En el repositorio encontrará los siguientes archivos:

- [__rvalp.pdf__](./rvalp.pdf) : Es un documento donde encontrará información
  detallada de cómo son escritas las instrucciones en el ensamblador. En
  particular le recomiendo echar un vistazo al capítulo 5. La sección 5.3 es muy
  importante porque allí encuentra el formato en el que cada instrucción debe
  quedar en la salida.
- [__RISCV_CARD.pdf__](./RISCV_CARD.pdf): Es el documento que contiene todo el
  conjunto de instrucciones. En especial le recomiendo ver la primera página.

Adicionalmente a los archivos, los siguientes enlaces pueden resultar de
utilidad.

- En [este](https://en.wikipedia.org/wiki/Two%27s_complement) enlace se define
  lo que es el complemento a dos de la representación binaria de un número.

- En [este](https://luplab.gitlab.io/rvcodecjs) otro enlace encontrarán una
  herramienta para comprobar que su codificación esté quedando bien hecha.
  Básicamente ustedes le dan una instrucción y les sale la codificación. Aquí ca
  un ejemplo relacionado con el código del ejercicio 6:

  ![alt text](image-11.png)

  en este caso se utilizó la página para extraer la instrucción original a
  partir de la codificación `00520663`. Para hacerlo en el otro sentido es
  solamente cuestión de escribir la instrucción y saldrá la codificación
  respectiva.

# Resumen de instrucciones

## Tipo R

![](./rtype.svg)

| Funct7  | RS2 | RS1 | Funct3 | RD  | Opcode  | Name |
| ------- | --- | --- | ------ | --- | ------- | ---- |
| 0000000 | rs2 | rs1 | 000    | rd  | 0110011 | ADD  |
| 0100000 | rs2 | rs1 | 000    | rd  | 0110011 | SUB  |
| 0000000 | rs2 | rs1 | 001    | rd  | 0110011 | SLL  |
| 0000000 | rs2 | rs1 | 010    | rd  | 0110011 | SLT  |
| 0000000 | rs2 | rs1 | 011    | rd  | 0110011 | SLTU |
| 0000000 | rs2 | rs1 | 100    | rd  | 0110011 | XOR  |
| 0000000 | rs2 | rs1 | 101    | rd  | 0110011 | SRL  |
| 0100000 | rs2 | rs1 | 101    | rd  | 0110011 | SRA  |
| 0000000 | rs2 | rs1 | 110    | rd  | 0110011 | OR   |
| 0000000 | rs2 | rs1 | 111    | rd  | 0110011 | AND  |

## Tipo I

## Aritméticas y lógicas

![](./itype.svg)
![](./iimm.svg)

| Imm12     | RS1 | Funct3 | RD  | Opcode  | Name  |
| --------- | --- | ------ | --- | ------- | ----- |
| imm[11:0] | rs1 | 000    | rd  | 0010011 | ADDI  |
| imm[11:0] | rs1 | 010    | rd  | 0010011 | SLTI  |
| imm[11:0] | rs1 | 011    | rd  | 0010011 | SLTIU |
| imm[11:0] | rs1 | 100    | rd  | 0010011 | XORI  |
| imm[11:0] | rs1 | 110    | rd  | 0010011 | ORI   |
| imm[11:0] | rs1 | 111    | rd  | 0010011 | ANDI  |

## Corrimientos

![](./ishifttype.svg)

| Imm7    | Imm5  | RS1 | Funct3 | RD  | Opcode  | Name |
| ------- | ----- | --- | ------ | --- | ------- | ---- |
| 0000000 | shamt | rs1 | 001    | rd  | 0010011 | SLLI |
| 0000000 | shamt | rs1 | 101    | rd  | 0010011 | SRLI |
| 0100000 | shamt | rs1 | 101    | rd  | 0010011 | SRAI |

## Carga en memoria

| Imm12     | RS1 | Funct3 | RD  | Opcode  | Name |
| --------- | --- | ------ | --- | ------- | ---- |
| imm[11:0] | rs1 | 000    | rd  | 0000011 | LB   |
| imm[11:0] | rs1 | 001    | rd  | 0000011 | LH   |
| imm[11:0] | rs1 | 010    | rd  | 0000011 | LW   |
| imm[11:0] | rs1 | 100    | rd  | 0000011 | LBU  |
| imm[11:0] | rs1 | 101    | rd  | 0000011 | LHU  |

## Saltos incondicionales

| Imm12     | RS1 | Funct3 | RD  | Opcode  | Name |
| --------- | --- | ------ | --- | ------- | ---- |
| imm[11:0] | rs1 | 000    | rd  | 1100111 | JALR |

## Interrupciones

| Imm12        | RS1   | Funct3 | RD    | Opcode  | Name   |
| ------------ | ----- | ------ | ----- | ------- | ------ |
| 000000000000 | 00000 | 000    | 00000 | 1110011 | ECALL  |
| 000000000001 | 00000 | 000    | 00000 | 1110011 | EBREAK |

## Tipo S

![](./stype.svg)
![](./simm.svg)

| Imm7      | RS2 | RS1 | Funct3 | Imm5     | Opcode  | Name |
| --------- | --- | --- | ------ | -------- | ------- | ---- |
| imm[11:5] | rs2 | rs1 | 000    | imm[4:0] | 0100011 | SB   |
| imm[11:5] | rs2 | rs1 | 001    | imm[4:0] | 0100011 | SH   |
| imm[11:5] | rs2 | rs1 | 010    | imm[4:0] | 0100011 | SW   |

## Tipo B

![](./btype.svg)
![](./bimm.svg)

| Imm7            | RS2 | RS1 | Funct3 | Imm5           | Opcode  | Name |
| --------------- | --- | --- | ------ | -------------- | ------- | ---- |
| imm[12 \| 10:5] | rs2 | rs1 | 000    | imm[4:1 \| 11] | 1100011 | BEQ  |
| imm[12 \| 10:5] | rs2 | rs1 | 001    | imm[4:1 \| 11] | 1100011 | BNE  |
| imm[12 \| 10:5] | rs2 | rs1 | 100    | imm[4:1 \| 11] | 1100011 | BLT  |
| imm[12 \| 10:5] | rs2 | rs1 | 101    | imm[4:1 \| 11] | 1100011 | BGE  |
| imm[12 \| 10:5] | rs2 | rs1 | 110    | imm[4:1 \| 11] | 1100011 | BLTU |
| imm[12 \| 10:5] | rs2 | rs1 | 111    | imm[4:1 \| 11] | 1100011 | BGEU |

## Tipo J

![](./jtype.svg)
![](./jimm.svg)

| Imm20                          | RD  | Opcode  | Name |
| ------------------------------ | --- | ------- | ---- |
| imm[20 \| 10:1 \| 11 \| 19:12] | rd  | 1101111 | JAL  |

## Tipo U

![U Type](./utype.svg)
![U Immediate](./uimm.svg) 

| Imm20      | RD  | Opcode  | Name  |
| ---------- | --- | ------- | ----- |
| imm[31:12] | rd  | 0110111 | LUI   |
| imm[31:12] | rd  | 0010111 | AUIPC |

