//
// Ceci est une solution, mais pas la seule
//

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
