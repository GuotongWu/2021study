% clc,clear,close all
% syms R L C
% den = [R/L,0];
% num = [1, R/L, 1/(L*C)];
% [A,B,C,D] = tf2ss(den,num);
%%
% % for test, given w=20,100,200
% clc,clear,close all
% Hs = @(R,L,C) tf([R/L,0],[1, R/L, 1/(L*C)]);
% t = 0:0.001:1;
% x = [sin(20*t); sin(100*t); sin(200*t)];
% y = zeros(size(x));
% figure()
% for i = 1:3
%     y(i,:) = lsim(Hs(1,0.01,0.01), x(i,:), t);
%     subplot(1,3,i)
%     plot(t,x(i,:),t,y(i,:))
% end
%%
% % for test
% clc,clear,close all
% Hs = @(R,L,C) tf([R/L,0],[1, R/L, 1/(L*C)]);
% Hs_curr = Hs(1,0.01,0.01);
% Fs = @(w) tf([w],[1,0,w^2]);
% Ys = Hs_curr * Fs(20);
% [n,d] = tfdata(Ys,'v');
% ys = ilaplace(poly2sym(n,sym('s'))/poly2sym(d, sym('s')));
% fplot(ys)
%%
% for test
clc,clear,close all
syms t s
f = @(w) sin(w*t);
F = laplace(f(200));
H = 100*s / (s^2+100*s+10000);
Y = F*H;
y = ilaplace(Y);
% fplot(y)
t = 0:0.001:1;
y_d = subs(y,t);  %将符号变量转化为数值变量
plot(t,double(y_d)) %最后仍然要使用double()