#ifndef TRITREE_H
#define TRITREE_H

#include <string>
#include <vector>
using namespace std;

struct Node
{
    char mContent;
    bool mMarker;
    vector<Node*> children;
    Node();
    Node* findChild(char character);
};

class TriTree
{
    Node* root;
    void deleteTree(Node* ptr);
    ostream& printTree(ostream& out, Node* ptr) const;
    public:
        /** Default constructor */
        TriTree();
        /** Default destructor */
        ~TriTree();
        /** Copy constructor
         *  \param other Object to copy from
         */
        TriTree(const TriTree& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        TriTree& operator=(const TriTree& other);

        void insertWord(string word);
        bool searchWord(string word);
        void deleteWord(string word);
        friend istream& operator >>(istream& read, TriTree& tree);
};

#endif // TRITREE_H
