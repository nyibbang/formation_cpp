#include "exo6.hpp"
#include <gtest/gtest.h>

TEST(Exo6, Tree)
{
  auto tree = Tree::make_tree("root");
  tree->add_child("hello");
  auto child = tree->child_at(0);
  ASSERT_NE(nullptr, child);
  EXPECT_EQ("hello", child->content());
  delete tree;
}

TEST(Exo6, Graph)
{
  auto graph = Graph::make_graph("root");
  auto node = Graph::make_graph("another node");
  graph->add_node(node);
  auto next_node = graph->node_at(0);
  ASSERT_NE(nullptr, next_node);
  EXPECT_EQ("another node", next_node->content());
  delete node;
  delete graph;
}
