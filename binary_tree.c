#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _node_t node_t;

struct _node_t 
{
    struct _node_t *left;
    struct _node_t *right;
    int key;
    void *data; 
};


typedef struct _binary_tree_t binary_tree_t;

struct _binary_tree_t
{
    node_t *root;
    node_t *(*search)(binary_tree_t *tree, int key);
    bool (*insert)(binary_tree_t *tree, node_t *node);
    node_t *(*delete)(binary_tree_t *tree, int key);
    void (*print)(binary_tree_t *tree);
    void (*destroy)(binary_tree_t *tree);
};


bool insert_node(node_t *root, node_t *node)
{
    node_t *tmp = root;
    node_t *parent = NULL;
    while(tmp)
    {
        if(tmp->key == node->key)
        {
            return false;
        }
        parent = tmp;
        tmp = node->key < tmp->key ? tmp->left:tmp->right;
    }

    if(node->key < parent->key)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }
}


//相同key值不能插入
bool insert(binary_tree_t *tree, node_t *node)
{
    node_t *tmp = tree->root;
    node_t *parent = NULL;
    while(tmp)
    {
        if(tmp->key == node->key)
        {
            return false;
        }
        parent = tmp;
        tmp = node->key < tmp->key ? tmp->left:tmp->right;
    }

    printf("insert %d\n", node->key);
    if(node->key < parent->key)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }
}

///不允许删除根节点
node_t *delete(binary_tree_t *tree, int key)
{
    node_t *tmp = tree->root;
    node_t *parent = NULL;
    while(tmp)
    {
        if(tmp->key == key)
        {
            if(parent == NULL)
            {
                return NULL;
            }
            else
            {
                if(tmp->left == NULL && tmp->right == NULL)
                {
                    if(tmp->key < parent->key)
                    {
                        parent->left = NULL;
                    }
                    else
                    {
                        parent->right = NULL;
                    }
                }
                else if(tmp->left == NULL && tmp->right !=NULL)
                {
                    if(tmp->key < parent->key)
                    {
                        parent->left = tmp->right;
                    }
                    else
                    {
                        parent->right = tmp->right;
                    }
                }
                else if(tmp->left != NULL && tmp->right ==NULL)
                {
                    if(tmp->key < parent->key)
                    {
                        parent->left = tmp->left;
                    }
                    else
                    {
                        parent->right = tmp->left;
                    }
                }
                else//都不为NULL
                {
                    if(tmp->key < parent->key)
                    {
                        if(tmp->left->right == NULL)
                        {
                            parent->left = tmp->left;
                            tmp->left->right = tmp->right; 
                        } 
                        else if (tmp->right->left == NULL )
                        {
                            parent->left = tmp->right;
                            tmp->right->left = tmp->left; 
                        }
                        else
                        {
                            parent->left = tmp->left;
                            insert_node(tmp->left, tmp->right);
                        }
                    }
                    else
                    {
                        if(tmp->left->right == NULL)
                        {
                            parent->right = tmp->left;
                            tmp->left->right = tmp->right; 
                        } 
                        else if (tmp->right->left == NULL )
                        {
                            parent->right = tmp->right;
                            tmp->right->left = tmp->left; 
                        }
                        else
                        {
                            parent->right = tmp->left;
                            insert_node(tmp->left, tmp->right);
                        }
                    }
                }                

                return tmp;
            }
        }

        parent = tmp;
        tmp = key < tmp->key ? tmp->left:tmp->right;
    }   

    return NULL;
}



node_t *search(binary_tree_t *tree, int key)
{
    node_t *tmp = tree->root;
    while(tmp)
    {
        if(tmp->key == key)
        {
            return tmp;
        }
        tmp = key < tmp->key ? tmp->left:tmp->right;
    }
    
    return NULL;
}


void print_node(node_t *node)
{
    if(node->left)
    {
        print_node(node->left);
    }
    printf("%d\n", node->key);
    if(node->right)
    {
        print_node(node->right);
    }
}

void print_binary(binary_tree_t *tree)
{
    print_node(tree->root);    
}


void print_mid_node(node_t *node)
{
    printf("%d\n", node->key);
    if(node->left)
    {
        print_node(node->left);
    }
    if(node->right)
    {
        print_node(node->right);
    }
}
void print_mid(binary_tree_t *tree)
{
    print_mid_node(tree->root);    
}


void destroy_node(node_t *node)
{
    if(node->left)
    {
        destroy_node(node->left);
    }
    if(node->right)
    {
        destroy_node(node->right);
    }
    free(node);//node->data看情况销毁
}

void destroy(binary_tree_t *tree)
{
    destroy_node(tree->root);
}


binary_tree_t * create_binary_tree(node_t *root)
{
    binary_tree_t *binary_tree = (binary_tree_t *)malloc(sizeof(binary_tree_t));
    binary_tree->root = root;
    binary_tree->insert = insert;
    binary_tree->print = print_binary;
//    binary_tree->print = print_mid;
    binary_tree->search = search;
    binary_tree->delete = delete;
    binary_tree->destroy = destroy;
}



void main()
{
    node_t *root = (node_t*)malloc(sizeof(node_t));
    memset(root, 0, sizeof(node_t));
    root->key = 10;//key
    binary_tree_t *bt = create_binary_tree(root);

    int array[10] = {-1, 21, 6, 3, 9, 20, 5, 11, 91, 91};
    int i = 0;
    for(i=0; i<10; i++)
    {
        node_t *tmp = (node_t*)malloc(sizeof(node_t));
        memset(tmp, 0, sizeof(node_t));
        tmp->key = array[i];
        bt->insert(bt, tmp); 
    }

    bt->print(bt);
    if(bt->search(bt, 91))
    {
        printf("find 91\n");
    }
    if(bt->search(bt, 100))
    {
        printf("not find 100\n");
    }

    bt->delete(bt,20);
    bt->print(bt);
    bt->delete(bt,9);
    bt->print(bt);

    bt->destroy(bt);

}
