#include <iostream>
using namespace std;

#define Max 1000
#define Number 10

int main(int argc, char const *argv[])
{
    int arr[Max];
    int size;
    cout << "insert size of array: ";
    cin >> size;

    int i,j;
    for (i = 0; i < size; i++)
    {
        cout << "insert element " << i + 1 << ": ";
        cin >> arr[i];
    }

    //find Number max

    int max[Number];
    int max_index[Number];

    int max_min;
    int max_min_index;

    max_min = max[0] = arr[0];
    max_min_index = max_index[0] = 0;

    for (i = 1; i < Number && i < size; i++)
    {
        max[i] = arr[i];
        max_index[i] = i;
        if (arr[i] < max_min)
        {
            max_min = arr[i];
            max_min_index = i;
        }
    }

    for (i = Number; i < size; i++)
    {
        if (arr[i] > max_min)
        {
            max[max_min_index] = arr[i];
            max_index[max_min_index] = i;

            max_min = max[0];
            max_min_index = 0;
            for (j = 1; j < Number; j++)
            {
                if (max[i] < max_min)
                {
                    max_min = max[j];
                    max_min_index = j;
                }
            }
        }
    }

    //find Number min

    int min[Number];
    int min_index[Number];

    int min_max;
    int min_max_index;

    min_max = min[0] = arr[0];
    min_max_index = min_index[0] = 0;

    for (i = 1; i < Number && i < size; i++)
    {
        min[i] = arr[i];
        min_index[i] = i;
        if (arr[i] > min_max)
        {
            min_max = arr[i];
            min_max_index = i;
        }
    }

    for (i = Number; i < size; i++)
    {
        if (arr[i] < min_max)
        {
            min[min_max_index] = arr[i];
            min_index[min_max_index] = i;

            min_max = min[0];
            min_max_index = 0;
            for (j = 1; j < Number; j++)
            {
                if (min[i] > min_max)
                {
                    min_max = min[j];
                    min_max_index = j;
                }
            }
        }
    }

    cout<<"\n max list: ";
    for( i = 0; i < Number; i++)
    {
        cout<<max_index[i]<<":"<<max[i]<<", - ";
    }

    cout<<"\n min list: ";
    for( i = 0; i < Number; i++)
    {
        cout<<min_index[i]<<":"<<min[i]<<", - ";
    }
    

    return 0;
}
