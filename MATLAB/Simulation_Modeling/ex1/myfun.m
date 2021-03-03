function x=myfun(A)
    x1=fun1(A);
    function B=fun1(A)
        B=A'
    end
    x=fun2(A,x1);    
end
function y=fun2(A,B)
    y=A*B;
end