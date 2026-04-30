
#include <iostream>
using namespace std;

void fill_array(int n[])
{
    cout << "Enter 12 numbers: \n";
    for (int i = 0; i < 12; i++)
    {
        cin >> n[i];
    }
}

void reverse_array(int n[])
{
    for (int i = 0; i < 6; i++)
    {
        int temp = n[i];
        n[i] = n[11 - i];
        n[11 - i] = temp;
    }
}
void print_array(int n[])
{
    cout << "\n reverse order: ";
    for (int i = 0; i < 12; i++)
    {
        cout << n[i] << " ";
    
    }
}


int main()
{
    int n[12];
    fill_array(n);
    reverse_array(n);
    print_array(n);
   
}
