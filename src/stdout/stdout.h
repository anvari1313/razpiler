#ifndef RAZPILER_STDOUT_H
#define RAZPILER_STDOUT_H

// Error Types
#define ERROR_TYPE_CRITICAL 255

// Errors
#define ERROR_FILE_NOT_FOUND 255
#define ERROR_MAIN_NOT_FOUND 200
#define ERROR_FUNCTION_NOT_FOUND 190

void std_out(const unsigned char type, const unsigned char error);

#endif //RAZPILER_STDOUT_H
