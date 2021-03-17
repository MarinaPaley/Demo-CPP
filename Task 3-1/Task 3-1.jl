leftBound = 2.0;
rightBound = 3.0;
step = 0.1;
x = leftBound;
while x <= rightBound
    y = 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
    println("x = ", x, " y = ", y);
    global x = x + step;
end;
