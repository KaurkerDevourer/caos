## Сигналы

Список и описание всех сигналов можно посмотреть так: `man 7 signal`.

- Сигналы - это программные прерывания в Unix-подобных системах
- Используются для асинхронного уведомления процессов о событиях
- Каждый сигнал имеет уникальный номер и символическое имя (SIGTERM, SIGINT и т.д.)
- Определены в <signal.h>

Основные сигналы:
```
SIGABRT - аварийное завершение
SIGFPE - ошибка операции с плавающей точкой
SIGILL - недопустимая инструкция
SIGINT - прерывание (Ctrl+C)
SIGSEGV - ошибка сегментации
SIGTERM - запрос завершения
SIGALRM - сигнал от таймера
SIGCHLD - дочерний процесс завершился
SIGKILL - принудительное завершение (нельзя перехватить)
SIGSTOP - остановка процесса (нельзя перехватить)
```

Обработка сигналов:
```
void signal_handler(int signum) {
    // Код обработчика
}

signal(SIGINT, signal_handler); // Простой способ
```

Более гибкий способ с sigaction:
```
struct sigaction sa;
sa.sa_handler = signal_handler;
sigemptyset(&sa.sa_mask);
sa.sa_flags = 0;
sigaction(SIGINT, &sa, NULL);
```

Отправка сигналов:
```
kill(pid, SIGTERM); // Отправка сигнала процессу
raise(SIGTERM);     // Отправка сигнала самому себе
```

Блокировка сигналов:
```
sigset_t set;
sigemptyset(&set);
sigaddset(&set, SIGINT);

// Блокировка
sigprocmask(SIG_BLOCK, &set, NULL);

// Разблокировка
sigprocmask(SIG_UNBLOCK, &set, NULL);
```

## Таймеры
alarm - таймер, отправляющий SIGALRM:
```
// Пример:
void alarm_handler(int signum) {
    printf("Прошло 5 секунд!\n");
}

signal(SIGALRM, alarm_handler);
alarm(5); // Установка таймера на 5 секунд
```

setitimer() - интервальный таймер:
```
struct itimerval {
    struct timeval it_interval; // Интервал повторения
    struct timeval it_value;    // Начальное значение
};

// Пример:
struct itimerval timer;
timer.it_value.tv_sec = 5;     // Первый сигнал через 5 секунд
timer.it_value.tv_usec = 0;
timer.it_interval.tv_sec = 2;  // Повторять каждые 2 секунды
timer.it_interval.tv_usec = 0;

setitimer(ITIMER_REAL, &timer, NULL);
```

Таймаут для операции:
```
void timeout_handler(int signum) {
    printf("Операция превысила время ожидания!\n");
    exit(1);
}

int main() {
    signal(SIGALRM, timeout_handler);
    alarm(5);  // Таймаут 5 секунд
    
    // Длительная операция
    
    alarm(0);  // Отмена таймера если операция завершилась
    return 0;
}
```
