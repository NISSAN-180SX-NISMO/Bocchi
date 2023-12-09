#ifndef BOCCHI_CAROUSEL_H
#define BOCCHI_CAROUSEL_H

#include <vector>
#include <memory>

template <class Data>
class Carousel {
private:
    std::vector<Data> vector;
    size_t currentIndex = 0;
public:
    void append(Data data) {
        vector.push_back(data);
    }
    void clear() {
        vector.clear();
        this->currentIndex = 0;
    }
    Data& getNext() {
        if (currentIndex == vector.size() - 1) {
            currentIndex = 0;
            return vector[currentIndex];
        }
        else {
            currentIndex++;
            return vector[currentIndex];
        }
    }

    Data& getPrevious() {
        if (currentIndex == 0) {
            currentIndex = vector.size() - 1;
            return vector[currentIndex];
        }
        else {
            currentIndex--;
            return vector[currentIndex];
        }
    }

    bool empty() {
        return vector.empty();
    }

    Carousel(std::pair<std::_Rb_tree_iterator<std::pair<MenuCase *const, MenuCase *>>,
             std::_Rb_tree_iterator<std::pair<MenuCase *const, MenuCase *>>> pair1) {
        for (auto it = pair1.first; it != pair1.second; it++) {
            this->append(it->second);
        }
    }
};

#endif //BOCCHI_CAROUSEL_H
