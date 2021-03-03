function b = ex1_prac1_func(X)
sum = 0;
for i = 1:length(X)
    sum = sum + X(i);
    if sum > 200
        sum = sum - X(i);
        b = [sum, X(1:i-1)];
        break
    end
end
b = b';