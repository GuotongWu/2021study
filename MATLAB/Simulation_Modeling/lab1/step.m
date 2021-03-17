% y = 4*exp(-4*t)*cos(10*t) + 10*sin(10*t)  (t>=0)
clc,clear,close all;
t = 0:0.001:2;
y = 4*exp(-4*t).*cos(10*t) + 10*sin(10*t);
figure()
plot(t,y)
xlabel('time')
ylabel('y(t)')
grid on
title('单位阶跃响应')
% 主程序调用maxV()
[max_y, max_t] = maxV(y,t)