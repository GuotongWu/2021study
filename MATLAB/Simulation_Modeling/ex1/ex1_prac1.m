clc,clear,close all
% （1）创建一个行向量X，其中各数据为1~100的随机整数；
% （2）依次求各数据的累加和，当累加和超过200时，停止累加，并将此时未超过200的最大累加结果及对应的累加数据个数保存到行向量b中。
% （3）将（2）中的功能用函数实现，重新编制程序。要求函数的出口参数b为列向量。
X = 100 * rand(1, 100);
sum = 0;
for i = 1:length(X)
    sum = sum + X(i);
    if sum > 200
        sum = sum - X(i);
        b = [sum, X(1:i-1)];
        break
    end
end
ex1_prac1_func(X)