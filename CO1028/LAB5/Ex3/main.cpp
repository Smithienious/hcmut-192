#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

void readArray(int **a)
{
#TODO
}

void printArray(int **a)
{
#TODO
}

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  int **arr;
  arr = new int *[10];
  for (int i = 0; i < 10; i++)
  {
    arr[i] = new int[10];
  }

  readArray(arr);
  printArray(arr);

  for (int i = 0; i < 10; i++)
  {
    delete[] arr[i];
  }
  delete[] arr;

  ifs.close();
  return 0;
}