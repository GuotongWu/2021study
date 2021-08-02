function res = binary2decimal(pop, bound, bilength)
    [sx,sy] = size(pop);
    res = zeros(sx,1);
    for k = 1:sx
        for m = 1:sy
            res(k) = 2*res(k) + pop(k,m);
        end
        res(k) = bound(1) + (bound(2)-bound(1))/(2^(bilength)-1) * res(k);
    end
end