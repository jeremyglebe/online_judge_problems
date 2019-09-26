#include <iostream>
using namespace std;

int main()
{
    // Stores the size of the array.
    int N;
    // Each data set starts with a size, read it in.
    while (cin >> N)
    {
        // Boolean that stores if the input contain any postive numbers
        bool pos = false;
        // Maximum Sum of any sub-rectangles
        int max = 0;
        // Create a 2D array (matrix)
        int mat[N][N];
        // Read all of the input data into the matrix
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                cin >> mat[r][c];
                // We need to know if there is at least one postive number
                // somewhere in the input data. More info in comments below.
                if (mat[r][c] >= 0)
                {
                    pos = true;
                }
            }
        }
        // There has to be at least one positive number in the input to use the
        // main algorithm of this solve. If there is not, there is a (actually
        // simpler) solution below for that case in the else statement.
        if (pos)
        {

            // We run through the matrix from every possible starting row and
            // then test every row from that row to the final row.
            for (int fr = 0; fr < N; fr++)
            {
                // Each time we start a new row setup (when the starting row
                // has changed), we need to generate a set of "collapsed"
                // columns. Basically we will be adding to an array
                // representing only the columns in the matrix. Each element
                // of this array will be the sum (up to the current row) of
                // all values in that column. At this point the collapsed
                // set represents the value of the rows at the current point
                // and we loop through each columns and get their highest
                // possible value (summing a selection of consecutive columns
                // such as 0-4, 1-3, 7-9, etc) Since we are looping through
                // all possible row setups (including changing the starting row
                // and thus accounting for rectangles not starting at row 0) we
                // can trust that the highest number found during the multiple
                // iterations of this process is the Maximum Sum
                int collapsed[N] = {0};
                // for every row
                for (int r = fr; r < N; r++)
                {
                    // current sum and sum to be tested, reset every loop
                    int sum = 0;
                    int test = 0;
                    // Here is where we actually create the collapsed set of
                    // columns. We add up values in that column from the
                    // current first row to the current row number being tested
                    for (int c = 0; c < N; c++)
                    {
                        collapsed[c] += mat[r][c];
                    }
                    // We want to go through each column of the collapsed
                    // columns and get the largest sum we can out of them.
                    // "sum" refers to the current largest sum (produced by
                    // this particular collapsed column set, NOT overall for
                    // the program). "test" is the value we're testing against
                    // it, and we add each value in the collapsed columns to it
                    // as we go through and test.
                    for (int c = 0; c < N; c++)
                    {
                        test += collapsed[c];
                        if (test > sum)
                        {
                            sum = test;
                        }
                        // if the running total at the moment is negative, it
                        // won't add anything to the next column's value, so we
                        // might as well consider that column on its own. hence
                        // the reset to zero.
                        if (test < 0)
                        {
                            test = 0;
                        }
                    }
                    // We can assume now we have the largest sum that can be
                    // produced from this particular collapsed set of columns.
                    // Now we compare that sum to the highest sum we've been
                    // able to get overall (for all of the collapsed column
                    // sets) If its greater, then its the new maximum sum.
                    if (sum > max)
                    {
                        max = sum;
                    }
                }
            }
            // output the value
            cout << max << '\n';
        }
        else
        {
            // This is a small snippet to handle all negative inputs. See, if
            // there is even one non-negative number in the input then the
            // maximum sum will not be negative, and my algorithm above kind of
            // relies on that concept. So we have to handle an all-negative
            // input separately. Luckily, its easy. In an all negative input,
            // the maximum sum will always be a 1x1 square consisting of the
            // negative number which is closest to 0. So we just loop through
            // the matrix once and compare every negative number.
            max = mat[0][0];
            for (int r = 0; r < N; r++)
            {
                for (int c = 0; c < N; c++)
                {
                    if (mat[r][c] > max)
                    {
                        max = mat[r][c];
                    }
                }
            }
            // output the value
            cout << max << '\n';
        }
    }
}