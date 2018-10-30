#include <vector>
#include <string>
#include <algorithm>
#include <memory>

// TODO:
// Réécrire ces classes en utilisant des smarts pointers là où c'est possible.
// Vous allez devoir retoucher les tests aussi.

class Tree
{
public:
  static Tree* make_tree(const std::string& content)
  {
    return new Tree(content);
  }

  ~Tree()
  {
    for (auto* child : _children)
      delete child;
  }

  void add_child(const std::string& child_content)
  {
    auto* new_child = new Tree(child_content);
    new_child->set_parent(this);
    _children.push_back(new_child);
  }

  Tree* child_at(std::size_t index) const
  {
    if (index >= _children.size())
      return nullptr;
    return _children.at(index);
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

  void set_parent(Tree* new_parent)
  {
    _parent = new_parent;
  }

  std::string _content;
  std::vector<Tree*> _children;
  Tree* _parent;
};

// TODO:
// Pour cette classe, vous allez sans doute avoir besoin de std::enable_shared_from_this:
//   https://en.cppreference.com/w/cpp/memory/enable_shared_from_this

class Graph
{
public:
  static Graph* make_graph(const std::string& content)
  {
    return new Graph(content);
  }

  ~Graph()
  {
    for (auto* node : _next_nodes)
    {
      if (!node)
        continue;

      // On retire 'this' des noeuds précédents du noeud.
      const auto new_end = std::remove(node->_previous_nodes.begin(),
                                       node->_previous_nodes.end(), this);
      node->_previous_nodes.erase(new_end, node->_previous_nodes.end());

      // Si le noeud n'a plus de noeud précédent, il est détruit.
      if (node->_previous_nodes.size() == 0)
        delete node;
    }
  }

  std::size_t previous_nodes_count() const
  {
    return _previous_nodes.size();
  }

  void add_node(Graph* node)
  {
    if (!node)
      return;
    _next_nodes.push_back(node);
    node->add_previous_node(this);
  }

  Graph* node_at(std::size_t index) const
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

  void add_previous_node(Graph* node)
  {
    if (!node)
      return;
    _previous_nodes.push_back(node);
  }

  std::string _content;
  std::vector<Graph*> _next_nodes;
  std::vector<Graph*> _previous_nodes;
};
