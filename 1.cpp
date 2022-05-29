#include <vector>
#include <thread>
#include <iostream>

int sum1 = 0;
int sum2 = 0;

void task1(const std::vector<int>& v){
  for(unsigned i = 0; i < 500000; ++i)
    sum1 += v[i];
}

void task2(const std::vector<int>& v){
  for(unsigned i = 5000000; i < 1000000; ++i)
    sum2 += v[i];
}

int main() {

  std::vector<int> v(1000000);
  for(unsigned i = 0; i < 1000000; ++i)
    v[i] = rand()%15;
  
  std::thread t1(task1, v);
  std::thread t2(task2, v);

  t1.join();
  t2.join();

  std::cout << sum1 + sum2;
  
}