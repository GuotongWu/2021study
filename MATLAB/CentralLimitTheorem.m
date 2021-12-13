% 中心极限定理
clc,clear,close all
%%
n = 10000; % 样本数量
m = 1000000; % 总体数量
rnd = exprnd(50, [1 m]); % 指数分布
res = zeros(n,1);
for k = 1:n
    % 每次抽100个数
    selected = randi([1,m], 1, n);
    % 计算平均
    res(k) = mean(rnd(selected));
end
% 绘制直方图
histogram(res, 50)