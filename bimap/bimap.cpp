#include "bimap.h"


bimap::bimap() {

}

bimap::bimap(const bimap &bimap1) {

}

bimap::left_iterator bimap::insert(const bimap::left_type &type, const bimap::right_type &right_type) {
    return bimap::left_iterator();
}

bimap::left_iterator bimap::erase(bimap::left_iterator iterator) {
    return bimap::left_iterator();
}

bimap::right_iterator bimap::erase(bimap::right_iterator iterator) {
    return bimap::right_iterator();
}

bimap::left_iterator bimap::find_left(const bimap::left_type &type) {
    return bimap::left_iterator();
}

bimap::right_iterator bimap::find_right(const bimap::right_type &type) {
    return bimap::right_iterator();
}

bool bimap::empty() const {
    return false;
}
