clc,clear,close all

% x范围
bound = [-1, 2];
% 种群大小
popsize = 100;
% 二进制编码长度
bilength = 10;
% 交叉概率
pc = 0.6;
% 变异概率
pm = 0.01;

% 初始化
pop = initpop(popsize, bilength);

figure
plot(-1:0.001:2, call_function([-1:0.001:2]), '-')
hold on

for k = 1:100
    % 计算适应度
    fitness = call_function(binary2decimal(pop, bound, bilength));
    % 选择
    pop = selection(pop, fitness);
    % 交叉
    pop = crossover(pop, pc, bilength);
    % 变异
    pop = mutation(pop, pm, bilength);
    % 寻找最优解
    [bestIndividual, bestFit] = best(pop, bound, bilength);
    % 绘图
    plot(bestIndividual, bestFit, 'o')
    title(['迭代次数为n=' num2str(k)]);
    pause(0.1);
end

fprintf('In test, when x = %.4f, we can get maxFx = %.4f\n', bestIndividual, bestFit);
fprintf('In theory, when x = 1.8505, we can get maxFx = 3.8503\n')
