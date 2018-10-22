struct Raii_handle
{
  Handle _handle;
  Raii_handle()
    : _handle(allocate_resource())
  {
  }

  ~Raii_handle()
  {
    deallocate_resource(_handle);
  }
};

void do_stuff()
{
  std::vector<Raii_handle> handles(10);

  // We have allocated resource, yeah ! Check something.
  for (int i = 0; i < handles.size(); ++i)
    check(i);

  // Pas besoin de libérer, tout sera fait à la sortie de la fonction.
}

