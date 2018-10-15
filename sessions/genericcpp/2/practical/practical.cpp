#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#include <atomic>
#include <random>
#include <chrono>

using namespace std;

struct Shared_data
{
  queue<int> data;
  mutex mut;
  condition_variable cond_var;
  atomic<bool> producingDone {false};
};

future<int> producer(Shared_data& shData)
{
  return async(launch::async, [&] {
    int expected = 0;
    random_device rd;
    default_random_engine engine(rd());
    uniform_int_distribution<> dist {1, 200'000'000};

    static const int count = 20000;
    for (int i = 0; i < count; ++i)
    {
      {
        lock_guard<mutex> lock {shData.mut};
        const auto val = dist(engine);
        if (val % 42 == 0)
          ++expected;
        shData.data.push(val);
      }
      shData.cond_var.notify_one();
    }
    shData.producingDone = true;
    return expected;
  });
}

// La fonction producer va créer une tâche asynchrone qui va remplir au fur et
// à mesure la queue dans Shared_data.
//
// L'objectif est de compter le nombre d'entiers divisibles par 42 dans la
// queue de Shared_data avec 4 threads en s'assurant de ne pas
// créer de data race. Pour cela, vous pouvez utiliser les outils de la STL
// que vous souhaitez.
future<int> consumer(Shared_data& shData)
{
  return async(launch::async, [&] {
    int count = 0;
    bool keepGoing = !shData.producingDone;
    while (keepGoing)
    {
      unique_lock<mutex> lock{shData.mut};
      if (shData.cond_var.wait_for(lock, chrono::microseconds{500}, [&]{ return !shData.data.empty(); }))
      {
        const auto val = shData.data.front();
        shData.data.pop();
        if (val % 42 == 0)
        {
          ++count;
        }
      }
      keepGoing = !shData.producingDone || !shData.data.empty();
    }
    return count;
  });
}

future<int> consumer_multithreaded(Shared_data& shData)
{
  return async(launch::async, [&] {
    auto c1 = consumer(shData);
    auto c2 = consumer(shData);
    auto c3 = consumer(shData);
    auto c4 = consumer(shData);
    return c1.get() + c2.get() + c3.get() + c4.get();
  });
}

int main()
{
  Shared_data shData;
  auto prod_res = producer(shData);
  auto cons_res = consumer_multithreaded(shData);

  cout << "Résultat attendu : " << prod_res.get() << endl;
  cout << "Résultat calculé : " << cons_res.get() << endl;
}
