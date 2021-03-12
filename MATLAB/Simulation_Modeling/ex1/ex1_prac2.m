%% 2. һ�׵�·ϵͳ�ĵ�λ��Ծ��ӦΪy(t)=1-e-t/t��t��0������MATLAB����ʵ�����¹��ܣ�
%     ��1����ͬһ��ͼ�δ��ڻ��Ƴ���t = 1 s��t =2 sʱ��t��0~10 sʱ�䷶Χ�ڵ�λ��Ծ��Ӧ�źŵĲ��Σ�ע�����ͼ�α��⡢X����⡢ͼ��ʾ���������ߡ�
%     ��2������������µ�·������ʱ�䣨��Ծ��Ӧ�ﵽ0.98�����ʱ�䣩��
% 	��3������2���еĹ����ú���t_rise()ʵ�֣������������е��á�д�������ĺ�������͵�����䡣
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
title('��λ��Ծ��Ӧ')
xlabel('t(s)')
%%
clc,clear
syms t tou;
eqn = 1 - exp(-t/tou) == 0.98;
solx = solve(eqn, t);
valx = vpa(subs(solx, tou, [1,2]))
%%
t_rise()