clc,clear,close all;
%%
% �����ֵy(0)=0
dy = @(t,y) (5*cos(20*pi*t) + 5*cos(200*pi*t) - y) / 0.02;
iter = 1000;
h = 0.2 / iter; %����
figure()
%%
% ŷ����
y = zeros(1,iter);
t = 0:h:0.2;
for i=1:iter
    y(i+1) = y(i) + dy(t(i),y(i))*h;
end
subplot(131)
plot(t,y)
title('ǰ��ŷ����')
xlabel('t')
ylabel('y(t)')
%%
% ode45
tspan = [0 0.2];
y0 = 0;
[t,y] = ode45(dy, tspan, y0);
subplot(132)
plot(t,y)
title('����ode45����')
xlabel('t')
ylabel('y(t)')
%%
% RK2
y = zeros(1,iter);
t = 0:h:0.2;
for i = 1:iter
   yp = y(i) + dy(t(i), y(i))*h;
   yc = y(i) + dy(t(i+1), yp)*h;
   y(i+1) = 0.5*(yp+yc);
end
subplot(133)
plot(t,y)
title('RK2�㷨���Ľ�ŷ������')
xlabel('t')
ylabel('y(t)')