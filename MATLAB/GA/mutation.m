function newpop = mutation(pop, pm, bilength)
    [sx,sy] = size(pop);
    newpop = pop;
    for k = 1:sx
        if(rand < pm)
            point = ceil(bilength*rand);
            newpop(k,point) = ~pop(k, point);
        end
    end
end