% ��λ��Ծ��Ӧ�������ȼ���Ӧ��ʱ��
function [max_y,max_t] = maxV_copy()
clc,clear
y = @(t) 1*exp(-4*t)*cos(10*t) - 1;
[t, yval] = fminbnd(y, 0, 2);
max_t = t
max_y = -yval
