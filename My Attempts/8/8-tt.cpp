#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    if (b >= a)
    {
        return b;
    }
}

int main()
{
    // vector<int> vec = {1, 2, 4, 5};
    // int i = 0;
    // for (auto vector : vec)
    // {
    //     cout << vec[i];
    //     i++;
    // }
    // int x = 5;

    // // j will be of type int : data type of x
    // auto j = x + 5;

    // set <string> st;
    // st.insert({"geeks", "for", "geeks", "org"});

    // // 'it' evaluates to iterator to set of string
    // // type automatically
    // for (auto set : st)
    //     cout << "ye ";
    string str;
    cin >> str;

    auto ptr1 = str.end();
    ptr1--;
    auto ptr2 = str.begin();
    // int c = ((str.length() + 1) / 2);
    int flag;
    int d;
    int num;
    while (ptr1 >= ptr2)
    {
        d = ptr1 - ptr2;
        // cout << d << endl;

        if (d > 1)
        {
            if (*ptr2 != *ptr1)
            {
                if (*ptr2 > *ptr1)
                {
                    *ptr1 = *ptr2;
                    flag = 0;
                }

                if (*ptr2 < *ptr1)
                {
                    *ptr1 = *ptr2;
                    flag = 1;
                    // cout << flag << endl;
                }
            }
        }

        else
        {
            cout << flag;

            if (flag == 0)
            {
                *ptr1 = max(*ptr1, *ptr2);
                *ptr2 = *ptr1;
            }

            if (flag == 1)
            {
                cout << "Inside flag baby 1" << endl;

                if (*ptr1 != *ptr2)
                {

                    *ptr1 = max(*ptr1, *ptr2);
                    *ptr2 = *ptr1;
                }
                else
                {
                    if (*ptr2 != '9')
                    {

                        num = (int)(*ptr1);
                        num++;
                        *ptr2 = char(num);
                        *ptr1 = *ptr2;
                        cout << "HI" << endl;
                    }
                    else
                    {
                        *ptr2 = '0';
                        *ptr1 = *ptr2;
                        auto ptr3 = ptr1;
                        auto ptr4 = ptr2;
                        while (true)
                        {
                            if (str.end() == ptr1)
                                break;
                            ptr4--;
                            ptr3++;
                            if (*ptr4 != '9')
                            {
                                num = (int)(*ptr3);
                                num++;
                                *ptr4 = char(num);
                                *ptr3 = *ptr4;
                                break;
                            }
                            else
                            {
                                *ptr4 = '0';
                                *ptr3 = *ptr4;
                            }
                        }
                        // cout << "whileloop ends" << endl;
                    }
                }
            }
        }

        ptr2++;
        ptr1--;

        // cout << str << endl;
    }

    cout << str;
}