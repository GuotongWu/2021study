function [bestIndividual, bestFit] = best(pop, bound, bilength)
    fitness = call_function(binary2decimal(pop, bound, bilength));
    [bestFit, bestIndividual] = max(fitness);
    bestIndividual = binary2decimal(pop(bestIndividual,:), bound, bilength);
end