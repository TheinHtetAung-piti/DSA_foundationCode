#include <stdio.h>
#include <string.h>
#include <time.h>

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

        for (int i = 0; i <= len_str - len_substr; i++)
        {
                int count = 0;
                for (int j = 0; j < len_substr; j++)
                {
                        if (str[i + count] != substr[j])
                                break;
                        count++;
                }
                if (count == len_substr)
                {
                        printf("Substring found at index %d\n", i);
                        return 0;
                }

        }
        printf("Substring not found\n");
        return 0;
}