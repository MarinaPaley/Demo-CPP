value = input();
x = tryparse(Float64, value);
if x == nothing
    exit(1);
end
a = 2.5;
if x > a
    F1 = x * (x - a)^(1/3);
    println(F1);
else
    F2 = x * sin(a * x);
    println(F2);
end;
