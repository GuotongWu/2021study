clc,clear,close all

% x��Χ
bound = [-1, 2];
% ��Ⱥ��С
popsize = 100;
% �����Ʊ��볤��
bilength = 10;
% �������
pc = 0.6;
% �������
pm = 0.01;

% ��ʼ��
pop = initpop(popsize, bilength);

figure
plot(-1:0.001:2, call_function([-1:0.001:2]), '-')
hold on

for k = 1:100
    % ������Ӧ��
    fitness = call_function(binary2decimal(pop, bound, bilength));
    % ѡ��
    pop = selection(pop, fitness);
    % ����
    pop = crossover(pop, pc, bilength);
    % ����
    pop = mutation(pop, pm, bilength);
    % Ѱ�����Ž�
    [bestIndividual, bestFit] = best(pop, bound, bilength);
    % ��ͼ
    plot(bestIndividual, bestFit, 'o')
    title(['��������Ϊn=' num2str(k)]);
    pause(0.1);
end

fprintf('In test, when x = %.4f, we can get maxFx = %.4f\n', bestIndividual, bestFit);
fprintf('In theory, when x = 1.8505, we can get maxFx = 3.8503\n')
