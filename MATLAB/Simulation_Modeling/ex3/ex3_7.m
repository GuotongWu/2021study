clc,clear,close all
t = 0:0.01:4*pi;
h = 0.01;
y1 = zeros(length(t),1);
y2 = zeros(length(t),1);
y1(1) = -2;
y2(1) = -0.5;
for k = 2:length(t)
    y1(k) = (exp(-2*t(k)) - exp(-2*t(k-1))) / h;
    y2(k) = y2(k-1) + h*exp(-2*t(k));
end
figure
subplot(1,2,1)
plot(t,y1,t,y2)
subplot(1,2,2)
plot(t, -2*exp(-2*t), t,-0.5*exp(-2*t))
