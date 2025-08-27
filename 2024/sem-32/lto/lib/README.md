Соберем как обычно:
```
clang++ -O2 -c lib.cpp -o lib.o
clang++ -O2 -c main.cpp -o main.o
clang++ -O2 main.o lib.o -o default

objdump -S default > objdump_default.txt
objdump -s -j .rodata default > rodata_default.txt
```

Виртуальные вызовы!


```
clang++ -flto=thin -O2 -c lib.cpp -o lib.o
clang++ -flto=thin -O2 -c main.cpp -o main.o
clang++ -flto=thin -O2 main.o lib.o -o optimized

objdump -S optimized > objdump_optimized.txt
objdump -s -j .rodata optimized > rodata_optimized.txt
```

А так вообще инлайнится между файлами!
