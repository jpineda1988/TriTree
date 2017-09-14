#include "TriTree.h"

Node::Node() : mContent(' '), mMarker(false)
{
}

Node* Node::findChild(char character)
{
   Node* temp = nullptr;
   for(int index = 0; index < children.size(); index++)
   {
       temp = children[index];
       if(temp->mContent == character)
          return temp;
   }
   return nullptr;
}



TriTree::TriTree() : root(new Node())
{
    //ctor
}

TriTree::~TriTree()
{
    deleteTree(root);
    //dtor
}

TriTree::TriTree(const TriTree& other)
{
    //copy ctor
}

TriTree& TriTree::operator=(const TriTree& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void TriTree::insertWord(string word)
{
    Node *current = root, *child = nullptr, *tmp = nullptr;

    if(word.empty())
    {
       current->mMarker = true;
       return;
    }


    for(int index = 0; index < word.size(); index++)
    {
        child = current->findChild(word[index]);
        if(child != nullptr)
           current = child;
        else
        {
           tmp = new Node();
           tmp->mContent = word[index];
           current->children.push_back(tmp);
           current = tmp;
        }
        if(index == word.length() - 1)
          current->mMarker = true;
    }
}

bool TriTree::searchWord(string word)
{
     Node *current = root, *temp = nullptr;

     if(current != nullptr)
     {
        for(int index = 0; index < word.size(); index++)
        {
           temp = current->findChild(word[index]);
           if(temp == nullptr)
              return false;
           current = temp;
        }

        return current->mMarker;
     }
     return false;
}

void TriTree::deleteWord(string word)
{
}


void TriTree::deleteTree(Node* ptr)
{
    if(ptr->mContent && ptr->children.empty())
    {
        delete ptr;
        ptr = nullptr;
    }
    else
    {
       for(int index = 0; index < ptr->children.size(); index++)
          deleteTree(ptr->children[index]);
       ptr->children.clear();
    }
}

istream& operator >>(istream& read, TriTree& tree)
{
     string word;
     read >> word;
     tree.insertWord(word);
     return read;
}


