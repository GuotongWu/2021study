function newpop = selection(pop, fitness)
    % ÂÖÅÌ¶Ä     
    [sx, sy] = size(pop);
    newpop = zeros(sx,sy);
    pb =  cumsum(fitness)/sum(fitness);
    
    for k = 1:sx
        index = find(pb >= rand, 1);
        newpop(k,:) = pop(index,:);
    end
end