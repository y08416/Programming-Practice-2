#include <stdio.h>
#include <string.h>

typedef struct word_pair
{
    char longer_word[10];
    char shorter_word[10];
    char combined_word[20];
    int longer_word_length;
    int shorter_word_length;
} word_pair_t;

word_pair_t create_word_pair(char *a, char *b)
{

    word_pair_t pair;

    int length_a = strlen(a);

    int length_b = strlen(b);

    if (length_a > length_b || (length_a == length_b && strcmp(a, b) > 0))
    {
        strcpy(pair.longer_word, a);
        strcpy(pair.shorter_word, b);
    }
    else if (length_b > length_a || (length_a == length_b && strcmp(a, b) < 0))
    {
        strcpy(pair.longer_word, b);
        strcpy(pair.shorter_word, a);
    }
    else
    {
        printf("Error\n");
        strcpy(pair.longer_word, a);
        pair.shorter_word[0] = '\0';
    }

    sprintf(pair.combined_word, "%s %s", pair.longer_word, pair.shorter_word);

    pair.longer_word_length = strlen(pair.longer_word);
    pair.shorter_word_length = strlen(pair.shorter_word);

    return pair;
}

int main()
{
    char input1[10];
    char input2[10];

    printf("1つ目の文字列を入力してください:");
    scanf("%s", input1);
    printf("2つ目の文字列を入力してください:");
    scanf("%s", input2);

    word_pair_t result = create_word_pair(input1, input2);

    printf("Longer word:%s\n", result.longer_word);
    printf("Shorter word:%s\n", result.shorter_word);
    printf("Combined word:%s\n", result.combined_word);
    printf("Length of longer word:%d\n", result.longer_word_length);
    printf("Length of shorter word:%d\n", result.shorter_word_length);

    return 0;
}