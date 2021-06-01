% 求单位阶跃响应的最大幅度及对应的时间
function [max_y,max_t] = maxV_copy_1(y, t)
max_y = 0;
max_t = 0;
for i=1:length(t)
    if y(i) > max_y
        max_y = y(i);
        max_t = t(i);
    end
end

