#ifndef TREEINTERFACE_H_
#define TREEINTERFACE_H_

template <typename T>
class TreeInterface {
        public:
                virtual ~TreeInterface() = default;
                virtual bool insert(T &_value) = 0;
                virtual bool remove(T &_value) = 0;
                virtual bool exist(T &_value) = 0;
};

#endif // TREEINTERFACE_H_
