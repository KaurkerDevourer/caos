// Задача: считать со строки ввода два числа и вывести их сумму
.intel_syntax noprefix
    .global main
main:
    // считать из строки ввода число в eax
    call    readi32
    // переложим считанное число в edi, чтобы можно было еще раз вызвать readi32
    // и потерять считанное ранее число
    cmp     eax, 12
    jz else
    mov edi, 1
    jmp end
else:
    mov edi, 0
end:
    call writei32

    // завершаем выполнение
    call    finish
