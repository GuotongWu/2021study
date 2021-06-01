clc,clear,close all
[A,B,C,D] = zp2ss([2], [0,-5,-2], 10);
[b,a] = zp2tf(2, [0,-5,-2], 10);