clc,clear,close all
%%
dy = @(t,y) 10*exp(-4*t) - 2*y;
t = 0:0.01:4*pi;
h = 0.01;
y = zeros(length(t),1);
y(1) = -1;
for k = 2:length(t)
    k1 = dy(t(k-1), y(k-1));
    k2 = dy(t(k), y(k-1)+k1*h);
    y(k) = y(k-1) + h*(k1+k2)/2;
end
figure()
subplot(121)
plot(t,y)
title('RK2')
xlabel('t')
ylabel('y(t)')
%%
% ode45
clear t y
tspan = [0 4*pi];
y0 = -1;
[t,y] = ode45(dy, tspan, y0);
subplot(122)
plot(t,y)
title('µ÷ÓÃode45º¯Êý')
xlabel('t')
ylabel('y(t)')
