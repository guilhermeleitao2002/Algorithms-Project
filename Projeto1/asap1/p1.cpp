#include <iostream>
#include <vector>
#include "tree.h"

class Node {
    private:
        int _value;
        NodeP _parent = NULL;
        std::vector<NodeP> _children;
    public:
        Node(int value){
            _value = value;
        }
        bool newNode(int val) {
            if (val > _value) {
                if (_children.size() == 0) {
                    std::cout << val << " added at " << this->_value << std::endl; //debugging
                    addChild(new Node(val));
                    return true;
                }
                else {
                    bool added = false;
                    for (NodeP child : _children){
                        std ::cout << "vairecursiva " << this->_value << " com filhos : " << this->_children.size() << std::endl ; //debugging
                        if (child->newNode(val))
                            added = true;
                    }
                    if (!added) {
                        std::cout << val << " added at parent " << this->getValue() << std::endl; // debugging
                        addChild(new Node(val));
                    }
                    return true;
                }
            }
            else{
                return false;
            }
        }
        void addChild(NodeP node) {
            _children.push_back(node);
            node->addParent(this);
        }
        void addParent(NodeP parent) {
            _parent = parent;
        }
        NodeP getParent() {
            return _parent;
        }
        std::vector<NodeP> getChildren(){
            return _children;
        }
        int getValue() {
            return _value;
        }
        int getSize() {
            if (_children.size() != 0) {
                int maxSize = 0;
                for (NodeP child : _children) {
                    int temp = child->getSize();
                    if (temp > maxSize) {
                        maxSize = temp;
                    }
                }
                return 1 + maxSize;
            }
            else 
                return 1;
        }
        int getMaxSeqN(int size) {
            int n = 0;
            //std::cout << "size : " << size << std::endl;
            if (_children.size() > 0) {
                for (NodeP child : _children) {
                    n += child->getMaxSeqN(size - 1);
                }
                return n;
            }
            else if (size == 0) return 1;
            else return 0;
        }

};

class Tree {
    private:
        std::vector<NodeP> _roots;
    public:
        void addNode(int val){
            bool isNewRoot = true;
            for (NodeP root : _roots) {
                if(root->getValue() < val) {
                    root->newNode(val);
                    isNewRoot = false;
                }
            }
            if(isNewRoot){
                std::cout << "new root : " << val << std::endl; //debugging
                _roots.push_back(new Node(val));
            }
        }
        int getSize() {
            int size = 0;
            for (NodeP root : _roots) {
                int temp = root->getSize();
                if (temp > size) {
                    size = temp;
                }
            }
            return size;
        }
        int getMaxSeqN(int size) {
            int nSeq = 0;
            for (NodeP root : _roots) {
                nSeq += root->getMaxSeqN(size);
            }
            return nSeq;
        }
        std::vector<NodeP> getRoots(){
            return _roots;
        }
};

std::vector<int> split(std::string str, std::string exclude);

int main() { //cenas a melhorar : nodeP necessário?
    std::string problemN;
    int temp;
    getline(std::cin, problemN);
    
    if (problemN.compare("1") == 0) {
        std::vector<int> vec;
        while (std::cin >> temp)
            vec.push_back(temp);
        Tree tree;
        for (int n : vec) {
            tree.addNode(n);
        }
        int size = tree.getSize();
        std::cout << "maxsize : " <<  size << std ::endl;
        int seq = tree.getMaxSeqN(size - 1) ;
        std::cout << "seq number : " << seq << std::endl;
    }
    else if (problemN.compare("2") == 0) {
        std::vector<int> vec1, vec2;
        std::string str;
        getline(std::cin, str);
        vec1 = split(str, " ");
        getline(std::cin, str);
        vec2 = split(str, " ");
    }
    return 0;
}

std::vector<int> split(std::string str, std::string exclude) {
    size_t pos;
    int num = 0;
    std::vector<int> vec;
    while ((pos = str.find(exclude)) != std::string::npos) {
        num = stoi(str.substr(0, pos));
        vec.push_back(num); 
        str.erase(0, pos + exclude.length());
    }
    vec.push_back(stoi(str));
    return vec;
}

void printTree(Tree tree){
    
}