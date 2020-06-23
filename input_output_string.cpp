#include <stdio.h>
#include <string.h>

enum {MAX_LINE_LEN = 50};
enum {MAX_WORD_LEN = 20};


int ReadWord(char* word);
int IsWhiteSpace(int ch);
void AddWord(const char* word, char* line, int* lineLen);
void WriteLine(const char* line, int lineLen, int numWords);
void ClearLine(char* line, int* lineLen, int* numWords);

int main() {
    char word[MAX_WORD_LEN + 1];
    int wordLen;
    char line[MAX_LINE_LEN + 1];
    int lineLen = 0;

    int numWords = 0;
    ClearLine(line, &lineLen, &numWords);

    for(;;) {
        wordLen = ReadWord(word);
        if ((wordLen == 0) && (lineLen > 0)) {
            puts(line);
            return 0;
        }
        if ((wordLen + lineLen + 1) > MAX_LINE_LEN) {
            WriteLine(line, lineLen, numWords);
            ClearLine(line, &lineLen, &numWords);
        }

        AddWord(word, line, &lineLen);
        numWords++;

    }

   
    return 0;
}


int ReadWord(char* word) {
    int ch, pos = 0;
    // bo qua whitespace
    ch = getchar();
    while (IsWhiteSpace(ch))
        ch = getchar();

    // save letters until MAX_WORD_LEN
    while (!IsWhiteSpace) {
        if (pos < MAX_WORD_LEN) {
            word[pos] = (char)ch;
            pos++;
        }
        ch = getchar();
    }
    word[pos] = '\0';
    return pos;
}

int IsWhiteSpace(int ch) {
    return (ch == ' ') || (ch == '\n') || (ch == '\t');
}

void AddWord(const char* word, char* line, int* lineLen) {
    if (*lineLen > 0) {
        line[*lineLen] = ' ';
        line[*lineLen + 1] = '\0';
        (*lineLen)++;
    }
    strcat(line, word);
    (*lineLen) += strlen(word);
}

void WriteLine(const char* line, int lineLen, int numWords) {
   
    int extrasSpaces, spacesToInserts, i, j;
    extrasSpaces = MAX_LINE_LEN - lineLen;

    for (i = 0; i < lineLen; i++) {
        if (line[i] != ' ')
            putchar(line[i]);
        else {
            spacesToInserts = extrasSpaces / (numWords - 1);

            for (j = 1; j <= spacesToInserts + 1; j++)
                putchar(' ');

            extrasSpaces -= spacesToInserts;
            numWords--;
        }
    }
    putchar('\n');
}

void ClearLine(char* line, int* lineLen, int* numWords) {
    line[0] = '\0';
    *lineLen = 0;
    *numWords = 0;
}