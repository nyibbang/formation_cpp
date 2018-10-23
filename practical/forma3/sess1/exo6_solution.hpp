class Tree
{
public:
  std::unique_ptr<Tree> make_tree(const std::string& content)
  {
    return std::unique_ptr<Tree>(new Tree(content));
  }

  void add_child(const std::string& child_content)
  {
    auto new_child = std::unique_ptr<Tree>(new Tree(child_content));
    new_child->set_parent(*this);
    _children.push_back(std::move(new_child));
  }

  // L'idéal serait de retourner une réference et lever une exception si index
  // est trop grand, ou bien en C++17 un std::optional<std::reference_wrapper<Tree>>.
  Tree* child_at(std::size_t index) const
  {
    if (index >= _children.size())
      return nullptr;
    return _children.at(index).get();
  }

  std::string content() const
  {
    return _content;
  }

private:
  Tree(const std::string& content)
    : _content(content)
  {
  }

  void set_parent(Tree& new_parent)
  {
    _parent = &new_parent;
  }

  std::string _content;
  std::vector<std::unique_ptr<Tree>> _children;
  Tree* _parent;
};

class Graph : public std::enable_shared_from_this<Graph>
{
public:
  static std::shared_ptr<Graph> make_graph(const std::string& content)
  {
    return std::make_shared<Graph>(content);
  }
  void add_node(std::shared_ptr<Graph> node)
  {
    if (!node)
      return;
    _next_nodes.push_back(node);
    node->add_previous_node(shared_from_this());
    // En C++17 : node->add_previous_node(weak_from_this());
  }

  std::shared_ptr<Graph> node_at(std::size_t index) const
  {
    if (index >= _next_nodes.size())
      return nullptr;
    return _next_nodes.at(index);
  }

  std::string content() const
  {
    return _content;
  }

private:
  Graph(const std::string& content)
    : _content(content)
  {
  }

  void add_previous_node(std::weak_ptr<Graph> node)
  {
    if (node.expired())
      return;
    _previous_nodes.push_back(node);
  }

  std::string _content;
  std::vector<std::shared_ptr<Graph>> _next_nodes;
  std::vector<std::weak_ptr<Graph>> _previous_nodes;
};

TEST(Exo6, Tree)
{
  auto tree = Tree::make_tree("root");
  tree->add_child("hello");
  auto child = tree->child_at(0);
  ASSERT_NE(nullptr, child);
  EXPECT_EQ("hello", child->content());
}

TEST(Exo6, Graph)
{
  auto graph = Graph::make_graph("root");
  auto node = Graph::make_graph("another node");
  graph->add_node(node);
  auto next_node = graph->node_at(0);
  ASSERT_NE(nullptr, next_node);
  EXPECT_EQ("another node", next_node->content());
}
