function newpop = crossover(pop, pc, bilength)
    [sx, sy] = size(pop);
    newpop = pop;
    for k = 1:2:sx
        if(rand <= pc)
            point = ceil(bilength*rand);
            newpop(k,:) = [pop(k,1:point), pop(k+1, point+1:end)];
            newpop(k+1,:) = [pop(k+1, 1:point), pop(k,point+1:end)];
        end 
    end
end