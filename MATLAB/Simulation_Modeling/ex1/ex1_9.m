clc,clear,close all
t=0:0.01:2;
x=sin(2*pi*t);
y=0.8*square(2*pi*t);
plot(t,x,'.-r',t,y,'linewidth',2);
title('正弦波和方波');
legend('正弦波','方波')
figure
subplot(2,1,1);plot(t,x);
ylabel('幅度/V')
subplot(2,1,2);plot(t,y,'-.k')
xlabel('t/s')
grid on
