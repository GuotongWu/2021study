function valx = t_rise()
syms t tou;
eqn = 1 - exp(-t/tou) == 0.98;
solx = solve(eqn, t);
valx = vpa(subs(solx, tou, [1,2]));