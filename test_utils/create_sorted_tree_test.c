#include "ft_create_sorted_tree.c"
#include "criterion/criterion.h"

#define create_sorted_tree_test_description                                    \
  CYAN "Initializes 100 ints inside of a btree in asceding "                   \
       "order and then prints it\n" RESET

#define create_sorted_tree_of_words_test_description	                       \
        CYAN "Initiallizes a sorted tree of words in alphabetical order, "     \
             "prints its "                                                     \
             "content and then traverses it in prefix, infix and suffix "      \
             "order printing "                                                 \
             "its content\n" RESET

Test(TEST_SUITE_NAME, create_sorted_tree_test, .description = create_sorted_tree_test_description) {
  t_btree *root = NULL;
  root = create_sorted_tree_with_100_ints(root);
  cr_expect_neq(root, NULL);
  ft_delete_tree(root, safe_free);
}

Test(TEST_SUITE_NAME, create_sorted_tree_of_words, .description = create_sorted_tree_of_words_test_description) {
	t_btree *root = NULL;
	root = create_sorted_tree_of_words(root);
	cr_expect_neq(root, NULL);
	btree_apply_suffix(root, safe_free);
	ft_delete_tree(root, safe_free);
}
