#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void squares(int x, int x1, int total, int &count)
{
    int x2 = x1;
    int newtotal = pow(x1, 2) + total;
    if (newtotal == x)
    {
        count++;
    }
    else
    {
        while (--x1)
        {
            if (newtotal < x)
            {
                squares(x, x1, newtotal, count);
            }
            squares(x, x1, total, count);
        }
    }
}

int main(int argc, char const *argv[])
{
    ifstream ifile;
    ofstream ofile;

    ifile.open("input.txt");
    ofile.open("output.txt");

    if (ifile.is_open())
    {
        string line;
        int x, x1, count, i = 1;
        while (getline(ifile, line))
        {
            x = stoi(line);
            count = 0;

            if (x > 0)
            {
                x1 = floor(sqrt(x));

                while (x1)
                {
                    squares(x, x1, 0, count);
                    x1--;
                }
            }
            else
            {
                count = 1;
            }

            ofile << "Case #" << i << ": " << count << endl;
            i++;
        }
    }

    return 0;
}
