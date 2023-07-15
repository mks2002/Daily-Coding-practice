#include <iostream>
using namespace std;

/*
Pattern 1
*******
*******
*******
*/
int main()
{

    int n;
    cin >> n;

    int i = 1;

    while (i <= n)
    {

        int j = 1;
        while (j <= n)
        {
            cout << "*";
            j = j + 1;
        }
        cout << endl;

        i = i + 1;
    }
}

int main(){
    int row,col;cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"* ";
        }cout<<endl;
    }
}