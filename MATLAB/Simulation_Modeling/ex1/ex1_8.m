clc,clear
a = round(100*rand(3,5))
for i=1:size(a,1)
    b(i)=a(i,1);
    c(i)=a(i,1);
    j=2;
    while j<=size(a,2)
        if a(i,j)>b(i)
            b(i)=a(i,j);
        elseif a(i,j)<c(i)
            c(i)=a(i,j);
        end
        j=j+1;
    end
end
[b',c']
