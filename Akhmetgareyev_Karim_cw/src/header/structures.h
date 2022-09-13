typedef struct {
    wchar_t *str;
} Sentence;

typedef struct {
    Sentence *sen;
    size_t len;
} Text;