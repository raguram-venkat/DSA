#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int N = 2;                                    // int(input())
    int n = 3;                                    // int(input())
    int M = 1;                                    // int(input())
    int m = 6;                                    // int(input())
    char x[] = "XXX";                             // input("")
    char ct[] = "DXHOXXXETXETXROXMOXENXODYXXCAX"; // input("")

    ////////////////////////////////////////////////////////////
    // void letterFencing
    int t[m];
    char q[100][100];

    int fnum(int i, int f, int m)
    {
        // printf("Hi");
        int c = 0;
        int d = m - i;
        int flag = -1;
        while (d < f)
        {
            int b = 2 * m - 2 * i;
            int a = 2 * i - 2;
            c += 1;
            flag *= -1;

            if (f > d)
            {
                if (flag == 1)
                    d += a;

                if (flag == -1)
                    d += b;

                if ((a == 0) && (flag == 1))
                    c -= 1;
                if ((b == 0) && (flag == -1))
                    c -= 1;
            }
        }
        return c;
    }

    for (int i = m; i > 0; i--)
    {
        t[m - i] = fnum(i, strlen(ct), m);
    }

    int c = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < t[i]; j++)
        {
            q[i][j] = ct[c];
            c += 1;
        }
    }

    c = 0;
    for (int i = 0; i < m; i++)
    {
        ct[c] = q[i][0];
        c += 1;
    }

    int flag = 1;
    int a = 0;
    int b = 0;
    int sum = t[0] + t[m - 1] - 2;
    for (int j = 1; j < sum + 1; j++)
    {
        if (flag == 1)
        {
            for (int i = m - 2; i > 0; i--)
            {
                ct[c] = q[i][j];
                c += 1;
            }
            a += 1;
            ct[c] = q[0][a];
            c += 1;
        }

        if (flag == -1)
        {
            for (int i = 1; i < m - 1; i++)
            {
                ct[c] = q[i][j];
                c += 1;
            }
            b += 1;
            ct[c] = q[m - 1][b];
            c += 1;
        }
        flag *= -1;
    }

    int num = 0;
    int h = m + sum * (m - 1);
    h = strlen(ct) - h;
    if (flag == 1)
    {
        for (int i = 0; i < h; i++)
        {
            num = t[m - 2 - i] - 1;
            ct[c] = q[m - 2 - i][num];
            c += 1;
        }
    }

    if (flag == -1)
    {
        for (int i = 0; i < h; i++)
        {
            num = t[i + 1] - 1;
            ct[c] = q[i + 1][num];
            c += 1;
        }
    }
    printf("\n");
    // for (int i = 0; i < strlen(ct); i++)
    // {
    //     printf("%c", ct[i]);
    // }

    ////////////////////////////////////////////
    // void removeSub()

    int check(char *a, char *o, int i, int j, int k, int n)
    {
        if (k == n)
        {
            // printf("bye");
            return 100;
        }

        if (a[j] == o[i])
        {
            k += 1;
            // printf("hi");
            check(a, o, i + 1, j + 1, k, n);
        }
        else
            return 0;
    }

    char str[100];

    c = 0;
    int y = 0;
    for (int i = 0; i < (strlen(ct) - strlen(x)); i++)
    {
        y = check(ct, x, 0, i, 0, strlen(x));
        // printf("%d\n", i);

        if (y == 100)
        {
            str[c] = ' ';
            c += 1;
            i += strlen(x) - 1;
        }
        else
        {
            str[c] = ct[i];
            c += 1;
        }
    }

    printf("\n");

    // for (int i = 0; i < strlen(ct); i++)
    // {
    //     printf("%c", str[i]);
    // }

    for (int i = 0; i < strlen(x); i++)
    {
        str[c] = (ct[strlen(ct) - strlen(x) + i]);
        c += 1;
    }
    // printf("\n");

    // for (int i = 0; i < strlen(ct); i++)
    // {
    //     printf("%c", str[i]);
    // }

    str[strlen(str)] = ' ';

    //////////////////////////////////////////////////////////////

    // void wordFencing()

    typedef struct dict_t
    {
        char r[100];
        char b;

    } dict;

    char temp[100];
    dict aw[100];
    c = 0;
    char bw[1] = "";
    char mid = ' ';
    char op[100];
    for (int i = 0; i < strlen(str); i++)
    {

        if (str[i] == ' ')
        {
            for (int j = 0; j < strlen(temp); j++)
            {
                ((aw[c].r)[j]) = temp[j];
            }
            mid = c + 1;
            (aw[c].b) = mid; // cth character;
            op[c] = mid;
            c += 1;
            strcpy(temp, bw);
        }
        else
        {
            char temps[2];
            temps[0] = str[i];
            temps[1] = '\0';
            strcat(temp, temps);
        }
    }

    // for (int i = 0; i < strlen(op); i++)
    // {
    //     printf("%c\n", op[i]);
    // }

    int tn[100];
    char qn[100][100];

    for (int p = 0; p < N; p++)
    {
        for (int i = n; i > 0; i--)
        {
            tn[n - i] = fnum(i, strlen(op), n);
        }

        c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < tn[i]; j++)
            {
                qn[i][j] = op[c];
                c += 1;
            }
        }

        c = 0;
        for (int i = 0; i < n; i++)
        {
            op[c] = qn[i][0];
            c += 1;
        }

        flag = 1;
        a = 0;
        b = 0;
        sum = tn[0] + tn[n - 1] - 2;
        for (int j = 1; j < sum + 1; j++)
        {
            if (flag == 1)
            {
                for (int i = n - 2; i > 0; i--)
                {
                    op[c] = qn[i][j];
                    c += 1;
                }
                a += 1;
                op[c] = qn[0][a];
                c += 1;
            }

            if (flag == -1)
            {
                for (int i = 1; i < n - 1; i++)
                {
                    op[c] = qn[i][j];
                    c += 1;
                }
                b += 1;
                op[c] = qn[n - 1][b];
                c += 1;
            }
            flag *= -1;
        }

        num = 0;
        h = n + sum * (n - 1);
        h = strlen(op) - h;
        if (flag == 1)
        {
            for (int i = 0; i < h; i++)
            {
                num = tn[n - 2 - i] - 1;
                op[c] = qn[n - 2 - i][num];
                c += 1;
            }
        }

        if (flag == -1)
        {
            for (int i = 0; i < h; i++)
            {
                num = tn[i + 1] - 1;
                op[c] = qn[i + 1][num];
                c += 1;
            }
        }
    }

    char s;
    char fstr[100];
    char space[100] = " ";

    for (int i = 0; i < strlen(op); i++)
    {
        s = op[i];
        c = 0;
        while ((aw[c].b) != s)
        {
            c += 1;
        }

        strcat(fstr, (aw[c].r));
        strcat(fstr, space);
    }

    printf("\n");

    for (int i = 0; i < strlen(fstr); i++)
    {
        printf("%c", fstr[i]);
    }
}