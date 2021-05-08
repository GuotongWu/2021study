clc,clear,close all;
%%
% 假设初值y(0)=0
dy = @(t,y) (5*cos(20*pi*t) + 5*cos(200*pi*t) - y) / 0.02;
% iter = 1000;
% h = 0.2 / iter; %步长
h = 0.001;
figure()
%%
% 欧拉法
y(1) = 0;
t = 0:h:0.2;
for i=2:length(t)
    y(i) = y(i-1) + dy(t(i-1),y(i-1))*h;
end
subplot(131)
plot(t,y)
title('前向欧拉法')
xlabel('t')
ylabel('y(t)')
%%
% ode45
clear t y
tspan = [0 0.2];
y0 = 0;
[t,y] = ode45(dy, tspan, y0);
subplot(132)
plot(t,y)
title('调用ode45函数')
xlabel('t')
ylabel('y(t)')
%%
% RK2
clear t y
y(1) = 0;
t = 0:h:0.2;
for i = 2:length(t)
%    yp = y(i) + dy(t(i), y(i))*h;
%    yc = y(i) + dy(t(i+1), yp)*h;
%    y(i+1) = 0.5*(yp+yc);
    k1 = dy(t(i-1), y(i-1));
    k2 = dy(t(i), y(i-1)+k1*h);
    y(i) = y(i-1) + h*(k1+k2)/2;
end
subplot(133)
plot(t,y)
title('RK2算法（改进欧拉法）')
xlabel('t')
ylabel('y(t)')