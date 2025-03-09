```
g++ -fPIC math_utils.cpp -c -o math_utils.o
g++ -shared math_utils.o -o libmath_utils.so
g++ main.cpp -o main -L. -lmath_utils
./main
```
