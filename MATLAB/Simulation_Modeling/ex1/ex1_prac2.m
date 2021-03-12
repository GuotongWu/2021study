%% 2. 一阶电路系统的单位阶跃响应为y(t)=1-e-t/t，t≥0，编制MATLAB程序实现如下功能：
%     （1）在同一个图形窗口绘制出当t = 1 s、t =2 s时，t在0~10 s时间范围内单位阶跃响应信号的波形，注意添加图形标题、X轴标题、图形示例和网格线。
%     （2）求两种情况下电路的上升时间（阶跃响应达到0.98所需的时间）。
% 	（3）将（2）中的功能用函数t_rise()实现，并在主程序中调用。写出完整的函数定义和调用语句。
%%
clc,clear,close all
t = 0:0.001:10;
figure()
hold on
for tou = 1:2
    y = 1 - exp(-t/tou);
    plot(t,y)
end
hold off
grid on
legend('tou = 1', 'tou = 2')
title('单位阶跃响应')
xlabel('t(s)')
%%
clc,clear
syms t tou;
eqn = 1 - exp(-t/tou) == 0.98;
solx = solve(eqn, t);
valx = vpa(subs(solx, tou, [1,2]))
%%
t_rise()