Nesta aula, implementamos um circuito subtrator/somador com complemento de 2, com as entradas sendo 2 números de 4 bits(tendo sinal), e a saída sendo o resultado da operação, ele sempre soma os números (inclusive soma de negativos), menos quando é apertado o botão KEY0, que representa a subtração do segundo número. Além disso, caso o resultado seja negativo, acenderá uma luz de led para representar.
Neste circuito foi utilizado a (Placa Pequena) DE0-CV: Cyclone V.

As entradas/saídas são representadas com os seguintes switches/displays:

 
 Entradas:
X0: PIN_AB15
X1: PIN_AA14
X2: PIN_AA13
X3: PIN_AB13
X4: PIN_AB12

Y0: PIN_U13
Y1: PIN_V13
Y2: PIN_T13
Y3: PIN_T12
Y4: PIN_AA15

Operação: PIN_U7

  Saídas:
A: PIN_U20 
B: PIN_Y20
C: PIN_V20
D: PIN_U16
E: PIN_U15
F: PIN_Y15
G: PIN_P9
G-: PIN_W19

A2: PIN_Y19
B2: PIN_AB17
C2: PIN_AA10
D2: PIN_Y14
E2: PIN_V14
F2: PIN_AB22
G2: PIN_AB21
G2-: PIN_V19

ind_op1: PIN_L1
ind_op2: PIN_AA2

A3: PIN_U21
B3: PIN_V21
C3: PIN_W22
D3: PIN_W21
E3: PIN_Y22
F3: PIN_Y21
G3: PIN_AA22
G3-: PIN_N2

A4: PIN_AA20
B4: PIN_AB20
C4: PIN_AA19
D4: PIN_AA18
E4: PIN_AB18
F4: PIN_AA17
G4: PIN_U22
