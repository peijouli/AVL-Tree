#include "avlbst.h"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class BSTTest : public testing::Test {
protected:

    BSTTest() {
        n1 = new Node<string, int>("Kevin", 1, NULL);
        bst.insert(std::make_pair("Kevin", 1));
        avl.insert(std::make_pair("Kevin", 1));
    }

    virtual ~BSTTest() {
        delete n1;
    }

    virtual void SetUp() {
        
        
    }

    virtual void TearDown() {
        
    }

    Node<string, int >* n1;
    BinarySearchTree<string, int> bst;
    AVLTree<string, int> avl;
};


TEST_F(BSTTest, NodeNominal) {
    EXPECT_EQ(n1->getKey(), "Kevin");
    EXPECT_EQ(n1->getValue(), 1);

    Node<string, int>* n2 = new Node<string, int>("Allen", 2, NULL);
    n1->setLeft(n2);
    EXPECT_EQ(n1->getLeft()->getValue(), 2);
    n2->setParent(n1);
    EXPECT_EQ(n2->getParent()->getValue(), 1);
    std::cout << "DEBUG IN NODE" << std::endl;
    //delete n2;
} 

/*TEST_F(BSTTest, TreeInsertNominal) {
    bst.insert(std::make_pair("Calvin", 2));
    bst.insert(std::make_pair("Allen", 4));
    bst.insert(std::make_pair("Chris", 3));
    bst.insert(std::make_pair("Allen", 7));
    bst.insert(std::make_pair("Zebra", 11));
    std::cout << "inserted" << std::endl;

    BinarySearchTree<string, int>::iterator it = bst.find("Allen");
    std::cout << "f" << std::endl;
    EXPECT_EQ(it->second, 7);
    ++it;
    EXPECT_EQ(it->first, "Calvin");
    EXPECT_EQ(it->second, 2);

    bst.print();
}*/

TEST_F(BSTTest, AVLTreeInsertLZigZig) {
    avl.insert(std::make_pair("Calvin", 2));
    avl.insert(std::make_pair("Allen", 4));
    EXPECT_EQ(avl.mRoot->getKey(), "Calvin");
    avl.print();
}

TEST_F(BSTTest, AVLTreeInsertRZigZig) {
    avl.insert(std::make_pair("Lauren", 3));
    avl.insert(std::make_pair("Zebra", 11));
    EXPECT_EQ(avl.mRoot->getKey(), "Lauren");
    avl.print();
}

TEST_F(BSTTest, AVLTreeInsertLZigZag) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Chris", 11));
    EXPECT_EQ(avl.mRoot->getKey(), "Chris");
    avl.print();
}

TEST_F(BSTTest, AVLTreeInsertRZigZag) {
    avl.insert(std::make_pair("Zebra", 11));
    avl.insert(std::make_pair("Lauren", 3));
    EXPECT_EQ(avl.mRoot->getKey(), "Lauren");
    avl.print();
}

TEST_F(BSTTest, AVLTreeInsertLZigZigChildren) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Zebra", 11));
    avl.insert(std::make_pair("Chris", 12));
    avl.insert(std::make_pair("Allen", 4));
    avl.insert(std::make_pair("Bob", 7));
    EXPECT_EQ(avl.mRoot->getKey(), "Calvin");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Kevin");
    EXPECT_EQ(avl.mRoot->getRight()->getLeft()->getKey(), "Chris");
    avl.print();
}

TEST_F(BSTTest, AVLTreeInsertLZigZagRChild) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Zebra", 11));
    avl.insert(std::make_pair("Chris", 12));
    avl.insert(std::make_pair("Allen", 4));
    avl.insert(std::make_pair("Connie", 7));
    EXPECT_EQ(avl.mRoot->getKey(), "Chris");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Kevin");
    EXPECT_EQ(avl.mRoot->getLeft()->getKey(), "Calvin");
    EXPECT_EQ(avl.mRoot->getRight()->getLeft()->getKey(), "Connie");
    avl.print();
}

TEST_F(BSTTest, AVLTreeInsertLZigZagLChild) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Zebra", 11));
    avl.insert(std::make_pair("Chris", 12));
    avl.insert(std::make_pair("Allen", 4));
    avl.insert(std::make_pair("Charles", 7));
    EXPECT_EQ(avl.mRoot->getKey(), "Chris");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Kevin");
    EXPECT_EQ(avl.mRoot->getLeft()->getKey(), "Calvin");
    EXPECT_EQ(avl.mRoot->getLeft()->getRight()->getKey(), "Charles");
    avl.print();
}

TEST_F(BSTTest, AVLTreeInsertRZigZigChildren) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Nina", 11));
    avl.insert(std::make_pair("Lion", 12));
    avl.insert(std::make_pair("Owen", 4));
    avl.insert(std::make_pair("Penny", 7));
    EXPECT_EQ(avl.mRoot->getKey(), "Nina");
    EXPECT_EQ(avl.mRoot->getLeft()->getKey(), "Kevin");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Owen");
    EXPECT_EQ(avl.mRoot->getLeft()->getRight()->getKey(), "Lion");
    avl.print();
}

TEST_F(BSTTest, AVLTreeInsertRZigZagLChild) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Nina", 11));
    avl.insert(std::make_pair("Lion", 12));
    avl.insert(std::make_pair("Owen", 4));
    avl.insert(std::make_pair("Lenny", 7));
    EXPECT_EQ(avl.mRoot->getKey(), "Lion");
    EXPECT_EQ(avl.mRoot->getLeft()->getKey(), "Kevin");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Nina");
    EXPECT_EQ(avl.mRoot->getLeft()->getRight()->getKey(), "Lenny");
    avl.print();
}

TEST_F(BSTTest, AVLTreeInsertRZigZagRChild) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Nina", 11));
    avl.insert(std::make_pair("Lion", 12));
    avl.insert(std::make_pair("Owen", 4));
    avl.insert(std::make_pair("Moh", 7));
    EXPECT_EQ(avl.mRoot->getKey(), "Lion");
    EXPECT_EQ(avl.mRoot->getLeft()->getKey(), "Kevin");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Nina");
    EXPECT_EQ(avl.mRoot->getRight()->getLeft()->getKey(), "Moh");
    avl.print();
}

TEST_F(BSTTest, AVLTreeInsertLargeNominal) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Leon", 3));
    avl.insert(std::make_pair("Lion", 3));
    avl.insert(std::make_pair("Larry", 3));
    avl.insert(std::make_pair("Allen", 3));
    avl.insert(std::make_pair("Manny", 3));
    avl.insert(std::make_pair("Liam", 3));
    avl.insert(std::make_pair("Charles", 3));
    EXPECT_EQ(avl.mRoot->getKey(), "Kevin");
    EXPECT_EQ(avl.mRoot->getLeft()->getRight()->getKey(), "Charles");
    EXPECT_EQ(avl.mRoot->getRight()->getLeft()->getKey(), "Larry");
}

TEST_F(BSTTest, AVLTreeRemoveNominal) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Leon", 3));
    avl.erase("Leon");
    EXPECT_EQ(avl.mRoot->getKey(), "Kevin");
    avl.erase("Kevin");
    EXPECT_EQ(avl.mRoot->getKey(), "Calvin");
    avl.insert(std::make_pair("Chris", 3));
    avl.print();
    avl.erase("Chris");
    avl.print();
    EXPECT_EQ(avl.mRoot->getKey(), "Calvin");
    avl.print();
    avl.erase("Calvin");
    avl.print();
}

TEST_F(BSTTest, AVLTreeRemoveZigZagNominal) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Leon", 3));
    avl.insert(std::make_pair("Chris", 3));
    avl.erase("Leon");
    EXPECT_EQ(avl.mRoot->getKey(), "Chris");
    EXPECT_EQ(avl.mRoot->getLeft()->getKey(), "Calvin");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Kevin");
    avl.print();
}

TEST_F(BSTTest, AVLTreeRemoveZigZagNominal2) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Leon", 3));
    avl.insert(std::make_pair("Chris", 3));
    avl.insert(std::make_pair("Manny", 3));
    avl.insert(std::make_pair("Allen", 3));
    avl.insert(std::make_pair("Charles", 3));
    avl.insert(std::make_pair("Dan", 3));
    avl.erase("Manny");
    avl.print();
    EXPECT_EQ(avl.mRoot->getKey(), "Chris");
    EXPECT_EQ(avl.mRoot->getLeft()->getKey(), "Calvin");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Kevin");
    EXPECT_EQ(avl.mRoot->getRight()->getLeft()->getKey(), "Dan");
    avl.print();
}

TEST_F(BSTTest, AVLTreeRemove2ChildrenRoot) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Leon", 3));
    avl.erase("Kevin");
    EXPECT_EQ(avl.mRoot->getKey(), "Leon");
    avl.print();
}

TEST_F(BSTTest, AVLTreeRemove2ChildrenRoot2) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Leon", 3));
    avl.insert(std::make_pair("Lion", 3));
    avl.insert(std::make_pair("Larry", 3));
    avl.erase("Kevin");
    EXPECT_EQ(avl.mRoot->getKey(), "Larry");
    avl.print();
}

TEST_F(BSTTest, AVLTreeRemove2ChildrenRootNominal) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Leon", 3));
    avl.insert(std::make_pair("Lion", 3));
    avl.insert(std::make_pair("Larry", 3));
    avl.insert(std::make_pair("Allen", 3));
    avl.insert(std::make_pair("Manny", 3));
    avl.insert(std::make_pair("Liam", 3));
    avl.erase("Leon");
    EXPECT_EQ(avl.mRoot->getKey(), "Kevin");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Liam");
    avl.erase("Allen");
    EXPECT_EQ(avl.mRoot->getKey(), "Liam");
    EXPECT_EQ(avl.mRoot->getLeft()->getRight()->getKey(), "Larry");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Lion");

    avl.print();
}

TEST_F(BSTTest, AVLTreeRemove2ChildrenRootNominal2) {
    avl.insert(std::make_pair("Calvin", 3));
    avl.insert(std::make_pair("Leon", 3));
    avl.insert(std::make_pair("Lion", 3));
    avl.insert(std::make_pair("Larry", 3));
    avl.insert(std::make_pair("Allen", 3));
    avl.insert(std::make_pair("Manny", 3));
    avl.insert(std::make_pair("Liam", 3));
    avl.erase("Allen");
    EXPECT_EQ(avl.mRoot->getKey(), "Leon");
    EXPECT_EQ(avl.mRoot->getLeft()->getRight()->getKey(), "Larry");
    EXPECT_EQ(avl.mRoot->getRight()->getKey(), "Lion");

    avl.print();
}


// #include "avlbst.h"

// #include "gtest/gtest.h"

// #include <ctime>

// #include <cstdlib>

// #include <algorithm>

// #include <iostream>

// #include <iomanip>

// #include <set>
// #include <vector>



// // slightly modified, originally taken from http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/



// /* The function returns true if root is balanced else false

//    The second parameter is to store the height of tree.

//    Initially, we need to pass a pointer to a location with value

//    as 0. We can also write a wrapper over this function */




// template<typename Key, typename Value>

// bool isBalanced(Node<Key, Value>* root, int* height)

// {

//   /* lh --> Height of left subtree

//      rh --> Height of right subtree */

//   int lh = 0, rh = 0;



//   /* l will be true if left subtree is balanced

//     and r will be true if right subtree is balanced */

//   int l = 0, r = 0;



//   if(root == NULL)

//   {

//     *height = 0;

//      return 1;

//   }



//   /* Get the heights of left and right subtrees in lh and rh

//     And store the returned values in l and r */

//   l = isBalanced(root->getLeft(), &lh);

//   r = isBalanced(root->getRight(),&rh);



//   /* Height of current node is max of heights of left and

//      right subtrees plus 1*/

//   *height = (lh > rh? lh: rh) + 1;



//   /* If difference between heights of left and right

//      subtrees is more than 2 then this node is not balanced

//      so return 0 */

//   if((lh - rh >= 2) || (rh - lh >= 2))

//     return 0;



//   /* If this node is balanced and left and right subtrees

//     are balanced then return true */

//   else return l&&r;

// }



// // taken from http://www.randygaul.net/2015/06/15/printing-pretty-ascii-trees/

// // modified for compatibility

// template<typename Key, typename Value>

// void printTree( Node<Key, Value>* tp, int spaces = 0)

// {

//   int i;



//   if( tp != NULL )

//   {

//     printTree( tp->getRight(), spaces + 3 );

//     for( i = 0; i < spaces; i++ )

//       std::cout <<' ';

//     std::cout << tp->getKey() << std::endl;

//     printTree( tp->getLeft(), spaces + 3 );

//   }

// }



// TEST(AVLBST_TEST, InsertInOrder100) {

//     AVLTree<int, int> tree;

//     for(int i = 0; i < 100; i++){

//         tree.insert(std::make_pair(i, i));

//     }

//     int counter = 0;

//     for(AVLTree<int, int>::iterator it = tree.begin(); it != tree.end(); ++it){

//         EXPECT_EQ(it->first, counter++);

//     }

// }



// TEST(AVLBST_TEST, InsertEraseInOrder100) {

//     AVLTree<int, int> tree;

//     for(int i = 0; i < 100; i++){

//         tree.insert(std::make_pair(i, i));

//     }

//     int counter = 0;

//     for(AVLTree<int, int>::iterator it = tree.begin(); it != tree.end(); ++it){

//         EXPECT_EQ(it->first, counter++);

//     }

// }



// TEST(AVLBST_TEST, RandomInsert1000000) {

//     srand(time(NULL));

//     AVLTree<int, int> tree;

//     for(int i = 0; i < 1000000; i++){

//         tree.insert(std::make_pair(rand() % 1000000, i));

//     }

//     int prev = -1;

//     for(AVLTree<int, int>::iterator it = tree.begin(); it != tree.end(); ++it){

//         EXPECT_LE(prev, it->first);

//         prev = it->first;

//     }

// }





// TEST(AVLBST_TEST, BalanceCheck100x10) {

//     srand(time(NULL));

//     for(int i = 0; i < 100; i++){

//         AVLTree<int, int> tree;

//         int height = 0;

//         std::set<int> dupes;



//         for(int i = 0; i < 10; i++){

//             int newKey = rand() % 10;

//             dupes.insert(newKey);

//             tree.insert(std::make_pair(newKey, i));

//         }



//         bool balanced = isBalanced(tree.mRoot, &height);

//         EXPECT_TRUE(balanced);

//         if(!balanced){

//             std::cout << "Tree with size of " << (dupes.size()) << " is **NOT** balanced!" << std::endl;

//             printTree(tree.mRoot);

//         }

//     }

// }



// TEST(AVLBST_TEST, BalanceCheck1000x1000) {

//     srand(time(NULL));

//     for(int i = 0; i < 1000; i++){

//         AVLTree<int, int> tree;

//         int height = 0;

//         std::set<int> dupes;

//         for(int i = 0; i < 1000; i++){

//             int newKey = rand() % 1000;

//             dupes.insert(newKey);

//             tree.insert(std::make_pair(newKey, i));

//         }

//         bool balanced = isBalanced(tree.mRoot, &height);

//         EXPECT_TRUE(balanced);

//         if(!balanced){

//             std::cout << "Tree with size of " << (dupes.size()) << " is not balanced!" << std::endl;

//             printTree(tree.mRoot);

//         }

//     }

// }



// TEST(AVLBST_TEST, BalanceCheck100x10000) {

//     srand(time(NULL));

//     for(int i = 0; i < 100; i++){

//         AVLTree<int, int> tree;

//         int height = 0;

//         std::set<int> dupes;

//         for(int i = 0; i < 10000; i++){

//             int newKey = rand() % 10000;

//             dupes.insert(newKey);

//             tree.insert(std::make_pair(newKey, i));

//         }

//         bool balanced = isBalanced(tree.mRoot, &height);

//         EXPECT_TRUE(balanced);

//         if(!balanced){

//             std::cout << "Tree with size of " << (dupes.size()) << " is not balanced!" << std::endl;

//             printTree(tree.mRoot);

//         }

//     }

// }



// TEST(AVLBST_TEST, BalanceCheckTiny1000) {

//     srand(time(NULL));

//     for(int i = 0; i < 1000; i++){

//         AVLTree<int, int> tree;

//         int height = 0;

//         std::set<int> dupes;

//         int size = rand() % 5 + 1;

//         for(int i = 0; i < size; i++){

//             int newKey = rand() % 100;

//             dupes.insert(newKey);

//             tree.insert(std::make_pair(newKey, i));

//         }

//         bool balanced = isBalanced(tree.mRoot, &height);

//         EXPECT_TRUE(balanced);

//         if(!balanced){

//             std::cout << "Tree with size of " << (dupes.size()) << " is not balanced!" << std::endl;

//             printTree(tree.mRoot);

//         }

//     }

// }



// TEST(AVLBST_TEST, RandomErase1000) {

//     srand(time(NULL));

//     for(int i = 0; i < 1000; i++){

//         AVLTree<int, int> tree;

//         std::set<int> dupes;

//         for(int i = 0; i < 1000; i++){

//             int newKey = rand() % 1000;

//             dupes.insert(newKey);

//             tree.insert(std::make_pair(newKey, i));

//         }

//         for(std::set<int>::iterator it = dupes.begin(); it != dupes.end(); ++it){

//             tree.erase(*it);

//         }

//         EXPECT_TRUE(tree.mRoot == NULL);

//     }

// }



// TEST(AVLBST_TEST, RandomErase1000SizeCheck) {

//     srand(time(NULL));

//     for(int i = 0; i < 1000; i++){

//         AVLTree<int, int> tree;

//         std::set<int> dupes;

//         for(int i = 0; i < 100; i++){

//             int newKey = rand() % 100;

//             dupes.insert(newKey);

//             tree.insert(std::make_pair(newKey, i));

//         }

//         std::vector<int> randomOrderedKeys;



//         for(std::set<int>::iterator it = dupes.begin(); it != dupes.end(); ++it){

//             randomOrderedKeys.push_back(*it);

//         }



//         int num = rand() % dupes.size();

//         for(int i = 0; i < num; i++){

//             tree.erase(randomOrderedKeys[i]);

//         }

//         int size = 0;

//         for(AVLTree<int, int>::iterator it = tree.begin(); it != tree.end(); ++it){

//             size++;

//         }

//         EXPECT_EQ(size, dupes.size() - num);

//     }

// }



// TEST(AVLBST_TEST, RandomEraseMost1000SizeCheck) {

//     srand(time(NULL));

//     for(int i = 0; i < 1000; i++){

//         AVLTree<int, int> tree;

//         std::set<int> dupes;

//         for(int i = 0; i < 100; i++){

//             int newKey = rand() % 100;

//             dupes.insert(newKey);

//             tree.insert(std::make_pair(newKey, i));

//         }

//         std::vector<int> randomOrderedKeys;



//         for(std::set<int>::iterator it = dupes.begin(); it != dupes.end(); ++it){

//             randomOrderedKeys.push_back(*it);

//         }



//         int num = dupes.size() - (rand() % 10);

//         for(int i = 0; i < num; i++){

//             tree.erase(randomOrderedKeys[i]);

//         }

//         int size = 0;

//         for(AVLTree<int, int>::iterator it = tree.begin(); it != tree.end(); ++it){

//             size++;

//         }

//         EXPECT_EQ(size, dupes.size() - num);

//     }

// }



// TEST(AVLBST_TEST, RandomErase1000BalanceCheck) {

//     srand(time(NULL));

//     for(int i = 0; i < 1000; i++){

//         AVLTree<int, int> tree;

//         std::set<int> dupes;

//         for(int i = 0; i < 100; i++){

//             int newKey = rand() % 100;

//             dupes.insert(newKey);

//             tree.insert(std::make_pair(newKey, i));

//         }

//         std::vector<int> randomOrderedKeys;



//         for(std::set<int>::iterator it = dupes.begin(); it != dupes.end(); ++it){

//             randomOrderedKeys.push_back(*it);

//         }



//         int num = rand() % dupes.size();

//         for(int i = 0; i < num; i++){

//             tree.erase(randomOrderedKeys[i]);

//         }

//         int height;

//         bool balanced = isBalanced(tree.mRoot, &height);

//         EXPECT_TRUE(balanced);

//         if(!balanced){

//             std::cout << "Tree with size of " << (dupes.size()) << " is not balanced!" << std::endl;

//             printTree(tree.mRoot);

//         }

//     }

// }



// TEST(AVLBST_TEST, RandomEraseMost1000BalanceCheck) {

//     srand(time(NULL));

//     for(int i = 0; i < 1000; i++){

//         AVLTree<int, int> tree;

//         std::set<int> dupes;

//         for(int i = 0; i < 100; i++){

//             int newKey = rand() % 100;

//             dupes.insert(newKey);

//             tree.insert(std::make_pair(newKey, i));

//         }

//         std::vector<int> randomOrderedKeys;



//         for(std::set<int>::iterator it = dupes.begin(); it != dupes.end(); ++it){

//             randomOrderedKeys.push_back(*it);

//         }



//         int num = dupes.size() - (rand() % 10);

//         for(int i = 0; i < num; i++){

//             tree.erase(randomOrderedKeys[i]);

//         }

//         int height;

//         bool balanced = isBalanced(tree.mRoot, &height);

//         EXPECT_TRUE(balanced);

//         if(!balanced){

//             std::cout << "Tree with size of " << (dupes.size()) << " is not balanced!" << std::endl;

//             printTree(tree.mRoot);

//         }

//     }

// }