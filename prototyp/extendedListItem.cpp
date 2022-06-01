#include "extendedListItem.h"

std::string ExtendedListItem::toString(void) {
    return std::to_string(this->key);
}

ExtendedListItem::ExtendedListItem(int key) {
    this->key = key;
}