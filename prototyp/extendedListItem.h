#include <string>

class ExtendedListItem
{
public:
    ExtendedListItem(int key);
    std::string toString();
    ExtendedListItem* next;
    ExtendedListItem* previous;
    int key;
};