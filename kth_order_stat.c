#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

void insert_into_tree(Node* root, Node* val) {
    if (val->value < root->value) {
        // insert in left
        if (root->left == NULL) root->left = val;
        else insert_into_tree(root->left, val);
    } else {
        // insert in right
        if (root->right == NULL) root->right = val;
        else insert_into_tree(root->right, val);
    }
}

int find_kth_element(Node* root, int* k) {
    int ret;
    if (root->left != NULL) {
        ret = find_kth_element(root->left, k);
    }
    if (*k == 0) return ret;
    (*k)--;
    if (*k == 0) return root->value;
    if (root->right != NULL) {
        ret = find_kth_element(root->right, k);
    }
    if (*k == 0) return ret;

    return -1;
}

int main(int argc, char** argv) {
    FILE* file;
    file = fopen("../kth_order_stat_input.txt", "r");
    int k;
    fscanf(file, "%d\n", &k);
    int n;
    fscanf(file, "%d\n", &n);
    int* nums = malloc(sizeof(int) * n); // not free'd
    for (int i = 0; i < n; ++i) {
        fscanf(file, "%d\n", &nums[i]);
    }

    int min = nums[0];
    int max = nums[0];
    Node* root = malloc(sizeof(Node));
    root->value = nums[0];
    root->left = NULL;
    root->right = NULL;
    for (int i = 1; i < n; ++i) {
        Node* val = malloc(sizeof(Node));
        val->value = nums[i];
        val->left = NULL;
        val->right = NULL;
        insert_into_tree(root, val);
        if (min > nums[i]) min = nums[i];
        if (max < nums[i]) max = nums[i];
    }

    int kth = find_kth_element(root, &k);

    FILE* out;
    out = fopen("../kth_order_stat_output.txt", "weight");

    fprintf(out, "min: %d\n", min);
    fprintf(out, "max: %d\n", max);
    fprintf(out, "kth: %d\n", kth);

    return 0;
}
