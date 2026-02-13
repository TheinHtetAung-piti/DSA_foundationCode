#include <stdio.h>
#include <string.h>

int main()
{
        char str[100], substr[100];

        printf("Enter main string: ");
        fgets(str, sizeof(str), stdin);

        printf("Enter substring to search: ");
        fgets(substr, sizeof(substr), stdin);

        str[strcspn(str, "\n")] = '\0';
        substr[strcspn(substr, "\n")] = '\0';

        int len_str = strlen(str);
        int len_substr = strlen(substr);
        int start_index = len_str - len_substr;

        if (len_substr > len_str)
        {
                printf("Substring not found\n");
                return 0;
        }

        int count = 0;

        for (int i = 0; i < len_substr; i++)
        {
                if (str[start_index + i] != substr[i])
                        break;
                count++;
        }

        if (count == len_substr)
        {
                printf("Substring found at index %d\n", start_index);
                return 0;
        }
        printf("Substring not found\n");

        return 0;
}
