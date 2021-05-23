clc,clear
A = [0 -6;1 -4];
B = [2; 0];
C = [0 0.5];
D = 0;
[b,a] = ss2tf(A,B,C,D);
Hs = tf(b,a)