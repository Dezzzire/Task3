#include <stdio.h>
#include <locale.h>

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Установим текущую локаль

    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE* file;
        if (fopen_s(&file, argv[i], "r") != 0) {
            printf("Не получается открыть текстовый файл: %s\n", argv[i]);
            continue;
        }

        printf("Открытый текстовый файл: %s\n", argv[i]);
        printf("=====================================\n");

        char line[256];
        int lineNumber = 1;
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%d: %s", lineNumber, line);
            lineNumber++;
        }

        printf("=====================================\n");

        fclose(file);
    }

    return 0;
}
