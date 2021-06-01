clc,clear
A = [0 1; 1 -4];
B = [0; 1];
C = [1 -1];
D = 0;
[b,a] = ss2tf(A,B,C,D);
Hs = tf(b,a)