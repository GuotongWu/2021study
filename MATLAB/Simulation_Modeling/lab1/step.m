% lab1.m ���㵥λ��Ծ��Ӧ
% y = -1*exp(-4*t).*cos(10*t) + 1; (t>=0)
clc,clear,close all;
t = 0:0.001:2;
y = -1*exp(-4*t).*cos(10*t) + 1;
figure()
plot(t, y, 'r', 'LineWidth',2)
xlabel('t/s')
ylabel('y(t)')
grid on
title('��λ��Ծ��Ӧ')
% ���������maxV()
[max_y, max_t] = maxV_copy_1(y,t)