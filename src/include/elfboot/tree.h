#ifndef __TREE_H__
#define __TREE_H__

#include <elfboot/core.h>
#include <elfboot/list.h>

struct tree_node;

struct tree_ops {
	int (*insert)(struct tree_node *, struct tree_node *);
	int (*remove)(struct tree_node *);
};

struct tree_node {
	struct tree_node *parent;
	struct list_head children;
	struct list_head siblings;
	uint32_t children_count;
};

struct tree_head {
	int count;
	struct tree_ops *ops;
	struct tree_node *root;
};

#define tree_for_each_child(pos, parent)				\
	list_for_each_entry(pos, &(parent)->children, siblings)

#define tree_for_each_child_safe(pos, n, parent)			\
	list_for_each_entry_safe(pos, n, &(parent)->children, siblings)

#define TREE_HEAD_INIT(name)						\
	{ 0, NULL, NULL }

#define TREE_HEAD(name)							\
	struct tree_head name = TREE_HEAD_INIT(name)

static inline void tree_node_init(struct tree_node *node)
{
	node->parent = NULL;
	list_init(&node->children);
	list_init(&node->siblings);
	node->children_count = 0;
}

/*
 * General n-ary tree functions
 *
 * int tree_node_is_leaf(struct tree_node *node): 
 * 	Is the specified node a leaf node?
 * 	
 * void tree_node_insert(struct tree_node *new, struct tree_node *parent):
 * 	Add a new node with all its children to an 
 * 	existing parent node.
 *
 * void tree_node_remove(struct tree_node *node):
 * 	Remove the specified node from the tree, but 
 * 	keep all references to its children.
 */

static inline int tree_node_is_leaf(struct tree_node *node)
{
	return !node->children_count;
}

static inline void tree_node_insert(struct tree_node *new, 
				    struct tree_node *parent)
{
	parent->children_count += (new->children_count + 1);
	new->parent = parent;
	
	list_add(&new->siblings, &parent->children);
}

static inline void tree_node_remove(struct tree_node *node)
{
	node->parent->children_count -= (node->children_count + 1);
	node->parent = NULL;

	list_del(&node->siblings);
}

#endif /* __TREE_H__ */