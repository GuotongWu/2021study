% ���ļ��޶���
clc,clear,close all
%%
n = 10000; % ��������
m = 1000000; % ��������
rnd = exprnd(50, [1 m]); % ָ���ֲ�
res = zeros(n,1);
for k = 1:n
    % ÿ�γ�100����
    selected = randi([1,m], 1, n);
    % ����ƽ��
    res(k) = mean(rnd(selected));
end
% ����ֱ��ͼ
histogram(res, 50)