% 求单位阶跃响应的最大幅度及对应的时间
function [max_y,max_t] = maxV(y,t)
[max_y, p] = max(y);
max_t = t(p);
