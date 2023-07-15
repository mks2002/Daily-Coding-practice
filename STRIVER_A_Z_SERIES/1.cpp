// this contains all the patterns printing.....

#include <bits/stdc++.h>
using namespace std;

void pattern1(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern2(int N)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

void pattern3(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern4(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern5(int N)
{
    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // This is the inner loop which loops for the columns no. of columns = (N - row index) for each line here...
        // we can use any of this inner loop...

        // for (int j = N; j > i; j--)
        // {
        //     cout << "* ";
        // }

        for (int j = i; j < N; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(int N)
{

    for (int i = 0; i < N; i++)
    {
        // we can use any one of the nested loop....
        for (int j = N; j > i; j--)
        {
            cout << N - j + 1 << " ";
        }

        for (int j = i; j < N; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void pattern7(int N)
{
    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << " ";
        }

        // For printing the stars in each row
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // For printing the spaces after the stars in each row
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << " ";
        }
        // the sum of ranges of this 3 loops is 2*n-1 which is the total no of columns....
        cout << endl;
    }
}

void pattern8(int N)
{
    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // For printing the stars in each row
        for (int j = 0; j < 2 * N - (2 * i + 1); j++)
        {
            cout << "*";
        }

        // For printing the spaces after the stars in each row
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern9(int N)
{
    pattern7(N);
    pattern8(N);
}



void pattern10(int N)
{
    for (int i = 1; i <= 2 * N - 1; i++)
    {
        // stars would be equal to the row no. uptill first half
        int stars = i;

        // for the second half of the rotated triangle.
        if (i > N)
            stars = 2 * N - i;

        // for printing the stars in each row.
        for (int j = 1; j <= stars; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

void pattern10_alternate(int N)
{
    pattern2(N - 1);
    for (int i = 0; i < N; i++)
    {
        cout << "* ";
    }
    cout << endl;
    pattern5(N - 1);
}

void pattern11(int N)
{
    // First row starts by printing a single 1.
    int start = 1;

    for (int i = 0; i < N; i++)
    {

        // if the row index is even then 1 is printed first in that row.
        if (i % 2 == 0)
            start = 1;

        // if odd, then the first 0 will be printed in that row.
        else
            start = 0;

        // We alternatively print 1's and 0's in each row by using the inner for loop.
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }

        cout << endl;
    }
}

void pattern12(int N)
{
    // initial no. of spaces in row 1.
    int spaces = 2 * (N - 1);

    // Outer loop for the number of rows.
    for (int i = 1; i <= N; i++)
    {
        // for printing numbers in each row
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        // for printing spaces in each row
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }
        // for printing numbers in each row
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;

        // After each iteration nos. increase by 2, thus spaces will decrement by 2.
        spaces -= 2;
    }
}

void pattern13(int N)
{
    // starting number
    int num = 1;

    for (int i = 1; i <= N; i++)
    {
        //    increment the no after each time it prints....
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num = num + 1;
        }

        cout << endl;
    }
}

void pattern14(int N)
{
    for (int i = 0; i < N; i++)
    {
        // Inner loop will loop for i times and print alphabets from A to A + i.
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }

        cout << endl;
    }
}

void pattern15(int N)
{
    // Outer loop for the number of rows.
    for (int i = 0; i < N; i++)
    {
        // Inner loop will loop for i times and print alphabets from A to A + (N-i-1).
        for (char ch = 'A'; ch <= 'A' + (N - i - 1); ch++)
        {
            cout << ch << " ";
        }

        cout << endl;
    }
}

void pattern16(int N)
{
    for (int i = 0; i < N; i++)
    {
        // Defining character for each row.
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            // same char is to be printed i times in that row.
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern17(int N)
{
    // Outer loop for the number of rows.
    for (int i = 0; i < N; i++)
    {
        // for printing the spaces.
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << " ";
        }

        // for printing the characters...
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {

            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
            {
                ch--;
            }
        }

        // for printing the spaces again after characters..
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern18(int N)
{
    for (int i = 0; i < N; i++)
    {
        // Inner loop for printing the alphabets from A + N -1 -i (i is row no.) to A + N -1 ( E in this case).
        for (char ch = ('A' + N - 1) - i; ch <= ('A' + N - 1); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern19(int N)
{
    // for the upper half of the pattern...........

    // initial spaces.
    int iniS = 0;
    for (int i = 0; i < N; i++)
    {
        // for printing the stars in the row.
        for (int j = 1; j <= N - i; j++)
        {
            cout << "*";
        }

        // for printing the spaces in the row.
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }

        // for printing the stars in the row.
        for (int j = 1; j <= N - i; j++)
        {
            cout << "*";
        }

        // The spaces increase by 2 every time we hit a new row.
        iniS += 2;
        cout << endl;
    }

    // for lower half of the pattern........

    // initial spaces.
    iniS = 2 * N - 2;
    for (int i = 1; i <= N; i++)
    {

        // for printing the stars in the row.
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // for printing the spaces in the row.
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }

        // for printing the stars in the row.
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // The spaces decrease by 2 every time we hit a new row.
        iniS -= 2;

        cout << endl;
    }
}

void pattern20(int n)
{
    // initialising the spaces.
    int spaces = 2 * n - 2;

    // Outer loop for printing row.
    for (int i = 1; i <= 2 * n - 1; i++)
    {

        // stars for first half
        int stars = i;

        // stars for the second half.
        if (i > n)
            stars = 2 * n - i;

        // for printing the stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        // for printing the spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // for printing the stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        cout << endl;
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}

void pattern21(int n)
{
    // outer loop for no. of rows.
    for (int i = 0; i < n; i++)
    {
        // inner loop for printing the stars at borders only.
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                cout << "*";

            // if not border index, print space.
            else
                cout << " ";
        }
        cout << endl;
    }
}

/*
this is the distance matrix of the given matrix
we getting it by subtracting each value from N

                     col --> 0 1 2 3 4 5 6

4 4 4 4 4 4 4     row  0 ->  0 0 0 0 0 0 0
4 3 3 3 3 3 4          1 ->  0 1 1 1 1 1 0
4 3 2 2 2 3 4    --->  2 ->  0 1 2 2 2 1 0
4 3 2 1 2 3 4          3 ->  0 1 2 3 2 1 0
4 3 2 2 2 3 4          4 ->  0 1 2 2 2 1 0
4 3 3 3 3 3 4          5 ->  0 1 1 1 1 1 0
4 4 4 4 4 4 4          6 ->  0 0 0 0 0 0 0

in each step we print the minimum distance of that cell among left right top and bottom..
during printing we again subtract it from the N so that we get the actual matrix...

*/
void pattern22(int n)
{
    // Outer loop for no. of rows
    for (int i = 0; i < 2 * n - 1; i++)
    {
        // inner loop for no. of columns...
        for (int j = 0; j < 2 * n - 1; j++)
        {
            // Initialising the top, down, left and right indices of a cell...
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int bottom = (2 * n - 2) - i;

            // Min of 4 directions and then we subtract from n because previously we would get a pattern whose border has 0's, but we want with border N's and then decreasing inside...
            cout << (n - min(min(top, bottom), min(left, right))) << " ";
        }

        cout << endl;
    }
}

int main()
{

    int N = 5;

    // pattern1(N);
    // pattern2(N);
    // pattern3(N);
    // pattern4(N);
    // pattern5(N);
    // pattern6(N);
    // pattern7(N);
    // pattern8(N);
    // pattern9(N);
    // pattern10(N);
    // pattern10_alternate(N);
    // pattern11(N);
    // pattern12(N);
    // pattern13(N);

    // pattern14(N);
    // pattern15(N);
    // pattern16(N);
    // pattern17(N);
    // pattern18(N);

    // pattern19(N);
    // pattern20(N);
    // pattern21(N);

    pattern22(N);

    return 0;
}
