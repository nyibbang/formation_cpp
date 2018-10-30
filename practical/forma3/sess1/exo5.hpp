#include <set>
#include <vector>
#include <cassert>

std::set<int> allocated_resources;
int current_resource = 0;

using Handle = std::set<int>::iterator;

Handle allocate_resource()
{
  auto it_pair = allocated_resources.insert(current_resource++);
  assert(it_pair.second);   
  return it_pair.first;
}

void deallocate_resource(Handle handle)
{
  allocated_resources.erase(handle);
}

void check(int i)
{
  if (i == 3)
    throw std::runtime_error("woops");
}

// TODO:
// Implémenter un type Raii_handle pour protéger les resources dans la
// fonction do_stuff.

// Cette fonction a l'air innocente, mais l'est-elle vraiment ?
void do_stuff()
{
  std::vector<Handle> handles;
  for (int i = 0; i < 10; ++i)
    handles.push_back(allocate_resource());

  // We have allocated resource, yeah ! Check something.
  for (int i = 0; i < handles.size(); ++i)
    check(i);

  // Time to stop, sadly.
  for (const auto& handle : handles)
    deallocate_resource(handle);
}

