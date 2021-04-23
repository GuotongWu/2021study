%%
clc,clear
b = [3,1,-4];
a = [1,8,17,10];
Hs = tf(b, a);
[z,p,k] = tf2zp(b, a);
zpk(z,p,k)
%%
clear
z = [-4/3; 1];
p = [-1; -2; -5];
k = 3;
[b,a] = zp2tf(z, p, k);
Hs = tf(b, a)