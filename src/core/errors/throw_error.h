#ifndef THROW_ERROR_H
#define THROW_ERROR_H

#define PANIC(message) do { perror(message); exit(EXIT_FAILURE); } while (0)

// тут также опишу структуру ответа на любое действие
// чтобы можно было удобно отлавливать верхнеуровневые ошибки


#endif 