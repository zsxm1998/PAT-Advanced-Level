#include <iostream>
using namespace std;

bool is_writen(int **sudo, int v, int k)
{
    for(int i = 0; i < 9; i++)
    {
        if(i != (v%9) && sudo[v/9][i] == k)
            return false;
    }
    for(int i = 0; i < 9; i++)
    {
        if(i != (v/9) && sudo[i][v%9] == k)
            return false;
    }
    int a = v/9, b = v%9;
    for(int i = 0; i < 3*3; i++)
    {
        if(!(((a/3*3 + i/3) == a) && ((b/3*3 + i%3) == b)) && sudo[a/3*3 + i/3][b/3*3 + i%3] == k)
            return false;
    }
    return true;
}

void dfs(int **sudo, int v)
{
    if(v == 81)
    {
        cout << "solution:" << endl;
        for(int i = 0; i < 9*9; i++)
        {
            if(i%9 == 0)
            {
                if(i == 0)
                    cout << sudo[i/9][i%9];
                else
                    cout << "\n" << sudo[i/9][i%9];
            } else {
                cout << " " << sudo[i/9][i%9];
            }
        }
        cout << endl;
        return;
    }
    if(sudo[v/9][v%9] == 0)
    {
        for(int i = 1; i < 10; i++)
        {
            if(is_writen(sudo, v, i))
            {
                sudo[v/9][v%9] = i;
                dfs(sudo, v+1);
                sudo[v/9][v%9] = 0;
            }
        }
    } else {
        dfs(sudo, v+1);
    }
}
void test1()
{
    int **sudo = new int*[9];
    for(int i = 0; i < 9; i++)
    {
        sudo[i] = new int[9];
    }
    for(int i = 0; i < 9*9; i++)
    {
        cin >> sudo[i/9][i%9];
    }
    dfs(sudo, 0);

    for(int i = 0; i < 9; i++)
    {
        delete sudo[i];
        sudo[i] = 0;
    }
    delete [] sudo;
    sudo = 0;
}

int main()
{
    test1();
    return 0;
}

